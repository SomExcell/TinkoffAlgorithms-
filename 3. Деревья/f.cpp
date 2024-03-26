#include <iostream>
#include <vector>

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree(const T &value):value(value){}

public:
    void push(const T &value)
    {
        BinarySearchTree<T> *node = this;
        while(true)
        {
            if(value == node->value){return;}
            else if(value < node->value)
            {
                if(node->left == nullptr)
                {
                    node->left = new BinarySearchTree<T>(value);
                    return;
                }else
                {
                    node = node->left;
                }
            }else if(value > node->value)
            {
                if(node->right == nullptr)
                {
                    node->right = new BinarySearchTree<T>(value);
                    return;
                }else
                {
                    node = node->right;
                }
            }
        }
    }

    T next(const T &value)
    {
        BinarySearchTree<T> *node = this;
        int res = -1;
        while(node)
        {
            if(node->value == value){return value;}
            else if(node->value > value){res = node->value;}
            if(node->value > value){node = node->left;}
            else if(node->value < value){node = node->right;}
        }
        return res;
    }

private:
    T value;
    BinarySearchTree<T> *left = nullptr;
    BinarySearchTree<T> *right = nullptr;
};

int main()
{
    BinarySearchTree<long> tree{0};
    long count,value,y;
    char operation;
    bool prevOperationNext = false;
    std::cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> operation;
        std::cin >> value;
        if(operation == '+')
        {
            if(prevOperationNext)
            {
                tree.push((value+y)%1000000000);
            }else{
                tree.push(value);
            }
            prevOperationNext = false;
            
        }else if(operation == '?')
        {
            y = tree.next(value);
            y == -1 ? prevOperationNext = false :prevOperationNext = true;
            std::cout << y << std::endl;
        }
    }
    
    
}