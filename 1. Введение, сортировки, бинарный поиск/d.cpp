#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

void binarySearch(const long double &query)
{
    long double l = 0,r = query,x,c,i=1000;
    while(i>0)
    {
        x = (l+r) / 2;
        c = pow(x,2) + sqrt(x+1);
        if(c == query){break;}
        if(c < query){l = x;}
        else{r = x;}
        i--;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << x;
}

int main()
{
    long double value;
    std::cin >> value;
    binarySearch(value);
    
    return 0;
}