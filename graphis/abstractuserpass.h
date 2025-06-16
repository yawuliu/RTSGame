#ifndef ABSTRACTUSERPASS_H
#define ABSTRACTUSERPASS_H

#include <MyGL/AbstractPass.h>
#include <MyGL/IScene.h>

class AbstractUserPass : public MyGL::AbstractPass {
public:
	AbstractUserPass(MyGL::IScene* s);

	const MyGL::IRenderPass::Pass::Type& type() const override;

	MyGL::IScene* scene();

	class UPass {
	public:
		enum Type {
			VirtualTexturigPass = MyGL::Pass::User + 1,
			Count
		};
	};
};

#endif // ABSTRACTUSERPASS_H
