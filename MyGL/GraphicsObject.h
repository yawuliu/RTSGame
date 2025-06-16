#pragma once

#include <string>
#include "MyGL/IGraphicsObject.h"
#include "IData.h"

namespace MyGL {
	class IModel;

	class IScene;

	class IShader;

	class StdMaterial;

	class ITexture2d;

	class GraphicsObject : public IGraphicsObject {
	public:
		GraphicsObject(MyGL::IScene* scene);

		GraphicsObject(MyGL::IScene* scene, const std::string& src);

		~GraphicsObject();

		MyGL::StdMaterial* material();

		void setModel(MyGL::IModel*);

		void setMaterial(MyGL::StdMaterial*);

		void setPosition(float x, float y, float z);

		void setVisible(bool v);

		void setSize(float x, float y, float z);

		void setAlvaysVisible(bool);

		MyGL::IModel* model();


		GameObjectClass::View* getObject();

		void setPositionF(float x, float y, float z);

		void setSize(float x, float y, float z, const double* base);

		void setRotate(float r);

		void setRotateXY(float r);

		float rotateAngle() const;

		float x() const override;

		float y() const override;

		float z() const override;

	protected:
		MyGL::IShader* extractTextures(GameObject* obj);

		MyGL::IShader* extractTextures(const GameObjectClass::View&,
			GameObject* obj,
			MyGL::StdMaterial* material,
			MyGL::IModel* model);

		MyGL::ITexture2d* textureFromData(const std::string& view,
			const char* postFix,
			bool mode, GameObject* obj);

		void initFromSrc(MyGL::GraphicsObject&,
			const GameObjectClass::View&,
			GameObject* gameObj);

		void initFromSrc(GameObject* obj);

		void setModelEvent(GameObject* obj);

		MyGL::IShader* getShadowShader(MyGL::GraphicsObject& obj,
			const GameObjectClass::View&);
	public:
		// 新增成员变量
		MyGL::IScene* m_scene = nullptr;
		MyGL::IModel* m_model = nullptr;
		MyGL::StdMaterial* m_material = nullptr;
		float m_x = 0.0f;
		float m_y = 0.0f;
		float m_z = 0.0f;
		float m_rotate = 0.0f;
		float m_rotateXY = 0.0f;
		bool m_visible = true;
		bool m_alvaysVisible = false;
		float m_sizeX = 1.0f;
		float m_sizeY = 1.0f;
		float m_sizeZ = 1.0f;

		// 通过 IGraphicsObject 继承
		bool isAlvaysVisible() const override;
		IModelInfo* modelInfo() const override;
		void delObjectEvent(IGraphicsObject*) override;
		void addObjectEvent(IGraphicsObject*) override;
		float xSize() const override;
		float ySize() const override;
		float zSize() const override;
		void setRotateX(float) override;
		void setRotateY(float) override;
		void setRotateZ(float) override;
		float xRotation() override;
		float yRotation() override;
		float zRotation() override;
	};
}


