#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

int indexOne(size_t val)
{
    size_t counter = 1;
    int result = 0;
    while(counter <= val){counter*=2;result+=1;}
    return result - 1;
}

std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r+=(n%2==0 ?"0":"1"); n/=2;}
    return r;
}

int main() 
{
    std::string answer;
    size_t price,countM,countVar;
    std::cin >> price >> countM;
    countM*=2;
    
    std::vector<size_t> monets(countM);
    for (size_t i = 0; i < countM; i+=2)
    {
        size_t val;
        std::cin >> val;
        monets[i] = monets[i+1] = val;
    }
    
    std::sort(monets.begin(),monets.end());
    countVar = std::pow(2,countM);
    std::vector<size_t> dp(countVar);
    std::vector<size_t> countOnes(countVar);
    for (size_t i = 1; i < countVar; i++)
    {
        size_t index = indexOne(i);
        size_t indexPrev = indexOne(i-1);
        dp[i] = dp[i ^ int(std::pow(2,index))]+ monets[index];
        countOnes[i]+=1;
        countOnes[i]+=countOnes[i^int(std::pow(2,index))];
    }
    int result = -1;
    size_t index;
    int countOne = 1e9;
    for (size_t i = 1; i < countVar; i++)
    {
        if(dp[i] > price && result != 1){result = 0;}
        else if(dp[i] == price && countOnes[i] < countOne)
        {
            countOne = countOnes[i];
            result = 1;index = i;
        }
    }
    if(result == 1)
    {
        int count = 0;
        std::string str = toBinary(index);
        for (size_t i = 0; i < str.size(); i++)
        {
            if(str[i] == '1'){++count;}
        }
        
        answer += std::to_string(count) + '\n';
        
        for (size_t i = 0; i < str.size(); i++)
        {
            if(str[i] == '1'){answer+=  std::to_string(monets[i]) + ' ';}
        }
        
    }
    else
    {
        answer = std::to_string(result);
    }

    std::cout << answer;

    return 0;
}