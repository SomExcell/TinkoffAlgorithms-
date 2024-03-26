#include <iostream>
#include <stack>
#include <list>

int main()
{

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int count,result = 0,value,countRemoved = 0,lastVal;
	std::cin >> count;
	std::stack<int> s;
	bool last = false;
	for (size_t i = 0; i < count; i++)
	{
		std::cin >> value;
		if(last && value == lastVal)
		{
			result++;
			continue;
		}
		last = false;
		s.push(value);
		while(!s.empty() && s.top() == value)
		{
			s.pop();
			countRemoved++;
		}
		if(countRemoved < 3)
		{
			while (countRemoved > 0)
			{
				s.push(value);
				countRemoved--;
			}
		}
		if(countRemoved >= 3)
		{
			result += countRemoved;
			last = true;
		}
		lastVal = value;
		countRemoved = 0;
	}
	std::cout << result;
}