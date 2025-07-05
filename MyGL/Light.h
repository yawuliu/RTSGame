#pragma once

#include <QList>
#include "IScene.h"
#include "Light.h"
#include "ITechnique.h"
#include "GraphicsObject.h"
#include "AbstractMaterial.h"
#include "ObjectMatrix.h"
#include "ILightsCollection.h"

namespace MyGL {
    class SmallLightsPass;

    class Light {
    public:
        class Data {
        public:
            Data(IScene &s);

            virtual ~Data();

        protected:
            GraphicsObject object;
        };

        class Material : public AbstractMaterial {
        public:
            Material(Light::Material *const m, IScene &s, ITechnique *t);

            virtual ~Material();

            void bind();

            const IRenderState *renderState();

            IRenderState *renderState();

            void setUniforms();

            ITechnique *technique();

            void uBind();

        protected:
            ITechnique *tech;
        };

        class Technicue {
        public:
            Technicue(IScene &s);

            virtual ~Technicue();

            void bind();

            const IShader *cmpShader();

            void completeDraw(const IRenderPass *a2);

            const IShader *currentShader();

            bool lPass(const SmallLightsPass *a2);

            bool passEvent(const IRenderPass *pass);

            IRenderState *renderState();

            void setUniforms();

            void uBind();
        };

    public:
        Light(ILightsCollection &c);

        virtual ~Light();

        Float *dirTransform();

        Float dirX();

        Float dirY();

        Float dirZ();

        bool hasOccluder();

        bool isDeferred();

        bool isShadowCaster();

        IModel *occluder();

        void setDeferred(bool d);

        void setDirection(Float x, Float y, Float z);

        void setPosition(Float x, Float y, Float z);

        void setShadowCast(bool doIt);

        void upset();

        Float x();

        Float y();

        Float z();

    private:
        ILightsCollection &collect;
        double pos[3];
        double dir[3];
        double tDir[3];
        bool sh;
        bool ds;
        // padding byte
        // padding byte
        // padding byte
        // padding byte
        // padding byte
        // padding byte
        Data *data;
    };
}


