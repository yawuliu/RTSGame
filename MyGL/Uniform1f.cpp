#include "Uniform1f.h"

using namespace MyGL;

Uniform1f::Uniform1f()
	: m_location(-1), m_value(0.0f) {
}

Uniform1f::Uniform1f(int location, float value)
	: m_location(location), m_value(value) {
}

void Uniform1f::setValue(float value) {
	m_value = value;
}

float Uniform1f::getValue() const {
	return m_value;
}

int Uniform1f::getLocation() const {
	return m_location;
}


