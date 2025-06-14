#include "landtechnicue.h"


#include <QDebug>
#include <MyGL/IRenderPass.h>
#include "graphis/abstractuserpass.h"
#include "graphis/virtualtexturingpass.h"
#include "MyGL/IRenderState.h"

using namespace MyGL;

LandTechnicue::LandTechnicue(MyGL::IScene* s) : StdTechnique(s) {

}

bool LandTechnicue::passEvent(const MyGL::ColorPass*) {
	return 0;
}

bool LandTechnicue::passEvent(const MyGL::IRenderPass* pass) {
	if (pass->type() == (IRenderPass::Pass::Type)AbstractUserPass::UPass::VirtualTexturigPass) {
		return bool(virtualTexturePass(
			static_cast<const VirtualTexturingPass*>(pass)));
	}

	return false;
}

bool LandTechnicue::virtualTexturePass(const VirtualTexturingPass*) {
	storeRenderState();
	setCurrentShader(colorShader());

	renderState()->setZTest(1);

	if (useDepthPass())
		renderState()->setZTestMode(IRenderState::ZTestMode::Equal);
	else
		renderState()->setZTestMode(IRenderState::ZTestMode::Less);

	return currentShader() != NULL;
}

void LandTechnicue::completeDraw(const MyGL::IRenderPass*) {
	restoreRenderState();
}
