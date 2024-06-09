import math
import matplotlib.pyplot as plt

# Define asymptotic functions as lambda functions
log_n = lambda x: math.log(x)
n = lambda x: x
n_log_n = lambda x: x * math.log(x)
n_square = lambda x: x**2
n_cube = lambda x: x**3

# Define the range of values
range_values = range(1, 101, 10)

# Calculate function values for the range using lambda functions
log_n_values = [log_n(x) for x in range_values]
n_values = [n(x) for x in range_values]
n_log_n_values = [n_log_n(x) for x in range_values]
n_square_values = [n_square(x) for x in range_values]
n_cube_values = [n_cube(x) for x in range_values]

# Plot graphs
plt.plot(range_values, log_n_values, label='log(n)')
plt.plot(range_values, n_values, label='n')
plt.plot(range_values, n_log_n_values, label='n*log(n)')
plt.plot(range_values, n_square_values, label='n^2')
plt.plot(range_values, n_cube_values, label='n^3')

# Plot 2^n for a limited range
range_values_2n = range(1, 21)  # Limiting range for 2^n
two_n_values = [2**x for x in range_values_2n]
plt.plot(range_values_2n, two_n_values, label='2^n')

# Adjust x and y limits
plt.xlim(1, 100)  # Adjust x-axis limits
plt.ylim(0, 1000)  # Adjust y-axis limits

plt.legend()
plt.show()
