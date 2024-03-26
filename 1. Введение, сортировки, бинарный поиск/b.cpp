#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

long binarySearch(const std::vector<long> &vec,const long &query)
{
    long l = 0,r = vec.size()-1,m,i=100;
    while(i>0)
    {
        m = (l+r) / 2;
        if(vec[m] == query){return m;}
        if(vec[m] < query){l = m;}
        else{r = m;}
        i--;
    }
    if(m+1<vec.size() && abs(query - vec[m]) > abs(query - vec[m+1]))
    {
        m+=1;
    }
    else if(m-1>=0 && abs(query - vec[m]) >= abs(query-vec[m-1]))
    {
        m -=1;
    }
    return m;
}

int main()
{
    long count,querys,value;
    std::cin >> count >> querys;
    std::vector<long> values(count);
    for(long &i:values)
    {
        std::cin >> value;
        i = value;
    }
    for (size_t i = 0; i < querys; i++)
    {
        std::cin >> value;
        std::cout << values[binarySearch(values,value)] << std::endl;
    }
    
    return 0;
}