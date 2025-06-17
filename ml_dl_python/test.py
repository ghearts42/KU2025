import matplotlib.pyplot as plt

data = [(1,), (2,), (3,), (4,)]
values = [x[0] for x in data]

plt.plot(values, marker='o')
plt.title('One-element Tuples Visualization')
plt.xlabel('Index')
plt.ylabel('Value')
plt.grid(True)
plt.show()