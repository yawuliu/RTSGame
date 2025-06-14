#pragma once

namespace MyGL {
	class IScene;

	class IAdapter {
	public:
		virtual IScene* scene() const = 0;
	};
}
