import numpy as np
import matplotlib.pyplot as plt


def fftAnalise():
    a = np.loadtxt(r"C:\Users\amirf\CLion\astronomyProject\cmake-build-debug\table.txt")
    betta = a[:, 0]
    freq = np.fft.rfftfreq(len(betta))
    ampl = np.abs(np.fft.rfft(betta))
    plt.plot(freq[:np.argmax(freq > 0.007)], ampl[:np.argmax(freq > 0.007)], 'o')
    plt.show()

def plot():
    a = np.loadtxt(r"C:\Users\amirf\CLion\astronomyProject\cmake-build-debug\table.txt")
    plt.figure(figsize=(9, 9))
    plt.subplot(2, 2, 1)
    plt.plot(a[:, 0], a[:, 1], '.', )
    plt.title('Аналемма')
    plt.xlabel('β')
    plt.ylabel('γ')
    plt.subplot(2, 2, 2)
    plt.plot(a[:, 0], '.')
    plt.title('β')
    plt.subplot(2, 2, 3)
    plt.plot(a[:, 1], '.')
    plt.title('γ')
    # plt.subplot(2, 2, 4)
    # plt.plot(a[:, 2])
    # plt.title('alpha')
    # plt.show()
    plt.savefig('img/bigEx0.8.png', dpi=300)
    plt.close()

# fftAnalise()

plot()