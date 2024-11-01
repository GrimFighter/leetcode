class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:

        row = [False for _ in matrix]
        col = [False for _ in matrix[0]]

        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    row[i] = True
                    col[j] = True

        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if row[i] or col[j]:
                    matrix[i][j] = 0
