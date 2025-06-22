#pragma once

namespace MyGL {
	class IScene;

	class IRenderPass {
	public:
		IRenderPass() = default;

		virtual ~IRenderPass() = default;

		class Pass {
		public:
			enum Type {
				None = 0x0,
				AddBlend = 0x1,
				Bloom = 0x2,
				Color = 0x3,
				Depth = 0x4,
				Glow = 0x5,
				Linc = 0x6,
				Shadow = 0x7,
				Transparent = 0x8,
				SSAO = 0x9,
				SmallLights = 0xA,
				User = 0x400,
				MaxUser = 0x8000,
			};
		};

		virtual  IRenderPass::Pass::Type type() const = 0;
	};
}