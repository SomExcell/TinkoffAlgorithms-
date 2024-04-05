#include <iostream>
#include <vector>
#include <math.h>

long countPermutations(int length)
{
    std::vector<long> perA(length+1);
    std::vector<long> perB(length+1);
    std::vector<long> perC(length+1);

    perA[1] = perB[1] = perC[1] = 1;

    for (size_t i = 2; i <= length; ++i)
    {
        perA[i] = perB[i-1] + perC[i-1];
        perB[i] = perA[i-1] + perB[i-1] + perC[i-1];
        perC[i] = perA[i-1] + perB[i-1] + perC[i-1];
    }
    return perA[length] + perB[length] + perC[length];
}

int main()
{
    long count;
    std::cin >> count;
    std::cout << countPermutations(count);

	return 0;
}