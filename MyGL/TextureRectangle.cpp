#include "MyGL/TextureRectangle.h"

using namespace MyGL;

TextureRectangle::TextureRectangle(MyGL::IRender* render)
	: m_render(render), m_width(0), m_height(0),
	m_minFilter(MyGL::ITexture::FilterType::Nearest),
	m_magFilter(MyGL::ITexture::FilterType::Nearest) {
}

void TextureRectangle::setFiltration(MyGL::ITexture::FilterType min, MyGL::ITexture::FilterType mag) {
	m_minFilter = min;
	m_magFilter = mag;
	// ����Ӧ��ʵ�ʵ�OpenGL/��ȾAPI�������ù��˷�ʽ
}

void TextureRectangle::load(unsigned char* data, MyGL::ITexture::InputFormat inputFormat, int width, int height, MyGL::ITexture::Format format) {
	m_width = width;
	m_height = height;
	// ����Ӧ��ʵ�ʵ�OpenGL/��ȾAPI�����ϴ���������
}

float TextureRectangle::width() const {
	return static_cast<float>(m_width);
}

float TextureRectangle::height() const {
	return static_cast<float>(m_height);
}

void TextureRectangle::loadMipMaps(unsigned char* data, MyGL::ITexture::InputFormat inputFormat, int width, int height, MyGL::ITexture::Format format) {
	m_width = width;
	m_height = height;
	// ����Ӧ��ʵ�ʵ�OpenGL/��ȾAPI�����ϴ�mipmap����
}

void TextureRectangle::bind(unsigned int unit) {
	// ����Ӧ��ʵ�ʵ�OpenGL/��ȾAPI���ð�����ָ����Ԫ
}

void TextureRectangle::unbind() {
	// ����Ӧ��ʵ�ʵ�OpenGL/��ȾAPI���ý������
}

int TextureRectangle::getWidth() const {
	return m_width;
}

int TextureRectangle::getHeight() const {
	return m_height;
}


