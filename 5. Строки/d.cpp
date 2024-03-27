#include <iostream>
#include <math.h>

std::string searchMinStringImCycleString(const std::string &string)
{
    std::string minString = string,cycleString = string;

    for(int i = 0; i < string.size(); ++i)
    {
        cycleString = cycleString[string.size()-1] + cycleString.substr(0,string.size()-1);
        minString = std::min(minString,cycleString);
    }
    return minString;
}

int main()
{
    std::string string;

    std::cin >> string;
    std::cout << searchMinStringImCycleString(string);
    return 0;
}