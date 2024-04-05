#include <iostream>
#include <vector>
#include <algorithm>

void printComponents(const std::vector<std::vector<int>> &components)
{
    std::cout << components.size() << '\n';
    for (size_t i = 0; i < components.size(); ++i)
    {
        std::cout << components[i].size() << '\n';
        for (size_t j = 0; j < components[i].size(); ++j)
        {
            std::cout << components[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void dfs(int vertex,std::vector<int> &visited,std::vector<int> &component,const std::vector<std::vector<int>> &connections)
{
    component.push_back(vertex);
    visited[vertex] = 1;
    for (size_t i = 0; i < connections[vertex].size(); i++)
    {
        int nextVertex = connections[vertex][i];
        if(visited[nextVertex] == 0)
        {
            dfs(nextVertex,visited,component,connections);
        }
    }
}

void connectedComponents(const std::vector<std::vector<int>> &connections)
{
    std::vector<int> visited(connections.size());
    int countComponents = 0;
    std::vector<std::vector<int>> allComponents;
    for (size_t i = 1; i < visited.size(); ++i)
    {
        if(visited[i] == 0)
        {
            std::vector<int> component;
            dfs(i,visited,component,connections);
            std::sort(component.begin(),component.end());
            allComponents.push_back(std::move(component));
            ++countComponents;
        }
    }
    printComponents(allComponents);
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    int countVertices, countEdges,firstVertex,secondVertex;
    std::cin >> countVertices >> countEdges;

    std::vector<std::vector<int>> connections(countVertices+1,std::vector<int>{});

    for (size_t i = 0; i < countEdges; ++i)
    {   
        std::cin >> firstVertex >> secondVertex;
        connections[firstVertex].push_back(secondVertex);
        connections[secondVertex].push_back(firstVertex);
    }
    connectedComponents(connections);

    

    return 0;
}