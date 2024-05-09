#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_set>

struct Multiplicity
{
    size_t size = 1;
    size_t value;
    size_t head;
    size_t min;
    size_t max;
};

int find(std::vector<Multiplicity> &sets,size_t value)
{
    size_t it = sets[value].head;
    while(it != sets[it].head)
    {
        it = sets[it].head;
    }
    return it;
}

void combine(std::vector<Multiplicity> &sets,size_t first,size_t second)
{
    int firstIt = find(sets,first);
    size_t secondIt = sets[second].value;
    size_t copyIt = secondIt;
    while(secondIt != sets[secondIt].head)
    {
        secondIt = sets[secondIt].head;
        sets[copyIt].head = firstIt;
        copyIt = secondIt;
    }
    if(firstIt != secondIt)
    {
        sets[secondIt].head = firstIt;
        sets[firstIt].size += sets[secondIt].size;
        sets[firstIt].min = std::min(sets[firstIt].min,sets[secondIt].min);
        sets[firstIt].max = std::max(sets[firstIt].max,sets[secondIt].max);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    size_t countElements, countOperations;
    std::cin >> countElements >> countOperations;

    std::vector<Multiplicity> sets(countElements+1);
    for (size_t i = 1; i < countElements+1; i++)
    {
        sets[i].min = sets[i].max = sets[i].value = sets[i].head = i;
    }

    for (size_t i = 0; i < countOperations; i++)
    {
        std::string typeOperation;
        std::cin >> typeOperation;
        size_t first,second;
        if(typeOperation == "union")
        {
            std::cin >> first >> second;
            combine(sets,first,second);
        }
        else if(typeOperation == "get")
        {
            std::cin >> first;
            second = find(sets,first);
            std::cout << sets[second].min << ' ' << sets[second].max << ' ' << sets[second].size << '\n';
        }
    }
    
    return 0;
}