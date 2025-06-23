#pragma once

#include "IUniform.h"

namespace MyGL {
	class IUniform4f : public IUniform {
	public:
		IUniform4f() = default;

		virtual ~IUniform4f() = default;

		virtual void set(int) = 0;

		virtual void set(float x, float y, float w, float h) = 0;
	};
}

