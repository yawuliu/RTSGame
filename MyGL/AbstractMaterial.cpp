
#include "AbstractMaterial.h"

inline MyGL::AbstractMaterial::AbstractMaterial(MyGL::IScene& r) : mscene(r) {

}

inline MyGL::AbstractMaterial::~AbstractMaterial() {

}

inline const MyGL::ITexture* MyGL::AbstractMaterial::getTexture(unsigned int a2) {
	return 0LL;
}

inline MyGL::IScene& MyGL::AbstractMaterial::scene() {
	return this->mscene;
}
