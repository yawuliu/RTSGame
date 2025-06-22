#pragma once

#include "ModelInfo.h"
#include "IModel.h"
#include "VBO.h"


namespace MyGL {
    class IRender;

    class Model : public IModel {
    public:
        class DataContent {
        public:
            enum flags {
                vertex = 0x1,
                texture = 0x2,
                normal = 0x4,
                extraData = 0x8,
            };
        };

    public:
        Model(IRender &r);

        virtual ~Model();

        void allocate(size_t s);

        void bind();

        Model::DataContent::flags content();

        const IModelInfo *cullInfo();

        void draw(bool binded);

        void drawInstance(int Isize, CGL::GLint *fist, CGL::GLsizei *count, bool binded);

        IVBO *extraBuffer();

        void free();

        void load(IIOModel &m);

        IVBO *normalBuffer();

        IVBO::PrimitiveType::Type primitiveType();

        void setPrimitivesType(IVBO::PrimitiveType::Type t);

        IVBO *textureBuffer();

        void uBind();

        void unsetCullInfo();

        IVBO *vertexBuffer();

    protected:
        IRender &render;
        VBO vert;
        VBO tex;
        VBO norm;
        VBO extra;
        IVBO::PrimitiveType::Type type;
        CGL::GLuint size;
        ModelInfo *mCullInform;
    };
}



