#pragma once

#include <MyGL/AbstractPass.h>
#include <MyGL/IScene.h>

class AbstractUserPass : public MyGL::AbstractPass {
public:
	AbstractUserPass(MyGL::IScene& s);

	MyGL::IRenderPass::Pass::Type type();
};


