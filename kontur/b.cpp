#include <iostream>
#include <vector>
#include <math.h>

int countChanges(const std::string &firstStr, const std::string &secondStr)
{
    int count = 0;
    for (size_t i = 0; i < firstStr.size(); i++)
    {
        if(firstStr[i] != secondStr[i]){++count;}
    }
    return count;
}

void countDividers(int value, std::vector<int> &dividers)
{
    for (size_t i = 1; i <= value; i++)
    {
        if(value % i == 0)
        {
            dividers.push_back(i);
        }
    }
}

std::string makeString(int length,int lengthBetweenChars,char firstChar)
{
    std::string str;
    str.resize(length);
    char c = firstChar;
    int countCharsAdded = 0;
    for (size_t i = 0; i < length; ++i)
    {
        str[i] = c;
        countCharsAdded++;
        if(countCharsAdded == lengthBetweenChars)
        {
            if(c == '1'){c = '0';}
            else{c = '1';}
            countCharsAdded = 0;
        }
    }
    return str;
}

int main()
{
    std::string str;
    std::cin >> str;
    int result = str.size(),preRes = 0;
    std::vector<int> dividers;
    countDividers(str.size(),dividers);
    for (size_t i = 0; i < dividers.size(); i++)
    {
        preRes = countChanges(str,makeString(str.size(),dividers[i],'0'));
        if(result > preRes){result = preRes;}
        preRes = countChanges(str,makeString(str.size(),dividers[i],'1'));
        if(result > preRes){result = preRes;}
    }
    std::cout << result;

    return 0;
}