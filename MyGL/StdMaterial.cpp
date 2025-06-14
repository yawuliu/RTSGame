#include "StdMaterial.h"
#include "StdTechnique.h"
#include "IRenderState.h"


using namespace MyGL;

StdMaterial::StdMaterial(IScene* scene)
	: mScene(scene),
	mShader(nullptr),
	mShadowShader(nullptr),
	mDepthShader(nullptr),
	mGlowShader(nullptr),
	mTexture(nullptr),
	mShadowTexture(nullptr),
	mDiffuseTexture(nullptr),
	mSpecularTexture(nullptr),
	mNormalTexture(nullptr),
	mGlowTexture(nullptr),
	mState(nullptr),
	mTechnique(nullptr),
	mUseGlow(false),
	mUseDepthPass(false),
	mUseCullFace(false)
{
}

StdMaterial::StdMaterial(IScene* scene, StdTechnique* technique)
	: mScene(scene),
	mShader(nullptr),
	mShadowShader(nullptr),
	mDepthShader(nullptr),
	mGlowShader(nullptr),
	mTexture(nullptr),
	mShadowTexture(nullptr),
	mDiffuseTexture(nullptr),
	mSpecularTexture(nullptr),
	mNormalTexture(nullptr),
	mGlowTexture(nullptr),
	mState(technique ? technique->m_renderState : nullptr),
	mTechnique(technique),
	mUseGlow(false),
	mUseDepthPass(technique ? technique->useDepthPass() : false),
	mUseCullFace(false)
{
}

void StdMaterial::setShader(IShader* shader) {
	mShader = shader;
	if (mTechnique) {
		mTechnique->setCurrentShader(shader);
	}
}

void StdMaterial::setShadowShader(IShader* shader) {
	mShadowShader = shader;
}

void StdMaterial::setDepthShader(IShader* shader) {
	mDepthShader = shader;
}

void StdMaterial::setGlowShader(IShader* shader) {
	mGlowShader = shader;
}

void StdMaterial::setShadowTexture(ITexture2d* tex) {
	mShadowTexture = tex;
}

void StdMaterial::setDiffuseTexture(ITexture2d* tex) {
	mDiffuseTexture = tex;
}

void StdMaterial::setSpecularTexture(ITexture2d* tex) {
	mSpecularTexture = tex;
}

void StdMaterial::setNormalTexture(ITexture2d* tex) {
	mNormalTexture = tex;
}

void StdMaterial::setGlowTexture(ITexture2d* tex) {
	mGlowTexture = tex;
}

void StdMaterial::useGlow(ITexture2d* tex) {
	mGlowTexture = tex;
	mUseGlow = (tex != nullptr);
}

void StdMaterial::useGlow(int enable) {
	mUseGlow = (enable != 0);
}

void StdMaterial::useDepthPass(bool enable) {
	mUseDepthPass = enable;
	if (mTechnique) {
		mTechnique->m_useDepthPass = enable;
	}
}

void StdMaterial::useCullFace(bool enable) {
	mUseCullFace = enable;
	if (mState) {
		mState->setCullFaceMode(enable ? IRenderState::CullMode::CullMode : IRenderState::CullMode(0));
	}
}

IRenderState* StdMaterial::renderState() const {
	return mState;
}


