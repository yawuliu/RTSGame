#include "RenderState.h"

namespace MyGL {
    RenderState::RenderState() {
        this->atest = 0.0;
        this->atestType = AlphaTestMode::Type::Always;
        this->zWriting = 1;
        this->zTest = 1;
        this->blend = 0;
        this->sfactor = AlphaBlendMode::Type::one;
        this->dfactor = AlphaBlendMode::Type::zero;
        this->alphaCoverage = 0;
        this->setColorMask(1, 1, 1, 1);
        this->zTestType = ZTestMode::Type::Less;
        this->setCullFaceMode(CullMode::Type::noCull);
    }

    RenderState::AlphaTestMode::Type RenderState::alphaTestMode() {
        return this->atestType;
    }

    Float RenderState::alphaTestRef() {
        return this->atest;
    }

    IRenderState *RenderState::copy(IRenderState &r) {
        this->atest = r.alphaTestRef();
        this->atestType = r.alphaTestMode();
        this->zWriting = r.isZWriting();
        this->zTest = r.isZTest();
        this->blend = r.isBlend();
        this->sfactor = r.getBlendSFactor();
        this->dfactor = r.getBlendDFactor();
        this->alphaCoverage = r.isAlphaCoverage();
        r.getColorMask(&this->clMask[0], &this->clMask[1], &this->clMask[2], &this->clMask[3]);
        this->zTestType = r.getZTestMode();
        this->cullMode = r.cullFaceMode();
        return this;
    }

    RenderState::CullMode::Type RenderState::cullFaceMode() {
        return this->cullMode;
    }

    RenderState::AlphaBlendMode::Type RenderState::getBlendDFactor() {
        return this->dfactor;
    }

    void RenderState::getBlendMode(AlphaBlendMode::Type &out_sfactor, AlphaBlendMode::Type &out_dfactor) {
        out_sfactor = this->sfactor;
        out_dfactor = this->dfactor;
    }

    RenderState::AlphaBlendMode::Type RenderState::getBlendSFactor() {
        return this->sfactor;
    }

    void RenderState::getColorMask(bool &r, bool &g, bool &b, bool &a) {
        r = this->clMask[0];
        g = this->clMask[1];
        b = this->clMask[2];
        a = this->clMask[3];
    }

    RenderState::ZTestMode::Type RenderState::getZTestMode() {
        return this->zTestType;
    }

    bool RenderState::isAlphaCoverage() {
        return this->alphaCoverage;
    }

    bool RenderState::isBlend() {
        return this->blend;
    }

    bool RenderState::isZTest() {
        return this->zTest;
    }

    bool RenderState::isZWriting() {
        return this->zWriting;
    }

    void RenderState::setAlphaCoverage(bool use) {
        this->alphaCoverage = use;
    }

    void RenderState::setAlphaTestMode(AlphaTestMode::Type mode) {
        this->atestType = mode;
    }

    void RenderState::setAlphaTestRef(Float atest) {
        this->atest = atest;
    }

    void RenderState::setBlend(bool use) {
        this->blend = use;
    }

    void RenderState::setBlendMode(AlphaBlendMode::Type s, AlphaBlendMode::Type d) {
        this->sfactor = s;
        this->dfactor = d;
    }

    void RenderState::setColorMask(bool r, bool g, bool b, bool a) {
        this->clMask[0] = r;
        this->clMask[1] = g;
        this->clMask[2] = b;
        this->clMask[3] = a;
    }

    void RenderState::setCullFaceMode(CullMode::Type use) {
        this->cullMode = use;
    }

    void RenderState::setZTest(bool use) {
        this->zTest = use;
    }

    void RenderState::setZTestMode(ZTestMode::Type use) {
        this->zTestType = use;
    }

    void RenderState::setZWriting(bool w) {
        this->zWriting = w;
    }
}