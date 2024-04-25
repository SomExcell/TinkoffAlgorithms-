#include <iostream>
#include <list>

std::string readOperation()
{
    char c;
    std::string operation;
    while(true)
    {
        std::cin >> c;
        if(c == '>'){break;}
        operation.push_back(c);
    }
    return operation;
}

int main() 
{
    std::list<char> listWithChars;
    std::string mainString,secondString;
    char symbol;
    int index = 0;
    auto iterator = listWithChars.begin();
    std::cin >> mainString;

    while(std::cin >> symbol)
    {
        if(symbol == '<')
        {
            std::string operation = readOperation();
            if(operation == "left" && index != 0){iterator--;index--;}
            else if(operation == "right" && index != listWithChars.size()){iterator++;index++;}
            else if(operation == "delete" && index != listWithChars.size()){iterator = listWithChars.erase(iterator);}
            else if(operation == "bspace" && index != 0){iterator--;index--;iterator = listWithChars.erase(iterator);}
            continue;
        }
        index++;
        listWithChars.emplace(iterator,symbol);
    }

    while(!listWithChars.empty())
    {
        secondString.push_back(listWithChars.front());
        listWithChars.pop_front();
    }

    if(secondString == mainString){std::cout << "Yes";}
    else{std::cout << "No";}
    
    return 0;
}