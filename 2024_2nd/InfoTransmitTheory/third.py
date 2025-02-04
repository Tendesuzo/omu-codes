import numpy as np
import matplotlib.pyplot as plt
from scipy.special import erfc

SNR_dB = np.linspace(0, 10, 100)
SNR = 10**(SNR_dB/10)
BER = 0.5 * erfc(np.sqrt(SNR))

plt.figure(figsize=(10, 6))
plt.semilogy(SNR_dB, BER, color="blue")
plt.xlabel("Eb/No")
plt.ylabel("BER")
plt.grid(True, which="both", linestyle="--", alpha=0.6)
plt.legend()
plt.xlim(0, 10)
plt.xticks(range(int(min(SNR_dB)), int(max(SNR_dB)) + 1, 1))
plt.ylim(10**-6, 10**0)
plt.show()
