#python script to create random inputs to test the matrix multiplication

import numpy as np

# Create two random 10x10 matrices
matrix1 = np.random.rand(100, 100)
matrix2 = np.random.rand(100, 100)

# Round the matrices and multiply by 100
matrix1 = np.round(matrix1 * 100)
matrix2 = np.round(matrix2 * 100)

# Save the matrices to a text file
with open("matrices_output.txt", "w") as file:
    # file.write("Matrix 1:\n")
    file.write(str(matrix1))
    # file.write("\n\nMatrix 2:\n")
    file.write(str(matrix2))

# print("Matrices have been saved to 'matrices_output.txt'.")
