#include "ShaderEnvironment.h"

using namespace MyGL;

void ShaderEnvironment::push(const std::string& key, const std::string& value) {
	environmentStack.emplace_back(key, value);
}

void ShaderEnvironment::pop(const std::string& key) {
	for (auto it = environmentStack.rbegin(); it != environmentStack.rend(); ++it) {
		if (it->first == key) {
			// 从栈中移除该元素
			environmentStack.erase(std::next(it).base());
			break;
		}
	}
}


