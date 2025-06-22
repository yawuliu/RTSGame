#include "abstractuserpass.h"

AbstractUserPass::AbstractUserPass(MyGL::IScene& s) : MyGL::AbstractPass(s) {}

MyGL::IRenderPass::Pass::Type AbstractUserPass::type()
{
	return MyGL::IRenderPass::Pass::User;
}

