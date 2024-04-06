#include <iostream>
#include <vector>
#include <list>
#include <math.h>

void maxSubsequence(const std::vector<long> &sequence)
{
    std::vector<long> result;
    std::vector<long> preResult;
    long value;
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        //if(result.size() > sequence.size() - i){break;}
        if(sequence[i] < 1){continue;}
        value = sequence[i];
        preResult.push_back(value);
        for (size_t j = i + 1; j < sequence.size(); ++j)
        {
            if(value < sequence[j])
            {
                value = sequence[j];
                preResult.push_back(value);
            }
        }
        if(preResult.size() > result.size())
        {
            result = std::move(preResult);
        }
        preResult.clear();
    }
    
    std::cout << result.size() << '\n';
    for (size_t i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << ' ';
    }
    
}

int main()
{
    int count;
    std::cin >> count;
    std::vector<long> sequence(count);
    for (long &i:sequence)
    {
        std::cin >> i;
    }
    
    maxSubsequence(sequence);


	return 0;
}