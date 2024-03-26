#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    long count,value,l,r;
    std::cin >> count;
    std::vector<std::pair<long,long>> sums(count,std::pair<long,long>{});

    std::cin >> value;
    sums[0].first = value,sums[0].second = value;
    for (size_t i = 1; i < count; i++)
    {
        std::cin >> value;
        sums[i].first = sums[i-1].first + value;
        sums[i].second = sums[i-1].second ^ value;
    }

    std::cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> value >> l >> r;
        if(value == 1)
        {
            if(l == 1)
            {
                std::cout << sums[r-1].first;
            }
            else
            {
                std::cout << sums[r-1].first - sums[l-2].first;
            }
        }
        else if(value == 2)
        {
            if(l == 1)
            {
                std::cout << sums[r-1].second;
            }
            else
            {
                value = sums[r-1].second ^ sums[l-2].second;
                std::cout << value;
            }
        }
        std::cout << '\n';
    }
    return 0;
}
