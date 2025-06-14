#pragma once
#include <vector>

namespace MyGL {
	class SSAO {
	public:
		SSAO();
		~SSAO();

		void Initialize(int width, int height);
		void GenerateKernel();
		void GenerateNoiseTexture();
		void RenderSSAO();
		void Resize(int width, int height);

		unsigned int GetSSAOTexture() const;

	private:
		int m_width;
		int m_height;
		unsigned int m_ssaoFBO;
		unsigned int m_ssaoTexture;
		unsigned int m_noiseTexture;
		std::vector<glm::vec3> m_kernel;
		std::vector<glm::vec3> m_noise;
		unsigned int m_kernelSize;
	};
}