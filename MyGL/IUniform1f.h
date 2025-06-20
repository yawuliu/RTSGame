#pragma once

namespace MyGL {
	class IUniform1f {
	public:
		virtual void setValue(float value) = 0;
		virtual float getValue() const = 0;
		virtual int getLocation() const = 0;
	};
}