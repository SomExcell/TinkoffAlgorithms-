#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


int main() {
	
    int n;
    std::cin >> n;
    std::vector<int> vec(n);
    for (size_t i = 0; i < n; i++)
    {
        vec[i] = i+1;
    }
    
    for (size_t i = 0; i < n; i++)
    {
        std::swap(vec[i],vec[i/2]);
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cout << vec[i] << ' ';
    }
    
	return 0;
}