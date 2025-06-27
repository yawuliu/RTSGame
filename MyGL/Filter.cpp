#include "Filter.h"
#include "IUniformSampler.h"
#include "IShader.h"

namespace MyGL {

    Filter::Filter(IScene &s) : AbstractPass(s) {
        this->data = new Filter::Data::Data();
        this->data->renderState->setZTest(0);
        this->data->renderState->etZWriting(0);
        this->data->quad = 0LL;
        this->data->shader = 0LL;
    }

    Filter::~Filter() {
        if (this->data) {
            delete this->data;
        }
    }

    IUniformSampler *Filter::addArgs(IUniformSampler *sm, ITexture *u) {
        void (__fastcall *v3)(IUniformSampler *, _QWORD);
        unsigned int v4;
        IScene *v6;
        __int64 v7;
        CGL *v8;
        IErrorControl *v9;
        IUniformSampler *sma;
        Filter *thisa;
        std::map<IUniformSampler *, ITexture *>::iterator i;
        std::_Rb_tree_iterator<std::pair<IUniformSampler *const, ITexture *> >::_Self __x;
        sma = sm;
        if (this->data->shader) {
            i._M_node = std::map<IUniformSampler *, ITexture *>::find(&thisa->data->args, &sma)._M_node;
            if (sma) {
                __x._M_node = std::map<IUniformSampler *, ITexture *>::end(&thisa->data->args)._M_node;
                if (std::_Rb_tree_iterator<std::pair<IUniformSampler *const, ITexture *>>::operator==(
                        &i, &__x)) {
                    v4 = std::map<IUniformSampler *, ITexture *>::size(&thisa->data->args);
                    sma->set(v4);
                }
                *std::map<IUniformSampler *, ITexture *>::operator[](&thisa->data->args, &sma) = u;
            }
            return sma;
        } else {
            v6 = AbstractPass::scene(thisa);
            v7 = v6->render();
            v8 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v7 + 72LL))(v7);
            v9 = v8->errorCtrl();
            v9->warning(
                    0LL,
                    "[Filter::addArgs]null shader");
            return 0LL;
        }
    }

    IUniformSampler *Filter::addArgs(const std::string &name, ITexture *u) {
        __int64(__fastcall *v3)(IShader *, __int64);
        __int64 v4;
        IUniformSampler *sm;
        IScene *v7;
        __int64 v8;
        CGL *v9;
        IErrorControl *v10;

        if (this->data->shader) {
            v4 = std::string::data((std::string *) name);
            sm = (IUniformSampler *) this->data->shader->uniformSampler(v4);
            return this->addArgs(sm, u);
        } else {
            v7 = this->scene();
            v8 = v7->render();
            v9 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v8 + 72LL))(v8);
            v10 = v9->errorCtrl();
            v10->warning(
                    0LL,
                    "[Filter::addArgs]null shader");
            return 0LL;
        }
    }

    void Filter::exec() {
        IScene *v1;
        __int64 v2;
        CGL *v3;
        IErrorControl *v4;
        IScene *v5;
        __int64 v6;
        IScene *v7;
        __int64 v8;
        IScene *v9;
        __int64 v10;
        IScene *v11;
        __int64 v12;
        void (__fastcall *v13)(__int64, IUniformSampler *const, ITexture *);
        ITexture *second;
        std::_Rb_tree_iterator<std::pair<IUniformSampler *const, ITexture *> >::pointer v15;
        IScene *v16;
        __int64 v17;
        IScene *v18;
        __int64 v19;
        std::map<IUniformSampler *, ITexture *>::iterator i;
        std::_Rb_tree_iterator<std::pair<IUniformSampler *const, ITexture *> >::_Self __x;

        if (this->data->shader && this->data->quad && this->data->shader) {
            v5 = AbstractPass::scene(this);
            v6 = v5->render();
            (*(void (__fastcall **)(__int64, Filter::Data *)) (*(_QWORD *) v6 + 272LL))(v6, this->data);
            v7 = AbstractPass::scene(this);
            v8 = v7->render();
            (*(void (__fastcall **)(__int64)) (*(_QWORD *) v8 + 296LL))(v8);
            v9 = AbstractPass::scene(this);
            v10 = v9->render();
            (*(void (__fastcall **)(__int64, IShader *)) (*(_QWORD *) v10 + 104LL))(v10, this->data->shader);
            for (i._M_node = std::map<IUniformSampler *, ITexture *>::begin(&this->data->args)._M_node;;
                 std::_Rb_tree_iterator<std::pair<IUniformSampler *const, ITexture *>>::operator++(
                         &i)) {
                __x._M_node = std::map<IUniformSampler *, ITexture *>::end(&this->data->args)._M_node;
                if (!std::_Rb_tree_iterator<std::pair<IUniformSampler *const, ITexture *>>::operator!=(
                        &i, &__x))
                    break;
                v11 = AbstractPass::scene(this);
                v12 = v11->render();
                v13 = *(void (__fastcall **)(__int64, IUniformSampler *const, ITexture *)) (
                        *(_QWORD *) v12 + 128LL);
                second = std::_Rb_tree_iterator<std::pair<IUniformSampler *const, ITexture *>>::operator->(
                        &i)->second;
                v15 = std::_Rb_tree_iterator<std::pair<IUniformSampler *const, ITexture *>>::operator->(
                        &i);
                v13(v12, v15->first, second);
            }
            v16 = AbstractPass::scene(this);
            v17 = v16->render();
            (*(void (__fastcall **)(__int64, IModel *)) (*(_QWORD *) v17 + 192LL))(v17, this->data->quad);
            v18 = AbstractPass::scene(this);
            v19 = v18->render();
            (*(void (__fastcall **)(__int64)) (*(_QWORD *) v19 + 312LL))(v19);
        } else {
            v1 = AbstractPass::scene(this);
            v2 = v1->render();
            v3 = (CGL *) (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v2 + 72LL))(v2);
            v4 = v3->errorCtrl();
            v4->warning(
                    0LL,
                    "Filter is incomplete");
        }
    }

    IModel *Filter::quadModel() {
        return this->data->quad;
    }

    IRenderState *Filter::renderState() {
        return this->data->renderState;
    }

    IUniformSampler *Filter::setInput(IUniformSampler *name, ITexture *arg) {
        return this->addArgs(name, arg);
    }

    IUniformSampler *Filter::setInput(const std::string &name, ITexture *arg) {
        return this->addArgs(name, arg);
    }

    void Filter::setQuadModel(IModel *m) {
        this->data->quad = m;
    }

    void Filter::setShader(IShader *s) {
        this->data->shader = s;
        this->data->args.clear();
    }

    IShader *Filter::shader() {
        return this->data->shader;
    }

    IRenderPass::Pass::Type Filter::type() {
        return 0;
    }
}