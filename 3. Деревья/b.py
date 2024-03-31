from functools import *
import sys

sys.setrecursionlimit(10 ** 9)

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

@lru_cache(None)
def heightTree(tree):
    if tree is None:
        return 0
    return 1 + max(heightTree(tree.left), heightTree(tree.right))

@lru_cache(None)
def isBalanced(tree):
    if tree is None:
        return True
    leftTree = heightTree(tree.left)
    rightTree = heightTree(tree.right)
    if abs(leftTree - rightTree) <= 1 and isBalanced(tree.left) and isBalanced(tree.right):
        return True
    return False


@lru_cache(None)
def isAvlTree(tree):
    if tree is None:
        return True
    return isBalanced(tree) and isAvlTree(tree.left) and isAvlTree(tree.right)


@lru_cache(None)
def isSubTreeValid(tree):
    if tree is None:
        return True
    if (tree.right and tree.right.key <= tree.key) or (tree.left and tree.left.key >= tree.key):
        return False
    return isSubTreeValid(tree.left) and isSubTreeValid(tree.right)

n, r = map(int, input().split())

tree = tuple(Node(i) for i in range(n))
for i in range(n):
    li, ri = map(int, input().split())
    if li != -1:
        tree[i].left = tree[li]
    if ri != -1:
        tree[i].right = tree[ri]

if isAvlTree(tree[r]) and isSubTreeValid(tree[r]):
    print(1)
else:
    print(0)