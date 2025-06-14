#pragma once

namespace MyGL {
	class IScene;

	class IRenderPass {
	public:
		IRenderPass(IScene* s);

		class Pass {
		public:
			enum Type {
				Shadow,// 阴影通道
				Transparent, // 透明通道
				Main,// 主渲染通道
				SSAO,// 屏幕空间环境光遮蔽
				Depth, // 深度通道
				Color,// 颜色通道
				AddBlend, // 叠加混合通道
				Abstract// 抽象通道（可能用于扩展）
			};
		};

		virtual const IRenderPass::Pass::Type& type() const = 0;

	protected:
		IScene* mScene;
	};
}