#include "IVBO.h"

float &MyGL::IVBO::IPointer::operator[](size_t i) {
    return data[i];
}


