#pragma once

#include "IRenderPass.h"

namespace MyGL {
	class IRenderAlgo : public IRenderPass {
	public:
		IRenderAlgo() = default;

		virtual ~IRenderAlgo() = default;
	};
}