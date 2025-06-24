#include "AbstractMaterial.h"
#include "IScene.h"


namespace MyGL {
    AbstractMaterial::AbstractMaterial(IScene &r) : mscene(r) {

    }

    AbstractMaterial::~AbstractMaterial() {

    }

    bool AbstractMaterial::drawEvent(const IGraphicsObject &o) {
        __int64 v2;

        v2 = (*((__int64 (__fastcall **)(AbstractMaterial *const)) this->_vptr_IMaterial + 5))(this);
        return (*(__int64 (__fastcall **)(__int64, const IGraphicsObject *const,
                                          AbstractMaterial *const)) (*(_QWORD *) v2 + 72LL))(
                v2,
                o,
                this);
    }

    ITexture &AbstractMaterial::getTexture(unsigned int a2) {
        return 0LL;
    }

    bool AbstractMaterial::greater(const ITechnique &t, const ITechnique &t2) {
        unsigned __int64 v2;

        v2 = (*((__int64 (__fastcall **)(const ITechnique *const)) t->_vptr_ITechnique + 6))(t);
        return v2 > (*((__int64 (__fastcall **)(const ITechnique *const)) t2->_vptr_ITechnique + 6))(t2);
    }

    bool AbstractMaterial::less(const ITechnique const &t, const ITechnique const &t2) {
        unsigned __int64 v2;

        v2 = (*((__int64 (__fastcall **)(const ITechnique *const)) t->_vptr_ITechnique + 6))(t);
        return v2 < (*((__int64 (__fastcall **)(const ITechnique *const)) t2->_vptr_ITechnique + 6))(t2);
    }

    bool AbstractMaterial::operator>(const IMaterial &other) {
        if (!(*((__int64 (__fastcall **)(const AbstractMaterial *const)) other_1->_vptr_IMaterial + 6))(
                other_1))
            return 0;
        if ((*(__int64 (__fastcall **)(const void *const)) (*(_QWORD *) other + 48LL))(other))
            return other_1 > other;
        return 1;
    }

    IRender *AbstractMaterial::render() {
        return this->mscene->render();
    }

    IScene &AbstractMaterial::scene() {
        return this->mscene;
    }

    bool AbstractMaterial::operator<(const IMaterial &other) {
        const ITechnique *t2_1;
        const ITechnique *t;
        const ITechnique *t2_2;
        const ITechnique *t_1;
        const ITexture *t2;
        const ITexture *t1;
        unsigned int i;

        if (!(*((__int64 (__fastcall **)(const AbstractMaterial *const)) this->_vptr_IMaterial + 6))(this)
            && (*(__int64 (__fastcall **)(const void *const)) (*(_QWORD *) other + 48LL))(other)) {
            return 1;
        }
        if (!(*(__int64 (__fastcall **)(const void *const)) (*(_QWORD *) other + 48LL))(other))
            return 0;
        t2_1 = (const ITechnique *) (*(__int64 (__fastcall **)(const void *const)) (*(_QWORD *) other +
                                                                                    48LL))(other);
        t = (const ITechnique *) (*(
                (__int64 (__fastcall **)(const AbstractMaterial *const)) this->_vptr_IMaterial
                + 6))(this);
        if (AbstractMaterial::less(t, t2_1))
            return 1;
        t2_2 = (const ITechnique *) (*(__int64 (__fastcall **)(const void *const)) (*(_QWORD *) other +
                                                                                    48LL))(other);
        t_1 = (const ITechnique *) (*(
                (__int64 (__fastcall **)(const AbstractMaterial *const)) this->_vptr_IMaterial
                + 6))(this);
        if (AbstractMaterial::greater(t_1, t2_2))
            return 0;
        for (i = 0; i <= 3; ++i) {
            t1 = (const ITexture *) (*(
                    (__int64 (__fastcall **)(const AbstractMaterial *const, _QWORD)) this->_vptr_IMaterial
                    + 9))(
                    this,
                    i);
            t2 = (const ITexture *) (*(__int64 (__fastcall **)(const void *const, _QWORD)) (
                    *(_QWORD *) other + 72LL))(
                    other,
                    i);
            if (t1 < t2)
                return 1;
            if (t1 > t2)
                return 0;
        }
        return 0;
    }
}