#pragma once

#include "MyGL/ITexture2d.h"

namespace MyGL {
	class IRender;

	class Texture2d : public ITexture2d {
	public:
		Texture2d(IRender*);

		// Í¨¹ý ITexture2d ¼Ì³Ð
		void loadMipMaps(unsigned char*, MyGL::ITexture::InputFormat, int, int, MyGL::ITexture::Format) override;
		void bind(unsigned int unit) override;
		void unbind() override;
		int getWidth() const override;
		int getHeight() const override;

	private:
		IRender* mRender;
		int mWidth;
		int mHeight;
		unsigned int mTextureId;
		bool mHasMipMaps;
	};
}