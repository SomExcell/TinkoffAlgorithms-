#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <math.h>

size_t culcGCD(size_t first,size_t second)
{
    size_t greater = std::max(first,second);
    size_t smaller = std::min(first,second);
    while(greater % smaller != 0)
    {
        size_t copy;
        copy = greater%smaller;
        greater = smaller;
        smaller = copy;
    }
    return smaller;
}

int main() 
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    size_t first,second;
    std::cin >> first >> second;
    size_t gcd = culcGCD(first,second);
    std::cout << first * second / gcd;
    
    return 0;
}