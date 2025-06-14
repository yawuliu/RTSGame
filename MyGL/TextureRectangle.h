#pragma once

#include "MyGL/ITextureRectangle.h"
#include "MyGL/ITexture2d.h"


namespace MyGL {
	class IRender;

	class TextureRectangle : public ITextureRectangle {
	public:
		TextureRectangle(MyGL::IRender*);

		void setFiltration(MyGL::ITexture::FilterType, MyGL::ITexture::FilterType);

		void load(unsigned char*, MyGL::ITexture::InputFormat, int, int, MyGL::ITexture::Format) override;

		float width() const override;

		float height() const override;


		// Í¨¹ý ITextureRectangle ¼Ì³Ð
		void loadMipMaps(unsigned char*, MyGL::ITexture::InputFormat, int, int, MyGL::ITexture::Format) override;

		void bind(unsigned int unit) override;

		void unbind() override;

		int getWidth() const override;

		int getHeight() const override;
	private:
		MyGL::IRender* m_render;
		int m_width;
		int m_height;
		MyGL::ITexture::FilterType m_minFilter;
		MyGL::ITexture::FilterType m_magFilter;
	};
}

