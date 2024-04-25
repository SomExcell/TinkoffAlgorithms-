#include <iostream>
#include <algorithm>
#include <vector>
 
size_t newLength(size_t prevLength)
{
    size_t length = 1;
    while(prevLength > length){length*=2;}
    return length;
}

struct Node
{
    int value = 0;
    long long sum = 0;
    int leftBorder = -1;
    int rightBorder = -1;
};

void buildSegmentTree(std::vector<Node>& segmentTree)
{
    size_t prevSize = segmentTree.size();
    size_t newSize= newLength(segmentTree.size());
    segmentTree.resize(newSize*2);
    for (size_t i = 0; i < prevSize; ++i)
    {
        int value;
        std::cin >> value;
        segmentTree[newSize+i].value = value;
        segmentTree[newSize+i].sum = value;
        segmentTree[newSize+i].leftBorder = i;
        segmentTree[newSize+i].rightBorder = i;
    }

    for (size_t i = newSize-1; i > 0; --i)
    {
        segmentTree[i].sum = 0ll + segmentTree[i*2].sum + segmentTree[i*2+1].sum;
        segmentTree[i].leftBorder = segmentTree[i*2].leftBorder;
        segmentTree[i].rightBorder = segmentTree[i*2+1].rightBorder;
        if(segmentTree[i].rightBorder == -1)
        {
            segmentTree[i].rightBorder = segmentTree[i].leftBorder;
        }
    }
    
}

void changeValue(std::vector<Node>& segmentTree,int index,int newValue)
{
    index += segmentTree.size()/2;
    segmentTree[index].value = newValue;
    segmentTree[index].sum = newValue;
    index/=2;
    while(index > 0)
    {
        segmentTree[index].sum = 0ll + segmentTree[index*2].sum + segmentTree[index*2+1].sum;
        index/=2;
    }
}

long long segmentTreeSum(int leftBorder,int rightBorder,std::vector<Node> &segmentTree)
{
    long long sum = 0;
    leftBorder+=segmentTree.size()/2;
    rightBorder+=segmentTree.size()/2;
    for(;leftBorder <= rightBorder;leftBorder/=2,rightBorder/=2)
    {
        if(leftBorder % 2 == 1){sum+=segmentTree[leftBorder++].sum;}
        if(rightBorder % 2 == 0){sum += segmentTree[rightBorder--].sum;}
    }
    return sum;
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
        int operation,leftBorder,rightBorder,value;
        std::cin >> operation;
        if(operation == 1)
        {
            std::cin >> leftBorder >> value;
            changeValue(segmentTree,leftBorder,value);
        }else
        {
            std::cin >> leftBorder >> rightBorder;
            std::cout << segmentTreeSum(leftBorder,rightBorder-1,segmentTree) << '\n';
        }
    }
    
    
    return 0;
}