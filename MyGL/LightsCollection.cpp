#include "LightsCollection.h"

namespace MyGL {
    LightsCollection::LightsCollection(IScene &s) : mscene(&s) {
        this->data = new pimpl();
    }

    LightsCollection::~LightsCollection() {
        for (size_t i = 0LL; this->data->lights.size() > i; ++i) {
            if (this->data->lights[i])
                delete this->data->lights[i];
        }
        if (this->data) {
            delete this->data;
        }
    }

    void LightsCollection::add(ILight &l) {
        this->data->lights.push_back(&l);
    }

    void LightsCollection::del(ILight &l) {
        for (size_t i = 0LL; this->data->lights.size() > i; ++i) {
            if (this->data->lights[i] == &l) {
                this->data->lights[i] = this->data->lights.back();
                this->data->lights.pop_back();
                if (l)
                    delete l;
                return;
            }
        }
    }

    void LightsCollection::remove(ILight &l) {
        for (size_t i = 0LL; this->data->lights.size() > i; ++i) {
            if (this->data->lights[i] == &l) {
                v2 = this->data->lights[i];
                *v2 = this->data->lights.back();
                this->data->lights.pop_back();
                return;
            }
        }
    }

    IScene *LightsCollection::scene() {
        return this->mscene;
    }

    int LightsCollection::size() {
        return this->data->lights.size();
    }

    ILight *LightsCollection::at(unsigned int id) {
        return this->data->lights.at(id);
    }
}