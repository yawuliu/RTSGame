#pragma once

#include "DisableCopy.h"

namespace MyGL {
	class IModelLoader : public DisableCopy {
	public:
		IModelLoader() = default;

		virtual ~IModelLoader() = default;
	};
}
