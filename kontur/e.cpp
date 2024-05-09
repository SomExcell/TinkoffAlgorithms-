#include <iostream>
#include <vector>
#include <unordered_map>

bool move(std::unordered_map<long,std::unordered_map<long,int>> &walls,std::unordered_map<long,long> &widthWalls,std::unordered_map<long,long> &heightWalls, long &x, long &y,const char &direction, const long &countSteps)
{
    int up = 0,right = 0;
    if(direction == 'R' || direction == 'L')
    {
        direction == 'R' ? right = 1 : right = -1;
    }else
    {
        direction == 'U' ? up = 1 : up = -1;
    }
    if(right != 0 && !heightWalls.count(y))
    {
        x+=(countSteps*right);
        return true;
    }
    else if(up != 0 && !widthWalls.count(x))
    {
        y+=(countSteps*up);
        return true;
    }
    for (size_t i = 0; i < countSteps; ++i)
    {
        x+=right,y+=up;
        if(walls[y].count(x)){return false;}
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    long n,x,y,countSteps;
    std::unordered_map<long,std::unordered_map<long,int>> walls;
    std::unordered_map<long,long> widthWalls;
    std::unordered_map<long,long> heightWalls;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> x >> y;
        widthWalls[x] = 1;
        heightWalls[y] = 1;
        walls[y][x] = 1;
    }

    x = 0, y = 0;
    char direction;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> direction >> countSteps;
        if(!move(walls,widthWalls,heightWalls,x,y,direction,countSteps)){std::cout << "Stop " << i + 1; return 0;}
    }
    std::cout << "Complete";
    
    
    return 0;
}