#ifndef ABSTRACTUSERPASS_H
#define ABSTRACTUSERPASS_H

#include <MyGL/AbstractPass.h>
#include <MyGL/IScene.h>

class AbstractUserPass : public MyGL::AbstractPass {
public:
	AbstractUserPass(MyGL::IScene* s);

	virtual MyGL::Pass::Type type() const { return MyGL::Pass::User; }

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
