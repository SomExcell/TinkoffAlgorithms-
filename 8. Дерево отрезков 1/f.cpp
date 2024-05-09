#include <iostream>
#include <vector>
#include <algorithm>

const int mx = 1000006;

long long tree[2][mx];
long long arr1[mx],arr2[mx];

void update(int id, int idx, long long val)
{
    for(; idx<mx && idx; idx+=idx&-idx)
        tree[id][idx]+=val;
}

long long query(int id, int idx)
{
    long long ret=0;
    for(; idx; idx-=idx&-idx)
        ret+=tree[id][idx];
    return ret;
}

std::vector<long long> vec;

int main()
{
    int count;
    std::cin >> count;
    vec.push_back(0);
    for (size_t i = 1; i <= count; i++)
    {
        std::cin >> arr1[i];
        vec.push_back(arr1[i]);
    }
    std::sort(vec.begin(),vec.end());

    long long ans = 0;

    for(int i=count; i>0; i--)
    {
        int id=lower_bound(vec.begin(),vec.end(),arr1[i])-vec.begin();
        arr2[i]=query(0,id);
        update(0,id+1,1);
    }

    for(int i=count; i>0; i--)
    {
        int id=lower_bound(vec.begin(),vec.end(),arr1[i])-vec.begin();
        ans+=query(1,id);
        update(1,id+1,arr2[i]);
    }

    std::cout << ans;

    return 0;
}