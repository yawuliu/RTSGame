#pragma once

#include "IVBO.h"
#include "IModelInfo.h"
#include "IRender.h"

namespace MyGL {
	class IModel {
	public:
		IModel() = default;

		virtual ~IModel() = default;

		virtual IVBO::PrimitiveType primitiveType() = 0;

		virtual IModelInfo* cullInfo() = 0;

		virtual void setPrimitivesType(IVBO::PrimitiveType) = 0;

		virtual void allocate(size_t) = 0;
	};
}


