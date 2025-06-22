#pragma once

#include <cstdint>
#include <MyGL/DisableCopy.h>

namespace MyGL {
	class IVBO : public DisableCopy {
	public:
		class IPointer {
		public:
			IPointer() = default;

			virtual ~IPointer() = default;
		};

	public:
		IVBO() = default;

		virtual ~IVBO() = default;

	public:
		class PrimitiveType {
		public:
			enum Type {
				Triangles = 0x0,
				TrianglesStrip = 0x1,
				Quads = 0x2,
				QuadsStrip = 0x3,
				Count = 0x4,
			};

		};
		class BindMode {
		public:
			enum Type {
				Vertex = 0x0,
				TexCoord = 0x1,
				Normal = 0x2,
				Color = 0x3,
				Count = 0x4,
			};
		};


		virtual IPointer* pointerToData() = 0;

		virtual void subData(size_t, int, float[]) = 0;

		virtual void allocate(size_t) = 0;
	};
}

