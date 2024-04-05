#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool haveCycle = false;

void dfs(int vertex,std::unordered_map<int,int> &visited,std::unordered_map<int,std::vector<int>> &graph)
{
    if(visited.count(vertex) && visited[vertex] == 1){haveCycle = true;return;}
    visited[vertex] = 1;
    for (const int &i:graph[vertex])
    {
        dfs(i,visited,graph);
    }
    visited[vertex] = 2;
}

void cycleInGraph(std::unordered_map<int,std::vector<int>> graph)
{
    std::unordered_map<int,int> visited;
    for (const auto &i:graph)
    {
        if(!visited.count(i.first))
        {
            dfs(i.first,visited, graph);
            if(haveCycle){std::cout << 1;return;}
        }
        visited[i.first] = 2;
    }
    std::cout << 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    int countVertices, countEdges,firstVertex,secondVertex;
    std::cin >> countVertices >> countEdges;

    std::unordered_map<int,std::vector<int>> graph;

    for (size_t i = 0; i < countEdges; ++i)
    {   
        std::cin >> firstVertex >> secondVertex;
        graph[firstVertex].push_back(secondVertex);
    }
    cycleInGraph(graph);

    return 0;
}