#pragma once

#include "IModelInfo.h"
#include "IIOModel.h"

namespace MyGL {

    class ModelInfo : public IModelInfo {
    public:
        ModelInfo();

        explicit ModelInfo(IIOModel &m);

        ~ModelInfo() override = default;

        IModelInfo &operator=(IModelInfo const &m) override;

        double minX() override;

        double minY() override;

        double minZ() override;

        double maxX() override;

        double maxY() override;

        double maxZ() override;

        double radius() override;

        void updateFrom(IIOModel &m) override;

        void setBox(float x, float y, float z, float X, float Y, float Z);

    protected:
        double minD[3];
        double maxD[3];
        double r;
    };

}
