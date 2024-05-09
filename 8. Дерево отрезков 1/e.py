from bisect import bisect_left

class BinaryIndexedTree:

    def __init__(self, count):
        self.n = count
        self.c = [0] * (count + 1)
        self.d = [0] * (count + 1)

    def update(self, x, value, cnt):
        while x <= self.n:
            if self.c[x] < value:
                self.c[x] = value
                self.d[x] = cnt
            elif self.c[x] == value:
                self.d[x] += cnt
            x += x & -x

    def search(self, value):
        v = cnt = 0
        while value:
            if self.c[value] > v:
                v = self.c[value]
                cnt = self.d[value]
            elif self.c[value] == v:
                cnt += self.d[value]
            value -= value & -value
        return v, cnt


def findNumberOfLIS(nums: list[int]) -> int:
    arr = sorted(set(nums))
    count = len(arr)
    tree = BinaryIndexedTree(count)
    for val in nums:
        i = bisect_left(arr, val) + 1
        v, cnt = tree.search(i - 1)
        tree.update(i, v + 1, max(cnt, 1))
    return tree.search(count)[1]

count = int(input())
queries = list(map(int, input().split()))
INF = 10 ** 9 + 7

answer = findNumberOfLIS(queries)
print(answer % INF)