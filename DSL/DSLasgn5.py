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

def bubble(Percent):
    for i in range(length - 1):
        swapped = False
        for j in range(length - i - 1):
            if(Percent[j] > Percent[j + 1]):
                temp = Percent[j]
                Percent[j] = Percent[j + 1]
                Percent[j + 1] = temp
                swapped = True
        if (swapped == False):
            break

def selection(Percent):
    for i in range(length):
        min = i
        for j in range(i + 1, length):
            if(Percent[j] < Percent[min]):
                min = j
        if(min != i):
            temp = Percent[i]
            Percent[i] = Percent[min]
            Percent[min] = temp
            
if __name__ == '__main__':
    while True:
        Choice = int(input("Enter 1 for selection sort and 2 for bubble sort: "))
        if(Choice != 1 and Choice != 2):
            print("Please enter either 1 or 2 only")
        else:
            break

    if(Choice == 1):
        selection(Percent)
        print("Selection Sorted array: ", Percent)
        print("Top 5 scores: ", Percent[-5:])
    if(Choice == 2):
        bubble(Percent)
        print("Bubble Sorted array: ", Percent)
        print("Top 5 scores: ", Percent[-5:])