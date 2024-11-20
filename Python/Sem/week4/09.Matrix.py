import random
def createMatrix(row,col):
    matrix=[]
    for i in range(row):
        addRow=[random.randint(1,10) for i in range(col)]
        matrix.append(addRow)
    return matrix
def printMatrix(matrix):
    for row in range(len(matrix)):
        for i in range(len(matrix[row])):
            print(matrix[row][i],end=" ")
        print()


def columnSum(matrix):
    transposed = [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]
    sums=[]
    for row in range(len(transposed)):
        sum=0
        for i in range(len(transposed[row])):
            sum+=transposed[row][i]
        sums.append(sum)
    print(sums)
matrix=createMatrix(3,4)
printMatrix(matrix)

print("----------------")
columnSum(matrix)
