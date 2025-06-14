#include "Adapter.h"

MyGL::Adapter::Adapter(MyGL::IScene* s) : mScene(s) {

}

MyGL::IScene* MyGL::Adapter::scene() const {
	return mScene;
}
