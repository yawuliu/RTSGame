#pragma once

#include <string>
#include <vector>
#include "IShaderEnvironment.h"

namespace MyGL {
	class ShaderEnvironment : public IShaderEnvironment {
	public:
		void pop(const std::string&) override;
		void push(const std::string&, const std::string&) override;

	private:
		// ���ڴ洢����������ջ�ṹ
		std::vector<std::pair<std::string, std::string>> environmentStack;
	};
}

