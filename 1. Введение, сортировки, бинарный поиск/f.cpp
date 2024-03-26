#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

long counter = 0;
void merge(std::vector<int>& vec, int l,int r)
{
    int i = l;
    int mid = l + (r - l) / 2;
    int j = mid + 1;
    int pos = 0;
    std::vector<int> result(r - l + 1);
    while(i <= mid || j <= r)
    {
        if(i <= mid && vec[i] <= vec[j] || j > r)
        {
            result[pos++] = vec[i++];
            //counter++;
        }else if (j <= r && vec[j] < vec[i] || i > mid)
        {
            if(i<=mid){
                counter+=mid-i+1;
            }
            result[pos++] = vec[j++];
        }
    }
    for (int i = l; i <= r; ++i)
    {
        vec[i] = result[i - l];
    }
    
}

void mergeSort(std::vector<int>& vec,int start,int end)
{
    if(end<=start){return;}
    int mid = start + (end - start) / 2;
    mergeSort(vec,start,mid);
    mergeSort(vec,mid+1,end);
    merge(vec,start,end);
}

int main()
{
    std::vector<int> vec;
    int count,value;
    std::cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> value;
        vec.push_back(value);
    }
    mergeSort(vec,0,count-1);
    std::cout << counter << std::endl;
    for (size_t i = 0; i < count; i++)
    {
        std::cout << vec[i] << ' ';
    }
    
    return 0;
}