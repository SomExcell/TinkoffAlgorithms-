#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

struct Node
{
    Node(int len,double left,double right):len(len),left(left),right(right){cut = (right+left)/2;}
    int len;
    double left,right;
    double cut;
};

int countBestCuts(std::list<int> cuts,int lengthTimber)
{
    std::list<Node> timbers;
    timbers.push_back(Node(lengthTimber,0,lengthTimber));
    auto itCuts = cuts.begin();
    auto itTimbers = timbers.begin();
    auto itBetterCuts = cuts.begin();
    auto itBetterTimbers = timbers.begin();
    double dist = 1e9;
    size_t sum = 0;
    while(!cuts.empty())
    {
        while (itTimbers!=timbers.end())
        {
            auto itCopy = itCuts;
            while(++itCopy != cuts.end() && std::abs(*itCopy - itTimbers->cut) < std::abs(*itCuts - itTimbers->cut))
            {
                itCuts++;
            }
            if(dist > std::abs(*itCuts - itTimbers->cut))
            {
                itBetterCuts = itCuts;
                itBetterTimbers = itTimbers;
                dist = std::abs(*itCuts - itTimbers->cut);
            }
            itTimbers++;
        }
        sum += itBetterTimbers->len;
        int coordCut = *itBetterCuts;
        cuts.erase(itBetterCuts);
        itCuts = cuts.begin();
        timbers.insert(itBetterTimbers,Node(coordCut-itBetterTimbers->left,itBetterTimbers->left,coordCut));
        timbers.insert(itBetterTimbers,Node(itBetterTimbers->right-coordCut,coordCut,itBetterTimbers->right));
        timbers.erase(itBetterTimbers);
        itTimbers = timbers.begin();
        dist = 1e9;
    }
    return sum;
}

int main() 
{
    int lengthTimber,countCuts;
    std::cin >> lengthTimber >> countCuts;
    std::list<int> cuts;
    for (size_t i = 0; i < countCuts; i++)
    {
        int coord;
        std::cin >> coord;
        cuts.push_back(coord);
    }
    
    std::cout << countBestCuts(cuts,lengthTimber);

    return 0;
}
