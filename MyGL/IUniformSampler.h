#pragma once

namespace MyGL {
	class ITexture2d;
	class IUniformSampler {
	public:
		// �󶨲�������ָ��������Ԫ
		virtual void Bind(int textureUnit) = 0;

		// ��������
		virtual void Unbind() = 0;

		// ��ȡ����������
		virtual const char* GetName() const = 0;
		virtual void setTexture(ITexture2d*) = 0;
	};
}
