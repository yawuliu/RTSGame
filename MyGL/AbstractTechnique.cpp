

#include "AbstractTechnique.h"

inline MyGL::AbstractTechnique::AbstractTechnique(IScene& s) : mscene(s) {
}

inline MyGL::AbstractTechnique::~AbstractTechnique() {

}

inline void MyGL::AbstractTechnique::completeDraw(const AddBlendPass* a2) {
    ;
}

inline void MyGL::AbstractTechnique::completeDraw(const ColorPass* a2) {
    ;
}

inline void MyGL::AbstractTechnique::completeDraw(const DepthPass* a2) {
    ;
}

inline void MyGL::AbstractTechnique::completeDraw(const GlowPass* a2) {
    ;
}

inline void MyGL::AbstractTechnique::completeDraw(const IRenderPass* a2) {
    ;
}

inline void MyGL::AbstractTechnique::completeDraw(const ShadowPass* a2) {
    ;
}

inline void MyGL::AbstractTechnique::completeDraw(const TransparentPass* a2) {
    ;
}

inline bool MyGL::AbstractTechnique::drawEvent(const IGraphicsObject* const a2, const IMaterial* const a3) {
    return 1;
}

inline bool MyGL::AbstractTechnique::passEvent(const AddBlendPass* a2) {
    return 0;
}

inline bool MyGL::AbstractTechnique::passEvent(const ColorPass* a2) {
    return 0;
}

inline bool MyGL::AbstractTechnique::passEvent(const DepthPass* a2) {
    return 0;
}

inline bool MyGL::AbstractTechnique::passEvent(const GlowPass* a2) {
    return 0;
}

inline bool MyGL::AbstractTechnique::passEvent(const IRenderPass* a2) {
    return 0;
}

inline bool MyGL::AbstractTechnique::passEvent(const ShadowPass* a2) {
    return 0;
}

inline bool MyGL::AbstractTechnique::passEvent(const TransparentPass* a2) {
    return 0;
}

inline IRender* MyGL::AbstractTechnique::render() {
    return (IRender*)(*((__int64(__fastcall**)(IScene* const)) this->mscene->_vptr_IScene + 3))(
        this->mscene);
}

inline IScene* MyGL::AbstractTechnique::scene() {
    return this->mscene;
}
