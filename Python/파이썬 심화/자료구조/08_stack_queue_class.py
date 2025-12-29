class Stack:
    def __init__(self):
        self.items = []
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        if self.is_empty():
            raise IndexError("스택이 비어있습니다")
        return self.items.pop()
    
    def peek(self):
        if self.is_empty():
            raise IndexError("스택이 비어있습니다")
        return self.items[-1]
    
    def is_empty(self):
        return len(self.items) == 0
    
    def size(self):
        return len(self.items)

stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
print(f"스택 크기: {stack.size()}")
print(f"탑: {stack.peek()}")
print(f"팝: {stack.pop()}")

class Queue:
    def __init__(self):
        self.items = []
    
    def enqueue(self, item):
        self.items.append(item)
    
    def dequeue(self):
        if self.is_empty():
            raise IndexError("큐가 비어있습니다")
        return self.items.pop(0)
    
    def front(self):
        if self.is_empty():
            raise IndexError("큐가 비어있습니다")
        return self.items[0]
    
    def is_empty(self):
        return len(self.items) == 0
    
    def size(self):
        return len(self.items)

queue = Queue()
queue.enqueue(1)
queue.enqueue(2)
queue.enqueue(3)
print(f"큐 크기: {queue.size()}")
print(f"프론트: {queue.front()}")
print(f"디큐: {queue.dequeue()}")

