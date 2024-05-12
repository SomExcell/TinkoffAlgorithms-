#include <iostream>
#include <vector>
#include <algorithm>

enum Color
{
    WHITE,
    BLACK,
    WB,
    NOT
};

struct Node
{
    int left;
    int right;
    Color color = WHITE;
    Color willColor = NOT;
    size_t length = 0;
    size_t count = 0;
};

size_t newSize(size_t size)
{
    size_t result = 1;
    while(result < size){result*=2;}
    return result;
}

void buildSegmentTree(std::vector<Node> &segmentTree)
{
    segmentTree.resize(newSize(segmentTree.size())*2);
    int value = segmentTree.size()/4*(-1);
    for (int i = segmentTree.size()/2; i < segmentTree.size(); i++,value++)
    {
        segmentTree[i].left = segmentTree[i].right = value;
    }
    for (size_t i = segmentTree.size()/2 - 1; i > 0; i--)
    {
        segmentTree[i].left = segmentTree[i*2].left;
        segmentTree[i].right = segmentTree[i*2+1].right;
    }
}

void willChild(int index, std::vector<Node> &segmentTree)
{
    if(segmentTree[index].willColor != NOT){segmentTree[index].color = segmentTree[index].willColor;}
    if(index < segmentTree.size()/2 && segmentTree[index].willColor != NOT)
    {
        segmentTree[index*2].willColor = segmentTree[index*2+1].willColor = segmentTree[index].willColor;
    }
    segmentTree[index].willColor = NOT;
}

void updateValues(int index, std::vector<Node> &segmentTree)
{
    if(index < segmentTree.size()/2)
    {
        willChild(index*2,segmentTree);
        willChild(index*2+1,segmentTree);
        segmentTree[index].count = segmentTree[index*2].count + segmentTree[index*2+1].count;
        segmentTree[index].length = segmentTree[index*2].length + segmentTree[index*2+1].length;
        if(segmentTree[index*2].color != segmentTree[index*2+1].color){segmentTree[index].color = WB;}
    }
    if(segmentTree[index].color == WHITE){segmentTree[index].count = 0, segmentTree[index].length = 0;}
}

void divNode(int index,std::vector<Node> &segmentTree)
{
    if(index < segmentTree.size()/2 && (segmentTree[index*2].willColor == BLACK || segmentTree[index*2].color == BLACK) && (segmentTree[index*2+1].willColor == BLACK ||segmentTree[index*2+1].color == BLACK))
    {
        segmentTree[index*2].count = segmentTree[index].count;
        segmentTree[index*2].length = segmentTree[index*2+1].length = segmentTree[index].length/2;
    }
}

void update(int index,std::vector<Node> &segmentTree)
{
    willChild(index,segmentTree);
    divNode(index,segmentTree);
    updateValues(index,segmentTree);
}

void up(int index,std::vector<Node> &segmentTree)
{
    while(index != 0)
    {
        updateValues(index,segmentTree);
        index/=2;
    }
}

int checkNode(int left,int right,std::vector<Node> &segmentTree)
{
    int index = 1;
    while(segmentTree[index].left != left || segmentTree[index].right != right)
    {
        update(index,segmentTree);
        if(segmentTree[index*2].right < left){index = index*2+1;}
        else{index*=2;}
    }
    update(index,segmentTree);
    if(segmentTree[index].color == WB)
    {
        while(segmentTree[index].color==WB)
        {
            update(index,segmentTree);
            index*=2;
        }
    }
    return index;
}

void updateCountBlack(int index,std::vector<Node> &segmentTree)
{
    int left,right;
    left = checkNode(segmentTree[index-1].left,segmentTree[index-1].right,segmentTree);
    right = checkNode(segmentTree[index+1].left,segmentTree[index+1].right,segmentTree);
    Color leftC = segmentTree[left].color;
    Color rightC = segmentTree[right].color;
    if(segmentTree[index].color == BLACK)
    {
        if(segmentTree[left].color == WHITE && segmentTree[right].color == WHITE)
        {
            segmentTree[index].count = 1;
        }
        else if(segmentTree[left].color == WHITE && segmentTree[right].color == BLACK)
        {
            segmentTree[index].count = 1;
            segmentTree[right].count = 0;
        }
        else if(segmentTree[left].color == BLACK && segmentTree[right].color == WHITE)
        {

        }
        else if(segmentTree[left].color == BLACK && segmentTree[right].color == BLACK)
        {
            segmentTree[right].count = 0;
        }
        segmentTree[index].length = std::abs(segmentTree[index].left - segmentTree[index].right) + 1;
    }
    else
    {
        if(segmentTree[left].color == WHITE && segmentTree[right].color == WHITE)
        {
        }
        else if(segmentTree[left].color == WHITE && segmentTree[right].color == BLACK)
        {
            segmentTree[right].count = 1;
        }
        else if(segmentTree[left].color == BLACK && segmentTree[right].color == WHITE)
        {
        }
        else if(segmentTree[left].color == BLACK && segmentTree[right].color == BLACK)
        {
            segmentTree[right].count = 1;
        }
        segmentTree[index].count = 0;
        segmentTree[index].length= 0;
    }
    up(left,segmentTree);
    up(right,segmentTree);
}

void draw(int index,int left, int right,Color color,std::vector<Node> &segmentTree)
{
    update(index,segmentTree);
    if(segmentTree[index].left >= left && segmentTree[index].right <= right)
    {
        segmentTree[index].color = color;segmentTree[index].willColor = color;
        updateCountBlack(index,segmentTree);
        update(index,segmentTree);
        return;
    }
    else if(segmentTree[index].right < left || right < segmentTree[index].left){return;}
    else
    {
        draw(index*2,left,right,color,segmentTree);
        draw(index*2+1,left,right,color,segmentTree);
    }
    update(index,segmentTree);
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    std::vector<Node> segmentTree(1e6);
    buildSegmentTree(segmentTree);
    size_t countQueries;
    std::cin >> countQueries;
    for (size_t i = 0; i < countQueries; i++)
    {
        char type;
        int left,right;
        std::cin >> type >> left >> right; 
        if(type == 'W'){draw(1,left,left+right-1,WHITE,segmentTree);}
        else{draw(1,left,left+right-1,BLACK,segmentTree);}
        std::cout << segmentTree[1].count << ' ' << segmentTree[1].length << '\n';
    }
    

    
    
    return 0;
}