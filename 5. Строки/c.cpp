#include <iostream>
#include <vector>
#include <set>

void getCyclesString(const std::string &string, std::set<std::string> &cyclesStrings)
{
    std::string cycleString = string;
    int mid = 1,index,countCycleString = 1;
    cyclesStrings.insert(cycleString);
    while(countCycleString < string.size())
    {
        index = 0;
        for (size_t i = mid; i < string.size(); ++i)
        {
            cycleString[index] = string[i];
            ++index;
        }
        for (size_t i = 0; i < mid; ++i)
        {
            cycleString[index] = string[i];
            ++index;
        }
        cyclesStrings.insert(cycleString);
        ++countCycleString;
        ++mid;
    }
}

size_t hashString(const std::string &string)
{
    size_t result = 0, coeffHash = 277, divider = 1e9+7;
    for (size_t i = 1; i <= string.size(); ++i)
    {
        result = (result * coeffHash + string[i-1]) % divider;
    }
    return result;
}

void hashesForStrings(std::vector<size_t> &hashes, const std::set<std::string> &strings)
{
    size_t numberString = 0;
    for(const std::string &string:strings)
    {
        hashes[numberString] = hashString(string);
        ++numberString;
    }
}

void fillPows(std::vector<size_t> &powsForHash)
{
    size_t coeffHash = 277,divider = 1e9+7;
    powsForHash[0] = 1;
    for (size_t i = 1; i < powsForHash.size(); ++i)
    {
        powsForHash[i] = (powsForHash[i-1] * coeffHash) % divider;
    }
}

void hashFile(const std::string &string, std::vector<size_t> &hashForFile,std::vector<size_t> &powsForHash)
{
    size_t coeffHash = 277, divider = 1e9+7;
    fillPows(powsForHash);
    for (size_t i = 1; i <= string.size(); ++i)
    {
        hashForFile[i] = (hashForFile[i-1] * coeffHash + string[i-1]) % divider;
    }
}

size_t countCycleStringInText(const std::string &text,const std::string &cycleString)
{
    std::set<std::string> cyclesStrings;
    getCyclesString(cycleString,cyclesStrings);
    std::vector<size_t> hashesCyclesString(cyclesStrings.size());
    hashesForStrings(hashesCyclesString,cyclesStrings);

    std::vector<size_t> hashForFile(text.size()+1);
    std::vector<size_t> powsForHashFile(text.size()+1);
    hashFile(text,hashForFile,powsForHashFile);

    size_t hashSubStringLeft,hashSubStringRight,hashSubString, divider = 1e9+7, counter = 0;
    for(size_t hashString:hashesCyclesString)
    {
        for (size_t i = cycleString.size(); i <= text.size(); ++i)
        {
            hashSubStringLeft = (hashForFile[i-cycleString.size()] * powsForHashFile[cycleString.size()]) % divider;
            hashSubStringRight = hashForFile[i];
            if(hashSubStringRight < hashSubStringLeft)
            {
                hashSubStringRight+=divider;
            }
            hashSubString = hashSubStringRight - hashSubStringLeft;
            if(hashSubString == hashString)
            {
                ++counter;
            }
        }
    }
    return counter;

}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::string mainString,cycleString;

    std::cin >> mainString >> cycleString;

    std::cout << countCycleStringInText(mainString,cycleString);

    return 0;
}