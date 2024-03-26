#include <iostream>
#include <vector>
#include <math.h>

int main()
{
    long count,querys;
    double value;
    std::cin >> count;
    long l = 1,r = count,m,res;
    std::string answer;
    bool ove = false;
    while(l<=r)
    {
        m = l + (r - l) / 2;
        std::cout << m << std::endl;
        fflush(stdout);
        std::cin >> answer;
        if(answer == ">=")
        {
            l = m + 1;
            res = m;
        }
        else{r = m - 1;}
    }
    std::cout << "! " << res;
    return 0;
}