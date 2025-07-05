#pragma once

#include "DisableCopy.h"

namespace MyGL {
    class IRenderState : public DisableCopy {
    public:
        class AlphaBlendMode {
        public:
            enum Type {
                zero = 0x0,
                one = 0x1,
                src_color = 0x2,
                one_minus_src_color = 0x3,
                src_alpha = 0x4,
                one_minus_src_alpha = 0x5,
                dst_alpha = 0x6,
                one_minus_dst_alpha = 0x7,
                dst_color = 0x8,
                one_minus_dst_color = 0x9,
                src_alpha_saturate = 0xA,
                Count = 0xB,
            };

        };

        class AlphaTestMode {
        public:
            enum Type {
                Never = 0x0,
                Greater = 0x1,
                Less = 0x2,
                LEqual = 0x3,
                GEqual = 0x4,
                NOEqual = 0x5,
                Equal = 0x6,
                Always = 0x7,
                Count = 0x8,
            };
        };

        class CullMode {
        public:
            enum Type {
                noCull = 0x0,
                front = 0x1,
                back = 0x2,
            };
        };

        class ZTestMode {
        public:
            enum Type {
                Never = 0x0,
                Greater = 0x1,
                Less = 0x2,
                LEqual = 0x3,
                GEqual = 0x4,
                NOEqual = 0x5,
                Equal = 0x6,
                Always = 0x7,
                Count = 0x8,
            };
        };

    public:
        IRenderState() = default;

        virtual ~IRenderState() = default; // 0
        // 1
        virtual Float alphaTestRef() = 0;//2
        virtual void setAlphaTestRef(double) = 0;//3
        virtual IRenderState *copy(IRenderState &) = 0;//4
        virtual void setAlphaTestMode(AlphaTestMode::Type) = 0;//5
        virtual AlphaTestMode::Type alphaTestMode() = 0;//6
        virtual void setColorMask(bool, bool, bool, bool) = 0;//7
        virtual void getColorMask(bool &, bool &, bool &, bool &) = 0;//8
        virtual bool isZWriting() = 0;//9
        virtual void setZWriting(bool) = 0;//10
        virtual bool isZTest() = 0;//11
        virtual void setZTest(bool) = 0;//12
        virtual CullMode::Type cullFaceMode() = 0;//13
        virtual void setCullFaceMode(CullMode::Type) = 0;//14
        virtual ZTestMode::Type getZTestMode() = 0;//15
        virtual void setZTestMode(ZTestMode::Type) = 0;//16
        virtual bool isBlend() = 0;//17
        virtual void setBlend(bool) = 0;//18
        virtual bool isAlphaCoverage() = 0;//19
        virtual void setAlphaCoverage(bool) = 0;//20
        virtual AlphaBlendMode::Type getBlendSFactor() = 0;//21
        virtual AlphaBlendMode::Type getBlendDFactor() = 0;//22
        virtual void getBlendMode(AlphaBlendMode::Type &, AlphaBlendMode::Type &) = 0;//23
        virtual void setBlendMode(AlphaBlendMode::Type, AlphaBlendMode::Type) = 0;//24
        //			virtual void setBlendMode() = 0;
        //
        //			virtual void setBlendMode(AlphaBlendMode) = 0;
        //
        //			virtual void setBlendMode(AlphaBlendMode, AlphaBlendMode) = 0;
        //
        //			virtual void setBlend(bool) = 0;
        //
        //			virtual void setAlphaTestMode(AlphaTestMode) = 0;
        //
        //			virtual void setAlphaCoverage(int) = 0;
        //
        //			virtual void setZTest(int) = 0;
        //
        //			virtual void setZTestMode(ZTestMode) = 0;
        //
        //			virtual void setCullFaceMode(CullMode) = 0;
        //
        //			virtual void setAlphaTestRef(float) = 0;
    };
}
