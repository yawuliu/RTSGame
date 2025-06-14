#pragma once

#include <QString>
#include "graphis/gamescene.h"

namespace MyGL {
	class MyGL_XmlData {
	public:
		MyGL_XmlData(GameScene*);

		void load(const QString&);
	};
}