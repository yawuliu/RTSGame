#ifndef CYRCLE_H
#define CYRCLE_H

#include <MyGL/GraphicsObject.h>
#include <MyGL/StdMaterial.h>

#include <MyGL/ITexture2d.h>
#include <MyGL/IModel.h>

namespace MyGL {
	class IScene;
};

class Cyrcle {
public:
	Cyrcle(MyGL::IScene*);
	~Cyrcle();

	void setPos(float x, float y, float z);
	void setVisible(bool v);

	void setSize(float s);
private:
	MyGL::IScene* scene;
	MyGL::StdMaterial* material;
	MyGL::GraphicsObject object;
};

#endif // CYRCLE_H
