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
    int max = -1;
    int left = -1;
    int right = -1;
};

void buildSegmentTree(std::vector<Node>& segmentTree)
{
    int prevSize = segmentTree.size();
    size_t newSize= newLength(segmentTree.size());
    segmentTree.resize(newSize*2);

    for (int i = 0; i < newSize; ++i,--prevSize)
    {
        int value = -1;
        if(prevSize > 0)
        {
            std::cin >> value;
        }
        segmentTree[newSize+i].max = value;
        segmentTree[newSize+i].left = segmentTree[newSize+i].right = i;
    }

    for (int i = newSize-1; i > 0; --i)
    {
        segmentTree[i].max = std::max(segmentTree[i*2].max, segmentTree[i*2+1].max);
        segmentTree[i].left = segmentTree[i*2].left;
        segmentTree[i].right = segmentTree[i*2+1].right;
    }
}

void changeValue(std::vector<Node>& segmentTree,int index,int newValue)
{
    index += segmentTree.size()/2;
    segmentTree[index].max = newValue;
    index/=2;
    while(index > 0)
    {
        segmentTree[index].max = std::max(segmentTree[index*2].max, segmentTree[index*2+1].max);
        index/=2;
    }
}

int result = -1;

void findValue(int index,int leftborder,int value,std::vector<Node> &segmentTree)
{
    //if(segmentTree[index].max < value || segmentTree[index].left > result){return;}
    if(segmentTree[index].max < value || segmentTree[index].right < leftborder){return;}
    if(result != -1){return;}
    if(index < segmentTree.size()/2)
    {
        findValue(index*2,leftborder,value,segmentTree); 
        findValue(index*2+1,leftborder,value,segmentTree);
    }else{
        index -= segmentTree.size()/2;
        if(index < result || result == -1){result = index;}
    }
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
        result = -1;
        int operation,index,value;
        std::cin >> operation;
        if(operation == 1)
        {
            std::cin >> index >> value;
            changeValue(segmentTree,index,value);
        }else
        {
            std::cin >> value >> index;
            findValue(1,index,value,segmentTree);
            std::cout << result << '\n';
        }
    }
    
    
    return 0;
}