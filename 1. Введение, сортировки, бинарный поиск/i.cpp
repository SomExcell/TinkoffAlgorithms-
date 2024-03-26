#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    int indexZero = n-1,countUnits = 0,index;
    std::cout << 1 << ' ';
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> index;
        vec[index-1] = 1;
        countUnits+=1;
        if(index-1 == indexZero)
        {
            for (int j = indexZero; j >= 0; --j)
            {
                if(vec[j] == 0)
                {
                    indexZero = j;
                    break;
                }
                countUnits--;
            }
        }
        std::cout << countUnits + 1 << ' ';
    }
    
    return 0;
}