#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <deque>

void countChangesInString(const std::string &firstString,const std::string &secondString,std::vector<std::vector<int>> &dp)
{
    for (size_t i = 0; i < firstString.size(); ++i)
    {
        for (size_t j = 0; j < secondString.size(); ++j)
        {
            int value = INT32_MAX;
            if(firstString[i] == secondString[j])
            {
                value = dp[i][j];
            }
            if(i > 0 && j > 0 && firstString[i] == secondString[j-1] && firstString[i-1] == secondString[j])
            {
                value = std::min(dp[i-1][j-1]+1,value);
            }
            if(firstString[i] != secondString[j])
            {
                value = std::min(std::min(std::min(dp[i+1][j],dp[i][j+1]),dp[i][j])+1,value);
            }
            dp[i+1][j+1] = value;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::string firstString,secondString;
    std::cin >> firstString >> secondString;
    
    
    std::vector<std::vector<int>> dp(firstString.size()+1,std::vector<int>(secondString.size()+1));
    for (size_t i = 0; i <= firstString.size(); ++i)
    {
        dp[i][0] = i;
    }
    for (size_t j = 0; j <= secondString.size(); j++)
    {
        dp[0][j] = j;
    }
    
    countChangesInString(firstString,secondString,dp);
    std::cout << dp[firstString.size()][secondString.size()];
	return 0;
}