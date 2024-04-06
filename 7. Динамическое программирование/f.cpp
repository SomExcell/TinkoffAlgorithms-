#include <iostream>
#include <vector>
#include <list>
#include <math.h>

void biggestArea(const std::vector<std::vector<int>> &rectangle)
{
    int n = rectangle.size(),m = rectangle[0].size();
    std::vector<std::vector<int>> dp(n,std::vector<int>(m));
    int x, y;
    int maxSide = 0;

    for (size_t i = 0; i < n; i++)
    {
        dp[i][0] = rectangle[i][0];
        if(dp[i][0] >= maxSide)
        {
            maxSide = dp[i][0];
            y = i, x = 0;
        }
    }

    for (size_t i = 0; i < m; i++)
    {
        dp[0][i] = rectangle[0][i];
        if(dp[0][i] >= maxSide)
        {
            maxSide = dp[0][i];
            x = i, y = 0;
        }
    }

    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 1; j < m; j++)
        {
            if(rectangle[i][j] == 1)
            {
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = std::min(dp[i][j],dp[i-1][j-1])+1;
                if(dp[i][j] >= maxSide)
                {
                    y = i,x = j;
                    maxSide = dp[i][j];
                }
            }
        }
    }
    std::cout << maxSide << '\n' << y - maxSide + 2 << ' ' << x - maxSide + 2;
}


int main()
{
    int n,m,value;
    std::cin >> n >> m;
    std::vector<std::vector<int>> area(n+1,std::vector<int>(m+1));
    std::vector<std::vector<std::pair<int,int>>> distances(n,std::vector<std::pair<int,int>>(m));

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            std::cin >> value;
            area[i][j] = value;
        }
    }

    biggestArea(area);



	return 0;
}