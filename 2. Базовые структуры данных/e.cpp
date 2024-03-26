#include <iostream>
#include <stack>
#include <list>
#include <queue>

int main()
{
	std::stack<int> stop;
	std::vector<std::pair<int,int>> actions;
	std::pair<int,int> p{0,0};
	int count,value,valueOut = 1;
	std::cin >> count;
	for (size_t i = 0; i < count; i++)
	{
		std::cin >> value;
		stop.push(value);
		p.first = 1,p.second+=1;
		if(stop.top() == valueOut)
		{
			actions.push_back(p);
			p.first = 2,p.second = 0;
		}
		while(!stop.empty() && stop.top() == valueOut)
		{
			stop.pop();
			p.second+=1;
			valueOut++;
		}
		if(p.first == 2)
		{
			actions.push_back(p);
			p.second = 0;
		}
	}
	if(valueOut-1 != count)
	{
		std::cout << 0;
	}else{
		std::cout << actions.size() << std::endl;
		for (size_t i = 0; i < actions.size(); i++)
		{
			std::cout << actions[i].first << ' ' << actions[i].second << std::endl;
		}
	}
	return 0;
}