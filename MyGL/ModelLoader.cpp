#include "ModelLoader.h"

namespace MyGL {
    ModelLoader::ModelLoader(IRender &r) : render(r) {

    }

    IModel *ModelLoader::load(const char *fileName, bool *ok) {
        IOModel model;
        if (!model.load(fileName)) {
            if (ok)
                *ok = 0;
            this->rende.gl()->errorCtrl()->loadError(this, &model, "[Error]:IOModel load error: \n" + fileName);
        } else {
            if (!model.size()) {
                this->render.gl()->errorCtrl()->loadError(this, &model, "[Warning]:IOModel is NULL: \n" + fileName);
            }
            this->load(&model);
        }
        return &model;
    }

    IModel *ModelLoader::loadBin_v0(const char *fileName, bool *ok) {
        IOModel model;
        if (!model.loadBin_v0(fileName)) {
            if (ok)
                *ok = 0;
            this->render.gl()->errorCtrl()->loadError(this, &model, "[Error]:IOModel load error: \n" + fileName);
        } else {
            if (ok)
                *ok = 1;
            if (!model.size()) {
                this->render.gl()->errorCtrl()->loadError(this, &model, "[Warning]:IOModel is NULL: \n" + fileName);
            }
            this->load(&model);
        }
        return &model;
    }
}