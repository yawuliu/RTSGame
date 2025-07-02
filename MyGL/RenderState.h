#pragma once

#include "Data.h"
#include "IRenderState.h"

namespace MyGL {
    class RenderState : public IRenderState {
    public:
        RenderState();

        virtual ~RenderState() = default;

        AlphaTestMode::Type alphaTestMode();

        Float alphaTestRef();

        virtual IRenderState *copy(const IRenderState &r) override;

        CullMode::Type cullFaceMode();

        AlphaBlendMode::Type getBlendDFactor();

        void getBlendMode(AlphaBlendMode::Type &out_sfactor, AlphaBlendMode::Type &out_dfactor);

        AlphaBlendMode::Type getBlendSFactor();

        void getColorMask(bool &r, bool &g, bool &b, bool &a);

        ZTestMode::Type getZTestMode();

        bool isAlphaCoverage();

        bool isBlend();

        bool isZTest();

        bool isZWriting();

        void setAlphaCoverage(bool use);

        void setAlphaTestMode(AlphaTestMode::Type mode);

        void setAlphaTestRef(Float atest);

        void setBlend(bool use);

        void setBlendMode(AlphaBlendMode::Type s, AlphaBlendMode::Type d);

        void setColorMask(bool r, bool g, bool b, bool a);

        void setCullFaceMode(CullMode::Type use);

        void setZTest(bool use);

        void setZTestMode(ZTestMode::Type use);

        void setZWriting(bool w);

    protected:
        Float atest;
        AlphaTestMode::Type atestType;
        ZTestMode::Type zTestType;
        CullMode::Type cullMode;
        bool zWriting;
        bool zTest;
        bool blend;
        bool alphaCoverage;
        AlphaBlendMode::Type sfactor;
        AlphaBlendMode::Type dfactor;
        bool clMask[4];
        //        0000002C     // padding byte
        //        0000002D     // padding byte
        //        0000002E     // padding byte
        //        0000002F     // padding byte
    };

}
