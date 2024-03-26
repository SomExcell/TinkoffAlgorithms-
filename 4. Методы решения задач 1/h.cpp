#include <iostream>
#include <vector>
#include <algorithm>

struct Task
{
    long start;
    long end;
    long index;
};

int main()
{
	long count,start,end,points;
    std::cin >> count >> points;
    std::vector<Task> times(count);
    std::vector<long> result;
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> start >> end;
        times[i].start = start,times[i].end = start+end,times[i].index = i + 1;
    }
    sort(times.begin(),times.end(),[](auto a,auto b){return a.end < b.end;});
    end = 0;
    for (size_t i = 0; i < count; i++)
    {
        if(times[i].start >= end)
        {
            end = times[i].end;
            result.push_back(times[i].index);
        }
    }
    std::cout << points * result.size() << '\n' << result.size() << '\n';
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << ' ';
    }
    
    return 0;
}