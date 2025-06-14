#pragma once

namespace MyGL {
	class IScene;

	class IRenderPass {
	public:
		IRenderPass(IScene* s);

		class Pass {
		public:
			enum Type {
				Shadow,// ��Ӱͨ��
				Transparent, // ͸��ͨ��
				Main,// ����Ⱦͨ��
				SSAO,// ��Ļ�ռ价�����ڱ�
				Depth, // ���ͨ��
				Color,// ��ɫͨ��
				AddBlend, // ���ӻ��ͨ��
				Abstract// ����ͨ��������������չ��
			};
		};

		virtual const IRenderPass::Pass::Type& type() const = 0;

	protected:
		IScene* mScene;
	};
}