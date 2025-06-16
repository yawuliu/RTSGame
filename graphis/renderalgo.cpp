#include "renderalgo.h"

#include <MyGL/MainPass.h>
#include "graphis/rendermainpass.h"

#include "adapter.h"

using namespace MyGL;

RenderAlgo::RenderAlgo(IScene* s, const ::Adapter* a) :
	MyGL::ForwardRenderAlgo(s, a, 0) {
	makeAlgo(a);

	setBloom(a->isBloom());
	setShadowPass(a->isShadowMapping());
}

MainPass* RenderAlgo::allockMainPass(const MyGL::Adapter* adapter) {
	RenderMainPass* r = new RenderMainPass(scene(), quad, adapter);

	return r;
}

IScene* RenderAlgo::dataControl()
{
	return nullptr;
}

ITexture2d* RenderAlgo::texture(const std::string& name)
{
	return nullptr;
}

IModel* RenderAlgo::model(const std::string& name)
{
	return nullptr;
}

IShader* RenderAlgo::shader(const std::string& name)
{
	return nullptr;
}

QList<Light*> RenderAlgo::lights()
{
	return QList<Light*>();
}

IRender* RenderAlgo::render()
{
	return nullptr;
}

ITextureLoader* RenderAlgo::textureLoader()
{
	return nullptr;
}

IShaderLoader* RenderAlgo::shaderLoader()
{
	return nullptr;
}

IShader* RenderAlgo::addShader(const QString&, const QString&, const QString&)
{
	return nullptr;
}

void RenderAlgo::draw()
{
}

IShaderLoader* RenderAlgo::loader()
{
	return nullptr;
}

QList<IGraphicsObject*> RenderAlgo::objects()
{
	return QList<IGraphicsObject*>();
}

void RenderAlgo::createRenderAlgo()
{
}

ISceneGraph* RenderAlgo::graph()
{
	return nullptr;
}

MyGL::ITexture2d* RenderAlgo::addTexture(std::string, MyGL::ITexture2d*)
{
	return nullptr;
}
