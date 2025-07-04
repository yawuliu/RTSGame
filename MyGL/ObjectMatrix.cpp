#include "ObjectMatrix.h"

namespace MyGL {
    ObjectMatrix::ObjectMatrix(const ObjectMatrix &other) {
        this->matrix = new pimpl();
        this->setData(other.data());
    }

    ObjectMatrix::ObjectMatrix(const Float *data) {
        this->matrix = new pimpl();
        this->setData(data);
    }

    ObjectMatrix::ObjectMatrix(Float a11, Float a12, Float a13, Float a14, Float a21,
                               Float a22, Float a23, Float a24, Float a31, Float a32,
                               Float a33, Float a34, Float a41, Float a42, Float a43,
                               Float a44) {
        this->matrix = new pimpl();
        this->setData(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44);
    }

    ObjectMatrix::ObjectMatrix() {
        this->matrix = new pimpl();
        this->identity();
    }

    ObjectMatrix::~ObjectMatrix() {
        delete this->matrix;
    }

    const Float *ObjectMatrix::data() {
        return glm::gtc::type_ptr::value_ptr<double>(&this->matrix->m);
    }

    void ObjectMatrix::identity() {
        this->setData(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
                      0.0, 1.0);
    }

    void ObjectMatrix::mul(const ObjectMatrix &other) {
        this->matrix->m *= other
    }

    void *ObjectMatrix::operator=(const ObjectMatrix &other) {
        this->matrix = other.matrix;
        return this;
    }

    void ObjectMatrix::project(Float x, Float y, Float z, Float w,
                               Float &ox, Float & oy, Float& oz, Float & ow) {
        ObjectMatrix::pimpl *matrix;
        Float wa;
        Float za;
        Float ya;
        Float xa;
        ObjectMatrix *thisa;
        glm::dvec4 r;
        glm::dvec4 v;

        xa = x;
        ya = y;
        za = z;
        wa = w;
        matrix = this->matrix;
        glm::dvec4(&v, &xa, &ya, &za, &wa);
        glm::detail::operator*<double>(&r, &v, &matrix->m);
        ox = r.x;
        oy = r.y;
        oz = r.z;
        ow = r.w;
    }

    void ObjectMatrix::rotate(Float angle, Float x, Float y, Float z) {
        Float za;
        Float ya;
        Float xa;
        Float anglea;
        glm::dmat4 m;
        glm::dvec3 v;
        anglea = angle;
        xa = x;
        ya = y;
        za = z;
        glm::dvec3(&v, &xa, &ya, &za);
        glm::gtc::matrix_transform::rotate<double>(&m, &this->matrix->m, &anglea, &v);
        glm::dmat4::operator=(&this->matrix->m, &m);
    }

    void ObjectMatrix::rotateOZ(Float angle) {
        this->rotate(angle, 0.0, 0.0, 1.0);
    }

    void ObjectMatrix::scale(Float x) {
        this->scale(x, x, x);
    }

    void ObjectMatrix::scale(Float x, Float y, Float z) {
        Float za;
        Float ya;
        Float xa;
        glm::dmat4 m;
        glm::dvec3 v;

        xa = x;
        ya = y;
        za = z;
        glm::dvec3(&v, &xa, &ya, &za);
        glm::gtc::matrix_transform::scale<double>(&m, &this->matrix->m, &v);
        glm::dmat4::operator=(&this->matrix->m, &m);
    }

    void ObjectMatrix::setData(const Float *data) {
        double *dest;

        dest = glm::gtc::type_ptr::value_ptr<double>(&this->matrix->m);
        memcpy(dest, data, 0x80uLL);
    }

    void ObjectMatrix::setData(Float a11, Float a12, Float a13, Float a14, Float a21,
                               Float a22, Float a23, Float a24, Float a31, Float a32,
                               Float a33, Float a34, Float a41, Float a42, Float a43,
                               Float a44) {
        v17 = glm::dmat4::operator[](&this->matrix->m, 0LL);
        *glm::dvec4::operator[](v17, 0LL) = a11;
        v18 = glm::dmat4::operator[](&this->matrix->m, 0LL);
        *glm::dvec4::operator[](v18, 1uLL) = a12;
        v19 = glm::dmat4::operator[](&this->matrix->m, 0LL);
        *glm::dvec4::operator[](v19, 2uLL) = a13;
        v20 = glm::dmat4::operator[](&this->matrix->m, 0LL);
        *glm::dvec4::operator[](v20, 3uLL) = a14;
        v21 = glm::dmat4::operator[](&this->matrix->m, 1uLL);
        *glm::dvec4::operator[](v21, 0LL) = a21;
        v22 = glm::dmat4::operator[](&this->matrix->m, 1uLL);
        *glm::dvec4::operator[](v22, 1uLL) = a22;
        v23 = glm::dmat4::operator[](&this->matrix->m, 1uLL);
        *glm::dvec4::operator[](v23, 2uLL) = a23;
        v24 = glm::dmat4::operator[](&this->matrix->m, 1uLL);
        *glm::dvec4::operator[](v24, 3uLL) = a24;
        v25 = glm::dmat4::operator[](&this->matrix->m, 2uLL);
        *glm::dvec4::operator[](v25, 0LL) = a31;
        v26 = glm::dmat4::operator[](&this->matrix->m, 2uLL);
        *glm::dvec4::operator[](v26, 1uLL) = a32;
        v27 = glm::dmat4::operator[](&this->matrix->m, 2uLL);
        *glm::dvec4::operator[](v27, 2uLL) = a33;
        v28 = glm::dmat4::operator[](&this->matrix->m, 2uLL);
        *glm::dvec4::operator[](v28, 3uLL) = a34;
        v29 = glm::dmat4::operator[](&this->matrix->m, 3uLL);
        *glm::dvec4::operator[](v29, 0LL) = a41;
        v30 = glm::dmat4::operator[](&this->matrix->m, 3uLL);
        *glm::dvec4::operator[](v30, 1uLL) = a42;
        v31 = glm::dmat4::operator[](&this->matrix->m, 3uLL);
        *glm::dvec4::operator[](v31, 2uLL) = a43;
        v32 = glm::dmat4::operator[](&this->matrix->m, 3uLL);
        *glm::dvec4::operator[](v32, 3uLL) = a44;
    }

    void ObjectMatrix::translate(Float *v) {
        this->translate(*v, v[1], v[2]);
    }

    void ObjectMatrix::translate(Float x, Float y, Float z) {
        Float za;
        Float ya;
        Float xa;
        glm::dmat4 m;
        glm::dvec3 v;

        xa = x;
        ya = y;
        za = z;
        glm::dvec3(&v, &xa, &ya, &za);
        glm::translate<double>(&m, &this->matrix->m, &v);
        this->matrix->m = m;
    }

    void ObjectMatrix::transpose() {
        glm::dmat4 m;

        glm::transpose<double>(&m, &this->matrix->m);
        this->matrix->m = m;
    }

    ObjectMatrix::pimpl *ObjectMatrix::pimpl::operator=(const pimpl &a2) {
        this->m = a2.m;
        return this;
    }
}