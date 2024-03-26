#include <iostream>
#include <vector>
#include <algorithm>

bool can(const std::vector<long> &values,long distance,long countSegments)
{
    unsigned long long sum = 0;
    long occupiedSegmentsCount = 1;
    for(const long& value:values)
    {
        sum +=value;
        if(sum <= distance){continue;}
        occupiedSegmentsCount++;
        sum = value;
        if(sum > distance){return false;}
    }
    return occupiedSegmentsCount <= countSegments;

}

int main()
{
	long countValues, countSegments;
    unsigned long long l = 1, r = 0,mid;
    std::cin >> countValues >> countSegments;
    std::vector<long> values(countValues);
    for(long &value:values)
    {
        std::cin >> value;
        r+=value;
    }
    while(r - l>1)
    {
        mid = (l+r)/2;
        if(can(values,mid,countSegments))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    std::cout << r;
    return 0;
}