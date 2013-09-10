#include <vector>

int main(void)
{
	std::vector<int> data1(3);
	auto it_1 = data1.begin();
	it_1++;	// it_1: 0 -> 1
	it_1++;	// it_1: 1 -> 2
	it_1++;	// it_1: 2 -> 3 == data1.end()
	it_1++;	// This line throws an assert because it_1 became more than data1.end();
	it_1++;
}