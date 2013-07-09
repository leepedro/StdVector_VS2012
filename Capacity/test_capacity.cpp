#include <vector>
#include <iostream>
#include <sstream>


template <typename T>
void PrintCapacity(const std::vector<T> &buffer)
{
	std::cout << "Capacity = " << buffer.capacity() << ", Size = " << buffer.size() << std::endl;	
}

// Observe from 0 to count.
template <typename T>
void ObserveCapacity(::size_t count)
{
	std::vector<T> buffer1;
	for (auto I = 0; I != count; ++I)
	{
		buffer1.push_back(static_cast<T>(0));
		PrintCapacity(buffer1);
	}
}

// Observe from count1 to count2.
template <typename T>
void ObserveCapacity(::size_t count1, ::size_t count2)
{
	if (count1 > count2)
		throw std::invalid_argument("count1 must be smaller than count2.");
	std::vector<T> buffer1(count1);
	PrintCapacity(buffer1);
	while (buffer1.size() != count2)
	{
		buffer1.push_back(static_cast<T>(0));
		PrintCapacity(buffer1);
	}
}

int main(int argc, char *argv[])
{
	try
	{		
		if (argc == 1)
		{
			ObserveCapacity<unsigned char>(100);
		}
		else if (argc == 2)
		{
			::size_t count(0);
			std::istringstream iss(argv[1]);
			if (!(iss >> count))				
			{
				std::string errMsg("Invalid value: ");
				errMsg += argv[1];
				throw std::invalid_argument(errMsg.c_str());
			}
			ObserveCapacity<unsigned char>(count);
		}
		else if (argc==3)
		{
			::size_t count1(0), count2(0);
			std::istringstream iss1(argv[1]), iss2(argv[2]);
			if (!(iss1 >> count1) || !(iss2 >> count2))				
			{
				std::string errMsg("Invalid values: ");
				errMsg.append(argv[1]);
				errMsg.append(", ");
				errMsg.append(argv[2]);
				throw std::invalid_argument(errMsg.c_str());
			}
			ObserveCapacity<unsigned char>(count1, count2);
		}
		else
			throw std::invalid_argument("Too many arguments.");		
	}
	catch (const std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}