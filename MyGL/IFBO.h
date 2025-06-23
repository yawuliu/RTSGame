#pragma once

#include "DisableCopy.h"

namespace MyGL {

	class IFBO : public DisableCopy {
	public:
		IFBO() = default;

		virtual ~IFBO() = default;
	};

}
