#include "Light.h"

using namespace MyGL;

Light::Light(QList<Light*> lights)
	: m_shadowCast(0), m_lights(lights)
{
	m_direction[0] = m_direction[1] = m_direction[2] = 0.0f;
	m_position[0] = m_position[1] = m_position[2] = 0.0f;
}

void Light::setShadowCast(int shadowCast)
{
	m_shadowCast = shadowCast;
}

void Light::setDirection(float x, float y, float z)
{
	m_direction[0] = x;
	m_direction[1] = y;
	m_direction[2] = z;
}

void Light::setPosition(float x, float y, float z)
{
	m_position[0] = x;
	m_position[1] = y;
	m_position[2] = z;
}


