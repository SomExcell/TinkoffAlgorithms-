#include <iostream>
#include <math.h>
#include <unordered_map>

struct Node
{
    int type = -1;
    int width = 1;
    int height = 1;
    int leftDiag = 1;
    int rightDiag = 1;
};

bool checkWidth(int x,int y,std::unordered_map<int,std::unordered_map<int,Node>> &area)
{
    int leftX = x,rightX = x,maxLen = 1;
    while(area[y].count(rightX+1) && area[y][rightX+1].type == area[y][x].type)
    {
        rightX+=1;maxLen++;
    }
    while(area[y].count(leftX-1) && area[y][leftX-1].type == area[y][x].type)
    {
        leftX-=1;maxLen++;
    }

    area[y][leftX].width = area[y][rightX].width = maxLen;

    if(maxLen >= 5){return true;}
    else{return false;}
}

bool checkHeight(int x,int y,std::unordered_map<int,std::unordered_map<int,Node>> &area)
{
    int downY = y,topY = y,maxLen = 1;
    while(area.count(downY + 1) && area[downY + 1][x].type == area[y][x].type)
    {
        downY+=1;maxLen++;
    }
    while(area.count(topY - 1) && area[topY - 1][x].type == area[y][x].type)
    {
        topY-=1;maxLen++;
    }
    area[topY][x].height = area[downY][x].height = maxLen;
    if(maxLen >= 5){return true;}
    else{return false;}
}

bool checkRightDiag(int x,int y,std::unordered_map<int,std::unordered_map<int,Node>> &area)
{
    int yTop = y,xTop = x,yDown = y,xDown = x,maxLen = 1;
    while(area.count(yTop-1) && area[yTop-1].count(xTop+1) && area[yTop-1][xTop+1].type == area[y][x].type)
    {
        yTop--,xTop++;maxLen++;
    }
    while(area.count(yDown+1) && area[yDown+1].count(xDown-1) && area[yDown+1][xDown-1].type == area[y][x].type)
    {
        yDown++,xDown--;maxLen++;
    }
    area[yTop][xTop].leftDiag = maxLen;
    area[yDown][xDown].leftDiag = maxLen;

    if(maxLen >= 5){return true;}
    else{return false;}
}

bool checkLeftDiag(int x,int y,std::unordered_map<int,std::unordered_map<int,Node>> &area)
{
    int yTop = y,xTop = x,yDown = y,xDown = x,maxLen = 1;

    while(area.count(yTop-1) && area[yTop-1].count(xTop-1) && area[yTop-1][xTop-1].type == area[y][x].type)
    {
        yTop--,xTop--;maxLen++;
    }
    while(area.count(yDown+1) && area[yDown+1].count(xDown+1) && area[yDown+1][xDown+1].type == area[y][x].type)
    {
        yDown++,xDown++;maxLen++;
    }
    area[yTop][xTop].leftDiag = maxLen;
    area[yDown][xDown].leftDiag = maxLen;

    if(maxLen >= 5){return true;}
    else{return false;}
}

bool check(int x,int y,std::unordered_map<int,std::unordered_map<int,Node>> &area)
{
    if(checkHeight(x,y,area) || checkWidth(x,y,area) || checkLeftDiag(x,y,area) || checkRightDiag(x,y,area))
    {
        return true;
    }
    else{return false;}
}

int main()
{
    int countSteps,x,y;
    bool first = false,second = false;
    std::cin >> countSteps;
    std::unordered_map<int,std::unordered_map<int,Node>> area;
    for (size_t i = 0; i < countSteps; i++)
    {
        if(first || second){std::cout << "Inattention\n";return 0;}
        std::cin >> x >> y;
        area[y][x].type = i % 2 + 1;
        if(check(x,y,area))
        {
            i % 2 == 0 ? first = true : second = true;
        }
    }
    if(!first && !second){std::cout << "Draw\n";}
    else if(first){std::cout << "First\n";}
    else if(second){std::cout << "Second\n";}
}

