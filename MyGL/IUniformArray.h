#pragma once

#include "IUniform.h"

namespace MyGL {
	template<typename T>
	class IUniformArray : public IUniform {
	public:
		IUniformArray() = default;

		virtual ~IUniformArray() = default;
	};

}
