#!/usr/bin/python3
'''Module that rotates a square matrix clockwise'''


def rotate_2d_matrix(matrix):
    '''Function that rotates a square matrix 90° clockwise'''
    n = len(matrix)
    for x in range(0, int(n / 2)):
        for y in range(x, n-x-1):
            tmp = matrix[x][y]
            matrix[x][y] = matrix[n-y-1][x]
            matrix[n-y-1][x] = matrix[n-x-1][n-y-1]
            matrix[n-x-1][n-y-1] = matrix[y][n-x-1]
            matrix[y][n-x-1] = tmp