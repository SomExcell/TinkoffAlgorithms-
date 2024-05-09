#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
    size_t min = 0;
    size_t willAdd = 0;
    size_t left = 0;
    size_t right = 0;
};

size_t newSize(const size_t &size)
{
    size_t result = 1;
    while(result <=size){result*=2;}
    return result;
}

void buildSegmentTree(std::vector<Node> &segmentTree)
{
    size_t prevSize = segmentTree.size();
    segmentTree.resize(newSize(segmentTree.size())*2);
    for (size_t i = segmentTree.size()/2; i < segmentTree.size(); ++i)
    {
        segmentTree[i].left = segmentTree[i].right = i - segmentTree.size()/2;
    }
    for (size_t i = segmentTree.size()/2-1; i > 0; --i)
    {
        segmentTree[i].left = segmentTree[i*2].left; segmentTree[i].right = segmentTree[i*2+1].right;
    }
}

void update(const size_t &index,std::vector<Node> &segmentTree)
{
    if(index < segmentTree.size()/2)
    {
        segmentTree[index*2].willAdd += segmentTree[index].willAdd;
        segmentTree[index*2+1].willAdd += segmentTree[index].willAdd;
    }
    segmentTree[index].min += segmentTree[index].willAdd;
    segmentTree[index].willAdd = 0;
}

void minOnSegment(const size_t &index, const size_t &left, const size_t &right,size_t &min,std::vector<Node> &segmentTree)
{
    update(index,segmentTree);
    if(segmentTree[index].left >= left && segmentTree[index].right <= right)
    {
        min = std::min(segmentTree[index].min, min);
        return;
    }
    if(segmentTree[index*2].right >= left)
    {
        minOnSegment(index*2,left,right,min,segmentTree);
    }
    if(segmentTree[index*2+1].left <= right)
    {
        minOnSegment(index*2+1,left,right,min,segmentTree);
    }
}

void addValue(const size_t &index,const size_t &left, const size_t &right, const size_t &value, std::vector<Node> &segmentTree)
{
    update(index,segmentTree);
    if(segmentTree[index].left >= left && segmentTree[index].right <= right)
    {
        segmentTree[index].willAdd += value;
        update(index,segmentTree);
        return;
    }
    if(segmentTree[index*2].right >= left)
    {
        addValue(index*2,left,right,value,segmentTree);
    }
    if(segmentTree[index*2+1].left <= right)
    {
        addValue(index*2+1,left,right,value,segmentTree);
    }
    update(index*2,segmentTree);
    update(index*2+1,segmentTree);
    segmentTree[index].min = std::min(segmentTree[index*2].min,segmentTree[index*2+1].min);
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    size_t sizeArr,countQueries;
    std::cin >> sizeArr >> countQueries;
    std::vector<Node> segmentTree(sizeArr);
    buildSegmentTree(segmentTree);
    for (size_t i = 0; i < countQueries; ++i)
    {
        int typeQuery,left,right,value;
        std::cin >> typeQuery >> left >> right;
        if(typeQuery == 1)
        {
            std::cin >> value;
            addValue(1,left,right-1,value,segmentTree);
        }
        else if(typeQuery == 2)
        {
            size_t min = INT64_MAX;
            minOnSegment(1,left,right-1,min,segmentTree);
            std::cout << min << '\n';
        }
    }
    

    return 0;
}