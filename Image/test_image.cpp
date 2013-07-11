#include "image.h"

#include <iostream>

template <typename T>
void test(void)
{
	Imaging::Image<T> img1;
	Imaging::Image<T> img2(4, 4, 1);
	Imaging::Image<T>::SizeType w = img2.width;
	Imaging::Image<T>::SizeType h = img2.height;
	Imaging::Image<T>::SizeType d = img2.depth;

	img2(0, 0) = static_cast<T>(1);
	T value = img2(0, 0);

	img2.clear();
	img1.resize(3, 2, 1);

	Imaging::Image<T>::Iterator it = img1.GetIterator(1, 1);
}

int main(void)
{
	try
	{
		test<unsigned char>();
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}