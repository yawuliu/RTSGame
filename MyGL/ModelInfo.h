#pragma once

#include "IModelInfo.h"
#include "IIOModel.h"


namespace MyGL {

    class ModelInfo : public IModelInfo {
    public:
        ModelInfo();

        ModelInfo(IIOModel &m);

        virtual ~ModelInfo();

        IModelInfo *operator=(IModelInfo const &m);

        double minX();

        double minY();

        double minZ();

        double maxX();

        double maxY();

        double maxZ();

        double radius();

        void updateFrom(IIOModel const &m);

        void setBox(float x, float y, float z, float X, float Y, float Z);

    protected:
        double minD[3];
        double maxD[3];
        double r;
    };

}
