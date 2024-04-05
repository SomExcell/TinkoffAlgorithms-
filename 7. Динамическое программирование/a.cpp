#include <iostream>
#include <vector>
#include <math.h>

int main()
{
    int count;
    std::cin >> count;
    std::vector<int> prices(count+1);
    std::vector<int> sums(count+1);

    for (size_t i = 1; i < count+1; ++i)
    {
        int value;
        std::cin >> value;
        prices[i] = value;
    }
    sums[1] = prices[1];

    for (size_t i = 2; i < count+1; ++i)
    {
        sums[i] = std::min(sums[i-1],sums[i-2])+prices[i];
    }
    std::cout << sums[count];

	return 0;
}