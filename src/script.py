#!/bin/python3

import random
import sys

def generate_random_numbers(count, int_min, int_max):
    if int_min > int_max:
        raise ValueError("int_min must be less than or equal to int_max")
    return [random.randint(int_min, int_max) for _ in range(count)]

# Parameters
int_min = -2147483648  # Minimum value for a 32-bit integer
int_max = 2147483647   # Maximum value for a 32-bit integer
count = 500            # Number of random numbers to generate
if 1 < len(sys.argv):
	count = int(sys.argv[1])

# Generate random numbers
random_numbers = generate_random_numbers(count, int_min, int_max)

# Save to a file or print
with open("random_numbers.txt", "w") as file:
    file.write(" ".join(map(str, random_numbers)))

print("500 random numbers have been generated and saved to 'random_numbers.txt'.")
