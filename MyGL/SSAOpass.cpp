#include "SSAOpass.h"
namespace MyGL {
	SSAOpass::Data::Data(IScene& s) :ssao(s) {}

	SSAOpass::SSAOpass(IScene& s, const gadapter& adapter, MainPass* mp) : AbstractPass(s)
	{
        this->data = new Data(this->scene());
        this->data->ssao->setShader(adapter->getSSAOShader());
        this->data->ssao->setQuadModel(mp->quadModel());
        this->data->ssao->setInput("mainPass", mp->output());
        this->data->ssao->setInput("depthBuffer", mp->depthBuffer());
        this->data->ssao->setInput("rand4x4", adapter->getRandTexture());
        this->data->ssao->renderState()->setBlend(1LL);
        this->data->ssao->renderState()->setBlendMode( 8LL, 0LL);
        this->out = new TextureRectangle(this->scene()->render());;
        this->depth = new TextureRectangle(this->scene()->render());;
        this->mpass = mp;
        this->active = 1;
	}

	SSAOpass::~SSAOpass()
	{
		if (this->data)
		{
            delete this->data;
		}
		if (this->out)
            delete this->out;
		if (this->depth)
            delete this->depth;
	}

	void SSAOpass::exec()
	{
		if (this->active)
		{
            this->resizeFrame();
            this->mpass->frameBuffer()->attachDepthTexture(this->depth);
            this->data->ssao->exec();
            this->mpass->frameBuffer()->attachDepthTexture(this->mpass->depthBuffer());
		}
	}

	bool SSAOpass::isActive()
	{
		return this->active;
	}

	ITextureRectangle* SSAOpass::output()
	{
		if (this->active)
			return this->out;
		else
			return this->mpass->output();
	}

	void SSAOpass::resizeFrame() {
		if (this->out->width() != this->mpass->frameBuffer()->width()
			|| (v3 = this->out->setClamping(),
				v4 = this->mpass->frameBuffer(),
				v3 != v4->height() ))
		{
            this->out->setFiltration((0LL, 1LL, this->mpass->frameBuffer()->width(), this->mpass->frameBuffer()->height(), 3LL);
            this->depth->setFiltration( 0LL, 3LL, this->mpass->frameBuffer()->width(), this->mpass->frameBuffer()->height(), 21LL);
		}
	}

	void SSAOpass::setActive(bool active)
	{
		this->active = active;
	}

	IRenderPass::Pass::Type SSAOpass::type()
	{
		return 9;
	}
}