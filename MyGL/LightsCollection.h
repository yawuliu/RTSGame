#pragma once

#include <vector>
#include <MyGL/ILightsCollection.h>
#include <MyGL/ILight.h>

namespace MyGL {
	class  LightsCollection :public ILightsCollection {
	public:
		class pimpl {
		public:
			pimpl() = default;
			virtual  ~pimpl() = default;
		protected:
			std::vector<ILight*> lights;
		};

	public:
		LightsCollection(IScene& s);
		virtual ~LightsCollection();
		void add(ILight& l);
		void del(ILight& l);
		void remove(ILight& l);
		IScene* scene();
		int size();
		ILight* at(unsigned int id);
	protected:
		LightsCollection::pimpl* data;
		IScene* mscene;
	};
}