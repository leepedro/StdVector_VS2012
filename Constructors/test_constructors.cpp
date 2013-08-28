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
	std::vector<int> i1(3, 1), i2, i4(2, 2);
	i2 = i1;	// i1 values are COPIED to i2.
	Print(i1);
	Print(i2);
	std::vector<int> i3 = std::move(i1);	// This line makes i1 empty.
	Print(i1);
	Print(i2);
	Print(i3);
	i1.assign(4, 2);	// This line does NOT change i2 or i3.
	Print(i1);
	Print(i2);
	Print(i3);
	Print(i4);
	i4 = std::move(i2);	// This line remove original i4 elements and move i2 elements to i4.
	Print(i2);
	Print(i4);
}

int main(void)
{
	Copy();
	Move();
}
