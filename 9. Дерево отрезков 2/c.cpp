#include <iostream>
#include <vector>

int getMiddle(int left, int right) 
{
    return left + (right - left) / 2;
}

struct Node 
{
    int number;
    int segments;
    int set;
    int l;
    int r;
    bool up;

    Node() 
    {
        number = 1;
        segments = 1;
        set = 0;
        up = false;
        l = 0;
        r = 0;
    }

    Node(int n, int seg, int s, int left, int right, bool u) 
    {
        number = n;
        segments = seg;
        set = s;
        l = left;
        r = right;
        up = u;
    }
};

std::vector <Node> tree;
std::vector<char> color;
std::vector<int> cord;
std::vector<int> delta;
int count;

void build(int v, int tl, int tr) 
{
    if (tl == tr) 
    {
        tree[v] = Node(0, 0, 0, tl, tr, false);
    } 
    else 
    {
        int tm = getMiddle(tl, tr);
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        tree[v] = Node(0, 0, 0, tl, tr, false);
    }
}

void push(int v) 
{
    if (!tree[v].up){return;}
        
    tree[v].number = tree[v].set * (tree[v].r - tree[v].l + 1);
    tree[v].segments = 1 * tree[v].set;
    tree[v].up = false;

    if (tree[v].l == tree[v].r){return;}
        
    tree[v * 2].set = tree[v].set;
    tree[v * 2 + 1].set = tree[v].set;

    tree[v * 2].up = true;
    tree[v * 2 + 1].up = true;
}

bool leftisblack(int v) 
{
    push(v);
    if (tree[v].l == tree[v].r){return tree[v].number == 1;}
    return leftisblack(v * 2);
}

bool rightisblack(int v) 
{
    push(v);
    if (tree[v].l == tree[v].r){return tree[v].number == 1;}
    return rightisblack(v * 2 + 1);
}

void update(int v, int value, int l, int r) {
    if (tree[v].r < l || tree[v].l > r)
        return;

    if (tree[v].r <= r && tree[v].l >= l) {
        push(v);
        tree[v].set = value;
        tree[v].up = true;
        return;
    }

    push(v);
    update(v * 2, value, l, r);
    update(v * 2 + 1, value, l, r);

    bool left = rightisblack(v * 2);
    bool right = leftisblack(v * 2 + 1);

    tree[v].number = tree[v * 2].number + tree[v * 2 + 1].number;
    tree[v].segments = tree[v * 2 + 1].segments + tree[v * 2].segments;

    if (left && right) {
        tree[v].segments--;
    }
}

int main() 
{
    std::cin >> count;
    color.resize((unsigned) count);
    cord.resize((unsigned) count);
    delta.resize((unsigned) count);

    int maxdelta = 0;
    int del;
    int maxcord = INT32_MIN;
    int mincord = INT32_MAX;

    for (int i = 0; i < count; i++) {
        std::cin >> color[i] >> cord[i] >> delta[i];

        if (delta[i] > 0) delta[i]--;
        else delta[i]++;

        del = cord[i] + delta[i];
        if (del > maxcord) 
        {
            maxcord = del;
        }

        if (maxdelta > cord[i]) 
        {
            maxdelta = cord[i];
        }
    }

    int length;
    if (maxdelta < 0) 
    {
        length = maxcord - maxdelta + 1;
    } else 
    {
        length = maxcord + 1;
    }

    tree.resize((unsigned) (4 * length));
    build(1, 0, length);
    for (int i = 0; i < count; i++) 
    {
        if (color[i] == 'W') 
        {
            update(1, 0, cord[i] - maxdelta, cord[i] + delta[i] - maxdelta);
            std::cout <<  tree[1].segments << ' ' << tree[1].number;
        }

        if (color[i] == 'B') 
        {
            update(1, 1, cord[i] - maxdelta, cord[i] + delta[i] - maxdelta);
            std::cout <<  tree[1].segments << ' ' << tree[1].number;
        }
        std::cout << '\n';
    }
    return 0;
}