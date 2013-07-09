#include <vector>

namespace Imaging
{
	/* A template based image class is derived from std::vector<T> class.
	DESIGN GOAL:
	The values of data may be changed externally, but the dimension of data must be changed
	through designated functions such as constructors.
	Conclusion:
	This approach needs to require to override many functions in std::vector<T> class, which
	may have new functions in future. Instead, define an image class which includes a
	std::vector<T> object as a data block, and open its content to outside thorough pointers
	and iterators while the data block is hidden as a protected member.
	*/
	template <typename T>
	class Image : public std::vector<T>
	{
	public:
		// Types and constants.
		typedef T ValueType;
		typedef typename std::vector<T>::size_type SizeType;
		typedef typename std::vector<T>::iterator Iterator;
		typedef typename std::vector<T>::const_iterator ConstIterator;

		// Default constructors.
		Image(void);
		Image(const Image<T> &src);
		Image<T> &operator=(const Image<T> &src);

		// Custom constructors.
		Image(SizeType w, SizeType h, SizeType d);

		// Accessors.
		T &operator()(SizeType x, SizeType y);
		const T &operator()(SizeType x, SizeType y) const;

		// Overridden functions.
		void clear(void);

		// Overloaded Functions.
		void resize(SizeType w, SizeType h, SizeType d);

		// Custom functions.
		Iterator GetIterator(SizeType x, SizeType y);
		ConstIterator GetIterator(SizeType x, SizeType y) const;

		const SizeType &width, &height, &depth;

	protected:
		void CheckRange(SizeType x, SizeType y) const;
		SizeType GetOffset(SizeType x, SizeType y) const;

		SizeType width_, height_, depth_;

	private:
		// Disabled functions.
		void pop_back(void);
		void push_back(const T &val);
		void resize(SizeType count);
	};

	template <typename T>
	Image<T>::Image(void) : std::vector<T>(), width(width_), height(height_), depth(depth_),
		width_(0), height_(0), depth_(0) {}

	template <typename T>
	Image<T>::Image(const Image<T> &src) : std::vector<T>(src), width(width_), height(height_),
		depth(depth_), width_(src.width), height_(src.height), depth_(src.depth) {}

	template <typename T>
	Image<T> &Image<T>::operator=(const Image<T> &src)
	{
		std::vector<T>::operator(src);
		this->width_ = src.width;
		this->height_ = src.height;
		this->depth_ = src.depth;
		return *this;
	}

	template <typename T>
	Image<T>::Image(SizeType w, SizeType h, SizeType d) : std::vector<T>(w * h * d),
		width(width_), height(height_), depth(depth_), width_(w), height_(h), depth_(d) {}

	template <typename T>
	T &Image<T>::operator()(SizeType x, SizeType y)
	{
		this->CheckRange(x, y);
		return this->at(this->GetOffset(x, y));
	}

	template <typename T>
	const T &Image<T>::operator()(SizeType x, SizeType y) const
	{
		this->CheckRange(x, y);
		return this->at(this->GetOffset(x, y));
	}

	template <typename T>
	void Image<T>::clear(void)
	{
		this->std::vector<T>::clear();
		this->width_ = 0;
		this->height_ = 0;
		this->depth_ = 0;
	}

	template <typename T>
	void Image<T>::resize(SizeType w, SizeType h, SizeType d)
	{
		SizeType count = w * h * d;
		this->std::vector<T>::resize(count);
		this->width_ = w;
		this->height_ = h;
		this->depth_ = d;
	}

	template <typename T>
	typename Image<T>::Iterator Image<T>::GetIterator(SizeType x, SizeType y)
	{
		this->CheckRange(x, y);
		return this->begin() + this->GetOffset(x, y);
	}

	template <typename T>
	typename Image<T>::ConstIterator Image<T>::GetIterator(SizeType x, SizeType y) const
	{
		this->CheckRange(x, y);
		return this->cbegin() + x * this->depth + y * this->width * this->depth;
	}

	template <typename T>
	void Image<T>::CheckRange(SizeType x, SizeType y) const
	{
		if (x >= this->width || y >= this->height)
			throw std::out_of_range("(x,y) is out of range.");
	}

	template <typename T>
	typename Image<T>::SizeType Image<T>::GetOffset(SizeType x, SizeType y) const
	{
		return x * this->depth + y * this->width * this->depth;
	}

}
