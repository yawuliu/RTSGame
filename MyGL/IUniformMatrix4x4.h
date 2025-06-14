#pragma once

namespace MyGL {
	class IUniformMatrix4x4 {
	public:
		virtual void SetMatrix(const float* matrix) = 0;
		virtual const float* GetMatrix() const = 0;;
	};
}