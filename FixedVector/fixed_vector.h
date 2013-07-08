#include <vector>

namespace Imaging
{
	template <typename T>
	class Array : public std::vector<T>
	{
	public:
		Array(void);
		explicit Array(::size_t n);
		Array(::size_t n, const T &val);
		Array(const Array<T> &src);
		Array<T> &operator=(const Array<T> &src);

	private:
		void push_back(const T &val);
		void pop_back(void);
	};

	template <typename T>
	Array<T>::Array(void) : std::vector<T>() {}

	template <typename T>
	Array<T>::Array(::size_t n) : std::vector<T>(n) {}

	template <typename T>
	Array<T>::Array(::size_t n, const T &val) : std::vector<T>(n, val) {}

	template <typename T>
	Array<T>::Array(const Array<T> &src) : std::vector<T>(src) {}

	template <typename T>
	Array<T> &Array<T>::operator=(const Array<T> &src)
	{
		std::vector<T>::operator=(src);
		return *this;
	}

}