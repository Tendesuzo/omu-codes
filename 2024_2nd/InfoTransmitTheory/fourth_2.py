import numpy as np
import matplotlib.pyplot as plt
from scipy.special import erfc

def generate_16QAM_symbols():
    real = np.array([-3, -1, 1, 3])
    imag = np.array([-3, -1, 1, 3])
    return np.array([r + 1j * i for r in real for i in imag])

def Q(x):
    return 0.5 * erfc(x / np.sqrt(2))

def theoretical_SER(Es_N0_dB, M=16):
    Es_N0 = 10 ** (Es_N0_dB / 10)
    return 1 - (1 - 2 * (1 - 1/np.sqrt(M)) * Q(np.sqrt(3 * Es_N0 / (M-1)))) * (1 - 2 * (1 - 1/np.sqrt(M)) * Q(np.sqrt(3 * Es_N0 / (M-1))))

def simulate_received_signals(symbols, Es_N0, generate_signals_num):
    Es = calculate_average_energy(symbols)
    N0 = Es / (10**(Es_N0 / 10))
    noise_std = np.sqrt(N0 / 2)
    a = np.random.choice(symbols, size=generate_signals_num)
    w = noise_std * (np.random.randn(generate_signals_num) + 1j * np.random.randn(generate_signals_num))
    z = a + w
    return a, z

def simulate_SER(symbols, Es_N0_dB, generate_signals_num=1000):
    a, z = simulate_received_signals(symbols, Es_N0_dB, generate_signals_num)
    errors = 0
    for i in range(generate_signals_num):
        distance = np.abs(z[i] - symbols)
        if np.argmin(distance) != np.where(symbols == a[i])[0]:
            errors += 1
    return errors / generate_signals_num

def calculate_average_energy(symbols):
    energy = np.mean(np.abs(symbols)**2)
    return energy

Es_N0_dB_range = np.linspace(0, 10, 11)
theoretical_SER = [theoretical_SER(dB) for dB in Es_N0_dB_range]
simulation_SER = [simulate_SER(generate_16QAM_symbols(), dB) for dB in Es_N0_dB_range]

plt.semilogy(Es_N0_dB_range, theoretical_SER, label='Theoretical SER', color='blue', marker='o')
plt.semilogy(Es_N0_dB_range, simulation_SER, label='Simulated SER', color='red', marker='o')
plt.xlabel('Es/N0 (dB)')
plt.ylabel('Symbol Error Rate (SER)')
plt.title('16QAM Symbol Error Rate (SER)', fontsize=14)
plt.grid(True, which="both", linestyle="--", alpha=0.5)
plt.legend()
plt.show()
