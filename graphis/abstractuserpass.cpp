#include "abstractuserpass.h"

using namespace MyGL;

AbstractUserPass::AbstractUserPass(IScene* s) : AbstractPass(s) {}

const MyGL::IRenderPass::Pass::Type& AbstractUserPass::type() const
{
	return MyGL::IRenderPass::Pass::User;
}

MyGL::IScene* AbstractUserPass::scene() {
	return nullptr;
}
