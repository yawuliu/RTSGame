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
	// 这里应有实际的OpenGL/渲染API调用设置过滤方式
}

void TextureRectangle::load(unsigned char* data, MyGL::ITexture::InputFormat inputFormat, int width, int height, MyGL::ITexture::Format format) {
	m_width = width;
	m_height = height;
	// 这里应有实际的OpenGL/渲染API调用上传纹理数据
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
	// 这里应有实际的OpenGL/渲染API调用上传mipmap数据
}

void TextureRectangle::bind(unsigned int unit) {
	// 这里应有实际的OpenGL/渲染API调用绑定纹理到指定单元
}

void TextureRectangle::unbind() {
	// 这里应有实际的OpenGL/渲染API调用解绑纹理
}

int TextureRectangle::getWidth() const {
	return m_width;
}

int TextureRectangle::getHeight() const {
	return m_height;
}


