#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int lengthLog,countCuts;
    std::cin >> lengthLog >> countCuts;
    std::vector<int> cuts;
    cuts.push_back(0);
    for (size_t i = 0; i < countCuts; i++)
    {
        int val;
        std::cin >> val;
        cuts.push_back(val);
    }
    cuts.push_back(lengthLog);
    countCuts+=2;
    std::vector<std::vector<int>> dp(countCuts,std::vector<int>(countCuts));
    for (size_t i = 1; i < countCuts; i++)
    {
        for (int j = i-2; j >= 0; j--)
        {
            dp[j][i] = 1e9;
            for (size_t k = j+1; k < i; k++)
            {
                dp[j][i] = std::min(dp[j][i],dp[j][k]+dp[k][i]);
            }
            dp[j][i] += cuts[i] - cuts[j];
        }
    }
    std::cout << dp[0][countCuts-1];
    
    return 0;
}
