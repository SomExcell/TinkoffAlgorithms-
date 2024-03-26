#include <iostream>
#include <vector>

int main()
{
    int count;
    char c, lastChar = ' ';
    std::string res;
    std::cin >> count;
    std::vector<int> vec(26);
    bool last = false;
    for (size_t i = 0; i < count; ++i)
    {
        std::cin >> c;
        ++vec[c-'A'];
    }

    //first half
    for (size_t i = 0; i < 26; i++)
    {
        count = vec[i]/2;
        for (size_t j = 0; j < count; j++)
        {
            res+=char(i+'A');
            //--vec[i];
        }
    }
    //mid char

    for (size_t i = 0; i < 26; i++)
    {
        if(vec[i]%2 == 1)
        {
            lastChar = i+'A';
            break;
        }
    }

    if(lastChar!=' ')
    {
        res+=lastChar;
        last = true;
    }
    

    //second half
    for (int i = 25; i >= 0; --i)
    {
        count = vec[i]/2;
        for (size_t j = 0; j < count; ++j)
        {
            res+=char(i+'A');
            last = false;
        }
    }
    if(last && res.size()>1)
    {
        res.pop_back();
    }
    
    std::cout << res;
    

    return 0;
}