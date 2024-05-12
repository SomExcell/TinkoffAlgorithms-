#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int main() 
{
    std::string str;
    std::cin >> str;
    int n = str.size();
    std::vector<std::vector<std::string>> dp(n,std::vector<std::string>(n));
    for (size_t len = 1; len <= n; len++)
    {
        for (size_t left = 0; left + len - 1 < n; left++)
        {
            int right = left + len - 1;
            std::string min = str.substr(left,len);
            if(len > 4)
            {
                for(int right1 = left; right1 < right;right1++)
                {
                    int left2 = right1 + 1;
                    std::string substr = dp[left][right1] + dp[left2][right];
                    if(substr.size() < min.size())
                    {
                        min = substr;
                    } 
                }
                for (size_t p = 1; p < len; p++)
                {
                    if(len % p == 0)
                    {
                        bool period = true;
                        for (size_t i = left + p; i <= right; i++)
                        {
                            if(str[i] != str[i-p])
                            {
                                period = false;
                                break;
                            }
                        }
                        if(period)
                        {
                            std::string substr = std::to_string(len/p) + "(" + dp[left][left+p-1]+")";
                            if(substr.size() < min.size())
                            {
                                min = substr;
                            }
                        }
                        
                    }
                }
            }
            dp[left][right] = min;
        }
    }
    std::cout << dp[0][n-1];

    return 0;
}