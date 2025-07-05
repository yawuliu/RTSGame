#pragma once

#include <glm/glm.hpp>
#include "Data.h"

namespace MyGL {
    class ObjectMatrix {
    public:
        class pimpl {
        public:
            pimpl() = default;

            pimpl &operator=(const pimpl &a2);

        public:
            glm::dmat4 m;
        };

    public:
        ObjectMatrix(const ObjectMatrix &other);

        explicit ObjectMatrix(const Float *data);

        ObjectMatrix(
                Float a11,
                Float a12,
                Float a13,
                Float a14,
                Float a21,
                Float a22,
                Float a23,
                Float a24,
                Float a31,
                Float a32,
                Float a33,
                Float a34,
                Float a41,
                Float a42,
                Float a43,
                Float a44);

        ObjectMatrix();

        virtual ~ObjectMatrix();

        const Float *data();

        void identity();

        void mul(const ObjectMatrix &other);

        ObjectMatrix &operator=(const ObjectMatrix &other);

        void project(Float x,
                     Float y,
                     Float z,
                     Float w,
                     Float &ox,
                     Float &oy,
                     Float &oz,
                     Float &ow);

        void rotate(Float angle,
                    Float x,
                    Float y,
                    Float z);

        void rotateOZ(Float angle);

        void scale(Float x);

        void scale(Float x, Float y, Float z);

        void setData(const Float *data);

        void setData(Float a11,
                     Float a12,
                     Float a13,
                     Float a14,
                     Float a21,
                     Float a22,
                     Float a23,
                     Float a24,
                     Float a31,
                     Float a32,
                     Float a33,
                     Float a34,
                     Float a41,
                     Float a42,
                     Float a43,
                     Float a44);

        void translate(Float *v);

        void translate(Float x,
                       Float y,
                       Float z);

        void transpose();

    protected:
        pimpl *matrix;
    };
}