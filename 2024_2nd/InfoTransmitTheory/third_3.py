import numpy as np
import matplotlib.pyplot as plt

num_samples = 10000
SNR_dB = np.linspace(0, 10, 100)
SNR = 10**(SNR_dB/10)
np.random.seed(10)
simulated_BER_MAP = []
P_a0 = 1 / 4
P_a1 = 3 / 4

for i in SNR:
    noise_std = np.sqrt(1 / (2 * i))
    a = np.random.choice([-1, 1], size=num_samples, p=[P_a0, P_a1])
    w = np.random.normal(0, noise_std, num_samples)
    z = a + w
    threshold = noise_std**2 * np.log(P_a1 / P_a0)
    a_hat = np.where(z > threshold, 1, -1)
    errors = np.sum(a != a_hat)
    simulated_BER_MAP.append(errors / num_samples)

plt.figure(figsize=(10, 6))
plt.semilogy(SNR_dB, simulated_BER_MAP, color="green")
plt.xlabel("Eb/No")
plt.ylabel("BER")
plt.grid(True, which="both", alpha=0.6)
plt.legend()
plt.show()
