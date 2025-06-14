#pragma once
#include <MyGL/ICamera.h>

namespace MyGL {
	class Camera :public ICamera
	{
	public:
		Camera();

		void setPos(float x, float y, float z) override;

		float x() const override;

		float y() const override;

		float z() const override;

		float rotXY() const override;

		float rotXZ() const override;

		float distance() const override;

		void setAngles(float x, float y) override;

		void setDistance(float) override;

		void move(float x, float y) override;
	protected:
		float m_x;
		float m_y;
		float m_z;
		float m_distance;
		float m_rotXY;
		float m_rotXZ;
	};
}

