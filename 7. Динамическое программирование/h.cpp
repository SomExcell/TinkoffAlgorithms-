#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <deque>

void maxSubsequence(const std::vector<long> &sequence,std::vector<int> &lengthesForSequence,std::pair<int,int> &maxLengthAndIndex)
{
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        lengthesForSequence[i] = 1;
        for (size_t j = 0; j < i; ++j)
        {
            if(sequence[j] < sequence[i] && lengthesForSequence[j] + 1 > lengthesForSequence[i])
            {
                lengthesForSequence[i] = lengthesForSequence[j] + 1;
                if(lengthesForSequence[i] > maxLengthAndIndex.first)
                {
                    maxLengthAndIndex.first = lengthesForSequence[i];
                    maxLengthAndIndex.second = i;
                }
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    int count;
    std::cin >> count;
    std::vector<long> sequence(count);
    std::vector<int> lengthesForSequence(count);
    for (long &i:sequence)
    {
        std::cin >> i;
    }
    std::pair<int,int> maxLengthAndIndex = {1,0};
    maxSubsequence(sequence,lengthesForSequence,maxLengthAndIndex);

    int lengthSubSequence = maxLengthAndIndex.first;
    int prevIndex = maxLengthAndIndex.second;
    std::cout << lengthSubSequence << '\n';
    std::deque<long> result;
    result.push_front(sequence[prevIndex]);
    for (int i = prevIndex; i >= 0; --i)
    {
        if(sequence[i] < sequence[prevIndex] && lengthesForSequence[i]+1 == lengthesForSequence[prevIndex])
        {
            result.push_front(sequence[i]);
            prevIndex = i;
        }
    }
    
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ' ';
    }
    

	return 0;
}