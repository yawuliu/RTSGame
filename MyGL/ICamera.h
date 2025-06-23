#pragma once

#include "DisableCopy.h"

namespace MyGL {
	class ICamera : public DisableCopy {
	public:
		ICamera() = default;

		virtual ~ICamera() = default;

		virtual void setPos(float x, float y, float z) = 0;

		virtual float x() const = 0;

		virtual float y() const = 0;

		virtual float z() const = 0;

		virtual float rotXY() const = 0;

		virtual float rotXZ() const = 0;

		virtual void setAngles(float x, float y) = 0;

		virtual void setDistance(float) = 0;

		virtual void move(float x, float y) = 0;

		virtual float distance() const = 0;
	};
}



