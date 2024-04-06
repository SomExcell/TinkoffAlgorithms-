#include <iostream>
#include <vector>
#include <list>
#include <math.h>

int closestInWidth(int y, int x,const std::vector<std::vector<int>> &area)
{
    int result = 0;
    for (size_t i = x; i < area[0].size(); ++i)
    {
        if(area[y][i] == 0){break;}
        ++result;
    }
    return result;
}

int closestInHeight(int y,int x, const std::vector<std::vector<int>> &area)
{
    int result = 0;
    for (size_t i = y; i < area.size(); ++i)
    {
        if(area[i][x] == 0){break;}
        ++result;
    }
    return result;
}

void calculateDistances(std::vector<std::vector<std::pair<int,int>>> &distances, const std::vector<std::vector<int>> &area)
{
    for (size_t y = 1; y < area.size(); y++)
    {
        for (size_t x = 1; x < area[0].size(); ++x)
        {
            if(area[y][x] == 0){continue;}

            if(y != 1 && distances[y-1][x].first != 0){distances[y][x].first = distances[y-1][x].first - 1;}
            if(x != 1 && distances[y][x-1].second != 0){distances[y][x].second = distances[y][x-1].second -1;}

            if(distances[y][x].first == 0){distances[y][x].first = closestInHeight(y,x,area);}
            if(distances[y][x].second == 0){distances[y][x].second = closestInWidth(y,x,area);}
        }
    }
}

bool checkArea(int y, int x, int lengthSide, const std::vector<std::vector<std::pair<int,int>>> &distances)
{
    for (size_t i = x; i < x+lengthSide; ++i)
    {
        if(distances[y][i].first < lengthSide){return false;}
    }
    for (size_t i = y; i < y + lengthSide; ++i)
    {
        if(distances[i][x].second < lengthSide){return false;}
    }
    
    return true;
}

void findBiggestArea(const std::vector<std::vector<std::pair<int,int>>> &distances)
{
    int result = 0, lengthSide;
    int x,y;
    for (size_t i = 1; i < distances.size(); ++i)
    {
        for (size_t j = 1; j < distances[0].size(); ++j)
        {
            lengthSide = std::min(distances[i][j].first,distances[i][j].second);
            if(result <= lengthSide && checkArea(i,j,lengthSide,distances))
            {
                result = lengthSide;
                y = i,x = j;
            }
        }
    }
    std::cout << result << '\n' << y << ' ' << x;
}

int main()
{
    int n,m,value;
    std::cin >> n >> m;
    std::vector<std::vector<int>> area(n+1,std::vector<int>(m+1));
    std::vector<std::vector<std::pair<int,int>>> distances(n+1,std::vector<std::pair<int,int>>(m+1));

    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= m; ++j)
        {
            std::cin >> value;
            area[i][j] = value;
        }
    }

    calculateDistances(distances,area);
    findBiggestArea(distances);



	return 0;
}