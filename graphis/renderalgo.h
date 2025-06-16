#pragma once
#include <QList>
#include "MyGL/Adapter.h"
#include "MyGL/ForwardRenderAlgo.h"
#include "MyGL/ITexture2d.h"
#include "MyGL/MainPass.h"

class Adapter;

class RenderAlgo : public MyGL::ForwardRenderAlgo {
public:
	RenderAlgo(MyGL::IScene* s, const ::Adapter* adaForwardRenderpter);

private:
	MyGL::MainPass* allockMainPass(const MyGL::Adapter* adapter);

	MyGL::IModel* quad;

	// Í¨¹ý ForwardRenderAlgo ¼Ì³Ð
	MyGL::IScene* dataControl() override;
	MyGL::ITexture2d* texture(const std::string& name) override;
	MyGL::IModel* model(const std::string& name) override;
	MyGL::IShader* shader(const std::string& name) override;
	QList<MyGL::Light*> lights() override;
	MyGL::IRender* render() override;
	MyGL::ITextureLoader* textureLoader() override;
	MyGL::IShaderLoader* shaderLoader() override;
	MyGL::IShader* addShader(const QString&, const QString&, const QString&) override;
	void draw() override;
	MyGL::IShaderLoader* loader() override;
	QList<MyGL::IGraphicsObject*> objects() override;
	void createRenderAlgo() override;
	MyGL::ISceneGraph* graph() override;
	MyGL::ITexture2d* addTexture(std::string, MyGL::ITexture2d*) override;
};


