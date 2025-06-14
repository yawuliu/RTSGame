#include "abstractuserpass.h"

using namespace MyGL;

AbstractUserPass::AbstractUserPass(IScene* s) : AbstractPass(s) {}

MyGL::IScene* AbstractUserPass::scene() {
	return nullptr;
}
