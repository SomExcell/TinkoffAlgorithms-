#include <iostream>
#include <vector>

bool binarySearch(const std::vector<int> &vec,const int &query)
{
    int l = 0,r = vec.size()-1,m;
    while(l<=r)
    {
        m = l + (r - l) / 2;
        if(vec[m] == query){return true;}
        if(vec[m] < query){l = m + 1;}
        else{r = m - 1;}
        
    }
    return false;
}

int main()
{
    int count,querys,value;
    std::cin >> count >> querys;
    std::vector<int> values(count);
    for(int &i:values)
    {
        std::cin >> value;
        i = value;
    }
    for (size_t i = 0; i < querys; i++)
    {
        std::cin >> value;
        if(binarySearch(values,value)){std::cout << "YES\n";}
        else{std::cout << "NO\n";}
    }
    
    return 0;
}