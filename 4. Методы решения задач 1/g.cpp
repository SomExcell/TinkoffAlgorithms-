#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	long count,hour1,min1,sec1,hour2,min2,sec2,sec,needWork,res = 0,nowWork = 0;
    std::cin >> count;
    needWork = count;
    std::vector<int> times(86400);
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> hour1 >> min1 >> sec1 >> hour2 >> min2 >> sec2;
        if(hour1 == hour2 && min1 == min2 && sec1 == sec2){needWork -=1;continue;}
        else if(hour1 < hour2)
        {
            times[sec1+min1*60+hour1*60*60] +=1;
            times[sec2+min2*60+hour2*60*60] -=1;
        }
        else if(hour1 > hour2)
        {
            times[sec1+min1*60+hour1*60*60] +=1;
            times[0]+=1;
            times[sec2+min2*60+hour2*60*60] -=1;
        }
    }
    
    for (size_t i = 0; i < 86400; i++)
    {
        nowWork+=times[i];
        if(nowWork == needWork){res+=1;}
    }
    std::cout << res;

    return 0;
}