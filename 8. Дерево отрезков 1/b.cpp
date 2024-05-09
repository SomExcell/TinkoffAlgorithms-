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
    int min = 1e9+7;
    int countMin = 0;
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
        segmentTree[newSize+i].min = value;
        segmentTree[newSize+i].countMin = 1;
    }

    for (int i = newSize-1; i > 0; --i)
    {
        segmentTree[i].min = std::min(segmentTree[i*2].min,segmentTree[i*2+1].min);
        if(segmentTree[i*2].min == segmentTree[i].min){segmentTree[i].countMin += segmentTree[i*2].countMin;}
        if(segmentTree[i*2+1].min == segmentTree[i].min){segmentTree[i].countMin += segmentTree[i*2+1].countMin;}
    }
}

void changeValue(std::vector<Node>& segmentTree,int index,int newValue)
{
    index += segmentTree.size()/2;
    segmentTree[index].min = newValue;
    index/=2;
    while(index > 0)
    {
        segmentTree[index].min = std::min(segmentTree[index*2].min, segmentTree[index*2+1].min);
        segmentTree[index].countMin = 0;
        if(segmentTree[index*2].min == segmentTree[index].min){segmentTree[index].countMin += segmentTree[index*2].countMin;}
        if(segmentTree[index*2+1].min == segmentTree[index].min){segmentTree[index].countMin += segmentTree[index*2+1].countMin;}
        index/=2;
    }
}

void countMinOnSegment(int leftBorder,int rightBorder,std::vector<Node> &segmentTree)
{
    int count = 0;
    int min = 1e9+7;

    int left = leftBorder + segmentTree.size()/2;
    int right = rightBorder + segmentTree.size()/2;

    for(;left<=right;left/=2,right/=2)
    {
        if(left % 2 == 1){min = std::min(min,segmentTree[left].min);++left;}
        if(right % 2 == 0){min = std::min(min,segmentTree[right].min);--right;}
    }

    left = leftBorder + segmentTree.size()/2;
    right = rightBorder + segmentTree.size()/2;

    for(;left<=right;left/=2,right/=2)
    {
        if(left % 2 == 1)
        {
            if(segmentTree[left].min == min){count+=segmentTree[left].countMin;}
            ++left;
        }
        if(right % 2 == 0)
        {
            if(segmentTree[right].min == min){count+=segmentTree[right].countMin;}
            --right;
        }
    }
    std::cout << min << ' ' << count << '\n';
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
            countMinOnSegment(leftBorder,rightBorder-1,segmentTree);
        }
    }
    
    
    return 0;
}