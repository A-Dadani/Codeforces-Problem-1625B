/****************************************************
 *					Problem 1625B					*
 * https://codeforces.com/problemset/problem/1625/B *
 ****************************************************/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

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

template<typename T>
std::vector<std::pair<T, T>> GetAllPairs(std::vector<T> input)
{
	std::vector<std::pair<T, T>> result;
	for (unsigned int i = 0; i < input.size() - 1; ++i)
	{
		for (unsigned int j = i + 1; j < input.size(); ++j)
		{
			result.emplace_back(input[i], input[j]);
		}
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
		for (unsigned int j = 0; j < arrSize; ++j)
		{
			unsigned int temp;
			std::cin >> temp;
			inputArr.emplace_back(temp);
		}
		//Capture Finished

		//Processing Data
		std::vector<bool> shouldBeChecked(arrSize, true);
		unsigned int currMaxPossibleLength = 0; //If no pair of arrays exists this variable is going to store 0 which we'll substitute with a -1 for print later
		for (unsigned int j = 0; j < arrSize; ++j)
		{
			if (!shouldBeChecked[j]) continue; //So we don't double check stuff which would be a waste of time and memory
			auto allOccurenceIndecies = GetAllIndecies(inputArr, [j, &inputArr](unsigned int i) { return inputArr[j] == i; }); //Capturing by reference without consting is dangerous but i'm lazy
			for (const auto& e : allOccurenceIndecies) shouldBeChecked[e] = false;
			if (allOccurenceIndecies.size() < 2) continue; //Skip if no pairs can be formed
			for (const auto& currPair : GetAllPairs(allOccurenceIndecies))
			{
				currMaxPossibleLength = std::max(currMaxPossibleLength, std::min(currPair.first, currPair.second) + arrSize - std::max(currPair.first, currPair.second));
			}
		}
		//Finished Processing

		//Printing Results
		std::cout << (currMaxPossibleLength == 0 ? "-1" : std::to_string(currMaxPossibleLength)) << std::endl;
		//Finished Printing
	}
	return 0;
}