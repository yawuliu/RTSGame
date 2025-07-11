#include "rendermainpass.h"


#include <MyGL/ColorPass.h>
#include <MyGL/AddBlendPass.h>
#include <MyGL/TransparentPass.h>
#include <MyGL/ShadowPass.h>
#include <MyGL/DepthPass.h>
#include <MyGL/SSAOpass.h>

#include "graphis/virtualtexturingpass.h"
#include "settingswidget.h"

using namespace MyGL;

RenderMainPass::RenderMainPass(IScene *s, IModel *quad,
                               const MyGL::gadapter *adapter) : MainPass(s, adapter, quad, 0) {
    makeAlgo(adapter);
}

MyGL::IScene *RenderMainPass::scene() {
    return nullptr;
}

MyGL::ITextureRectangle *RenderMainPass::output() {
    return nullptr;
}

void RenderMainPass::makeAlgo(std::vector<MyGL::IRenderPass *> &passes,
                              const MyGL::Adapter *adapter) {

    passes.push_back(new VirtualTexturingPass(scene(),
                                              this,
                                              output()));

    passes.push_back(new DepthPass(scene()));
    passes.push_back(new ColorPass(scene()));


    passes.push_back(new AddBlendPass(scene()));
    passes.push_back(new TransparentPass(scene()));

    if (SettingsWidget::settings.ssao)
        passes.push_back(new SSAOpass((IScene *) scene(), (IAdapter *) adapter, (IRenderPass *) this));
}


void RenderMainPass::makeAlgo(const MyGL::Adapter *adapter) {

}