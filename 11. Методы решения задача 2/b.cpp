#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct Node
{
    int parent = -1;
    int parentPrice = 1e9;
    int leftChild = -1;
    int leftPrice = 1e9;
    int rightChild = -1;
    int rightPrice = 1e9;
};

int find(std::vector<Node> &tree)
{
    size_t firstVertex,secondVertex;
    std::cin >> firstVertex >> secondVertex;
    int result = 1e9;
    while(true)
    {   
        if(firstVertex == secondVertex){return result;}
        while(firstVertex != -1 && firstVertex > secondVertex)
        {
            result = std::min(result,tree[firstVertex].parentPrice);
            firstVertex = tree[firstVertex].parent;
        }
        while(secondVertex != -1 && secondVertex > firstVertex)
        {
            result = std::min(result,tree[secondVertex].parentPrice);
            secondVertex = tree[secondVertex].parent;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    size_t countVertex;
    std::cin >> countVertex;
    std::vector<Node> tree(countVertex);
    for (size_t i = 1; i < countVertex; i++)
    {
        int parent,price;
        std::cin >> parent >> price;
        tree[i].parent = parent;
        tree[i].parentPrice = price;
        if(tree[parent].leftChild == -1)
        {
            tree[parent].leftChild = i;
            tree[parent].leftPrice = price;
        }
        else
        {
            tree[parent].rightChild = i;
            tree[parent].rightPrice = price;
        }
    }
    
    size_t countQueries;
    std::cin >> countQueries;
    for (size_t i = 0; i < countQueries; i++)
    {
        std::cout << find(tree) << '\n';
    }
    
    
    return 0;
}