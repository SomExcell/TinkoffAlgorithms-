#include <iostream>
#include <vector>

void fillPows(std::vector<size_t> &powsForHash)
{
    size_t coeffHash = 173,divider = 1e9+7;
    powsForHash[0] = 1;
    for (size_t i = 1; i < powsForHash.size(); ++i)
    {
        powsForHash[i] = (powsForHash[i-1] * coeffHash) % divider;
    }
}

void hashFile(const std::string &string, std::vector<size_t> &hashForFile,std::vector<size_t> &powsForHash)
{
    size_t coeffHash = 173, divider = 1e9+7;
    fillPows(powsForHash);
    for (size_t i = 1; i <= string.size(); ++i)
    {
        hashForFile[i] = (hashForFile[i-1] * coeffHash + (string[i-1]-96)) % divider;
    }
}

size_t hashString(const std::string &string)
{
    size_t result = 0, coeffHash = 173, divider = 1e9+7;
    for (size_t i = 1; i <= string.size(); ++i)
    {
        result = (result * coeffHash + (string[i-1]-96)) % divider;
    }
    return result;
}

void searchStringInText(std::vector<size_t> hashForFile, std::vector<size_t> powsForHash, const size_t &hashQueryString, const size_t &lengthQueryString)
{
    size_t hashSubStringLeft,hashSubStringRight,hashSubString, divider = 1e9+7, countStringInFile = 0;
    std::vector <size_t> indices;
    for (size_t i = lengthQueryString; i < hashForFile.size(); ++i)
    {
        hashSubStringLeft = (hashForFile[i-lengthQueryString] * powsForHash[lengthQueryString]) % divider;
        hashSubStringRight = hashForFile[i];
        if(hashSubStringRight < hashSubStringLeft)
        {
            hashSubStringRight+=divider;
        }
        hashSubString = hashSubStringRight - hashSubStringLeft;
        if(hashSubString == hashQueryString)
        {
            ++countStringInFile;
            indices.push_back(i - lengthQueryString);
        }
    }

    std::cout << countStringInFile << ' ';
    for (size_t i = 0; i < countStringInFile; ++i)
    {
        std::cout << indices[i] << ' ';
    }
    std::cout << '\n';
    
}

void queriesInText(std::vector<size_t> hashForFile, std::vector<size_t> powsForHash, size_t countQueries)
{
    std::string stringFromQuery;
    size_t hashForQueryString;
    for (size_t i = 0; i < countQueries; ++i)
    {
        std::cin >> stringFromQuery;
        hashForQueryString = hashString(stringFromQuery);
        searchStringInText(hashForFile,powsForHash,hashForQueryString,stringFromQuery.size());
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
    
    std::string textFromFile;
    int countQueries;
    std::cin >> textFromFile >> countQueries;
    std::vector<size_t> hashForFile(textFromFile.size()+1);
    std::vector<size_t> powsForHash(textFromFile.size()+1);

    hashFile(textFromFile,hashForFile,powsForHash);
    queriesInText(hashForFile,powsForHash,countQueries);

    return 0;
}