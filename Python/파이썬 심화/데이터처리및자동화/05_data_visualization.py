import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 100)
y = np.sin(x)

plt.figure(figsize=(8, 6))
plt.plot(x, y, label='sin(x)')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Sine Wave')
plt.legend()
plt.grid(True)
plt.show()

categories = ['A', 'B', 'C', 'D']
values = [23, 45, 56, 78]

plt.figure(figsize=(6, 4))
plt.bar(categories, values)
plt.xlabel('카테고리')
plt.ylabel('값')
plt.title('Bar Chart')
plt.show()

sizes = [30, 25, 20, 15, 10]
labels = ['A', 'B', 'C', 'D', 'E']

plt.figure(figsize=(6, 6))
plt.pie(sizes, labels=labels, autopct='%1.1f%%')
plt.title('Pie Chart')
plt.show()

x_scatter = np.random.rand(50)
y_scatter = np.random.rand(50)

plt.figure(figsize=(6, 6))
plt.scatter(x_scatter, y_scatter, alpha=0.6)
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Scatter Plot')
plt.show()

