#pragma once

#include "MyGL/IAdapter.h"


namespace MyGL {
	class IScene;

	class Adapter : public IAdapter {
	public:
		Adapter(IScene* s);

		IScene* scene() const override;
	protected:
		IScene* mScene;
	};
}
