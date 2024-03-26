#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int count,value,first = 0,last = 0;
	std::vector<int> que(1000000);
	std::vector<int> place(100000);
	std::cin >> count;
	for (size_t i = 0; i < count; ++i)
	{
		std::cin >> value;
		if(value == 1)
		{
			std::cin >> value;
			place[value] = last;
			que[last] = value;
			++last;
		}
		else if(value == 2)
		{
			++first;
		}
		else if(value == 3)
		{
			--last;
		}
		else if(value == 4)
		{
			std::cin >> value;
			std::cout << place[value]-first << '\n';
		}
		else if(value == 5)
		{
			std::cout << que[first] << '\n';
		}
	}
}