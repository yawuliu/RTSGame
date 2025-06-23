#include "AbstractPass.h"

namespace MyGL {
	AbstractPass::AbstractPass(IScene& s) : mscene(s) {

	}


	IScene& AbstractPass::scene() {
		return this->mscene;
	}
}