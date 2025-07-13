#include "ModelInfo.h"

namespace MyGL {
    ModelInfo::ModelInfo() {
        for (int i = 0; i <= 2; ++i) {
            this->minD[i] = 0.0;
            this->maxD[i] = 0.0;
        }
        this->r = 0.0;
    }

    ModelInfo::ModelInfo(IIOModel &m) {
        this->updateFrom(m);
    }

    ModelInfo &ModelInfo::operator=(IModelInfo &m) {
        // 直接使用浮点变量存储边界值
        float maxX = m.maxX();
        float maxY = m.maxY();
        float maxZ = m.maxZ();
        float minX = m.minX();
        float minY = m.minY();
        float minZ = m.minZ();

        // 设置边界值并更新包围盒
        this->setBox(minX, minY, minZ, maxX, maxY, maxZ);

        return *this;
    }

    double ModelInfo::minX() {
        return this->minD[0];
    }

    double ModelInfo::minY() {
        return this->minD[1];
    }

    double ModelInfo::minZ() {
        return this->minD[2];
    }

    double ModelInfo::maxX() {
        return this->maxD[0];
    }

    double ModelInfo::maxY() {
        return this->maxD[1];
    }

    double ModelInfo::maxZ() {
        return this->maxD[2];
    }

    double ModelInfo::radius() {
        return this->r;
    }

    void ModelInfo::updateFrom(IIOModel &m) {
        double dVec[3];
        for (int i = 0; i <= 2; ++i) {
            this->minD[i] = 0.0;
            this->maxD[i] = 0.0;
        }
        this->r = 0.0;
        if (m.size() != 0) {
            for (int i_0 = 0; i_0 <= 2; ++i_0) {
                this->minD[i_0] = *(float *) (4LL * i_0 + m.points());
                this->maxD[i_0] = *(float *) (4LL * i_0 + m.points());
            }
            for (int i_1 = 0;; i_1 += 3) {
                if (3 * m.size() <= i_1)
                    break;
                for (int j = 0; j <= 2; ++j) {
                    double p = *(float *) (4LL * (i_1 + j) + m.points());
                    this->minD[j] = std::min<double>(this->minD[j], p);
                    this->maxD[j] = std::max<double>(this->maxD[j], p);
                }
            }
            for (int i_2 = 0; i_2 <= 2; ++i_2)
                dVec[i_2] = this->maxD[i_2] - this->minD[i_2];
            this->r = sqrt(dVec[2] * dVec[2] + dVec[0] * dVec[0] + dVec[1] * dVec[1]) * 0.5;
        }
    }

    void ModelInfo::setBox(float x, float y, float z, float X, float Y, float Z) {
        double dVec[3];
        int i;

        this->minD[0] = x;
        this->minD[1] = y;
        this->minD[2] = z;
        this->maxD[0] = X;
        this->maxD[1] = Y;
        this->maxD[2] = Z;
        for (i = 0; i <= 2; ++i)
            dVec[i] = this->maxD[i] - this->minD[i];
        this->r = sqrt(dVec[2] * dVec[2] + dVec[0] * dVec[0] + dVec[1] * dVec[1]) * 0.5;
    }
}
