#pragma once

namespace MyGL {
	class ITexture2d;
	class IUniformSampler {
	public:
		// 绑定采样器到指定的纹理单元
		virtual void Bind(int textureUnit) = 0;

		// 解绑采样器
		virtual void Unbind() = 0;

		// 获取采样器名称
		virtual const char* GetName() const = 0;
		virtual void setTexture(ITexture2d*) = 0;
	};
}
