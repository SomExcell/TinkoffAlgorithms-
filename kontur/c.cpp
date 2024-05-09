#include <iostream>
#include <vector>

long countComponents(const std::vector<long> &widthValues, const std::vector<long> &heightValues)
{
    long result = 0;
    bool countHeight = true,countWidth = true;
    for (size_t i = 0; i < widthValues.size(); ++i)
    {
        if(countHeight && heightValues[i] == 0)
        {
            for (size_t j = 0; j < heightValues.size(); ++j)
            {
                if(countWidth && widthValues[j] == 0)
                {
                    result+=1;
                    countWidth = false;
                }
                if(widthValues[j] > 0 )
                {
                    countWidth = true;
                }
            }
            countHeight = false;
            countWidth = true;
        }
        if(heightValues[i] > 0)
        {
            countHeight = true;
        }
    }
    
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
    long size,countQueries,width,height;
    std::cin >> size >> countQueries;
    std::vector<long> widthValues(size);
    std::vector<long> heightValues(size);
    char c;
    for (size_t i = 0; i < countQueries; ++i)
    {
        std::cin >> c >> width >> height;
        width--,height--;
        if(c == '+'){widthValues[width]++;;heightValues[height]++;}
        else if(c == '-'){widthValues[width]--;;heightValues[height]--;}
        std::cout << countComponents(widthValues,heightValues) << '\n';
    }
    

    return 0;
}