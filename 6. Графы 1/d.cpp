#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct GameArea
{
    GameArea()
    {
        for (size_t i = 0; i < 21; ++i)
        {
            for (size_t j = 0; j < 21; ++j)
            {
                area[i][j] = 1000000;
            }
        }
    }
    int x;
    int y;
    int finishX;
    int finishY;
    int size;
    std::vector<std::pair<int,int>> resultWay;
    std::vector<std::vector<int>> area{21,std::vector<int>(21)};
};

void searchMinWay(GameArea &area,const std::vector<std::pair<int,int>> &moves,std::vector<std::pair<int,int>> &way,int countMove)
{
    way.push_back({area.x,area.y});
    if(countMove>14){return;}
    ++countMove;
    area.area[area.x][area.y] = countMove;
    int x,y,z;
    if(area.x == area.finishX && area.y == area.finishY && (countMove < area.resultWay.size() || area.resultWay.size() == 0))
    {
        area.resultWay = way;
        return;
    }
    for(const auto &move:moves)
    {
        x = area.x + move.first,y = area.y + move.second;
        if(x  > 0 && x  <= area.size && y  > 0 && y  <= area.size && area.area[x][y] > countMove)
        {   
            area.x+=move.first,area.y+=move.second;
            searchMinWay(area,moves,way,countMove);
            way.pop_back();
            area.x -=move.first,area.y-=move.second;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::vector<std::pair<int,int>> moves{{-1,-2},{-2,-1},{1,-2},{2,-1},{-2,1},{-1,2},{2,1},{1,2}};
    std::vector<std::pair<int,int>> way;
    
    GameArea area;
    std::cin >> area.size >> area.x >> area.y >> area.finishX >> area.finishY;
    area.area[area.x][area.y] = 0;


    searchMinWay(area,moves,way,0);

    std::cout << area.resultWay.size()-1 << '\n';
    for (size_t i = 0; i < area.resultWay.size(); i++)
    {
        std::cout << area.resultWay[i].first << ' ' << area.resultWay[i].second << '\n';
    }
    

    return 0;
}