/****************************************************
 *					Problem 1625B					*
 * https://codeforces.com/problemset/problem/1625/B *
 ****************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	//Capture Data
	unsigned short int nCases;
	std::cin >> nCases;
	while (nCases--)
	{
		unsigned int arrSize;
		std::vector<unsigned int> inputArr;
		std::cin >> arrSize;
		inputArr.reserve(arrSize);
		for (unsigned int i = 0; i < arrSize; ++i)
		{
			unsigned int temp;
			std::cin >> temp;
			inputArr.emplace_back(temp);
		}
		//Capture Finished

		//Processing Data
		std::vector<int> lastIndex(150000, -1);
		unsigned int bestDist = 0;
		for (unsigned int i = 0; i < arrSize; ++i)
		{
			if (lastIndex[inputArr[i]] != -1)
			{
				bestDist = (bestDist == 0 
					? i - lastIndex[inputArr[i]]
					: std::min(bestDist, i - lastIndex[inputArr[i]]));

			}
			lastIndex[inputArr[i]] = i;
			if (bestDist == 1) break;
		}
		//Finished Processing

		//Print Results
		std::cout << (bestDist == 0 ? "-1" : std::to_string(arrSize - bestDist)) << std::endl;
		//Finished Printing
	}
	return 0;
}