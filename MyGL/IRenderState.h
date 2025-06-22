#pragma once

#include <MyGL/DisableCopy.h>

namespace MyGL {
    class IRenderState : public DisableCopy {
    public:
        IRenderState() = default;

        virtual ~IRenderState() = default;
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

        virtual void setBlendMode() = 0;

        virtual void setBlendMode(AlphaBlendMode) = 0;

        virtual void setBlendMode(AlphaBlendMode, AlphaBlendMode) = 0;

        virtual void setBlend(bool) = 0;

        virtual void setAlphaTestMode(AlphaTestMode) = 0;

        virtual void setAlphaCoverage(int) = 0;

        virtual void setZTest(int) = 0;

        virtual void setZTestMode(ZTestMode) = 0;

        virtual void setCullFaceMode(CullMode) = 0;

        virtual void setAlphaTestRef(float) = 0;
    };
}


