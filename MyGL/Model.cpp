#include "MyGL/Model.h"
#include "MyGL/IVBO.h"
#include "IModelInfo.h"

using namespace MyGL;

Model::Model(IRender* render)
	: mRender(render),
	mCullInfo(nullptr),
	mPrimitiveType(IVBO::PrimitiveType::Triangles),
	mVertexBuffer(nullptr),
	mTextureBuffer(nullptr),
	mNormalBuffer(nullptr),
	mExtraBuffer(nullptr) {
}

IVBO::PrimitiveType Model::primitiveType() {
	return mPrimitiveType;
}

IModelInfo* Model::cullInfo() {
	return mCullInfo;
}

void Model::setPrimitivesType(IVBO::PrimitiveType type) {
	mPrimitiveType = type;
}

void Model::allocate(size_t size) {
	// ����IVBO��һ��allocate(size_t)����
	if (mVertexBuffer) mVertexBuffer->allocate(size);
	if (mTextureBuffer) mTextureBuffer->allocate(size);
	if (mNormalBuffer) mNormalBuffer->allocate(size);
	if (mExtraBuffer) mExtraBuffer->allocate(size);
}

void Model::unsetCullInfo() {
	mCullInfo = nullptr;
}

MyGL::IVBO* Model::vertexBuffer() const {
	return mVertexBuffer;
}

MyGL::IVBO* Model::textureBuffer() const {
	return mTextureBuffer;
}

MyGL::IVBO* Model::normalBuffer() const {
	return mNormalBuffer;
}

MyGL::IVBO* Model::extraBuffer() const {
	return mExtraBuffer;
}


