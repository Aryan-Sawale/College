SIZE = 10

class node:
    next = None
    def __init__(self, name, phone_no):
        self.name = name
        self.phone_no = phone_no
    


def hashfunction(name):
    sum = 0
    for x in name:
        sum += ord(x)  #ord converts char to ascii value

    return sum % SIZE


class hashtable:
    table = [None] * SIZE

    def insert_chaining(self, name, phone_no):
        index = hashfunction(name)
        
        new_node = node(name, phone_no)
        
        if (self.table[index] == None):
            self.table[index] = new_node
            return
        
        last = self.table[index]
        while (last.next != None):
            last = last.next
        
        last.next = new_node

    def display_chaining(self):
            for i in range(SIZE):
                temp = self.table[i]
                print("index ", i, ": ", end = ' ')  #end can be used to remove default newline
                if (temp == None):
                    print("No element")
                    continue
        
                while True:
                    if (temp.next == None):
                        print(temp.name, ": ", temp.phone_no)
                        break
                    print(temp.name, ": ", temp.phone_no, " -->", end = ' ')
                    temp = temp.next        
    
    def isfull(self):
        flag = True
        for i in range(SIZE):
            if (self.table[i] == None):
                flag = False
                break
        
        return flag

    def insert_linear(self, name, phone_no):
        if (self.isfull()):
            print("Value can't be inserted, table is full")
        
        index = hashfunction(name)

        new_node = node(name, phone_no)

        while (self.table[index] != None):
            index += 1
            index = index % SIZE
        
        self.table[index] = new_node
    
    def display_linear(self):
        for i in range(SIZE):
            print("index ", i, ": ", end = ' ')
            if (self.table[i] == None):
                print("No element")
                continue
            print(self.table[i].name, ": ", self.table[i].phone_no)    

    def find_chaining(self, name):
        index = hashfunction(name)
        temp = self.table[index]

        flag = False
        position = 0
        comparisons = 0
        while (temp != None):
            comparisons += 1
            if (name == temp.name):
                flag = True
                break
            temp = temp.next
            position += 1
        
        if(flag):
            print(name, ": ",temp.phone_no, " is found at index ", index, " and position ", position)
            print("No. of comparisons: ", comparisons)
        else:
            print(name, " not found in the book")
            print("No. of comparisons: ", comparisons)
    
    def find_linear(self, name):
        index = hashfunction(name)
        temp = self.table[index]

        flag = False
        comparisons = 0 
        while(temp != None):
            comparisons += 1
            print(temp.name, ": ", comparisons)
            if (comparisons >= SIZE):
                break
            if (name == temp.name):
                flag = True
                break
            index += 1
            index = index % SIZE
            temp = self.table[index]

        if(flag):
            print(name, ": ",temp.phone_no,  " is found at index ", index)
            print("No. of comparisons: ", comparisons)
        else:
            print(name, " not found in the book")
            print("No. of comparisons: ", comparisons)



while True:
    Choice = int(input("Enter 1 for Chaining, 2 for Linear probing and 3 for Exiting: "))
    if(Choice != 1 and Choice != 2 and Choice != 3):
        print("Please enter either 1,2 or 3 only")
        continue

    if(Choice == 1):
        people = int(input("Enter number of people: ")) 
        tab1 = hashtable()

        for i in range(people):
            name = input("Enter name: ")
            phone_no = input("Enter phone number: ")
            tab1.insert_chaining(name, phone_no)
        
        print("Displaying hashtable...")
        tab1.display_chaining()

        key_name = input("Enter the name you want to search: ")
        tab1.find_chaining(key_name)

    if(Choice == 2):
        people = int(input("Enter number of people: ")) 
        tab2 = hashtable()

        for i in range(people):
            name = input("Enter name: ")
            phone_no = input("Enter phone number: ")
            tab2.insert_linear(name, phone_no)
        
        print("Displaying hashtable...")
        tab2.display_linear()

        key_name = input("Enter the name you want to search: ")
        tab2.find_linear(key_name)

    if(Choice == 3):
        print("Exitiing...")
        break











# print("Chaining")
# tab1 = hashtable()
# tab1.insert_chaining("kek1", 12);
# tab1.insert_chaining("kek2", 22);
# tab1.insert_chaining("kek3", 32);
# tab1.display_chaining();

# print("\nLinear Probing")
# tab2 = hashtable()
# tab2.insert_linear("kek1", 12);
# tab2.insert_linear("kek2", 22);
# tab2.insert_linear("kek3", 32);
# tab2.display_linear();

# tab1.find_chaining("kek1")
# tab2.find_chaining("kek1")

# head = Node(1);
# second = Node(2);
# head.next = second;
# temp = head;
# while (temp != None):
#     print(temp.data);
#     temp = temp.next;

# from msilib.schema import tables
# from unittest import TextTestRunner