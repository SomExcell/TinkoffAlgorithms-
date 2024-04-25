#include <iostream>
#include <math.h>
#include <deque>
#include <vector>

int main()
{
    std::deque<std::pair<long long,long long>> mins;
    long long countDays, term;
    std::cin >> countDays >> term;
    std::vector<long long> dp(countDays);
    std::vector<long long> prices(countDays);
    for(auto &i:prices)
    {
        std::cin >> i;
    }
    dp[0] = 1;
    mins.push_back({prices[0],0});
    long long sum = prices[0];
    for (size_t i = 1; i < countDays; ++i)
    {
        long long lastDay = i - term;
        while(!mins.empty() && lastDay >= mins.front().second)
        {
            mins.pop_front();
        }
        while(!mins.empty() && prices[i] <= mins.back().first)
        {
            mins.pop_back();
        }
        mins.push_back({prices[i],i});
        dp[mins.front().second]+=1;
        sum+=mins.front().first;
    }
    std::cout << sum << '\n';
    for (const auto &i:dp)
    {
        std::cout << i << ' ';
    }
    
    
}

