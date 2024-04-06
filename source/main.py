def largest_square_area(rectangle):
    n = len(rectangle)
    m = len(rectangle[0])

    dp = [[0] * m for _ in range(n)]

    max_side = 0

    # Initialize first row and column
    for i in range(n):
        dp[i][0] = int(rectangle[i][0])
        max_side = max(max_side, dp[i][0])
    for j in range(m):
        dp[0][j] = int(rectangle[0][j])
        max_side = max(max_side, dp[0][j])

    # Fill DP table
    for i in range(1, n):
        for j in range(1, m):
            if rectangle[i][j] == '1':
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                max_side = max(max_side, dp[i][j])

    return max_side * max_side  # Return area of the largest square

# Example usage:
rectangle = [
    ['0', '1', '0', '0', '0'],
    ['0', '1', '0', '1', '1'],
    ['0', '1', '1', '0', '1'],
    ['0', '0', '0', '1', '0']
]
print("Area of largest square consisting only of 1s:", largest_square_area(rectangle))
