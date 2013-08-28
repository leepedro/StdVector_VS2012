#include <vector>

template <typename T>
class Wrapper
{
public:
	Wrapper(void);
	Wrapper(const Wrapper<T> &src);
	Wrapper<T> &operator=(const Wrapper<T> &src);

	void Assign(typename std::vector<T>::size_type length, T value);
	void MoveTo(Wrapper<T> &dst);
	void MoveFrom(std::vector<T> &&src);

	const std::vector<T> &data;

protected:
	std::vector<T> data_;
};

template <typename T>
Wrapper<T>::Wrapper(void) : data(data_) {}

template <typename T>
Wrapper<T>::Wrapper(const Wrapper<T> &src) : data(data_), data_(src.data) {}

template <typename T>
Wrapper<T> &Wrapper<T>::operator=(const Wrapper<T> &src)
{
	Wrapper<T> temp(src);
	// NOTE: class modifier works on class level instead of object level.
	// In other words, two DIFFERENT OBJECTS of the SAME CLASS can access each others'
	// PRIVATE members!!!
	std::swap(this->data_, temp.data_);	// data_ is protedted ?!?!
	return *this;
}

template <typename T>
void Wrapper<T>::Assign(typename std::vector<T>::size_type length, T value)
{
	this->data_.assign(length, value);
}

template <typename T>
void Wrapper<T>::MoveTo(Wrapper<T> &dst)
{
	dst.MoveFrom(std::move(this->data_));
}

template <typename T>
void Wrapper<T>::MoveFrom(std::vector<T> &&src)
{
	// Well...
	this->data_ = std::move(src);	// std::move() must be here.
}