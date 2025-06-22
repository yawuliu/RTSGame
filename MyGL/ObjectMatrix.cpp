#include "ObjectMatrix.h"

MyGL::ObjectMatrix::ObjectMatrix(const ObjectMatrix &other) {
    this->matrix = new MyGL::ObjectMatrix::pimpl::pimpl();
    data = MyGL::ObjectMatrix::data((const MyGL::ObjectMatrix *const) other);
    this->setData(data);
}

MyGL::ObjectMatrix::ObjectMatrix(const MyGL::Float *data) {
    this->matrix = new MyGL::ObjectMatrix::pimpl::pimpl();
    this->setData(data);
}

MyGL::ObjectMatrix::ObjectMatrix(MyGL::Float a11, MyGL::Float a12, MyGL::Float a13, MyGL::Float a14, MyGL::Float a21,
                                 MyGL::Float a22, MyGL::Float a23, MyGL::Float a24, MyGL::Float a31, MyGL::Float a32,
                                 MyGL::Float a33, MyGL::Float a34, MyGL::Float a41, MyGL::Float a42, MyGL::Float a43,
                                 MyGL::Float a44) {
    this->matrix = new MyGL::ObjectMatrix::pimpl::pimpl();
    this->setData(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34, a41, a42, a43, a44);
}

MyGL::ObjectMatrix::ObjectMatrix() {
    this->matrix = new MyGL::ObjectMatrix::pimpl::pimpl();
    this->identity();
}

MyGL::ObjectMatrix::~ObjectMatrix() {
    delete this->matrix;
}

const MyGL::Float *MyGL::ObjectMatrix::data() {
    return glm::gtc::type_ptr::value_ptr<double>(&this->matrix->m);
}

void MyGL::ObjectMatrix::identity() {
    this->setData(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
                  0.0, 1.0);
}

void MyGL::ObjectMatrix::mul(const void *const other) {
    glm::detail::tmat4x4<double>::operator*=<double>(
            &p_mv->matrix->m,
            *(const glm::detail::tmat4x4<double> *const *) other);
}

void *MyGL::ObjectMatrix::operator=(const ObjectMatrix &other) {
    MyGL::ObjectMatrix::pimpl::operator=(this->matrix, *(const MyGL::ObjectMatrix::pimpl *const *) other);
    return this;
}

void MyGL::ObjectMatrix::project(MyGL::Float x, MyGL::Float y, MyGL::Float z, MyGL::Float w, MyGL::Float *const ox,
                                 MyGL::Float *const oy, MyGL::Float *const oz, MyGL::Float *const ow) {
    MyGL::ObjectMatrix::pimpl *matrix;
    MyGL::Float wa;
    MyGL::Float za;
    MyGL::Float ya;
    MyGL::Float xa;
    MyGL::ObjectMatrix *thisa;
    glm::detail::tvec4<double> r;
    glm::detail::tvec4<double> v;

    thisa = thisa_1;
    xa = x;
    ya = y;
    za = z;
    wa = w;
    matrix = thisa_1->matrix;
    glm::detail::tvec4<double>::tvec4(&v, &xa, &ya, &za, &wa);
    glm::detail::operator*<double>(&r, &v, &matrix->m);
    *ox = r.x;
    *oy = r.y;
    *oz = r.z;
    *ow = r.w;
}

void MyGL::ObjectMatrix::rotate(MyGL::Float angle, MyGL::Float x, MyGL::Float y, MyGL::Float z) {
    MyGL::Float za;
    MyGL::Float ya;
    MyGL::Float xa;
    MyGL::Float anglea;
    MyGL::ObjectMatrix *thisa;
    glm::detail::tmat4x4<double> m;
    glm::detail::tvec3<double> v;

    thisa = thisa_1;
    anglea = angle;
    xa = x;
    ya = y;
    za = z;
    glm::detail::tvec3<double>::tvec3(&v, &xa, &ya, &za);
    glm::gtc::matrix_transform::rotate<double>(&m, &thisa->matrix->m, &anglea, &v);
    glm::detail::tmat4x4<double>::operator=(&thisa->matrix->m, &m);
}

void MyGL::ObjectMatrix::rotateOZ(MyGL::Float angle) {
    this->rotate(angle, 0.0, 0.0, 1.0);
}

void MyGL::ObjectMatrix::scale(MyGL::Float x) {
    this->scale(x, x, x);
}

void MyGL::ObjectMatrix::scale(MyGL::Float x, MyGL::Float y, MyGL::Float z) {
    MyGL::Float za;
    MyGL::Float ya;
    MyGL::Float xa;
    MyGL::ObjectMatrix *thisa;
    glm::detail::tmat4x4<double> m;
    glm::detail::tvec3<double> v;

    thisa = thisa_1;
    xa = x;
    ya = y;
    za = z;
    glm::detail::tvec3<double>::tvec3(&v, &xa, &ya, &za);
    glm::gtc::matrix_transform::scale<double>(&m, &thisa->matrix->m, &v);
    glm::detail::tmat4x4<double>::operator=(&thisa->matrix->m, &m);
}

void MyGL::ObjectMatrix::setData(const MyGL::Float *data) {
    double *dest;

    dest = glm::gtc::type_ptr::value_ptr<double>(&this->matrix->m);
    memcpy(dest, data, 0x80uLL);
}

void MyGL::ObjectMatrix::setData(MyGL::Float a11, MyGL::Float a12, MyGL::Float a13, MyGL::Float a14, MyGL::Float a21,
                                 MyGL::Float a22, MyGL::Float a23, MyGL::Float a24, MyGL::Float a31, MyGL::Float a32,
                                 MyGL::Float a33, MyGL::Float a34, MyGL::Float a41, MyGL::Float a42, MyGL::Float a43,
                                 MyGL::Float a44) {
    glm::detail::tvec4<double> *v17;
    glm::detail::tvec4<double> *v18;
    glm::detail::tvec4<double> *v19;
    glm::detail::tvec4<double> *v20;
    glm::detail::tvec4<double> *v21;
    glm::detail::tvec4<double> *v22;
    glm::detail::tvec4<double> *v23;
    glm::detail::tvec4<double> *v24;
    glm::detail::tvec4<double> *v25;
    glm::detail::tvec4<double> *v26;
    glm::detail::tvec4<double> *v27;
    glm::detail::tvec4<double> *v28;
    glm::detail::tvec4<double> *v29;
    glm::detail::tvec4<double> *v30;
    glm::detail::tvec4<double> *v31;
    glm::detail::tvec4<double> *v32;

    v17 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 0LL);
    *glm::detail::tvec4<double>::operator[](v17, 0LL) = a11;
    v18 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 0LL);
    *glm::detail::tvec4<double>::operator[](v18, 1uLL) = a12;
    v19 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 0LL);
    *glm::detail::tvec4<double>::operator[](v19, 2uLL) = a13;
    v20 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 0LL);
    *glm::detail::tvec4<double>::operator[](v20, 3uLL) = a14;
    v21 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 1uLL);
    *glm::detail::tvec4<double>::operator[](v21, 0LL) = a21;
    v22 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 1uLL);
    *glm::detail::tvec4<double>::operator[](v22, 1uLL) = a22;
    v23 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 1uLL);
    *glm::detail::tvec4<double>::operator[](v23, 2uLL) = a23;
    v24 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 1uLL);
    *glm::detail::tvec4<double>::operator[](v24, 3uLL) = a24;
    v25 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 2uLL);
    *glm::detail::tvec4<double>::operator[](v25, 0LL) = a31;
    v26 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 2uLL);
    *glm::detail::tvec4<double>::operator[](v26, 1uLL) = a32;
    v27 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 2uLL);
    *glm::detail::tvec4<double>::operator[](v27, 2uLL) = a33;
    v28 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 2uLL);
    *glm::detail::tvec4<double>::operator[](v28, 3uLL) = a34;
    v29 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 3uLL);
    *glm::detail::tvec4<double>::operator[](v29, 0LL) = a41;
    v30 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 3uLL);
    *glm::detail::tvec4<double>::operator[](v30, 1uLL) = a42;
    v31 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 3uLL);
    *glm::detail::tvec4<double>::operator[](v31, 2uLL) = a43;
    v32 = glm::detail::tmat4x4<double>::operator[](&p_lMatrix->matrix->m, 3uLL);
    *glm::detail::tvec4<double>::operator[](v32, 3uLL) = a44;
}

void MyGL::ObjectMatrix::translate(MyGL::Float *v) {
    this->translate(*v, v[1], v[2]);
}

void MyGL::ObjectMatrix::translate(MyGL::Float x, MyGL::Float y, MyGL::Float z) {
    MyGL::Float za;
    MyGL::Float ya;
    MyGL::Float xa;
    MyGL::ObjectMatrix *thisa;
    glm::detail::tmat4x4<double> m;
    glm::detail::tvec3<double> v;

    thisa = thisa_1;
    xa = x;
    ya = y;
    za = z;
    glm::detail::tvec3<double>::tvec3(&v, &xa, &ya, &za);
    glm::gtc::matrix_transform::translate<double>(&m, &thisa->matrix->m, &v);
    glm::detail::tmat4x4<double>::operator=(&thisa->matrix->m, &m);
}

void MyGL::ObjectMatrix::transpose() {
    glm::detail::tmat4x4<double> m;

    glm::core::function::matrix::transpose<double>(&m, &this->matrix->m);
    glm::detail::tmat4x4<double>::operator=(&this->matrix->m, &m);
}

MyGL::ObjectMatrix::pimpl *MyGL::ObjectMatrix::pimpl::operator=(const pimpl &a2) {
    glm::detail::tmat4x4<double>::operator=(&this->m, &a2->m);
    return this;
}
