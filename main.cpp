#include <iostream>
#include <vector>

void approximateStringMathing(const std::string &text, const std::string &pattern)
{
    if(text.size() < pattern.size()){std::cout << '0';return;}
    int countChangesChars = 0;
    std::vector<int> positionsApproximateStrings;
    for (size_t i = 0; i < text.size() - pattern.size() + 1; ++i)
    {
        countChangesChars = 0;
        for (size_t j = 0; j < pattern.size(); ++j)
        {
            if(text[i+j] != pattern[j])
            {
                ++countChangesChars;
                if(countChangesChars > 1){break;}
            }
        }
        if(countChangesChars <= 1)
        {
            positionsApproximateStrings.push_back(i+1);
        }
    }

    std::cout << positionsApproximateStrings.size() << '\n';
    for (size_t i = 0; i < positionsApproximateStrings.size(); ++i)
    {
        std::cout << positionsApproximateStrings[i] << ' ';
    }
    
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::string text,pattern;
    std::cin >> pattern >> text;
    

    approximateStringMathing(text,pattern);

    return 0;
}