#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <deque>

int main()
{
    long count,lengthJump;
    std::cin >> count >> lengthJump;
    std::vector<long> prices(count+1);
    for (size_t i = 2; i < count; ++i)
    {
        long value;
        std::cin >> value;
        prices[i] = value;
    }
    std::deque<std::pair<long,int>> maxs;
    std::vector<std::pair<long,int>> dp(count+1,std::pair<long,int>{});
    
    dp[1].first = 0,dp[1].second = 0;
    maxs.push_back({0,1});

    for (size_t i = 2; i <= count; i++)
    {
        dp[i].first = maxs.front().first + prices[i];
        dp[i].second = maxs.front().second;
        while(maxs.size() > 0 && dp[i].first > maxs.back().first)
        {
            maxs.pop_back();
        }
        if(maxs.size() > 0 && i - lengthJump == maxs.front().second)
        {
            maxs.pop_front();
        }
        maxs.push_back({dp[i].first,i});
    }
    std::deque<int> result;
    result.push_front(count);
    std::cout << dp[count].first << '\n';
    int index = count;
    while(index != 1)
    {
        index = dp[index].second;
        result.push_front(index);
    }
    
    std::cout << result.size() - 1  << '\n';
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ' ';
    }
    
	return 0;
}