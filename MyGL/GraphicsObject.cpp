#include "GraphicsObject.h"

using namespace MyGL;

MyGL::GraphicsObject::GraphicsObject(MyGL::IScene* scene) {

}

MyGL::GraphicsObject::GraphicsObject(MyGL::IScene* scene, const std::string& src) {

}

MyGL::GraphicsObject::~GraphicsObject() {

}

MyGL::StdMaterial* MyGL::GraphicsObject::material() {
	return nullptr;
}

void MyGL::GraphicsObject::setModel(MyGL::IModel*) {

}

void MyGL::GraphicsObject::setMaterial(MyGL::StdMaterial*) {

}

void MyGL::GraphicsObject::setPosition(float x, float y, float z) {

}

void MyGL::GraphicsObject::setRotateZ(float r) {

}

void MyGL::GraphicsObject::setVisible(bool v) {

}

void MyGL::GraphicsObject::setSize(float x, float y, float z) {

}

void MyGL::GraphicsObject::setAlvaysVisible(bool) {

}

MyGL::IModel* MyGL::GraphicsObject::model() {
	return nullptr;
}

MyGL::GameObjectClass::View* MyGL::GraphicsObject::getObject() {
	return nullptr;
}

void MyGL::GraphicsObject::setPositionF(float x, float y, float z) {

}

void MyGL::GraphicsObject::setSize(float x, float y, float z, const double* base) {

}

void MyGL::GraphicsObject::setRotate(float r) {

}

void MyGL::GraphicsObject::setRotateXY(float r) {

}

float MyGL::GraphicsObject::rotateAngle() const {
	return 0;
}

float MyGL::GraphicsObject::x() const {
	return 0;
}

float MyGL::GraphicsObject::y() const {
	return 0;
}

float MyGL::GraphicsObject::z() const {
	return 0;
}

MyGL::IShader* MyGL::GraphicsObject::extractTextures(MyGL::GameObject* obj) {
	return nullptr;
}

MyGL::IShader* MyGL::GraphicsObject::extractTextures(const MyGL::GameObjectClass::View&, MyGL::GameObject* obj,
	MyGL::StdMaterial* material, MyGL::IModel* model) {
	return nullptr;
}

MyGL::ITexture2d*
MyGL::GraphicsObject::textureFromData(const std::string& view, const char* postFix, bool mode, MyGL::GameObject* obj) {
	return nullptr;
}

void MyGL::GraphicsObject::initFromSrc(MyGL::GraphicsObject&, const MyGL::GameObjectClass::View&,
	MyGL::GameObject* gameObj) {

}

void MyGL::GraphicsObject::initFromSrc(MyGL::GameObject* obj) {

}

void MyGL::GraphicsObject::setModelEvent(MyGL::GameObject* obj) {

}

MyGL::IShader* MyGL::GraphicsObject::getShadowShader(MyGL::GraphicsObject& obj, const MyGL::GameObjectClass::View&) {
	return nullptr;
}

bool MyGL::GraphicsObject::isAlvaysVisible() const
{
	return false;
}

IModelInfo* MyGL::GraphicsObject::modelInfo() const
{
	return nullptr;
}

void MyGL::GraphicsObject::delObjectEvent(IGraphicsObject*)
{
}

void MyGL::GraphicsObject::addObjectEvent(IGraphicsObject*)
{
}


float MyGL::GraphicsObject::xSize() const
{
	return 0.0f;
}

float MyGL::GraphicsObject::ySize() const
{
	return 0.0f;
}

float MyGL::GraphicsObject::zSize() const
{
	return 0.0f;
}

void MyGL::GraphicsObject::setRotateX(float)
{
}

void MyGL::GraphicsObject::setRotateY(float)
{
}

float MyGL::GraphicsObject::xRotation()
{
	return 0.0f;
}

float MyGL::GraphicsObject::yRotation()
{
	return 0.0f;
}

float MyGL::GraphicsObject::zRotation()
{
	return 0.0f;
}
