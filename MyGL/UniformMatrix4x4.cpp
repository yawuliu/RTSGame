#include "UniformMatrix4x4.h"
#include <cstring>

using namespace MyGL;

UniformMatrix4x4::UniformMatrix4x4() {
	std::memset(m_matrix, 0, sizeof(m_matrix));
}

UniformMatrix4x4::UniformMatrix4x4(const float* matrix) {
	if (matrix) {
		std::memcpy(m_matrix, matrix, sizeof(m_matrix));
	}
	else {
		std::memset(m_matrix, 0, sizeof(m_matrix));
	}
}

void UniformMatrix4x4::SetMatrix(const float* matrix) {
	if (matrix) {
		std::memcpy(m_matrix, matrix, sizeof(m_matrix));
	}
}

const float* UniformMatrix4x4::GetMatrix() const {
	return m_matrix;
}


