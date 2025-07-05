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
        explicit Model(IRender &r);

        ~Model() override;

        void allocate(size_t s);

        void bind() override;

        Model::DataContent::flags content();

        const IModelInfo *cullInfo() override;

        void draw(bool binded) override;

        void drawInstance(int Isize, CGL::GLint *fist, CGL::GLsizei *count, bool binded) override;

        IVBO *extraBuffer();

        void free() override;

        void load(IIOModel &m) override;

        IVBO *normalBuffer();

        IVBO::PrimitiveType::Type primitiveType() override;

        void setPrimitivesType(IVBO::PrimitiveType::Type t) override;

        IVBO *textureBuffer();

        void uBind() override;

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



