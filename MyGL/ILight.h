#pragma once

namespace MyGL {
    class ILight {
    public:
        ILight() = default;

		virtual  ~ILight() = default;// 0
		//virtual  ~ILight() = 0;// `
		virtual void setPosition(double,double,double) = 0;//  2
		virtual void x() = 0;// 3
		virtual void y() = 0;// 4
		virtual void z() = 0;// 5
		virtual void setShadowCast(bool) = 0;// 6
		virtual void isShadowCaster() = 0;// 7
		virtual void setDirection(double,double,double) = 0;// 8
		virtual void dirX() = 0;// 9
		virtual void dirY() = 0;// 10
		virtual void dirZ() = 0;//11
		virtual void upset() = 0;// 12
		virtual void dirTransform() = 0;// 13
		virtual void hasOccluder() = 0;// 14
		virtual void occluder() = 0;// 15
		virtual void isDeferred() = 0;// 16
		virtual void setDeferred(bool) = 0;// 17
    };

}


