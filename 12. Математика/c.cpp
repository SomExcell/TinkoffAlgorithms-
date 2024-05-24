#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <math.h>

int main() 
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::vector<std::pair<int,bool>> values(1e6);
    for (size_t i = 0; i < 1e6; i++)
    {
        values[i].first = i;values[i].second = true;
    }

    int left = 2,right;
    int countOper = 0;
    for (size_t i = 2; i < 1e6; i++)
    {
        countOper++;
        if(!values[i].second){continue;}
        right = i;
        for (size_t j = i + i; j < 1e6; j +=i)
        {
            values[j].second = false;
            countOper++;
        }
    }
    
    int value;
    std::cin >> value;
    while(left + right != value)
    {
        if(left + right < value)
        {
            left+=1;
            while(!values[left].second){left+=1;}
        }
        else
        {
            right-=1;
            while(!values[right].second){right-=1;}
        }
    }

    std::cout << left << ' ' << right;
    
    
    return 0;
}