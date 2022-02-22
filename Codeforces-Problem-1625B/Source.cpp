/****************************************************
 *					Problem 1625B					*
 * https://codeforces.com/problemset/problem/1625/B *
 ****************************************************/

#include <iostream>
#include <vector>

template<typename T, typename Functor>
std::vector<unsigned int> GetAllIndecies(std::vector<T> input, Functor lambda)
{
	std::vector<unsigned int> result;
	for (unsigned int i = 0; i < input.size(); ++i)
	{
		if (lambda(input[i])) result.emplace_back(i);
	}
	return result;
}

int main()
{
	//Capture Data
	unsigned short int nCases;
	std::cin >> nCases;
	for (unsigned short int i = 0; i < nCases; ++i)
	{
		unsigned int arrSize;
		std::vector<unsigned int> inputArr;
		std::cin >> arrSize;
		inputArr.reserve(arrSize);
		for (int j = 0; j < arrSize; ++j)
		{
			unsigned int temp;
			std::cin >> temp;
			inputArr.emplace_back(temp);
		}
		//Capture Finished
	}
	return 0;
}