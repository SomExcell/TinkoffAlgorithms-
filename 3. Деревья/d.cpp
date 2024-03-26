#include <iostream>
#include <vector>

struct BinaryHeap
{

public:
	void push(const int &value)
	{
		values.push_back(value);
		trickleUp(values.size()-1);
	}

	void pop()
	{
		std::swap(values[0],values[values.size()-1]);
		values.pop_back();
		trickleDown(0);
	}

	int max()
	{
		return values[0];
	}

private:
	void trickleUp(const int &currentIndex)
	{
		int pIndex = parentIndex(currentIndex);
		if(pIndex == currentIndex || values[pIndex] > values[currentIndex]){return;}
		std::swap(values[pIndex],values[currentIndex]);
		trickleUp(pIndex);
	}

	void trickleDown(const int &currentIndex)
	{
		int greatChildIndex(graterChildIndex(leftChildIndex(currentIndex),rightChildIndex(currentIndex)));
		if(greatChildIndex == -1){return;}
		else if(values[greatChildIndex] < values[currentIndex]){return;}
		std::swap(values[greatChildIndex],values[currentIndex]);
		trickleDown(greatChildIndex);
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

	int graterChildIndex(const int &leftIndex,const int &rightIndex)
	{
		if(leftIndex == -1 && rightIndex == -1){return -1;}
		else if(leftIndex == -1){return rightIndex;}
		else if(rightIndex == -1){return leftIndex;}
		else if(values[rightIndex] > values[leftIndex]){return rightIndex;}
		else{return leftIndex;}
	}

	int rightChildIndex(const int &index)
	{
		int indexChild = index*2+2;
		if(indexChild >= values.size()){return -1;}
		return indexChild;
	}

private:
	std::vector<int> values;
};

int main()
{
	BinaryHeap heap{};
	int countOperation,operation,value;
	std::cin >> countOperation;
	for (size_t i = 0; i < countOperation; i++)
	{
		std::cin >> operation;
		if(operation == 1)
		{
			std::cout << heap.max() << std::endl;
			heap.pop();
		}else if(operation == 0)
		{
			std::cin >> value;
			heap.push(value);
		}
	}
	return 0;
}