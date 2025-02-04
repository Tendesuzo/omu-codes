import numpy as np
import matplotlib.pyplot as plt
from scipy.special import erfc

num_samples = 10000
SNR_dB = np.linspace(0, 10, 100)
SNR = 10**(SNR_dB/10)
BER = 0.5 * erfc(np.sqrt(SNR))
np.random.seed(10)
simulated_BER_ML = []

for i in SNR:
    noise_std = np.sqrt(1 / (2 * i))
    a = np.random.choice([-1, 1], size=num_samples)
    w = np.random.normal(0, noise_std, num_samples)
    z = a + w
    a_hat = np.sign(z)
    errors = np.sum(a != a_hat)
    simulated_BER_ML.append(errors / num_samples)

plt.figure(figsize=(10, 6))
plt.semilogy(SNR_dB, BER, label="Theoretical BER (Q-function)", color="blue")
plt.semilogy(SNR_dB, simulated_BER_ML, label="Simulated BER (ML Detection)", color="red")
plt.xlabel("Eb/No")
plt.ylabel("BER")
plt.grid(True, which="both", alpha=0.6)
plt.legend()
plt.show()
