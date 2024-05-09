#include <iostream>
#include <math.h>
#include <vector>

struct Node
{
    int min = 1e9+7;
    int countSequence = 1;
    int length = 1;
    int left = -1;
    int right = -1;
};

size_t newSize(size_t prevSize)
{
    size_t result = 1;
    while(result < prevSize){result*=2;}
    return result;
}

void buildSegmentTree(std::vector<Node> &segmentTree)
{
    int prevSize  = segmentTree.size();
    segmentTree.resize(newSize(segmentTree.size())*2);
    
    for (size_t i = segmentTree.size()/2; i < segmentTree.size(); ++i,--prevSize)
    {
        if(prevSize > 0)
        {
            std::cin >> segmentTree[i].min;
        }
        segmentTree[i].left = segmentTree[i].right = i - segmentTree.size()/2;
    }

    for (size_t i = segmentTree.size()/2-1; i > 0; --i)
    {
        segmentTree[i].min = std::min(segmentTree[i*2].min,segmentTree[i*2+1].min);
        segmentTree[i].left = segmentTree[i*2].left;
        segmentTree[i].right = segmentTree[i*2+1].right;
    }
}

void countForIndex(int searhIndex, int index,std::vector<Node> &segmentTree)
{
    int mod = 1e9+7;
    if(segmentTree[searhIndex].left > segmentTree[index].left){return;}
    if(searhIndex >= segmentTree.size()/2)
    {
        if(segmentTree[index].length < segmentTree[searhIndex].length + 1)
        {
            segmentTree[index].length = segmentTree[searhIndex].length + 1;
            segmentTree[index].countSequence = segmentTree[searhIndex].countSequence;
        }else if(segmentTree[index].length == segmentTree[searhIndex].length + 1)
        {
            segmentTree[index].countSequence += segmentTree[searhIndex].countSequence;
            segmentTree[index].countSequence%=mod;
        }
        return;
    }
    if(segmentTree[searhIndex*2].left < segmentTree[index].left && segmentTree[searhIndex*2].min < segmentTree[index].min)
    {
        countForIndex(searhIndex*2,index,segmentTree);
    }
    if(segmentTree[searhIndex*2+1].left < segmentTree[index].left && segmentTree[searhIndex*2+1].min < segmentTree[index].min)
    {
        countForIndex(searhIndex*2+1,index,segmentTree);
    }

}

void countSubSequence(std::vector<Node> &segmentTree)
{
    for (size_t i = segmentTree.size()/2; i < segmentTree.size() && segmentTree[i].min != 1e9+7; i++)
    {
        countForIndex(1,i,segmentTree);
    }
}

void outMaxSubSequens(std::vector<Node> &segmentTree)
{
    int maxLength = 1;
    int countMaxSubSequence = 0;
    int mod = 1e9+7;
    for (size_t i = segmentTree.size()/2; i < segmentTree.size(); i++)
    {
        maxLength = std::max(segmentTree[i].length,maxLength);
    }
    for (size_t i = segmentTree.size()/2; i < segmentTree.size(); i++)
    {
        if(segmentTree[i].length == maxLength && segmentTree[i].min!=1e9+7)
        {
            countMaxSubSequence+=segmentTree[i].countSequence;
            countMaxSubSequence%=mod;
        }
    }
    std::cout << countMaxSubSequence;
}

int main()
{
    size_t countElem;
    std::cin >> countElem;
    std::vector<Node> segmentTree(countElem);
    buildSegmentTree(segmentTree);
    countSubSequence(segmentTree);
    outMaxSubSequens(segmentTree);
    
}

