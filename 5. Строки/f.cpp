#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

size_t coeffHash = 277,divider = 1e9+7;

void fillPows(std::vector<size_t> &powsForHash)
{
    powsForHash[0] = 1;
    for (size_t i = 1; i < powsForHash.size(); ++i)
    {
        powsForHash[i] = (powsForHash[i-1] * coeffHash) % divider;
    }
}

void hashFile(const std::string &string, std::vector<size_t> &hashForFile)
{
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

size_t countPolindroms(const std::string &string)
{
    std::string reversedString = string;
    std::reverse(reversedString.begin(),reversedString.end());

    std::vector<size_t> hashString(string.size()+1);
    std::vector<size_t> hashReversedString(string.size()+1);
    std::vector<size_t> powsHash(string.size()+1);

    fillPows(powsHash);
    hashFile(string,hashString);
    hashFile(reversedString,hashReversedString);

    size_t countPolindroms = string.size();
    size_t firstHash,secondHash;
    size_t left,right;
    for (size_t i = 2; i <= string.size(); ++i)
    {
        for (size_t j = 1; j <= string.size()-i+1; ++j)
        {   
            left = j,right = j + i - 1; 
            firstHash = hashSubStr(hashString,powsHash,left,right);
            left = string.size()-i-j+2,right =string.size()-j+1; 
            secondHash = hashSubStr(hashReversedString,powsHash,left,right);
            if(firstHash == secondHash)
            {
                ++countPolindroms;
            }
        }
    }
    return countPolindroms;
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::string string;
    string.resize(100000);
    //std::cin >> string;
    for (size_t i = 0; i < string.size(); i++)
    {
        string[i] = 'a';
    }
    

    std::cout << countPolindroms(string);

    return 0;
}