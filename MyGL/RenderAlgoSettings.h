#pragma once

#include "IRenderAlgoSettings.h"
#include "ForwardRenderAlgo.h"

namespace MyGL {

    template<typename T>
    class RenderAlgoSettings : public IRenderAlgoSettings {
    public:
        RenderAlgoSettings() : algo(algo) {

        }

        ~RenderAlgoSettings() override {

        }

        // ~RenderAlgoSettings() override;
        bool isBloom() override {
            return this->algo.isBloom();
        }

        void setBloom(bool use) override {
            this->algo.setBloom(use);
        }

        bool isShadowPass() override {
            return this->algo.isShadowPass();
        }

        void setShadowPass(bool use) override {
            this->algo.setShadowPass(use);
        }

    protected:
        ForwardRenderAlgo &algo;
    };

} // MyGL


