#pragma once
#include <glm/glm.hpp>
#include "IRender.h"
#include "IShader.h"
#include "IErrorControl.h"
#include "privateGLSupportClass.h"
#include "Color.h"
#include "IScene.h"
#include "CGL.h.h"
#include "IMaterial.h"
#include "IVBO.h"

namespace MyGL {
	class RenderState;
	class ObjectMatrix;

	class Render :public IRender {
	public:
		Render(CGL& glDevice);
		Render(CGL* glDevice);
		virtual ~Render();
		unsigned int batchCount();
		void begin();
		void bindCamera();
		void bindMaterial(IMaterial* material);
		void bindModel(IModel* m);
		void bindTexture(IUniformSampler* sampler, ITexture* tex);
		void bindTexture(CGL::TextureUnitHandle tx_unit, ITexture* tex);
		void bindVBO(IVBO* vbo, IVBO::BindMode::Type mode);
		ICamera* camera();
		void clear(Color c, clear::ClearMode mode);
		void clear(clear::ClearMode mode);
		void clearColor(a_1, Color c);
		Color clearColor();
		unsigned int dipCount();
		void draw(IGraphicsObject& obj);
		void drawModel(IModel* m);
		void drawModel(IModel* m, const ObjectMatrix& objMatrix);
		void drawVBO(IVBO::PrimitiveType::Type p, CGL::GLsizei size);
		void end();
		void finitGL();
		std::string getError();
		void getModeViewlMatrix(ObjectMatrix& out);
		void getModeViewlMatrix(Float* out);
		void getProjectionMatrix(ObjectMatrix& out);
		void getProjectionMatrix(Float* out);
		void getTransformMatrix(ObjectMatrix& out);
		void getViewport(int& x, int& y, int& w, int& h);
		CGL* gl();
		void glLoadMatrix(const double* x);
		void glLoadMatrix(const float* x);
		void glMultMatrix(const double* x);
		void glMultMatrix(const float* x);
		void init();
		bool initGL();
		bool isActive();
		bool isShaderCurrent(IShader* sh);
		unsigned int polyCount();
		IRenderState* renderState();
		void resetBatchCount();
		void resetCounters();
		void resetDipCount();
		void resetPolyCount();
		void resetRenderState();
		void setCamera(ICamera& c);
		void setRenderState(IRenderState* r);
		void setScene(IScene& s);
		void setViewport(int x, int y, int w, int h);
		void setZRange(double near, double far);
		void ubindMaterial();
		void ubindModel();
		void ubindTexture(IUniformSampler* sampler);
		void ubindTexture(CGL::TextureUnitHandle tx_unit);
		void ubindVBO(IVBO* vbo);
		void upsetRState();
		void useShader(IShader* sh);
		bool wasInit();
	protected:
		CGL* glDev;
		bool autoDel;
		//00000011     // padding byte
		//	00000012     // padding byte
		//	00000013     // padding byte
		//	00000014     // padding byte
		//	00000015     // padding byte
		//	00000016     // padding byte
		//	00000017     // padding byte
		IScene* scene;
		bool wInit;
		bool isWork;
		//00000022     // padding byte
		//	00000023     // padding byte
		unsigned int polyCount_val;
		unsigned int batchCount_val;
		unsigned int dipCount_val;
		IShader* currShader;
		IModel* currModel;
		IMaterial* currMaterial;
		bool isGL_ARB_multisampleEnable;
		//00000049     // padding byte
		//	0000004A     // padding byte
		//	0000004B     // padding byte
		//	0000004C     // padding byte
		//	0000004D     // padding byte
		//	0000004E     // padding byte
		//	0000004F     // padding byte
		double zNear;
		double zFar;
		double modelView[16];
		double projectionMat[16];
		Color clrColor;
		ICamera* cam;
		IRenderState* state;
		IRenderState* defState;
	};
}