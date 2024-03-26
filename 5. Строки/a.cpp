#include <iostream>
#include <vector>
#include <math.h>

int main()
{
    long long countQueries,l1,r1,l2,r2,firstHash,secondHash,koef = 173;
	std::string str;
    std::cin >> str;
    std::vector<long long> hashSubStr(str.size()+1);
    std::vector<long long> powsKoef(str.size()+1);
    powsKoef[0] = 1;
    for (size_t i = 1; i <= str.size(); ++i)
    {
        hashSubStr[i] = (hashSubStr[i-1]*koef+(str[i-1]-96))%1000000007;
        powsKoef[i] = (koef * powsKoef[i-1])%1000000007; 
    }
    std::cin >> countQueries;
    for (size_t i = 0; i < countQueries; ++i)
    {
        std::cin >> l1 >> r1 >> l2 >> r2;
        firstHash = (hashSubStr[r1] + hashSubStr[l2-1] * powsKoef[r2-l2+1])%1000000007;
        secondHash = (hashSubStr[r2] + hashSubStr[l1-1] * powsKoef[r1-l1+1])%1000000007;
        if(firstHash == secondHash && r1-l1 == r2-l2)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
    
    return 0;
}