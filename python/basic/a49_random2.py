# pip install matplotlib
import math, random
import matplotlib.pyplot as plt


def main():
    n_sample = 10000
    sample_size = 30
    a = 0
    b = 1
    
    means = []
    for _ in range(n_sample):
        sample = [random.uniform(a,b) for _ in range(sample_size)]
        mean = sum(sample) / sample_size
        means.append(mean)
    
    plt.hist(means, bins=sample_size)
    
    mu = (a + b) / 2
    sigma = math.sqrt((b - a) ** 2 / (12 * sample_size))  # 표준 편차
    
    x = [mu - 4 * sigma + i * (8 * sigma / 100) for i in range(100)]
    y = [random.gauss(mu, sigma) for t in x]

    plt.plot(x, y)
    plt.show()

if __name__ == "__main__":
    main()