#include <vector>
#include <iostream>

template <typename T>
void Print(const std::vector<T> &src)
{
	std::cout << "size = " << src.size() << std::endl;
	for (const auto &elem: src)
		std::cout << elem << ' ';
	std::cout << std::endl;
}

void Copy(void)
{
	std::cout << "Using copy constructors" << std::endl;
	std::vector<int> i1(3, 1), i2;
	std::vector<int> i3 = i1;
	i2 = i1;
	std::cout << "Before changing original values" << std::endl;
	Print(i1);
	Print(i2);
	Print(i3);
	i1.assign(4, 2);
	std::cout << "After changing original values" << std::endl;
	Print(i1);
	Print(i2);
	Print(i3);
}

void Move(void)
{
	std::cout << "Using move constructors" << std::endl;
	std::vector<int> i1(3, 1), i2;
	Print(i1);
	std::vector<int> i3 = std::move(i1);
	Print(i1);
	Print(i3);
	i1.assign(4, 2);
	Print(i1);
	Print(i3);
}

int main(void)
{
	Copy();
	Move();
}
