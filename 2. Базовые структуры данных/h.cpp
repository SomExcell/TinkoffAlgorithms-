#include <iostream>
#include <stack>
#include <vector>

std::vector<long> prefixSum(std::vector<long> vec)
{
    std::vector<long> result(vec.size());
	result[0] = vec[0];
    for (size_t i = 1; i < vec.size(); ++i)
	{
		result[i] = result[i-1]+vec[i];
	}
	
    return result;
}

std::vector<std::pair<int,int>> smallerValue(std::vector<long> vec)
{
	std::stack<std::pair<int,int>> first;
	std::stack<std::pair<int,int>> second;
	int len = vec.size();
	std::vector<std::pair<int,int>> result(len,std::pair<int,int>{-1,len});
	std::pair<int,int> p;
	for (size_t i = 0; i < len; ++i)
	{
		while(!first.empty() && first.top().first >= vec[i])
		{
			first.pop();
		}
		if(!first.empty())
		{
			result[i].first = first.top().second;
		}else
		{
			result[i].first = -1;
		}
		while(!second.empty() && second.top().first >= vec[len - i - 1])
		{
			second.pop();
		}
		if(!second.empty())
		{
			result[len-i-1].second = len-second.top().second-1;
		}else
		{
			result[len-i-1].second = len;
		}
		p.first = vec[i],p.second = i;
		first.push(p);
		p.first = vec[len-i-1],p.second = i;
		second.push(p);
	}
	return result;
}


int main()
{
	long count,value,result = 0,x,y,preRes;
	std::cin >> count;
	std::vector<long> vec(count);
	for(int i = 0; i < count; ++i)	
	{
		std::cin >> value;
		vec[i] = value;
	}
	std::vector<std::pair<int,int>> smaller = smallerValue(vec);
	std::vector<long> sums = prefixSum(vec);
	for (size_t i = 0; i < count; ++i)
	{
		value = vec[i];
		x = smaller[i].first;
		y = smaller[i].second;
		if(x!= -1)
		{
			preRes = (sums[y-1] - sums[x]) * value;
		}
		else
		{
			preRes = sums[y-1] * value;
		}
		result = std::max(result,preRes);
	}
	std::cout << result;
	
}