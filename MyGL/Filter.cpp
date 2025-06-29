#include "Filter.h"
#include "IUniformSampler.h"
#include "IShader.h"

namespace MyGL {

	Filter::Filter(IScene& s) : AbstractPass(s) {
		this->data = new Data();
		this->data->renderState->setZTest(0);
		this->data->renderState->setZWriting(0);
		this->data->quad = 0LL;
		this->data->shader = 0LL;
	}

	Filter::~Filter() {
		if (this->data) {
			delete this->data;
		}
	}

	IUniformSampler* Filter::addArgs(IUniformSampler* sm, ITexture* u) {
		if (this->data->shader)
		{
			auto&& i = this->data->args.find(&sm);
			if (sm)
			{
				if (i == this->data->args.end())
				{
					sm->set(this->data->args.size());
				}
				*(this->data->args[sm]) = u;
			}
			return sm;
		}
		else
		{
			this->scene()->render()->gl()->errorCtrl()->warning(0LL, "[Filter::addArgs]null shader");
			return 0LL;
		}

		IUniformSampler* Filter::addArgs(const std::string & name, ITexture * u) {
			if (this->data->shader) {
				return this->addArgs(this->data->shader->uniformSampler(name), u);
			}
			else {
				this->scene()->render()->gl()->errorCtrl()->warning(0LL, "[Filter::addArgs]null shader");
				return 0LL;
			}
		}

		void Filter::exec() {
			if (this->data->shader && this->data->quad && this->data->shader) {
				this->scene()->render()->setRenderState(this->data);
				this->scene()->render()->begin();
				this->scene()->render()->useShader(this->data->shader);
				for (auto&& i = this->data->args.begin();; i++) {
					if (i == this->data->args.end())
						break;
					this->scene()->render()->bindTexture(i->first, i->second);
				}
				this->scene()->render()->drawModel(this->data->quad);
				this->scene()->render()->end();
			}
			else
			{
				this->scene()->render()->gl()->errorCtrl()->warning(0LL, "Filter is incomplete");
			}
		}

		IRenderPass::Pass::Type Filter::type() {
			return IRenderPass::Pass::None;
		}

		IModel* Filter::quadModel() {
			return this->data->quad;
		}

		IRenderState* Filter::renderState() {
			return this->data->renderState;
		}

		IUniformSampler* Filter::setInput(IUniformSampler * name, ITexture * arg) {
			return this->addArgs(name, arg);
		}

		IUniformSampler* Filter::setInput(const std::string & name, ITexture * arg) {
			return this->addArgs(name, arg);
		}

		void Filter::setQuadModel(IModel * m) {
			this->data->quad = m;
		}

		void Filter::setShader(IShader * s) {
			this->data->shader = s;
			this->data->args.clear();
		}

		IShader* Filter::shader() {
			return this->data->shader;
		}


	}