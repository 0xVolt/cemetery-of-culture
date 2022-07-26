import numpy as np
import matplotlib.pyplot as plt

from scipy import stats
mu = 5
std = 2
snd = stats.norm(mu, std)
#
# Generate 1000 random values between -100, 100
#
x = np.linspace(-100, 100, 1000)

plt.figure(figsize=(7.5,7.5))
plt.plot(x, snd.pdf(x))
plt.xlim(-60, 60)
plt.title('Normal Distribution (Mean = 5, STD = 2)', fontsize='15',color='purple')
plt.show()