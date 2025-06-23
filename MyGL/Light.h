#pragma once

#include <QList>
#include "IScene.h"
#include "Light.h"
#include "ITechnique.h"
#include "GraphicsObject.h"
#include "AbstractMaterial.h"
#include "ObjectMatrix.h"

namespace MyGL {
    class SmallLightsPass;

    class Light {
    public:
        class Data {
        public:
            Data(IScene &s);

            virtual ~Data();

        protected:
            GraphicsObject *object;
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
        int m_shadowCast;
        float m_direction[3];
        float m_position[3];
        QList<Light *> m_lights;
    };
}


