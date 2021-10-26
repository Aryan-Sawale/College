length = int(input("How many students? "))
Percent = list()

counter = 0
while True:
    if(counter == length):
        break
    scores = float(input("Enter the percentage: "))
    if(scores < 0):
        print("Error: you have entered a negative value")
    else:
        counter += 1
        Percent.append(scores)

def insertion(Percent):
    for i in range(1, length):
        key = Percent[i]
        j = i - 1
        while j >= 0 and key < Percent[j]:
            j -= 1
        Percent[j + 1] = key

def shell(Percent):
    gap = length // 2
    while gap > 0:
        for i in range(gap, length):
            temp = Percent[i]
            j = i
            while j >= gap and Percent[j - gap] > temp:
                Percent[j] = Percent[j - gap]
                j -= gap

            Percent[j] = temp
        gap //= 2

if __name__ == '__main__':
    while True:
        Choice = int(input("Enter 1 for insertion sort \nEnter 2 for shell sort: "))
        if(Choice != 1 and Choice != 2):
            print("Please enter either 1 or 2 only")
        else:
            break

    if(Choice == 1):
        insertion(Percent)
        print("insertion Sorted array: ", Percent)
        print("Top 5 scores: ", Percent[-5:])
    if(Choice == 2):
        shell(Percent)
        print("shell Sorted array: ", Percent)
        print("Top 5 scores: ", Percent[-5:])