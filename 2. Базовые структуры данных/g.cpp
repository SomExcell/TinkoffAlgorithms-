#include <iostream>
#include <stack>
#include <list>
#include <queue>

int main()
{
	std::list<int> leftQue;
	std::list<int> rightQue;
	int count,value,mid;
	char c;
	std::cin >> count;
	for (size_t i = 0; i < count; i++)
	{
		std::cin >> c;
		if(c == '+')
		{
			std::cin >> value;
			rightQue.push_back(value);
			
		}else if(c == '-')
		{
			std::cout << leftQue.front() << std::endl;
			leftQue.pop_front();
		}else if(c == '*')
		{
			std::cin >> value;
			rightQue.push_front(value);
		}
		
		if(leftQue.size() < rightQue.size())
		{
			leftQue.push_back(rightQue.front());
			rightQue.pop_front();
		}
	}
}