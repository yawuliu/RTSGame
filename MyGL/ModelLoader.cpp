#include "ModelLoader.h"
#include "IModel.h"

namespace MyGL {
    ModelLoader::ModelLoader(IRender &r) : render(r) {

    }

    IModel *ModelLoader::load(IModel &taget, const char *fileName, bool *ok) {
        IOModel model;
        if (!model.load(fileName)) {
            if (ok)
                *ok = 0;
            this->render.gl()->errorCtrl()->loadError(this, &model, (std::string("[Error]:IOModel load error: \n") +
                                                                     fileName).c_str());
        } else {
            if (!model.size()) {
                this->render.gl()->errorCtrl()->loadError(this, &model, (std::string("[Warning]:IOModel is NULL: \n") +
                                                                         fileName).c_str());
            }
            taget.load(model);
        }
        return &model;
    }

    IModel *ModelLoader::loadBin_v0(IModel &taget, const char *fileName, bool *ok) {
        IOModel model;
        if (!model.loadBin_v0(fileName)) {
            if (ok)
                *ok = 0;
            this->render.gl()->errorCtrl()->loadError(this, &model, (std::string("[Error]:IOModel load error: \n") +
                                                                     fileName).c_str());
        } else {
            if (ok)
                *ok = 1;
            if (!model.size()) {
                this->render.gl()->errorCtrl()->loadError(this, &model, (std::string("[Warning]:IOModel is NULL: \n") +
                                                                         fileName).c_str());
            }
            taget.load(model);
        }
        return &model;
    }
}