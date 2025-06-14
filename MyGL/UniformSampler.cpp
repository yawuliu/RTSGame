#include "UniformSampler.h"

using namespace MyGL;

UniformSampler::UniformSampler() {
	// 构造函数实现（如有需要可初始化成员变量）
}

void UniformSampler::Bind(int textureUnit) {
	// 绑定采样器到指定纹理单元
	// 示例：glActiveTexture(GL_TEXTURE0 + textureUnit); glBindSampler(textureUnit, samplerId);
}

void UniformSampler::Unbind() {
	// 解绑采样器
	// 示例：glBindSampler(0, 0);
}

const char* UniformSampler::GetName() const {
	// 返回采样器名称
	return "UniformSampler";
}


