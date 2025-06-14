#pragma once

#include "MyGL/IModel.h"

namespace MyGL {
    class IRender;

    class Model : public IModel {
    public:
        Model(IRender *);

        IVBO::PrimitiveType primitiveType() override;

        IModelInfo *cullInfo() override;

        void setPrimitivesType(IVBO::PrimitiveType) override;

        void allocate(size_t) override;

        void unsetCullInfo();

        MyGL::IVBO *vertexBuffer() const;

        MyGL::IVBO *textureBuffer() const;

        MyGL::IVBO *normalBuffer() const;

        MyGL::IVBO *extraBuffer() const;

    protected:
        IRender *mRender;
        IModelInfo *mCullInfo;
        IVBO::PrimitiveType mPrimitiveType;
        MyGL::IVBO *mVertexBuffer;
        MyGL::IVBO *mTextureBuffer;
        MyGL::IVBO *mNormalBuffer;
        MyGL::IVBO *mExtraBuffer;

    };
}



