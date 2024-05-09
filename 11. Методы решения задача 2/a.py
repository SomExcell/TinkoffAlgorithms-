import sys

sys.setrecursionlimit(10 ** 9)

class LCA:
    def __init__(self, tree):
        self.tree = tree
        self.depth = [0] * len(tree)
        self.top = [[-1] * 20 for _ in range(len(tree))]
        self.dfs(0, -1)

    def dfs(self, node, par):
        self.depth[node] = self.depth[par] + 1
        self.top[node][0] = par
        for i in range(1, 20):
            if self.top[node][i - 1] != -1:
                self.top[node][i] = self.top[self.top[node][i - 1]][i - 1]

        for child in self.tree[node]:
            if child != par:
                self.dfs(child, node)

    def lca(self, u, v):
        if self.depth[u] < self.depth[v]:
            u, v = v, u
        for i in range(19, -1, -1):
            if self.depth[u] - (1 << i) >= self.depth[v]:
                u = self.top[u][i]
        if u == v:
            return u
        for i in range(19, -1, -1):
            if self.top[u][i] != self.top[v][i]:
                u = self.top[u][i]
                v = self.top[v][i]
        return self.top[u][0]


n = int(input())
tree = [[] for _ in range(n)]
nodes = list(map(int, input().split()))
for i in range(1, n):
    tree[nodes[i - 1]].append(i)

queries = int(input())
lca = LCA(tree)

for _ in range(queries):
    u, v = map(int, input().split())
    print(lca.lca(u, v))