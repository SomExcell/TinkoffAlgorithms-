#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

size_t findMin(std::unordered_map<size_t,size_t> &spanningTree,std::unordered_map<size_t,bool> &visited)
{
    size_t nextVertex;
	bool noVal = true;
    for (const auto &i:visited)
    {
        if(i.second == false && (noVal || spanningTree[i.first] < spanningTree[nextVertex]))
        {
            nextVertex = i.first;
			noVal = false;
        }
    }
    return nextVertex;
}

void dijkstra(std::unordered_map<size_t,size_t> &spanningTree, std::unordered_map<size_t,std::unordered_map<size_t,size_t>> &graph,size_t countVertex)
{
    spanningTree[1] = 0;
    std::unordered_map<size_t,bool> visited;
	for(const auto &i:spanningTree){visited[i.first] = false;}

    size_t nextVertex = 1;
    for (size_t i = 0; i < countVertex; i++)
    {
        for(const auto &vertex:graph[nextVertex])
        {
            if(visited[vertex.first] != 1 && spanningTree[vertex.first] > spanningTree[nextVertex]+vertex.second)
            {
                spanningTree[vertex.first] = spanningTree[nextVertex]+vertex.second;
            }
        }
        visited[nextVertex] = true;
        nextVertex = findMin(spanningTree,visited);
    }
}

int main()
{
    size_t inf = 1e15;
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    size_t countVertex,countEdges;
    std::cin >> countVertex >> countEdges;
    std::unordered_map<size_t,size_t> spanningTree;
    std::unordered_map<size_t,std::unordered_map<size_t,size_t>> graph;
    for (size_t i = 0; i < countEdges; i++)
    {
        size_t firstVertex,secondVertex,weight;
        std::cin >> firstVertex >> secondVertex >> weight;
		spanningTree[firstVertex] = inf;
		spanningTree[secondVertex] = inf;
        graph[firstVertex][secondVertex] = weight;
        graph[secondVertex][firstVertex] = weight;
    }
    
    dijkstra(spanningTree,graph,countVertex);
    for (size_t i = 1; i < countVertex + 1; i++)
    {
        std::cout << spanningTree[i] << ' ';
    }
    
    
    return 0;
}