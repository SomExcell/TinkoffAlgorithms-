#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>

size_t coeffHash = 277,divider = 1e9+7;

void fillPows(std::vector<size_t> &powsForHash)
{
    powsForHash[0] = 1;
    for (size_t i = 1; i < powsForHash.size(); ++i)
    {
        powsForHash[i] = (powsForHash[i-1] * coeffHash) % divider;
    }
}

void hashFile(const std::string &string, std::vector<size_t> &hashForFile,std::vector<size_t> &powsForHash)
{
    fillPows(powsForHash);
    for (size_t i = 1; i <= string.size(); ++i)
    {
        hashForFile[i] = (hashForFile[i-1] * coeffHash + string[i-1]) % divider;
    }
}

size_t hashSubStr(const std::vector<size_t> &hashString,const std::vector<size_t> &powsForHash,size_t leftIndex,size_t rightIndex)
{
    size_t hashSubStr,leftHash,rightHash;
    leftHash = (hashString[leftIndex-1]*powsForHash[rightIndex-leftIndex+1]) % divider;
    rightHash = hashString[rightIndex];
    if(rightHash < leftHash)
    {
        rightHash += divider;
    }
    hashSubStr = rightHash - leftHash;
    return hashSubStr;
}

void hashCycleString(const std::string &string, std::unordered_set<size_t> &hashesCycleString)
{
    std::vector<size_t> hashString(string.size()+1);
    std::vector<size_t> powsForHash(string.size()+1);
    hashFile(string,hashString,powsForHash);
    size_t i = 1,j = 2;
    size_t hashCycleString = hashString[string.size()];
    hashesCycleString.insert(hashCycleString);
    
    while(j <= string.size())
    {
        hashCycleString = ((hashSubStr(hashString,powsForHash,j,string.size()) * powsForHash[i])%divider + hashSubStr(hashString,powsForHash,1,i))%divider;
        hashesCycleString.insert(hashCycleString);
        ++i,++j;
    }

}

size_t countCycleStringInText(const std::string &text,const std::string &cycleString)
{
    std::unordered_set<size_t> hashesCycleString;
    hashCycleString(cycleString,hashesCycleString);

    std::vector<size_t> hashForFile(text.size()+1);
    std::vector<size_t> powsForHashFile(text.size()+1);
    hashFile(text,hashForFile,powsForHashFile);

    size_t hashSubStringLeft,hashSubStringRight,hashSubString, divider = 1e9+7, counter = 0;
    for(const size_t &hashString:hashesCycleString)
    {
        for (size_t i = cycleString.size(); i <= text.size(); ++i)
        {
            hashSubString = hashSubStr(hashForFile,powsForHashFile,i-cycleString.size()+1,i);
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