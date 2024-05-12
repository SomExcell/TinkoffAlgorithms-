#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int n, m, a[20];
long long s;
vector<int> cur, res;
void f(int pos = 0, long long sum = 0) {
    if (pos == m) 
    {
        if (sum == n) 
        {
            if (!res.size() || cur.size() < res.size()) 
            {
                res = cur;
            }
            return;
        }
        return;
    }
    f(pos + 1, sum);
    cur.push_back(a[pos]);
    f(pos + 1, sum + a[pos]);
    cur.push_back(a[pos]);
    f(pos + 1, sum + a[pos] * 2);
    cur.pop_back();
    cur.pop_back();
}

std::string first()
{
    std::string answer;
    //cin >> n >> m;
    for (int i = 0; i < m; i++) 
    {
        //cin >> a[i];
        s += a[i] * 2;
    }
    if (s < n) 
    {
        answer = "-1";
        return answer;
    }
    f();
    if (!res.size()) {
        answer = "0";
        return answer;
    }
    answer += to_string(res.size()) + "\n";
    for (auto ans : res) answer+=to_string(ans)+' ';
    return answer;
}

int indexOne(size_t val)
{
    size_t counter = 1;
    int result = 0;
    while(counter <= val){counter*=2;result+=1;}
    return result - 1;
}

std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r+=(n%2==0 ?"0":"1"); n/=2;}
    return r;
}

std::string second(int n, int m)
{
    std::string answer;
    size_t price = n,countM = m,countVar;
    //std::cin >> price >> countM;
    countM*=2;
    
    std::vector<size_t> monets(countM);
    for (size_t i = 0; i < countM; i+=2)
    {
        size_t val;
        //std::cin >> val;
        monets[i] = monets[i+1] = a[i/2];
    }
    
    std::sort(monets.begin(),monets.end());
    countVar = std::pow(2,countM);
    std::vector<size_t> dp(countVar);
    std::vector<size_t> countOnes(countVar);
    for (size_t i = 1; i < countVar; i++)
    {
        size_t index = indexOne(i);
        size_t indexPrev = indexOne(i-1);
        dp[i] = dp[i ^ int(std::pow(2,index))]+ monets[index];
        countOnes[i]+=1;
        int v = countOnes[i^int(std::pow(2,index))];
        countOnes[i]+=countOnes[i^int(std::pow(2,index))];
    }
    int result = -1;
    size_t index;
    int countOne = 1e9;
    for (size_t i = 1; i < countVar; i++)
    {
        if(dp[i] > price && result != 1){result = 0;}
        else if(dp[i] == price && countOnes[i] < countOne)
        {
            countOne = countOnes[i];
            result = 1;index = i;
        }
    }
    if(result == 1)
    {
        int count = 0;
        std::string str = toBinary(index);
        for (size_t i = 0; i < str.size(); i++)
        {
            if(str[i] == '1'){++count;}
        }
        
        answer += to_string(count) + '\n';
        
        for (size_t i = 0; i < str.size(); i++)
        {
            if(str[i] == '1'){answer+=  to_string(monets[i]) + ' ';}
        }
        
    }
    else
    {
        answer = to_string(result);
    }
    return answer;
}



int main() 
{
    int inf = 1000;
    srand(time(0));
    while(true)
    {
        //size_t n,m;
        n = rand() % inf + 1;
        m = rand() % 10 + 1;
        for (size_t i = 0; i < m; i++)
        {
            size_t random = rand()%inf+1;
            a[i] = random;
        }
        std::sort(begin(a),a+m);
        std::string firs = first();
        std::string sec = second(n,m);
        if(firs[0] != sec[0])
        {
            std::cout << "AnswersFirst:\n"<< firs << "\nAnswerSec:\n" << sec << '\n';
            std::cout << "Test\n" << n << ' ' << m << '\n';
            for (size_t i = 0; i < m; i++)
            {
                std::cout << a[i] << ' ';
            }
            std::cout << "\n\n";
            first();
            second(n,m);
            //break;
        }
        for (size_t i = 0; i < 20; i++)
        {
            a[i] = 0;
        }
        std::cout.clear();
        s = 0;
        res.clear();
        cur.clear();
    }

    return 0;
}