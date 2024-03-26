#include <iostream>
#include <stack>

int main()
{
	std::stack<std::pair<int,int>> s;
	std::pair<int,int> p;
	int n,oper,value;
	std::cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> oper;
		if(oper == 1)
		{
			std::cin >> value;
			p.first = value;
			if(s.empty() || s.top().second > value)
			{
				p.second = value;
			}else
			{
				p.second = s.top().second;
			}
			s.push(p);
		}
		else if(oper == 2)
		{
			s.pop();
		}else
		{
			std::cout << s.top().second << std::endl;
		}
	}
	
}