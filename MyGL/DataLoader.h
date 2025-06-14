#pragma once

namespace MyGL {
	class DataLoader {
	public:
		template<typename T>
		class IAllocator {
		public:
			IAllocator() {}
		};

		template<typename T, typename N>
		class Allocator :public IAllocator<N> {
		public:
			Allocator() {}
		};

	};

}



