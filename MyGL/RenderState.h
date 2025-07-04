#pragma once

#include "Data.h"
#include "IRenderState.h"

namespace MyGL {
    class RenderState : public IRenderState {
    public:
        RenderState();

        ~RenderState() override = default;

        AlphaTestMode::Type alphaTestMode() override;

        Float alphaTestRef() override;

        virtual IRenderState *copy(const IRenderState &r) override;

        CullMode::Type cullFaceMode() override;

        AlphaBlendMode::Type getBlendDFactor() override;

        void getBlendMode(AlphaBlendMode::Type &out_sfactor, AlphaBlendMode::Type &out_dfactor) override;

        AlphaBlendMode::Type getBlendSFactor() override;

        void getColorMask(bool &r, bool &g, bool &b, bool &a) override;

        ZTestMode::Type getZTestMode() override;

        bool isAlphaCoverage() override;

        bool isBlend() override;

        bool isZTest() override;

        bool isZWriting() override;

        void setAlphaCoverage(bool use) override;

        void setAlphaTestMode(AlphaTestMode::Type mode) override;

        void setAlphaTestRef(Float atest) override;

        void setBlend(bool use) override;

        void setBlendMode(AlphaBlendMode::Type s, AlphaBlendMode::Type d) override;

        void setColorMask(bool r, bool g, bool b, bool a) override;

        void setCullFaceMode(CullMode::Type use) override;

        void setZTest(bool use) override;

        void setZTestMode(ZTestMode::Type use) override;

        void setZWriting(bool w) override;

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
