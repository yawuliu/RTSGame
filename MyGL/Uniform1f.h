#pragma once

#include <MyGL/IUniform1f.h>

namespace MyGL {
	class Uniform1f : public IUniform1f {
	public:
		Uniform1f();
		Uniform1f(int location, float value);
		void setValue(float value) override;
		float getValue() const override;
		int getLocation() const override;

	private:
		int m_location;
		float m_value;
	};
}


