while True:
    length = int(input("How many students? "))
    if(length <= 0):
        print("Error: you have entered a negative value for length")
    else:
        break
marks = list()
for i in range(length):
    scores = int(input("Enter the marks of students "))
    marks.append(scores)

count = 0
for i in range(length):
    if(marks[i] == -1):
        count += 1
if(count == length):
    print("All students were absent for the test")
    quit()
print("Number of absent students is: ", count)


sum = 0
for i in marks:
    if(i != -1):
        sum += i
print("Average marks of the students: ", sum/length)

Min, Max = marks[0], marks[0]
for i in range(1, length):
    if marks[i] < Min:
        if(marks[i] != -1):
            Min = marks[i]
    if marks[i] > Max:
        Max = marks[i]
print("Highest score is: ", Max)
print("Lowest score is: ", Min)

Freq = 0
Highest = marks[0]
for i in range(length):
    count = 0
    if(marks[i] != -1):
        for j in range(length):
            if(marks[i] == marks[j]):
                count += 1
    if(count > Freq):
        Freq = count
        Highest = marks[i]
print("Marks with highest frequency are:", Highest, "with frequency:", Freq)