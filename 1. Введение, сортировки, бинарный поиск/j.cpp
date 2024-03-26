#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

int main()
{
    long count,n,m,l,r,vSum,t,d,hSum,lVal,rVal,tVal,dVal,lSum,rSum,tSum,dSum,mid,prevMid,vRes,hRes;
    std::cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> n >> m;
        vSum = 0, hSum = 0;
        l = 1,r = m,t = 1, d = n;
        lVal = (2+m*n-m)*n/2;
        rVal = lVal + (m-1) * n;
        tVal = m * (m + 1) / 2;
        dVal = tVal + m * m * (n-1);

        while(l<=r)
        {
            mid = (l+r)/2;
            lSum = (lVal + lVal + n*(mid-1))*mid/2;
            rSum = (rVal + rVal - n*(m - mid-1))*(m-mid)/2;
            if(lSum < rSum)
            {
                l = mid;
            }else{
                r = mid;
            }
            if(prevMid == mid){break;}
            prevMid = mid;
        }
        vRes = r;
        vSum = abs(lSum-rSum);
        if(l-1>=1)
        {
            lSum = (lVal + lVal + n*((l-1)-1))*(l-1)/2;
            rSum = (rVal + rVal - n*(m - r+1))*(m-r+2)/2;
            if(abs(lSum-rSum) <= vSum)
            {
                vSum = abs(lSum-rSum);
                vRes = r-1;
            }
        }
        if(r+1<=m)
        {
            lSum = (lVal + lVal + n*((l+1)-1))*(l+1)/2;
            rSum = (rVal + rVal - n*(m - r - 1))*(m-r)/2;
            if(abs(lSum-rSum) < vSum)
            {
                vSum = abs(lSum-rSum);
                vRes = r+1;
            }
        }
        prevMid = -1;
        while(t<=d)
        {
            mid = (t+d)/2;
            tSum = (tVal + tVal + m*m*(mid-1))*mid/2;
            dSum = (dVal + dVal - m*m*(n-mid-1))*(n-mid)/2;
            if(tSum < dSum)
            {
                t = mid;
            }else{
                d = mid;
            }
            if(prevMid == mid){break;}
            prevMid = mid;
        }
        hRes = d;
        hSum = abs(dSum-tSum);
        if(t-1>=1)
        {
            tSum = (tVal + tVal + m*m*(t-1-1))*(t-1)/2;
            dSum = (dVal + dVal - m*m*(n-d+1))*(n-d+2)/2;
            if(abs(tSum-dSum) <= hSum)
            {
                hSum = abs(tSum-dSum);
                hRes = d-1;
            }
        }
        if(d+1<=n)
        {
            tSum = (tVal + tVal + m*m*(t+1-1))*(t+1)/2;
            dSum = (dVal + dVal - m*m*(n-d-1))*(n-d)/2;
            if(abs(tSum-dSum) < hSum)
            {
                hSum = abs(tSum-dSum);
                hRes = d+1;
            }
        }
        prevMid = -1;
        if(m!=1 && vSum <= hSum)
        {
            std::cout << "V " << vRes; 
        }else if (n!=1 && vSum > hSum){
            std::cout << "H " << hRes;
        }
        std::cout << std::endl;

    }
    
    
    return 0;
}