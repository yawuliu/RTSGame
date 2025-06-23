#pragma once

#include <string>
#include "IModelLoader.h"
#include "IRender.h"
#include "IModel.h"
#include "IOModel.h"
#include "IErrorControl.h"

namespace MyGL {
	class ModelLoader : public IModelLoader {
	public:
		ModelLoader(IRender& r);

		virtual ~ModelLoader() = default;

		IModel* load(const char* fileName, bool* ok);

		IModel* loadBin_v0(const char* fileName, bool* ok);

	protected:
		IRender& render;
	};
}