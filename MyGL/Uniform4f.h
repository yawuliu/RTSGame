#pragma once

#include <MyGL/IUniform4f.h>

namespace MyGL {
	class Uniform4f : public IUniform4f {
	public:
		Uniform4f();

		void set(int) override;

		void set(float x, float y, float w, float h) override;

	private:
		float m_x;
		float m_y;
		float m_w;
		float m_h;
	};
}


