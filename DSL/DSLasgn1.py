groupA = []
groupB = []
groupC = []
uni = []
def get(group):
    length = int(input("Enter the no. of students: "))
    i = 0
    while i < length:
        rollno = int(input("Enter the rollno of students: "))
        i += 1
        if rollno in group:
            print("error: you have entered a duplicate value")
            i -= 1
        else:
            group.append(rollno)
    print(group)
    
def union(A, B):
    U = A.copy()
    for i in range(len(B)):
        flag = True                              #using flag as a boolean instead of number
        for j in range(len(A)):
            if(B[i] == A[j]):
                flag = False
                break
        if(flag):
            U.append(B[i])
    return U

def inters(A, B):
    I = []
    for i in range(len(A)):
        for j in range(len(B)):
            if(A[i] == B[j]):
                I.append(A[i])
    return I

def diff(A, B):
    D = []
    for i in range(len(A)):
        flag = True
        for j in range(len(B)):
            if(A[i] == B[j]):
                flag = False
                break
        if(flag):
            D.append(A[i])
    return D

def symdif(A, B):
    S = diff(union(A, B), inters(A, B))
    return S

if __name__ == '__main__':
    print("ENTER INPUT")
    get(groupA)
    get(groupB)
    get(groupC)
    T = union(groupA, groupB)
    U = union(T, groupC)
    while(True):
        print("1. List of students who play both cricket and badminton")
        print("2. List of students who play either cricket or badminton but not both")
        print("3. Number of students who play neither cricket nor badminton")
        print("4. Number of students who play cricket and football but not badminton")
        print("5. Exit")
        selection = int(input("Make your selection: "))
        if(selection == 1):
            print("List of students who play both cricket and badminton: ", inters(groupA, groupB), "\n") 
        if(selection == 2):
            print("List of students who play either cricket or badminton but not both: ", symdif(groupA, groupB), "\n")
        if(selection == 3):
            print("Number of students who play neither cricket nor badminton: ", diff(U, union(groupA, groupB)), "\n") #complement of A u B
        if(selection == 4):
            print("Number of students who play cricket and football but not badminton ", diff(inters(groupA, groupC), groupB), end = "\n")
        if(selection == 5):
            exit()