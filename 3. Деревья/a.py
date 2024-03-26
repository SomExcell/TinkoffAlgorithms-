def dfs(tree, start):
    visited = set()
    stack = [(start, 0)]

    maxDistance = 0
    further = start

    while stack:
        node, distance = stack.pop()
        if node not in visited:
            visited.add(node)
            if distance > maxDistance:
                maxDistance = distance
                further = node

            for child in tree[node]:
                stack.append((child, distance + 1))

    return further, maxDistance

def diameter(tree):
    startNode = next(iter(tree))
    further, _ = dfs(tree, startNode)
    _, diameter = dfs(tree, further)
    return diameter

count = int(input())
p = list(map(int, input().split()))
currNum = 0
d = {0: 1}
h = {currNum: 0}
adj = {0: []}
answer = [0]
H = 0
for i in range(count - 1):
    currNum += 1
    if p[i] in adj:
        adj[p[i]].append(currNum)
    else:
        adj[p[i]] = [currNum]
    if currNum in adj:
        adj[currNum].append(p[i])
    else:
        adj[currNum] = [p[i]]

    h_i = h[p[i]] + 1
    h[currNum] = h_i
    answer.append(h_i)
    H = max(H, h_i)

D = diameter(adj)

print(H, D)
print(*answer)