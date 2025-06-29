#pragma once

#include <vector>
#include "IScene.h"
#include "ISceneGraph.h"
#include "IRenderPass.h"
#include "IGraphicsObject.h"


namespace MyGL {
    class SceneGraph : public ISceneGraph {
    public:
        SceneGraph(IScene &s);

        virtual ~SceneGraph() = default;

        void addObjectEvent(IGraphicsObject &a2);

        void beginFrame(IRenderPass &a2);

        void beginFrame();

        void delObjectEvent(IGraphicsObject &a2);

        void endFrame();

        void getGl();

        virtual bool isObjectVisible(IGraphicsObject const &obj) override;

        void normalization(double &X, double &Y, double &Z, double &D);

        double po(double x, double y, double z, double X, double Y, double Z, double D);

        void updateCull();

        void updateVisible();

        virtual IGraphicsObject *visible(int num) override;

        virtual int visiblesCount() override;

    protected:
        double model_proj[16];
        double cullM[6][4];
        IScene &scene;
        std::vector<IGraphicsObject *> visObj;
    };
}


