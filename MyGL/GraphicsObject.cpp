#include "GraphicsObject.h"
#include "ModelInfo.h"


namespace MyGL {
    GraphicsObject::GraphicsObject(IScene &s) {
        this->init(&s);
    }

    GraphicsObject::GraphicsObject(IScene *s) {
        this->init(s);
    }

    GraphicsObject::~GraphicsObject() {
        if (this->scene)
            this->scene->removeObject(*this);
        if (this->actualInfo)
            delete this->actualInfo;
    }

    void GraphicsObject::init(IScene *s) {
        this->scene = s;
        this->gmodel = nullptr;
        this->gmaterial = nullptr;
        this->isVisible = true;
        this->setAlvaysVisible(false);
        for (int i = 0; i <= 2; ++i) {
            this->pos[i] = 0.0;
            this->angles[i] = 0.0;
            this->size[i] = 1.0;
        }
        this->upsetMatrix();
        if (this->scene)
            this->scene->insertObject(*this);
        this->actualInfo = new ModelInfo();
    }

    bool GraphicsObject::isAlvaysVisible() {
        return this->isAVisible;
    }

    IMaterial *GraphicsObject::material() {
        return this->gmaterial;
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

        old = this->gmaterial;
        this->gmaterial = m;
        if (this->scene) {
            if (old)
                this->scene->changeObject(*this, *old);
            else
                this->scene->insertObject(*this);
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
        if (this->gmodel) {
            IModelInfo *m = this->gmodel->cullInfo();
            // 计算缩放后的包围盒值（使用标准浮点运算）
            float minX = this->size[0] * m->minX();
            float minY = this->size[1] * m->minY();
            float minZ = this->size[2] * m->minZ();
            float maxX = this->size[0] * m->maxX();
            float maxY = this->size[1] * m->maxY();
            float maxZ = this->size[2] * m->maxZ();

            // 设置实际包围盒信息
            this->actualInfo->setBox(minX, minY, minZ, maxX, maxY, maxZ);
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