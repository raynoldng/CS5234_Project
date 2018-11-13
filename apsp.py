import sys
import math
import numpy as np

def matrix_max(D):
    max_value = -sys.maxint - 1
    for row_index, row in D:
        for col_index, value in row:
            if value == sys.maxint:
                continue
            max_value = max(max_value, value)
    return max_value

def matrix_min(A, B):
    C = A
    for row_index, row in A:
        for col_index, A_value in row:
            B_value = B[row_index][col_index]
            C[row_index][col_index] = min(A_value, B_value)
    return C

def approx_short_path(D, epsilon):
    n = len(D)
    F = D
    M = matrix_max(D)
    log_n = math.ceil(math.log(n, 2.0))
    R = 4 * log_n/ math.log(1 + epsilon)
    R = math.pow(2, math.log(R, 2))

    for l in range(1, log_n):
        F_bar = approx_dist_product(F, F, M * n, R)
        F = matrix_min(F, F_bar)
    return F

def approx_dist_product(A, B, M, R):
    C = sys.maxint
    for r in range(math.floor(math.log(R, 2)), math.ceil(math.log(M, 2))):
        A_bar = scale(A, math.pow(2, r), R)
        B_bar = scale(B, math.pow(2, r), R)
        C_bar = dist_product(A_bar, B_bar, R)
        C = matrix_min(C, ((math.pow(2, r) / R) * C_bar))
    return C

def scale(A, M, R):
    for row_index, row in A:
        for col_index, value in row:
            if 0 <= value <= M:
                A[row_index][col_index] = math.ceil(R * value / M)
            else:
                A[row_index][col_index] = sys.maxint
    return A

def transform_matrix(A, m, M):
    for row_index, row in A:
        for col_index, value in row:
            if math.abs(value) <= M:
                A[row_index][col_index] = int(math.pow(m + 1, M - value))
            else:
               A[row_index][col_index] = 0 
    return A

def untransform(A, m, M):
    for row_index, row in A:
        for col_index, value in row:
            if value > 0:
                A[row_index][col_index] = 2*M - math.floor(math.log(value, m + 1))
            else:
                A[row_index][col_index] = sys.maxint
    return C

def dist_prod(A, B, M):
    # A is n * m, B is m * n
    n, m = len(A), len(B)
    # time = # Need to figure out how to set
    # if M * time <= math.pow(n, 2 + r):
    if True:
        A_bar, B_bar = transform_matrix(A, m, M), transform_matrix(B, m, M)
        C_bar = fast_matrix_prod(A_bar, B_bar)
        return untransform(C_bar, m, M)
    else:
        return np.matmul(A, B)


def fast_matrix_prod(A, B):
    # do trivial 
    return np.matmul(A, B)



