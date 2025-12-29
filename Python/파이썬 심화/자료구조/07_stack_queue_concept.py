stack = []

stack.append(1)
stack.append(2)
stack.append(3)

print(f"스택: {stack}")

top = stack.pop()
print(f"팝: {top}, 스택: {stack}")

from collections import deque

queue = deque()

queue.append(1)
queue.append(2)
queue.append(3)

print(f"큐: {list(queue)}")

front = queue.popleft()
print(f"디큐: {front}, 큐: {list(queue)}")

def is_balanced(s):
    stack = []
    pairs = {')': '(', '}': '{', ']': '['}
    
    for char in s:
        if char in pairs.values():
            stack.append(char)
        elif char in pairs:
            if not stack or stack.pop() != pairs[char]:
                return False
    
    return len(stack) == 0

print(is_balanced("()[]{}"))
print(is_balanced("([)]"))

