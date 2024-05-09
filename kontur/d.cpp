#include <iostream>
#include <vector>
#include <math.h>

void changeString(std::string &str,const std::vector<long long> &sumsOnSegments, const std::vector<char> &chars)
{
    long long x = 0;
    long long c;
    for (size_t i = 0; i < str.size(); ++i)
    {
        x+=sumsOnSegments[i];
        c = str[i];
        if(c < 91){c = (c - 65)*2+1;}
        else{c = (c - 97)*2;}
        c+=x;
        c %=52;
        str[i] = chars[c];
    }
}

void fillChars(std::vector<char> &chars)
{
    char c = 'a';
    for (size_t i = 0; i < 52; i+=2)
    {
        chars[i] = c;
        c++;
    }
    c = 'A';
    for (size_t i = 1; i < 52; i+=2)
    {
        chars[i] = c;
        c++;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
    
    std::vector<char> chars(52);
    std::string str;
    long long count,l,r,x;
    fillChars(chars);

    std::cin >> str;
    std::vector<long long> sumsOnSegments(str.size());

    std::cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> l >> r >> x;
        sumsOnSegments[l-1]+=x;
        if(r<str.size()){sumsOnSegments[r]-=x;}
    }
    changeString(str,sumsOnSegments,chars);
    std::cout << str;
    
    return 0;
}