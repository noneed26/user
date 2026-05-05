# matrix operation
def add(A, B):
    n = len(A)
    res = []
    for i in range(n):
        row = []
        for j in range(n):
            temp = A[i][j] + B[i][j]
            row.append(temp)
        res.append(row)
    return res    
    
def subtract(A, B):
    n = len(A)
    res = []
    for i in range(n):
        row = []
        for j in range(n):
            temp = A[i][j] - B[i][j]
            row.append(temp)
        res.append(row)
    return res
    
# strassen algorithm
def strassen(A, B):
    n = len(A)
    
    # base case
    if n == 1:
        return [[A[0][0] * B[0][0]]]
        
    A11, A12, A21, A22 = [], [], [], []
    B11, B12, B21, B22 = [], [], [], []
    
    mid = n // 2    
    # divide matrix
    
    for i in range(mid):
        A11.append(A[i][:mid])
        A12.append(A[i][mid:])
        B11.append(B[i][:mid])    
        B12.append(B[i][mid:])
        
    for i in range(mid, n):
        A21.append(A[i][:mid])
        A22.append(A[i][mid:])
        B21.append(B[i][:mid])
        B22.append(B[i][mid:])
    
    # recuursive multplication
    M1 = strassen(add(A11, A22), add(B11, B22))
    M2 = strassen(add(A21, A22), B11)
    M3 = strassen(A11, subtract(B12, B22))
    M4 = strassen(A22, subtract(B21, B11))
    M5 = strassen(add(A11, A12), B22)
    M6 = strassen(subtract(A21, A11), add(B11, B12))
    M7 = strassen(subtract(A12, A22), add(B21, B22))
    
    C11 = add(subtract(add(M1, M4), M5), M7)
    C12 = add(M3, M5)
    C21 = add(M2, M4)
    C22 = add(subtract(add(M1, M3), M2), M6)

    C = []
    for i in range(mid):
        C.append(C11[i] + C12[i])
    for i in range(mid):
        C.append(C21[i] + C22[i])

    return C

# MAIN PROGRAM

# matrix size
n = int(input("Enter size of matrix: "))

print("Enter matrix A row-wise: ")
# matrix A
A = []
for i in range(n):
    row = list(map(int, input().split()))
    A.append(row)
    
print("Enter matrix B row-wise: ")
# matrix B
B = []
for i in range(n):
    row = list(map(int, input().split()))
    B.append(row)

result = strassen(A, B);
print("Result Matrix is: ")
for row in result:
    print(row)
    
# T(n)=7T(n/2)+O(n2)
# O(n2.81)