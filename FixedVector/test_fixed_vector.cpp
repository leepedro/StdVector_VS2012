#include "fixed_vector.h"

#include <iostream>


template <typename T>
void test(void)
{
	std::vector<T> a1;
	Imaging::Array<T> b1;

	std::vector<T> a2(1);
	Imaging::Array<T> b2(2);
	a2[0] = 2;
	a2.push_back(1);
	b2[0] = 2;
	//b2.push_back(1);

	std::vector<T> a3(a2);
	Imaging::Array<T> b3(b2);

	a1 = a3;
	b1 = b3;
}


int main(void)
{
	try
	{
		test<unsigned char>();		
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exception." << std::endl;
	}
}