#pragma once

#include <glm/glm.hpp>
#include "IRender.h"
#include "IShader.h"
#include "IErrorControl.h"
#include "privateGLSupportClass.h"
#include "Color.h"
#include "IScene.h"
#include "CGL.h"
#include "IMaterial.h"
#include "IVBO.h"

namespace MyGL {
    class RenderState;

    class ObjectMatrix;

    class Render : public IRender {
    public:
        class clear {
        public:
            typedef int ClearMode;
        };

    public:
        explicit Render(CGL &glDevice);

        explicit Render(CGL *glDevice);

        ~Render() override;

        unsigned int batchCount() override;

        void begin() override;

        void bindCamera() override;

        void bindMaterial(IMaterial *material) override;

        void bindModel(IModel *m) override;

        void bindTexture(IUniformSampler *sampler, ITexture *tex) override;

        void bindTexture(CGL::TextureUnitHandle tx_unit, ITexture *tex) override;

        void bindVBO(IVBO *vbo, IVBO::BindMode::Type mode) override;

        ICamera *camera() override;

        void clear(Color c, Render::clear::ClearMode mode) override;

        void clear(Render::clear::ClearMode mode) override;

        void clearColor(Color c) override;

        Color clearColor() override;

        unsigned int dipCount() override;

        void draw(IGraphicsObject &obj) override;

        void drawModel(IModel *m) override;

        void drawModel(IModel *m, const ObjectMatrix &objMatrix) override;

        void drawVBO(IVBO::PrimitiveType::Type p, CGL::GLsizei size) override;

        void end() override;

        void finitGL() override;

        std::string getError() override;

        void getModeViewlMatrix(ObjectMatrix &out) override;

        void getModeViewlMatrix(Float *out) override;

        void getProjectionMatrix(ObjectMatrix &out) override;

        void getProjectionMatrix(Float *out) override;

        void getTransformMatrix(ObjectMatrix &out) override;

        void getViewport(int &x, int &y, int &w, int &h) override;

        CGL *gl() override;

        void glLoadMatrix(const double *x);

        void glLoadMatrix(const float *x);

        void glMultMatrix(const double *x);

        void glMultMatrix(const float *x);

        void init();

        bool initGL() override;

        bool isActive() override;

        bool isShaderCurrent(IShader *sh) override;

        unsigned int polyCount() override;

        IRenderState *renderState() override;

        void resetBatchCount() override;

        void resetCounters() override;

        void resetDipCount() override;

        void resetPolyCount() override;

        void resetRenderState() override;

        void setCamera(ICamera &c) override;

        void setRenderState(IRenderState *r) override;

        void setScene(IScene &s) override;

        void setViewport(int x, int y, int w, int h) override;

        void setZRange(double near, double far) override;

        void ubindMaterial() override;

        void ubindModel() override;

        void ubindTexture(IUniformSampler *sampler) override;

        void ubindTexture(CGL::TextureUnitHandle tx_unit) override;

        void ubindVBO(IVBO *vbo) override;

        void upsetRState();

        void useShader(IShader *sh) override;

        bool wasInit() override;

    protected:
        CGL *glDev;
        bool autoDel;
        //00000011     // padding byte
        //	00000012     // padding byte
        //	00000013     // padding byte
        //	00000014     // padding byte
        //	00000015     // padding byte
        //	00000016     // padding byte
        //	00000017     // padding byte
        IScene *scene;
        bool wInit;
        bool isWork;
        //00000022     // padding byte
        //	00000023     // padding byte
        unsigned int polyCount_val;
        unsigned int batchCount_val;
        unsigned int dipCount_val;
        IShader *currShader;
        IModel *currModel;
        IMaterial *currMaterial;
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
        ICamera *cam;
        IRenderState *state;
        IRenderState *defState;
    };
}