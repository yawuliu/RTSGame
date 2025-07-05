#pragma once

#include <vector>
#include "IScene.h"
#include "ISceneGraph.h"
#include "IRenderPass.h"
#include "IGraphicsObject.h"


namespace MyGL {
    class SceneGraph : public ISceneGraph {
    public:
        explicit SceneGraph(IScene &s);

        ~SceneGraph() override = default;

        void addObjectEvent(IGraphicsObject &a2) override;

        void beginFrame(IRenderPass &a2) override;

        void beginFrame() override;

        void delObjectEvent(IGraphicsObject &a2) override;

        void endFrame() override;

        void getGl();

        bool isObjectVisible(IGraphicsObject const &obj) override;

        void normalization(double &X, double &Y, double &Z, double &D);

        double po(double x, double y, double z, double X, double Y, double Z, double D);

        void updateCull();

        void updateVisible() override;

        IGraphicsObject *visible(int num) override;

        int visiblesCount() override;

    protected:
        double model_proj[16];
        double cullM[6][4];
        IScene &scene;
        std::vector<IGraphicsObject *> visObj;
    };
}


