#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

    long height,width,countQueries,value,y1,x1,y2,x2;
    std::cin >> height >> width >> countQueries;
    std::vector<std::vector<long>> sums(height,std::vector<long>(width));
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            std::cin >> value;
            if(j == 0){sums[i][j] = value;}
            else{sums[i][j] = sums[i][j-1] + value;}
        }
        
    }
    for (size_t i = 0; i < countQueries; ++i)
    {
        value = 0;
        std::cin >> y1 >> x1 >> y2 >> x2;
        for (size_t j = y1-1; j < y2; ++j)
        {
            if(x1 == 1)
            {
                value += sums[j][x2-1];
            }
            else
            {
                value += sums[j][x2-1] - sums[j][x1-2];
            }
        }
        std::cout << value << '\n';
    }
  
    return 0;
}