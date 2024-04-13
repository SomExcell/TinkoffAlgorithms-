def longest_valid_bracket_sequence(s):
    stack = []
    max_length = 0
    start_index = -1

    bracket_pairs = {']': '[', '}': '{', ')': '('}

    for i, char in enumerate(s):
        if char in bracket_pairs.values():
            stack.append((char, i))
        elif char in bracket_pairs.keys():
            if stack and stack[-1][0] == bracket_pairs[char]:
                stack.pop()
                current_length = i - (stack[-1][1] if stack else start_index)
                if current_length > max_length:
                    max_length = current_length
            else:
                start_index = i

    longest_sequence = ''
    if stack:
        stack.append(('end', len(s)))
        for i in range(len(stack) - 1):
            if stack[i][0] != 'end':
                sequence = s[stack[i][1]:stack[i + 1][1]]
                if len(sequence) > len(longest_sequence):
                    longest_sequence = sequence

    return longest_sequence

# Пример использования:
bracket_sequence = "{([)}][]"
print("Наибольшая правильная скобочная последовательность:", longest_valid_bracket_sequence(bracket_sequence))
