#pragma once

#include <MyGL/IUniformMatrix4x4.h>

namespace MyGL {
	class UniformMatrix4x4 : public IUniformMatrix4x4 {
	public:
		UniformMatrix4x4();
		UniformMatrix4x4(const float* matrix);
		void SetMatrix(const float* matrix) override;
		const float* GetMatrix() const override;

	protected:
		float m_matrix[16];
	};
}

