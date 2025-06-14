#include "Texture2d.h"
#include <stdexcept>

using namespace MyGL;

Texture2d::Texture2d(IRender* render)
	: mRender(render), mWidth(0), mHeight(0), mTextureId(0), mHasMipMaps(false) {
}

void Texture2d::loadMipMaps(unsigned char* data, MyGL::ITexture::InputFormat inputFormat, int width, int height, MyGL::ITexture::Format format) {
	// ������OpenGL����ʵ�֣�ʵ��Ӧ��IRenderʵ��
	mWidth = width;
	mHeight = height;
	mHasMipMaps = true;
	// ����ֻ��ʾ����ʵ��Ӧ����mRender��ؽӿ�
	// ��������ID
	static unsigned int nextId = 1;
	mTextureId = nextId++;
	// ʡ��ʵ�ʵ������ϴ���mipmap����
}

void Texture2d::bind(unsigned int unit) {
	// ����ֻ��ʾ����ʵ��Ӧ����mRender��ؽӿ�
	// ������ָ����Ԫ
	// ʡ��ʵ�ʰ󶨴���
}

void Texture2d::unbind() {
	// ����ֻ��ʾ����ʵ��Ӧ����mRender��ؽӿ�
	// �������
	// ʡ��ʵ�ʽ�����
}

int Texture2d::getWidth() const {
	return mWidth;
}

int Texture2d::getHeight() const {
	return mHeight;
}


