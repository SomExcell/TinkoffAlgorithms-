#include <iostream>
#include <vector>
#include <list>
#include <math.h>

int main()
{
    long count,lengthJump;
    std::cin >> count >> lengthJump;
    std::vector<long> prices(count+1);
    for (size_t i = 2; i < count; ++i)
    {
        long value;
        std::cin >> value;
        prices[i] = value;
    }

    long place = 1;
    long long sum = 0;
    std::vector<long> places{place};
    while(place != count)
    {
        long long max = -10000;
        long newPlace = 0;
        for (size_t i = 1; i <= lengthJump && place + i <= count; ++i)
        {
            if(max < prices[place+i])
            {
                newPlace = place+i;
                max = prices[place+i];
            }
            if(max > 0){break;}
        }
        sum+=max;
        place = newPlace;
        places.push_back(place);
    }

    std::cout << sum << '\n' << places.size()-1 << '\n';
    for (size_t i = 0; i < places.size(); ++i)
    {
        std::cout << places[i] << ' ';
    }
    
    

    
    

	return 0;
}