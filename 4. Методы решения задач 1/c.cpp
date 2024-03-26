#include <iostream>
#include <vector>
#include <algorithm>

bool can(const std::vector<long> &coordinatesStall,long distance,long cowCount)
{
    long occupiedStallCount = 1, lastOccupiedStallCoord = coordinatesStall[0];
    for(const long& pos:coordinatesStall)
    {
        if(lastOccupiedStallCoord + distance > pos){continue;}
        occupiedStallCount++;
        lastOccupiedStallCoord = pos;
    }
    return occupiedStallCount >= cowCount;
}

int main()
{
	long stallCount, cowCount;
    std::cin >> stallCount >> cowCount;
    std::vector<long> coordinatesStall(stallCount);
    for(long &i:coordinatesStall)
    {
        std::cin >> i;
    }

    int l = 0, r = 1e9,mid;
    while(l + 1<r)
    {
        mid = (l+r)/2;
        if(can(coordinatesStall,mid,cowCount))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    std::cout << l;
    return 0;
}