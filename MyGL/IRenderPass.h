#pragma once

namespace MyGL {
    class IScene;

    class IRenderPass {
    public:
        class Pass {
        public:
            enum Type {
                None = 0x0,
                AddBlend = 0x1,
                Bloom = 0x2,
                Color = 0x3,
                Depth = 0x4,
                Glow = 0x5,
                Linc = 0x6,
                Shadow = 0x7,
                Transparent = 0x8,
                SSAO = 0x9,
                SmallLights = 0xA,
                User = 0x400,
                MaxUser = 0x8000,
            };
        };

    public:
        IRenderPass() = default;


        virtual ~IRenderPass() = default;//0
        //1
        virtual void exec() = 0;//2

        virtual Pass::Type type() = 0;//3
    };
}