A = [[0,0,0],
[0,0,0],
[0,0,0]] 

B = [[0,0,0],
[0,0,0],
[0,0,0]] 

def get_matrix(M):
    print("Enter elements rowwise: ")
    counter = 1
    for i in range(3):          
        for j in range(3):
            M[i][j] = int(input("Element %i: " % counter))         #string modulo(%) operator used to simulate printf 
            counter += 1

get_matrix(A)
get_matrix(B)

Add = [[0,0,0],
[0,0,0],
[0,0,0]] 
for i in range(3):          
    for j in range(3):
        Add[i][j] = A[i][j] + B[i][j]

Sub = [[0,0,0],
[0,0,0],
[0,0,0]] 
for i in range(3):          
    for j in range(3):
        Sub[i][j] = A[i][j] - B[i][j]  

Trans = [[0,0,0],
[0,0,0],
[0,0,0]] 
for i in range(3):          
    for j in range(3):
        Trans[j][i] = A[i][j]

Multi = [[0,0,0],
[0,0,0],
[0,0,0]] 
for i in range(3):          
    for j in range(3):
        for k in range(3):
            Multi[i][j] += A[i][k] * B[k][j]  

     
def display(M):
    for i in range(3):
        for j in range(3):
            print(M[i][j], end = " ")  
        print()                          #blank print() works like newline

print("Matrix 1:")
display(A)
print("Matrix 2:")
display(B)
print("Transpose:")
display(Trans)
print("Addition:")
display(Add)
print("Subtraction:")
display(Sub)
print("Multiplication:")
display(Multi)