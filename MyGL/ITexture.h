#pragma once

#include <cstdint>
#include "DisableCopy.h"
#include "Color.h"

namespace MyGL {
	class ITexture : public DisableCopy {
	public:
		class InputFormat {
		public:
			enum Type {
				Luminance8 = 0x0,
				RGB8 = 0x1,
				RGBA8 = 0x2,
				Depth = 0x3,
				Count = 0x4,
			};
		};

		class ClampMode {
		public:
			enum Type {
				Clamp = 0x0,
				ClampToBorder = 0x1,
				ClampToEdge = 0x2,
				MirroredRepeat = 0x3,
				Repeat = 0x4,
				Count = 0x5,
			};
		};

		class FilterType {
		public:
			enum Type {
				Nearest = 0x0,
				Linear = 0x1,
				Count = 0x2,
			};
		};

		class Format {
		public:
			enum Type {
				Luminance = 0x0,
				Luminance4 = 0x1,
				Luminance8 = 0x2,
				Luminance16 = 0x3,
				RGB = 0x4,
				RGB4 = 0x5,
				RGB5 = 0x6,
				RGB10 = 0x7,
				RGB12 = 0x8,
				RGB16 = 0x9,
				RGBA = 0xA,
				RGBA8 = 0xB,
				RGB10_A2 = 0xC,
				RGBA12 = 0xD,
				RGBA16 = 0xE,
				RGB_DXT1 = 0xF,
				RGBA_DXT1 = 0x10,
				RGBA_DXT3 = 0x11,
				RGBA_DXT5 = 0x12,
				Depth16 = 0x13,
				Depth24 = 0x14,
				Depth32 = 0x15,
				Count = 0x16,
			};
		};

	public:
		ITexture() = default;

		virtual  ~ITexture() = default;// 0
		//virtual  ~ITexture() = default;// 1
		virtual void create() = 0;// 2
		virtual void bind() = 0;// 3
		virtual void free() = 0;// 4
		virtual void getHandle() = 0;// 5
		virtual void
			setFiltration(ITexture::FilterType::Type, ITexture::FilterType::Type, ITexture::FilterType::Type) = 0;//  6
		virtual void setFiltration(ITexture::FilterType::Type, ITexture::FilterType::Type) = 0;// 7
		virtual void
			setClamping(ITexture::ClampMode::Type, ITexture::ClampMode::Type, ITexture::ClampMode::Type) = 0;// 8
		virtual void setClamping(ITexture::ClampMode::Type) = 0;// 9
		virtual void setBorderColor(Color const&) = 0;// 10
		virtual void
			load(void const*, ITexture::InputFormat::Type, uint32_t, uint32_t, ITexture::Format::Type) = 0;// 11
		virtual void
			loadMipMaps(void const*, ITexture::InputFormat::Type, uint32_t, uint32_t, ITexture::Format::Type) = 0;// 12
		virtual void setAnisotropy(double) = 0;// 13
		virtual void width() = 0;// 14
		virtual void height() = 0;// 15


	};
}