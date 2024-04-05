#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

void topological(std::unordered_map<int,std::vector<int>> &graph,const std::vector<int> &topologicalSequence)
{
    std::unordered_map<int,int> visited;
    for (int i = topologicalSequence.size()-1;i >= 0; --i)
    {    
        int vertex = topologicalSequence[i];
        for (int j = 0; j < graph[vertex].size(); ++j)
        {
            if(!visited.count(graph[vertex][j]))
            {
                std::cout << "NO";return;
            }
        }
        visited[vertex] = 1;
    }
    std::cout << "YES";
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    int countVertices, countEdges,firstVertex,secondVertex;
    std::cin >> countVertices >> countEdges;

    std::unordered_map<int,std::vector<int>> graph;
    std::vector<int> topologicalSequence(countVertices);
    for (size_t i = 0; i < countEdges; ++i)
    {   
        std::cin >> firstVertex >> secondVertex;
        graph[firstVertex].push_back(secondVertex);
    }
    for (size_t i = 0; i < countVertices; ++i)
    {
        std::cin >> firstVertex;
        topologicalSequence[i] = firstVertex;
    }
    
    topological(graph,topologicalSequence);


    return 0;
}