#ifndef VIRTUALTEXTURINGPASS_H
#define VIRTUALTEXTURINGPASS_H

#include "graphis/abstractuserpass.h"

namespace MyGL {
	class ITextureRectangle;

	class MainPass;
}

class VirtualTexturingPass : public AbstractUserPass {
public:
	template<class T>
	T drawObject(MyGL::ISceneGraph) {
		return T();
	}

	VirtualTexturingPass();
	VirtualTexturingPass(MyGL::IScene* s,
		MyGL::MainPass* mp,
		MyGL::ITextureRectangle* mpb);

	~VirtualTexturingPass();

	void exec();

	const MyGL::IRenderPass::Pass::Type& type() const;

	static void setMapSize(int x, int y, int tw, int th);

private:
	MyGL::ITextureRectangle* screen, * preScreen, * mpassBuf;
	MyGL::MainPass* mpass;

	void resizeFrame();

	class Data;

	Data* data;

	void paintLand();

	static VirtualTexturingPass* inst;
};

#endif // VIRTUALTEXTURINGPASS_H
