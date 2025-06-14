#pragma once

namespace MyGL {
	template<typename T>
	class UniformArray {
	public:
		UniformArray()
			: m_data(nullptr), m_count(0) {
		}

		UniformArray(int count)
			: m_data(count > 0 ? new T[count]() : nullptr), m_count(count) {
		}

		~UniformArray() {
			delete[] m_data;
		}

		UniformArray(const UniformArray& other)
			: m_data(other.m_count > 0 ? new T[other.m_count] : nullptr), m_count(other.m_count) {
			if (m_data && other.m_data) {
				std::copy(other.m_data, other.m_data + m_count, m_data);
			}
		}

		UniformArray& operator=(const UniformArray& other) {
			if (this != &other) {
				delete[] m_data;
				m_count = other.m_count;
				m_data = m_count > 0 ? new T[m_count] : nullptr;
				if (m_data && other.m_data) {
					std::copy(other.m_data, other.m_data + m_count, m_data);
				}
			}
			return *this;
		}

		UniformArray(UniformArray&& other) noexcept
			: m_data(other.m_data), m_count(other.m_count) {
			other.m_data = nullptr;
			other.m_count = 0;
		}

		UniformArray& operator=(UniformArray&& other) noexcept {
			if (this != &other) {
				delete[] m_data;
				m_data = other.m_data;
				m_count = other.m_count;
				other.m_data = nullptr;
				other.m_count = 0;
			}
			return *this;
		}

		T& operator[](int index) {
			if (index < 0 || index >= m_count) {
				throw std::out_of_range("UniformArray index out of range");
			}
			return m_data[index];
		}

		const T& operator[](int index) const {
			if (index < 0 || index >= m_count) {
				throw std::out_of_range("UniformArray index out of range");
			}
			return m_data[index];
		}

		int size() const {
			return m_count;
		}

		T* data() {
			return m_data;
		}

		const T* data() const {
			return m_data;
		}

		void fill(const T& value) {
			if (m_data) {
				std::fill(m_data, m_data + m_count, value);
			}
		}

	private:
		T* m_data;
		int m_count;
	};
	template<class T>
	T* uniformArray(int location, int count) {
		if (count <= 0) {
			return nullptr;
		}
		return new T[count]();
	}
}
