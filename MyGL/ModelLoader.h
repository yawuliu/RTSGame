#pragma once

#include <string>
#include <MyGL/IModelLoader.h>
#include <MyGL/IRender.h>
#include <MyGL/IModel.h>
#include <MyGL/IOModel.h>
#include <MyGL/IErrorControl.h>

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