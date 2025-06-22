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

        bool isObjectVisible(const IGraphicsObject &obj);

        void normalization(double &X, double &Y, double &Z, double &D);

        double po(double x, double y, double z, double X, double Y, double Z, double D);

        void updateCull();

        void updateVisible();

        IGraphicsObject *visible(int num);

        int visiblesCount();

    protected:
        double model_proj[16];
        double cullM[6][4];
        IScene &scene;
        std::vector<IGraphicsObject *> visObj;
    };
}


