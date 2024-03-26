#include <iostream>
#include <stack>
#include <queue>
#include <list>

int main()
{
	std::queue<int> que;
	std::list<int> mins;
	int n,k,value;
	std::cin >> n >> k;
	for (int i = 0; i < k && i < n; ++i)
	{
		std::cin >> value;
		que.push(value);
		while(!mins.empty() && mins.back() > value)
		{
			mins.pop_back();
		}
		mins.push_back(value);
	}
	std::cout << mins.front() << ' ';
	for (int i = n-k; i > 0; --i)
	{
		if(que.front() == mins.front())
		{
			mins.pop_front();
		}
		que.pop();
		std::cin >> value;
		que.push(value);
		while(!mins.empty() && mins.back() > value)
		{
			mins.pop_back();
		}
		mins.push_back(value);
		std::cout << mins.front() << ' ';
	}
	
}