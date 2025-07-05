#include "Light.h"
#include "RenderState.h"

namespace MyGL {
    Light::Data::Data(IScene &s) : object(s) {
        this->object.setMaterial(new Material(new Technicue(s)));
    }

    Light::Data::~Data() {
        if (this->object.material())
            delete this->object.material();
        // delete this->object;
    }

    Light::Material::Material(Light::Material *const m, IScene &s, ITechnique *t) : AbstractMaterial(s) {
        m->tech = t;
    }

    Light::Material::~Material() {
        if (this->tech)
            delete this->tech;
    }

    void Light::Material::bind() {
        v1 = this->technique();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v1 + 16LL))(v1);
        v2 = this->technique();
        (*(void (__fastcall **)(__int64)) (*(_QWORD *) v2 + 24LL))(v2);
        this->render()->setRenderState(this->renderState());
    }

    IRenderState *Light::Material::renderState() {
        static RenderState rs;
        return &rs;
    }

    void Light::Material::setUniforms() {
        this->bind();
    }

    ITechnique *Light::Material::technique() {
        return this->tech;
    }

    void Light::Material::uBind() {
        ;
    }


    Light::Technicue::Technicue(IScene &s) : AbstractTechnique(s) {
    }

    Light::Technicue::~Technicue() {


    }

    void Light::Technicue::bind() {
        ;
    }

    const IShader *Light::Technicue::cmpShader(const) {
        return 0LL;
    }

    void Light::Technicue::completeDraw(const IRenderPass *a2) {
        ;
    }

    const IShader *Light::Technicue::currentShader(const) {
        return 0LL;
    }

    bool Light::Technicue::lPass(const SmallLightsPass *a2) {
        return 0;
    }

    bool Light::Technicue::passEvent(const IRenderPass *pass) {
        return pass->type() == 10
               && this->lPass((const SmallLightsPass *) pass);
    }

    IRenderState *Light::Technicue::renderState() {
        return &Light::Technicue::rs;
    }

    void Light::Technicue::setUniforms() {
        ;
    }

    void Light::Technicue::uBind() {
        ;
    }

    Light::Light(ILightsCollection &c) {
        this->collect = c;
        this->collect->add(this);
        Light::setPosition(this, 0.0, 0.0, 0.0);
        this->sh = 0;
        this->data = 0LL;
        Light::setDirection(this, 1.0, 1.0, 1.0);
        Light::setDeferred(this, 0);
    }

    Light::~Light() {
        this->collect->remove(this);
        if (this->data) {
            delete this->data;
        }
    }

    Float *Light::dirTransform() {
        return this->tDir;
    }

    Float Light::dirX() {
        return this->dir[0];
    }

    Float Light::dirY() {
        return this->dir[1];
    }

    Float Light::dirZ() {
        return this->dir[2];
    }

    bool Light::hasOccluder() {
        return 0;
    }

    bool Light::isDeferred() {
        return this->ds;
    }

    bool Light::isShadowCaster() {
        return this->sh;
    }

    IModel *Light::occluder() {
        return 0LL;
    }

    void Light::setDeferred(bool d) {
        this->ds = d;
        if (this->data) {
            delete this->data;
        }
        if (this->ds) {
            this->data = new Data(this->collect->scene());
        }
    }

    void Light::setDirection(Float x, Float y, Float z) {
        double l;
        int i;

        this->dir[0] = x;
        this->dir[1] = y;
        this->dir[2] = z;
        l = sqrt(z * z + x * x + y * y);
        for (i = 0; i <= 2; ++i)
            this->dir[i] = this->dir[i] / l;
    }

    void Light::setPosition(Float x, Float y, Float z) {
        this->pos[0] = x;
        this->pos[1] = y;
        this->pos[2] = z;
    }

    void Light::setShadowCast(bool doIt) {
        this->sh = doIt;
    }

    void Light::upset() {
        v1 = this->collect.scene();
        v2 = (*(__int64 (__fastcall **)(__int64)) (*(_QWORD *) v1 + 24LL))(v1);
        (*(void (__fastcall **)(__int64, ObjectMatrix *)) (*(_QWORD *) v2 + 320LL))(v2, &m);
        for (int i_0 = 0; i_0 <= 2; ++i_0) {
            v3 = m.data();
            this->tDir[i_0] = v3[4 * i_0 + 3];
            for (r = 0; r <= 2; ++r) {
                v5 = this->tDir[i_0];
                v4 = m.data();
                this->tDir[i_0] = this->dir[r] * v4[4 * r + i_0] + v5;
            }
        }
        l = sqrt(this->tDir[2] * this->tDir[2] + this->tDir[0] * this->tDir[0] + this->tDir[1] * this->tDir[1]);
        for (int i = 0; i <= 2; ++i)
            this->tDir[i] = this->tDir[i] / -l;
    }

    Float Light::x() {
        return this->pos[0];
    }

    Float Light::y() {
        return this->pos[1];
    }

    Float Light::z() {
        return this->pos[2];
    }
}