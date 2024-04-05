#include <iostream>
#include <vector>
#include <math.h>

int main()
{
    int countCity,countWays;
    std::cin >> countCity >> countWays;

    const int INF = 1e9;
    std::vector<std::vector<int>> dist(countCity+1,std::vector<int>(countCity+1,INF));

    for (size_t i = 0; i <= countCity; ++i)
    {
        dist[i][i] = 0;
    }
    
    for (size_t i = 0; i < countWays; ++i)
    {
        int a,b,weight;
        std::cin >> a >> b >> weight;
        dist[a][b] = weight;
        dist[b][a] = weight;
    }

    for(int v = 1; v <= countCity; ++v)
    {
        for (int i = 1; i <= countCity; ++i)
        {
            for (int j = 1; j <= countCity; ++j)
            {
                if(dist[i][v] != INF && dist[v][j] != INF && dist[i][j] > dist[i][v] + dist[v][j])
                {
                    dist[i][j] = dist[i][v] + dist[v][j];
                }
            }
        }
    }
    
    int bestCity = 0;
    long minWay = INF;

    for (size_t i = 1; i <= countCity; ++i)
    {
        long maxWay = 0;
        for (size_t j = 1; j <= countCity; ++j)
        {
            if(dist[i][j] > maxWay){maxWay = dist[i][j];}
        }
        if(maxWay < minWay)
        {
            bestCity = i,minWay = maxWay;
        }
    }

    std::cout << bestCity;

    return 0;
}