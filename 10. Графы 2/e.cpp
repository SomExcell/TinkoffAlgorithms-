#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

size_t findMin(const std::vector<size_t> &spanningTree,const std::vector<int> &visited)
{
    size_t nextVertex = 0;
    for (size_t i = 1; i < spanningTree.size(); i++)
    {
        if(visited[i] == 0 && spanningTree[i] < spanningTree[nextVertex])
        {
            nextVertex = i;
        }
    }
    return nextVertex;
}

void dijkstra(std::vector<size_t> &spanningTree, std::unordered_map<size_t,std::unordered_map<size_t,size_t>> &graph)
{
    spanningTree[1] = 0;
    std::vector<int> visited(spanningTree.size());
    size_t nextVertex = 1;
    for (size_t i = 1; i < spanningTree.size(); i++)
    {
        for(const auto &vertex:graph[nextVertex])
        {
            if(visited[vertex.first] != 1 && spanningTree[vertex.first] > spanningTree[nextVertex]+vertex.second)
            {
                spanningTree[vertex.first] = spanningTree[nextVertex]+vertex.second;
            }
        }
        visited[nextVertex] = 1;
        nextVertex = findMin(spanningTree,visited);
    }
    
}

int main()
{
    size_t inf = 1e9;
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    size_t countVertex,countEdges;
    std::cin >> countVertex >> countEdges;
    std::vector<size_t> spanningTree(countVertex+1,inf);
    std::unordered_map<size_t,std::unordered_map<size_t,size_t>> graph;
    for (size_t i = 0; i < countEdges; i++)
    {
        size_t firstVertex,secondVertex,weight;
        std::cin >> firstVertex >> secondVertex >> weight;
        graph[firstVertex][secondVertex] = weight;
        graph[secondVertex][firstVertex] = weight;
    }
    
    dijkstra(spanningTree,graph);
    for (size_t i = 1; i < spanningTree.size(); i++)
    {
        std::cout << spanningTree[i] << ' ';
    }
    
    
    return 0;
}