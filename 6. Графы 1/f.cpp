#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

int bfs(std::unordered_map<std::string,std::vector<std::string>> &graph, const std::string& search, std::queue<std::pair<std::string,int>> &elements,std::unordered_set<std::string> &wereFindElements,int countTransform)
{
    std::string name = elements.front().first;
    if(name == search){return countTransform;}
    for(const std::string &string:graph[name])
    {
        if(!wereFindElements.count(string))
        {
            elements.push({string,countTransform+1});
            wereFindElements.insert(string);
        }
    }
    elements.pop();
    if(elements.size() == 0){return -1;}
    int result = bfs(graph,search,elements,wereFindElements,elements.front().second);
    if(result != -1){return result;}
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    int count;
    std::string firstName,secondName,empty;
    std::unordered_map<std::string,std::vector<std::string>> graph;
    std::cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> firstName >> empty >> secondName;
        graph[firstName].push_back(secondName);
    }
    std::cin >> firstName >> secondName;

    std::queue<std::pair<std::string,int>> elements;
    elements.push({firstName,0});
    std::unordered_set<std::string> wereFindElements;
    wereFindElements.insert(firstName);
    std::cout << bfs(graph,secondName,elements,wereFindElements,0);
    

    return 0;
}