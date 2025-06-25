#include "GraphicsObject.h"

namespace MyGL {
    GraphicsObject::GraphicsObject(IScene &s) {
        this->init(s);
    }

    GraphicsObject::GraphicsObject(IScene *s) {
        this->init(s);
    }

    GraphicsObject::~GraphicsObject() {
        if (this->scene)
            this->scene->removeObject(this);
        if (this->actualInfo)
            (*((void (__fastcall **)(ModelInfo *)) this->actualInfo->_vptr_IModelInfo + 1))(this->actualInfo);
    }

    void GraphicsObject::init(IScene *s) {
        ModelInfo *mCullInform;
        int i;

        this->scene = s;
        this->gmodel = 0LL;
        this->gmaterial = 0LL;
        this->isVisible = 1;
        this->setAlvaysVisible(0LL);
        for (i = 0; i <= 2; ++i) {
            this->pos[i] = 0.0;
            this->angles[i] = 0.0;
            this->size[i] = 1.0;
        }
        this->upsetMatrix();
        if (this->scene)
            this->scene->insertObject(this);
        this->actualInfo = newModelInfo::ModelInfo();
    }

    bool GraphicsObject::isAlvaysVisible(const) {
        return this->isAVisible;
    }

    IMaterial *GraphicsObject::material() {
        return p_object->gmaterial;
    }

    IModel *GraphicsObject::model() {
        return this->gmodel;
    }

    const IModelInfo *GraphicsObject::modelInfo() {
        return this->actualInfo;
    }

    const ObjectMatrix *GraphicsObject::objectMatrix() {
        return &this->matrix;
    }

    void GraphicsObject::setAlvaysVisible(bool isAVisible) {
        this->isAVisible = isAVisible;
    }

    void GraphicsObject::setMaterial(IMaterial *m) {
        IMaterial *old;

        old = p_object->gmaterial;
        p_object->gmaterial = m;
        if (p_object->scene) {
            if (old)
                p_object->scene->changeObject(p_object, old);
            else
                p_object->scene->insertObject(p_object);
        }
    }

    void GraphicsObject::setMatrix(ObjectMatrix &m) {
        const Float *data;

        data = m.data();
        this->matrix.setData(data);
    }

    void GraphicsObject::setModel(IModel *model) {
        this->gmodel = model;
        this->updateModelInfo();
    }

    void GraphicsObject::setPosition(Float x, Float y, Float z) {
        this->pos[0] = x;
        this->pos[1] = y;
        this->pos[2] = z;
        this->upsetMatrix();
    }

    void GraphicsObject::setRotateY(Float angle) {
        this->angles[1] = angle;
    }

    void GraphicsObject::setRotateZ(Float angle) {
        this->angles[0] = angle;
        this->upsetMatrix();
    }

    void GraphicsObject::setSize(Float s) {
        this->setSize(s, s, s);
        this->upsetMatrix();
    }

    void GraphicsObject::setSize(Float x, Float y, Float z) {
        this->size[0] = x;
        this->size[1] = y;
        this->size[2] = z;
        this->upsetMatrix();
    }

    void GraphicsObject::setVisible(bool isVisible) {
        this->isVisible = isVisible;
    }

    void GraphicsObject::updateModelInfo() {
        double v1;
        __m128d v2;
        double v3;
        __m128d v4;
        double v5;
        __m128d v6;
        double v7;
        __m128d v8;
        double v9;
        __m128d v10;
        double v11;
        __m128d v12;
        float y;
        float z;
        float X;
        float Y;
        float Z;
        const IModelInfo *m;

        if (this->gmodel) {
            m = this->gmodel->cullInfo();
            v1 = (*((double (__fastcall **)(const IModelInfo *)) m->_vptr_IModelInfo + 7))(m);
            v2 = (__m128d) *(unsigned __int64 *) &this->size[2];
            v2.m128d_f64[0] = v2.m128d_f64[0] * v1;
            *(float *) v2.m128d_f64 = _mm_unpacklo_pd(v2, v2).m128d_f64[0];
            Z = *(float *) v2.m128d_f64;
            v3 = (*((double (__fastcall **)(const IModelInfo *)) m->_vptr_IModelInfo + 6))(m);
            v4 = (__m128d) *(unsigned __int64 *) &this->size[1];
            v4.m128d_f64[0] = v4.m128d_f64[0] * v3;
            *(float *) v4.m128d_f64 = _mm_unpacklo_pd(v4, v4).m128d_f64[0];
            Y = *(float *) v4.m128d_f64;
            v5 = (*((double (__fastcall **)(const IModelInfo *)) m->_vptr_IModelInfo + 5))(m);
            v6 = (__m128d) *(unsigned __int64 *) &this->size[0];
            v6.m128d_f64[0] = v6.m128d_f64[0] * v5;
            *(float *) v6.m128d_f64 = _mm_unpacklo_pd(v6, v6).m128d_f64[0];
            X = *(float *) v6.m128d_f64;
            v7 = (*((double (__fastcall **)(const IModelInfo *)) m->_vptr_IModelInfo + 4))(m);
            v8 = (__m128d) *(unsigned __int64 *) &this->size[2];
            v8.m128d_f64[0] = v8.m128d_f64[0] * v7;
            *(float *) v8.m128d_f64 = _mm_unpacklo_pd(v8, v8).m128d_f64[0];
            z = *(float *) v8.m128d_f64;
            v9 = (*((double (__fastcall **)(const IModelInfo *)) m->_vptr_IModelInfo + 3))(m);
            v10 = (__m128d) *(unsigned __int64 *) &this->size[1];
            v10.m128d_f64[0] = v10.m128d_f64[0] * v9;
            y = _mm_unpacklo_pd(v10, v10).m128d_f64[0];
            v11 = (*((double (__fastcall **)(const IModelInfo *)) m->_vptr_IModelInfo + 2))(m);
            v12 = (__m128d) *(unsigned __int64 *) &this->size[0];
            v12.m128d_f64[0] = v12.m128d_f64[0] * v11;
            ModelInfo::setBox(this->actualInfo, _mm_unpacklo_pd(v12, v12).m128d_f64[0], y, z, X, Y, Z);
        }
    }

    void GraphicsObject::upsetMatrix() {
        this->matrix.identity();
        this->matrix.translate(this->pos);
        this->matrix.rotateOZ(this->angles[0]);
        this->matrix.rotate(this->angles[1], 0.0, 1.0, 0.0);
        this->matrix.scale(this->size[0], this->size[1], this->size[2]);
        this->updateModelInfo();
    }

    bool GraphicsObject::visible() {
        return this->isVisible || this->isAlvaysVisible();
    }

    Float GraphicsObject::x() {
        return this->pos[0];
    }

    Float GraphicsObject::xSize() {
        return this->size[0];
    }

    Float GraphicsObject::y() {
        return this->pos[1];
    }

    Float GraphicsObject::yRotation() {
        return this->angles[1];
    }

    Float GraphicsObject::ySize() {
        return this->size[1];
    }

    Float GraphicsObject::z() {
        return this->pos[2];
    }

    Float GraphicsObject::zRotation() {
        return this->angles[0];
    }

    Float GraphicsObject::zSize() {
        return this->size[2];
    }
}