#pragma once

#include <QList>

namespace MyGL {
	class Light {
	public:
		Light(QList<Light*>);

		void setShadowCast(int);

		void setDirection(float, float, float);

		void setPosition(float, float, float);
	private:
		int m_shadowCast;
		float m_direction[3];
		float m_position[3];
		QList<Light*> m_lights;
	};
}


