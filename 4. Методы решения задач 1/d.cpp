#include <iostream>
#include <vector>
#include <math.h>

int main()
{
    unsigned long n,k,left,right,mid,count,copyMid;
    std::cin >> n >> k;
    left = 1,right = n*n;
    count = 0;
    while(left < right)
    {
        mid = (left + right)/2;
        copyMid = mid;
        for (size_t i = 1; i < n+1; ++i)
        {
            copyMid = mid/i;
            count += std::min(copyMid,n);
        }
        if(count < k)
        {
            left = mid + 1;
        }else
        {
            right = mid;
        }
        count= 0;
    }
    std::cout << left;
    
    return 0;
}