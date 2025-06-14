#pragma once

namespace MyGL {
	class Color {
	public:
		Color(float x, float y, float z, float w);

	protected:
		float r, g, b, a;
	};
}