#if !defined(COORDINATE_H)
#define COORDINATE_H

#include <array>

template <typename T, ::size_t N>
class Cartesian : public std::array<T, N>
{
public:
	//Cartesian(void);
	//Cartesian(const Cartesian<T, N> &src);
	//Cartesian<T, N> &operator=(const Cartesian<T, N> &src);
};

//template <typename T, ::size_t N>
//Cartesian<T, N>::Cartesian(void) : std::array<T, N>() {}
//
//template <typename T, ::size_t N>
//Cartesian<T, N>::Cartesian(const Cartesian<T, N> &src) : std::array<T, N>(src) {}
//
//template <typename T, ::size_t N>
//Cartesian<T, N> &Cartesian<T, N>::operator=(const Cartesian<T, N> &src)
//{
//	this->std::array<T, N>::operator=(src);
//	return *this;
//}

template <typename T>
class Cartesian2D : public std::array<T, 2>
{
public:
	Cartesian2D(void);
	Cartesian2D(const Cartesian2D<T> &src);
	Cartesian2D<T> &operator=(const Cartesian2D<T> &src);

	Cartesian2D(T x, T y);
	
	T &x, &y;
};

template <typename T>
Cartesian2D<T>::Cartesian2D(void) : std::array<T, 2>(), x(at(0)), y(at(1)) {}

template <typename T>
Cartesian2D<T>::Cartesian2D(const Cartesian2D &src) : std::array<T, 2>(src), x(at(0)), y(at(1)) {}

template <typename T>
Cartesian2D<T> &Cartesian2D<T>::operator=(const Cartesian2D<T> &src)
{
	this->std::array<T, 2>::operator=(src);
	return *this;
}

template <typename T>
Cartesian2D<T>::Cartesian2D(T x_val, T y_val) : std::array<T, 2>(), x(at(0)), y(at(1))
{
	this->x = x_val;
	this->y = y_val;
}

#endif
