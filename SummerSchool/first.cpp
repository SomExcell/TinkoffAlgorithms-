#include <iostream>

int main() 
{
    std::string str;
    std::cin >> str;
    bool number = false,upper = false,lower = false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if(str[i] > 47 && str[i] < 58){number = true;}
        else if(str[i] > 64 && str[i] < 91){upper = true;}
        else if(str[i] > 96 && str[i] < 123){lower = true;}
    }
    if(str.size() > 7 && number && upper && lower){std::cout << "YES";}
    else{std::cout << "NO";}
    
    return 0;
}