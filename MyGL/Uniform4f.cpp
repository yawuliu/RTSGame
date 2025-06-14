#include "Uniform4f.h"

using namespace MyGL;

Uniform4f::Uniform4f()
	: m_x(0.0f), m_y(0.0f), m_w(0.0f), m_h(0.0f) {
}

void Uniform4f::set(int value) {
	m_x = static_cast<float>(value);
	m_y = static_cast<float>(value);
	m_w = static_cast<float>(value);
	m_h = static_cast<float>(value);
}

void Uniform4f::set(float x, float y, float w, float h) {
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
}


