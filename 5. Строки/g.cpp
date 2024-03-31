#include <iostream>
#include <vector>
#include <math.h>

size_t divider = 1e9+7;
size_t mod = 16769023;
size_t coeff = 2029;

size_t maxLengthSegment(const std::vector<size_t> &firstArray, const std::vector<size_t> &secondArray)
{
    size_t maxLengthSegment = 0;
    size_t lengthSubStr = 1,minLength = std::min(firstArray.size(),secondArray.size())-1;
    size_t firstHash,secondHash;
    for (size_t length = 1; length <= minLength; ++length)
    {
        for (size_t i = 1; i <= firstArray.size()-length; ++i)
        {
            for (size_t j = 1; j <= secondArray.size()-length; ++j)
            {

                firstHash = firstArray[i+length-1] - firstArray[i-1];
                secondHash = secondArray[j+length-1] - secondArray[j-1];
                if(firstHash == secondHash)
                {
                    if(maxLengthSegment < length){maxLengthSegment = length;}
                }
            }
        }
    }
    

    return maxLengthSegment;
}

void hashNumberArray(std::vector<size_t> &array,std::vector<size_t> newValues)
{
    size_t value;
    for (size_t i = 1; i < array.size(); i++)
    {
        std::cin >> value;
        value = newValues[value];
        array[i] = (array[i-1] + value);
    }
}

void hashValues(std::vector<size_t> &newValues)
{
    newValues[0] = 108301; 
    for (size_t i = 1; i < 100001; ++i)
    {
        newValues[i] = ((newValues[i-1] * (i * coeff) % mod) % mod);
        coeff = (coeff * 131) % mod;
        mod = (mod * 727) % divider;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::vector<size_t> newValues(100001);
    hashValues(newValues);

    size_t countValues;
    std::cin >> countValues;
    std::vector<size_t> firstArray(countValues+1);
    hashNumberArray(firstArray,newValues);
    
    
    std::cin >> countValues;
    std::vector<size_t> secondArray(countValues+1);
    hashNumberArray(secondArray,newValues);
    
    std::cout << maxLengthSegment(firstArray,secondArray);
    
    return 0;
}