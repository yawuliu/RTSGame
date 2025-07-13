#pragma once
namespace MyGL {
    class IRenderAlgoSettings {
    public:
        IRenderAlgoSettings() = default;

        virtual  ~IRenderAlgoSettings() = default; // 0

        // virtual ~RenderAlgoSettings() override; // 1
        virtual bool isBloom() = 0; // 2

        virtual void setBloom(bool) = 0; // 3

        virtual bool isShadowPass() = 0; // 4

        virtual void setShadowPass(bool) = 0; // 5
    };
}


