import numpy as np
import matplotlib.pyplot as plt

def generate_16QAM_symbols():
    real = np.array([-3, -1, 1, 3])
    imag = np.array([-3, -1, 1, 3])
    return np.array([r + 1j * i for r in real for i in imag])

def calculate_average_energy(symbols):
    energy = np.mean(np.abs(symbols)**2)
    return energy

def simulate_received_signals(symbols, Es_N0, generate_signals_num):
    Es = calculate_average_energy(symbols)
    N0 = Es / (10**(Es_N0 / 10))
    noise_std = np.sqrt(N0 / 2)
    a = np.random.choice(symbols, size=generate_signals_num)
    w = noise_std * (np.random.randn(generate_signals_num) + 1j * np.random.randn(generate_signals_num))
    z = a + w
    return a, z

Es_N0 = 10
generate_signals_num = 100

symbols = generate_16QAM_symbols()

a, z = simulate_received_signals(symbols, Es_N0, generate_signals_num)

plt.scatter(z.real, z.imag, color='blue', s=20, alpha=0.6)
plt.title("16QAM Received Symbols with Gaussian Noise (Es/N0 = 10dB)")
plt.grid(True, linestyle='--', alpha=0.5)
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)
plt.axis('equal')
plt.show()
