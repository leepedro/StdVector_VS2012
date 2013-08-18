#include <vector>
#include <iostream>

void Print(const std::vector<int> &data)
{
	for (auto it = data.begin(), itEnd = data.end(); it != itEnd; ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void Increase(std::vector<int> &data)
{
	for (auto it = data.begin(), itEnd = data.end(); it != itEnd; ++it)
		*it = *it + 1;
}

int main(void)
{
	std::vector<int> data(3, 0);
	Print(data);	// Should be '0 0 0'. Good!
	Increase(data);
	Print(data);	// Should be '1 1 1'. Good!
	Increase(data);
	Print(data);	// Should be '2 2 2'. Good!
	Increase(data);
	Print(data);	// Should be '3 3 3'. Good!

	// resize() function appends two elements and set the value as given.
	// However, resize() function does NOT set the existing elements.
	data.resize(5, 0);
	Print(data);	// Should be '3 3 3 0 0'. Good!
	Increase(data);
	Print(data);	// Should be '4 4 4 1 1'. Good!

	// resize() function remove the last element, but it does NOT set the existing values as given.
	data.resize(4, 0);
	Print(data);	// Should be '4 4 4 1'. Good!
	Increase(data);
	Print(data);	// Should be '5 5 5 2'. Good!

	// If you want to change the size of a vector with given initial values, use assign() function instead.
	data.assign(3, 0);
	Print(data);	// Should be '0 0 0'. Good!
}