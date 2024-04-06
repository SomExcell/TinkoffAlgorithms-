#include <iostream>
#include <vector>
#include <list>
#include <math.h>

void dfs(int x,int y,std::vector<std::vector<long>> &area,const std::vector<std::pair<int,int>> &moves)
{
    area[y][x]+=1;
    if(y == area.size()-1 && x == area[0].size()-1){return;}
    for(const auto &pair:moves)
    {
        if(x + pair.first < area[0].size() && x + pair.first > 0 && y + pair.second < area.size() && y + pair.second > 0)
        {
            dfs(x+pair.first,y+pair.second,area,moves);
        }
    }
}

int main()
{
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<long>> area(n+1,std::vector<long>(m+1));
    std::vector<std::pair<int,int>> moves{{2,-1},{2,1},{1,2},{-1,2}};
    dfs(1,1,area,moves);
    std::cout << area[n][m];

	return 0;
}