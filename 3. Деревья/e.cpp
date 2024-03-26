#include <iostream>
#include <vector>

class BinaryHeap
{
public:
    BinaryHeap(){}
    //BinaryHeap(const BinaryHeap& rhs);
    //BinaryHeap(BinaryHeap&& rhs);
    //BinaryHeap& operator=(const BinaryHeap& rhs);
    //BinaryHeap& operator=(BinaryHeap&& rhs);
public:
	void push(const int &value)
    {
        values.push_back(value);
        if(reversed){trickleUpReversed(values.size()-1);}
        else{trickleUp(values.size()-1);}
    }

	void pop()
    {
        std::swap(values[0],values[values.size()-1]);
        values.pop_back();
        if(reversed){trickleDownReversed(0);}
        else{trickleDown(0);}
    }

	int top()
    {
        return values[0];
    }

	void reverse()
    {
        reversed = true;
    }

private:
	void trickleUp(const int &currentIndex)
    {
        int pIndex = parentIndex(currentIndex);
        if(pIndex == currentIndex || values[pIndex] >= values[currentIndex]){return;}
        std::swap(values[pIndex],values[currentIndex]);
        trickleUp(pIndex);
    }
	void trickleDown(const int &currentIndex)
    {
        int greatChildIndex = graterChild(leftChildIndex(currentIndex),rightChildIndex(currentIndex));
        if(greatChildIndex == -1){return;}
        else if(values[greatChildIndex] < values[currentIndex]){return;}
        std::swap(values[greatChildIndex],values[currentIndex]);
        trickleDown(greatChildIndex);
    }

	void trickleUpReversed(const int &currentIndex)
    {
        int pIndex = parentIndex(currentIndex);
        if(pIndex == currentIndex || values[pIndex] <= values[currentIndex]){return;}
        std::swap(values[pIndex],values[currentIndex]);
        trickleUpReversed(pIndex);
    }

	void trickleDownReversed(const int &currentIndex)
    {
        int leastChildIndex = leastChild(leftChildIndex(currentIndex),rightChildIndex(currentIndex));
        if(leastChildIndex == -1){return;}
        else if(values[leastChildIndex] > values[currentIndex]){return;}
        std::swap(values[leastChildIndex],values[currentIndex]);
        trickleDownReversed(leastChildIndex);
    }

	int parentIndex(const int &index)
    {
        return (index-1)/2;
    }
	int leftChildIndex(const int &index)
    {
        int indexChild = index*2+1;
        if(indexChild >= values.size()){return -1;}
        return indexChild;
    }
    int rightChildIndex(const int &index)
    {
        int indexChild = index*2+2;
        if(indexChild >= values.size()){return -1;}
        return indexChild;
    }

	int graterChild(const int &leftIndex,const int &rightIndex)
    {
        if(leftIndex == -1 && rightIndex == -1){return -1;}
        else if(leftIndex == -1){return rightIndex;}
        else if(rightIndex == -1){return leftIndex;}
        else if(values[rightIndex] > values[leftIndex]){return rightIndex;}
        else{return leftIndex;}
    }
	int leastChild(const int &leftIndex, const int &rightIndex)
    {
        if(leftIndex == -1 && rightIndex == -1){return -1;}
        else if(leftIndex == -1){return rightIndex;}
        else if(rightIndex == -1){return leftIndex;}
        else if(values[rightIndex] < values[leftIndex]){return rightIndex;}
        else{return leftIndex;}
    }

private:
	std::vector<int> values;
	bool reversed;
};



int main()
{
    BinaryHeap heap{};
    heap.reverse();
    int countOperation,value;
	std::cin >> countOperation;
	for (size_t i = 0; i < countOperation; i++)
	{
		std::cin >> value;
		heap.push(value);
	}
    for (size_t i = 0; i < countOperation; i++)
    {
        std::cout << heap.top() << ' ';
        heap.pop();
    }
    
}