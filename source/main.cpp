#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>

std::pair<int,int> distance(const int &cut, std::list<int> &goodCut)
{
    std::pair<int,int> indexAndDistance{-1,1e9};
    int dist = 1e9;
    for(const auto &i:goodCut)
    {
        dist = std::abs(cut-i);
        if(dist < indexAndDistance.second)
        {
            indexAndDistance.first = i,indexAndDistance.second = dist;
        }
    }
    return indexAndDistance;
}

void removeCut(std::list<int> &cuts,int index)
{
    auto it = cuts.begin();
    while(*it != index)
    {
        it++;
    }
    cuts.erase(it);
}

void sawing(std::list<int> &cuts,size_t lengthTimber)
{
    size_t sum = 0;
    std::list<int> goodCut;
    goodCut.push_back(lengthTimber/2);
    std::pair<int,int> distAndIndex,better{-1,1e9};
    int indexInCut;
    while(!cuts.empty())
    {
        for(const auto &i:cuts)
        {
            distAndIndex = distance(i,goodCut);
            if(distAndIndex.second < better.second)
            {
                indexInCut = i;
                better = distAndIndex;
            }
        }
        goodCut.push_back(distAndIndex.first/2);
        goodCut.push_back(distAndIndex.second+distAndIndex.second/2);
        removeCut(goodCut,distAndIndex.second);
        removeCut(cuts,indexInCut);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    size_t lengthTimber,countSawing;
    std::cin >> lengthTimber >> countSawing;
    std::list<size_t> cuts;
    for (size_t i = 0; i < countSawing; i++)
    {
        size_t value;
        std::cin >> value;
        cuts.push_back(value);
    }

    
    
    return 0;
}