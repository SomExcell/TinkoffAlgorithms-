#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
 
size_t newLength(size_t prevLength)
{
    size_t length = 1;
    while(prevLength > length){length*=2;}
    return length;
}

struct Node
{
    int countOnes = 0;
};

void buildSegmentTree(std::vector<Node>& segmentTree)
{
    size_t prevSize = segmentTree.size();
    size_t newSize= newLength(segmentTree.size());
    segmentTree.resize(newSize*2);

    for (int i = 0; i < prevSize; ++i)
    {
        int value ;
        std::cin >> value;
        if(value == 1){segmentTree[newSize+i].countOnes = 1;}
    }

    for (int i = newSize-1; i > 0; --i)
    {
        segmentTree[i].countOnes = segmentTree[i*2].countOnes + segmentTree[i*2+1].countOnes;
    }
}

void changeValue(std::vector<Node>& segmentTree,int index)
{
    index += segmentTree.size()/2;
    segmentTree[index].countOnes == 1 ? segmentTree[index].countOnes = 0:segmentTree[index].countOnes = 1;
    index/=2;
    while(index > 0)
    {
        segmentTree[index].countOnes = segmentTree[index*2].countOnes + segmentTree[index*2+1].countOnes;
        index/=2;
    }
}

void findIndex(int number,std::vector<Node> &segmentTree)
{
    int counter = 0;
    int index = 1;
    while(index < segmentTree.size()/2)
    {
        if(segmentTree[index*2].countOnes + counter < number)
        {
            counter+=segmentTree[index*2].countOnes;
            index = index * 2 +1;
        }else
        {
            index *=2;
        }
    }
    std::cout << index - segmentTree.size()/2 << '\n';
    
}

int main() 
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    size_t countValues,countQueries;
    std::cin >> countValues >> countQueries;
    std::vector<Node> segmentTree(countValues);
    buildSegmentTree(segmentTree);
    for (size_t i = 0; i < countQueries; ++i)
    {
        int operation,index;
        std::cin >> operation >> index ;
        if(operation == 1)
        {
            changeValue(segmentTree,index);
        }else
        {
            findIndex(index,segmentTree);
        }
    }
    
    
    return 0;
}