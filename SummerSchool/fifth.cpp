#include <iostream>
#include <math.h>
#include <deque>
#include <vector>

struct Node
{
    int firstVertex;
    int secondVertex;
    int price;
    size_t time;
};

bool buildConnections(std::vector<std::vector<size_t>> &matrix,std::vector<Node> &newConnection, std::vector<Node> &requirements,int price)
{
    size_t inf = 1e9+7;
    std::vector<std::vector<size_t>> copyMatrix = matrix;
    for (size_t i = 0; i < newConnection.size(); i++)
    {
        int firstVertex = newConnection[i].firstVertex,secondVertex = newConnection[i].secondVertex;
        if(newConnection[i].price <= price)
        {
            copyMatrix[firstVertex][secondVertex] = copyMatrix[secondVertex][firstVertex] = newConnection[i].time;
        }
    }
    
    for (size_t v = 1; v < matrix.size(); v++)
    {
        for (size_t i = 1; i < matrix.size(); i++)
        {
            for (size_t j = 1; j < matrix.size(); j++)
            {
                if(copyMatrix[i][v] != inf && copyMatrix[v][j] != inf)
                {
                    copyMatrix[i][j] = std::min(copyMatrix[i][j],copyMatrix[i][v]+copyMatrix[v][j]);
                }
            }
        }
    }

    for (const auto &node:requirements)
    {
        if(copyMatrix[node.firstVertex][node.secondVertex] > node.time){return false;}
    }
    return true;

}

int main()
{
    size_t inf = 1e9+7;
    int maxPrice = -1;
    size_t countVertex,countConnection;
    std::cin >> countVertex >> countConnection;
    std::vector<std::vector<size_t>> matrix(countVertex+1,std::vector<size_t>(countVertex+1,inf));

    int firstVertex,secondVertex,time,price;
    for (size_t i = 0; i < countConnection; ++i)
    {
        std::cin >> firstVertex >> secondVertex >> time;
        matrix[firstVertex][secondVertex] = matrix[secondVertex][firstVertex] = time;
    }

    int countNewConnection;
    std::cin >> countNewConnection;
    std::vector<Node> newConnection(countNewConnection);
    for (auto &node:newConnection)
    {
        std::cin >> node.firstVertex >> node.secondVertex >> node.time >> node.price;
        maxPrice = std::max(maxPrice,node.price);
    }

    int countRequirements;
    std::cin >> countRequirements;
    std::vector<Node> requirements(countRequirements);
    for(auto &node:requirements)
    {
        std::cin >> node.firstVertex >> node.secondVertex >> node.time;
    }
    
    int left = 0,right = maxPrice;
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(buildConnections(matrix,newConnection,requirements,mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    if(left > maxPrice){std::cout << -1 << '\n';return 0;}
    int count = 0;
    for (size_t i = 0; i < newConnection.size(); i++)
    {
        if(newConnection[i].price <= left)
        {
            ++count;
        }
    }
    std::cout << count << '\n';
    for (size_t i = 0; i < newConnection.size(); i++)
    {
        if(newConnection[i].price <= left)
        {
            std::cout << i + 1 << ' ';
        }
    }
    
    
}

