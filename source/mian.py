def generate_permutations(n):
    def backtrack(permutation):
        if len(permutation) == n:
            permutations.append(permutation[:])
            return
        for letter in letters:
            if (letter == 'A' and permutation and permutation[-1] != 'A') or (letter != 'A'):
                permutation.append(letter)
                backtrack(permutation)
                permutation.pop()

    permutations = []
    letters = ['A', 'B', 'C']
    backtrack([])
    return permutations

# Example usage
permutations = generate_permutations(2)
print(len(permutations))
for perm in permutations:
    print(''.join(perm))
