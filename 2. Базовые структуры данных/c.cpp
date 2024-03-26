#include <iostream>
#include <stack>
#include <queue>
#include <list>

int main()
{
	std::stack<int> s;
	std::string expression;
	getline(std::cin, expression);
	int value = 0,lVal,rVal;
	bool sign = false;
	for (size_t i = 0; i < expression.size(); ++i)
	{
		if(expression[i] > 47 )
		{
			value += expression[i] - 48;
			value*=10;
		}
		else if(i+1 < expression.size() && expression[i] == '-' && expression[i+1] != ' ')
		{
			sign = true;
		}
		else if(expression[i] < 48 && expression[i] != ' ')
		{
			rVal = s.top();
			s.pop();
			lVal = s.top();
			s.pop();
			if(expression[i] == '+')
			{
				s.push(lVal + rVal);
			}else if(expression[i] == '-')
			{
				s.push(lVal - rVal);
			}else if(expression[i] == '*')
			{
				s.push(lVal * rVal);
			}
			i++;
		}
		else if(expression[i] == ' ')
		{
			if(sign)
			{
				value*=-1;
				sign = false;
			}
			value/=10;
			s.push(value);
			value = 0;
		}
	}
	std::cout << s.top();
}