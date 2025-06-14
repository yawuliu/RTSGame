#include "Texture2d.h"
#include <stdexcept>

using namespace MyGL;

Texture2d::Texture2d(IRender* render)
	: mRender(render), mWidth(0), mHeight(0), mTextureId(0), mHasMipMaps(false) {
}

void Texture2d::loadMipMaps(unsigned char* data, MyGL::ITexture::InputFormat inputFormat, int width, int height, MyGL::ITexture::Format format) {
	// 假设有OpenGL风格的实现，实际应由IRender实现
	mWidth = width;
	mHeight = height;
	mHasMipMaps = true;
	// 这里只是示例，实际应调用mRender相关接口
	// 生成纹理ID
	static unsigned int nextId = 1;
	mTextureId = nextId++;
	// 省略实际的纹理上传和mipmap生成
}

void Texture2d::bind(unsigned int unit) {
	// 这里只是示例，实际应调用mRender相关接口
	// 绑定纹理到指定单元
	// 省略实际绑定代码
}

void Texture2d::unbind() {
	// 这里只是示例，实际应调用mRender相关接口
	// 解绑纹理
	// 省略实际解绑代码
}

int Texture2d::getWidth() const {
	return mWidth;
}

int Texture2d::getHeight() const {
	return mHeight;
}


