import numpy as np
import matplotlib.pyplot as plt


def plot_runge():

    data = np.loadtxt("./build/test-runge-out.txt")

    x = data[:, 0]
    y = data[:, 1]


    fig, axs = plt.subplots(1, 1, figsize=(10,10))  
    axs.plot(x, y)

    lmax = np.max(np.abs([x, y])) * 1.2
    lmin = -lmax * 1.2

    axs.set_xlim((lmin, lmax))
    axs.set_ylim((lmin, lmax))

    axs.plot(x[0], y[0], "bo")
    axs.plot(x[-1], y[-1], "ro")



if __name__ == "__main__":
    plot_runge()
    
    plt.show()