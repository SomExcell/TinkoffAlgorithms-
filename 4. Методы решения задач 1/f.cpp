#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	long count,l,r,sum;
    std::cin >> count;
    std::vector<std::pair<long,bool>> coordinates(count*2,std::pair<long,bool>{});
    for (size_t i = 0; i < count*2; i+=2)
    {
        std::cin >> l >> r;
        coordinates[i].first = l, coordinates[i].second = true;
        coordinates[i+1].first = r,coordinates[i+1].second = false;
    }
    sort(coordinates.begin(),coordinates.end(),[](auto a,auto b){return a.first < b.first;});
    long countStart = 0,startValue = -1,result = 0;
    for (size_t i = 0; i < count*2; ++i)
    {
        if(coordinates[i].second)
        {
            ++countStart;
            if(startValue == -1){startValue = coordinates[i].first;}
        }
        else if(!coordinates[i].second)
        {
            --countStart;
        }
        if(countStart == 0)
        {
            result += coordinates[i].first - startValue;
            startValue = -1;
        }
    }
    std::cout << result;
    
    return 0;
}