#include "Camera.h"

using namespace MyGL;

Camera::Camera()
	: m_x(0.0f), m_y(0.0f), m_z(0.0f),
	m_rotXY(0.0f), m_rotXZ(0.0f), m_distance(1.0f) {
}

void Camera::setPos(float x, float y, float z) {
	m_x = x;
	m_y = y;
	m_z = z;
}

float Camera::x() const {
	return m_x;
}

float Camera::y() const {
	return m_y;
}

float Camera::z() const {
	return m_z;
}

float Camera::rotXY() const {
	return m_rotXY;
}

float Camera::rotXZ() const {
	return m_rotXZ;
}

float Camera::distance() const {
	return m_distance;
}

void Camera::setAngles(float x, float y) {
	m_rotXY = x;
	m_rotXZ = y;
}

void Camera::setDistance(float d) {
	m_distance = d;
}

void Camera::move(float x, float y) {
	m_x += x;
	m_y += y;
}
