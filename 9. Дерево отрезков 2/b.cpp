#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
    size_t sum = 0;
    size_t willAdd = 0;
    size_t newValue = INT64_MAX;
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

void updateAdd(const size_t &index,const size_t &value,std::vector<Node> &segmentTree)
{
    if(segmentTree[index].newValue == INT64_MAX)
    {
        segmentTree[index].willAdd += value;
    }
    else
    {
        segmentTree[index].newValue += value;
    }
}

void updateValue(const size_t &index,const size_t &value,std::vector<Node> &segmentTree)
{
    segmentTree[index].willAdd = 0;
    segmentTree[index].newValue = value;
}

void update(const size_t &index,std::vector<Node> &segmentTree)
{
    if(segmentTree[index].newValue != INT64_MAX)
    {
        segmentTree[index].sum = (segmentTree[index].right - segmentTree[index].left+1) * segmentTree[index].newValue;
    }
    else
    {
        segmentTree[index].sum += (segmentTree[index].right - segmentTree[index].left+1) * segmentTree[index].willAdd;
    }
    if(index < segmentTree.size()/2)
    {
        if(segmentTree[index].newValue!= INT64_MAX)
        {
            updateValue(index*2,segmentTree[index].newValue,segmentTree);
            updateValue(index*2+1,segmentTree[index].newValue,segmentTree);
        }
        else
        {
            updateAdd(index*2,segmentTree[index].willAdd,segmentTree);
            updateAdd(index*2+1,segmentTree[index].willAdd,segmentTree);
        }
    }

    segmentTree[index].willAdd = 0;
    segmentTree[index].newValue = INT64_MAX;
}

void sumOnSegment(const size_t &index, const size_t &left, const size_t &right,size_t &sum,std::vector<Node> &segmentTree)
{
    update(index,segmentTree);
    if(segmentTree[index].left >= left && segmentTree[index].right <= right)
    {
        sum += segmentTree[index].sum;
        return;
    }
    else if(segmentTree[index].right < left || right < segmentTree[index].left){return;}
    else
    {
        sumOnSegment(index*2,left,right,sum,segmentTree);
        sumOnSegment(index*2+1,left,right,sum,segmentTree);
    }
}

void addValue(const size_t &index,const size_t &left, const size_t &right, const size_t &value, std::vector<Node> &segmentTree)
{
    update(index,segmentTree);
    if(segmentTree[index].left >= left && segmentTree[index].right <= right)
    {
        updateAdd(index,value,segmentTree);
        update(index,segmentTree);
    }
    else if(segmentTree[index].right < left || right < segmentTree[index].left){return;}
    else
    {
        addValue(index*2,left,right,value,segmentTree);
        addValue(index*2+1,left,right,value,segmentTree);
        segmentTree[index].sum = segmentTree[index*2].sum + segmentTree[index*2+1].sum;
    }
}

void changeValue(const size_t &index, const size_t &left, const size_t &right, const size_t &value, std::vector<Node> &segmentTree)
{
    update(index,segmentTree);
    if(segmentTree[index].left >= left && segmentTree[index].right <= right)
    {
        updateValue(index,value,segmentTree);
        update(index,segmentTree);
    }
    else if(segmentTree[index].right < left || right < segmentTree[index].left){return;}
    else
    {
        changeValue(index*2,left,right,value,segmentTree);
        changeValue(index*2+1,left,right,value,segmentTree);
        segmentTree[index].sum = segmentTree[index*2].sum + segmentTree[index*2+1].sum;
    }
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
            changeValue(1,left,right-1,value,segmentTree);
        }
        else if(typeQuery == 2)
        {
            std::cin >> value;
            addValue(1,left,right-1,value,segmentTree);
        }
        else if(typeQuery == 3)
        {
            size_t sum = 0;
            sumOnSegment(1,left,right-1,sum,segmentTree);
            std::cout << sum << '\n';
        }
    }

    return 0;
}