#pragma once

#include <vector>
#include "ILightsCollection.h"
#include "ILight.h"
#include "IScene.h"

namespace MyGL {
    class LightsCollection : public ILightsCollection {
    public:
        class pimpl {
        public:
            pimpl() = default;

            virtual  ~pimpl() = default;

        public:
            std::vector<ILight *> lights;
        };

    public:
        LightsCollection(IScene &s);

        virtual ~LightsCollection();

        void add(ILight &l);

        void del(ILight &l);

        void remove(ILight &l);

        IScene *scene();

        int size();

        ILight *at(unsigned int id);

    protected:
        LightsCollection::pimpl *data;
        IScene *mscene;
    };
}