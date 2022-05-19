SIZE = 10

class node:
    next = None
    def __init__(self, word, meaning):
        self.word = word
        self.meaning = meaning


def hashfunction(word):
    sum = 0
    for x in word:
        sum += ord(x)  #ord converts char to ascii value

    return sum % SIZE

class hashtable:
    table = [None] * SIZE

    def insert_chaining(self, word, meaning):
        index = hashfunction(word)
        
        new_node = node(word, meaning)
        
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
                        print(temp.word, ": ", temp.meaning)
                        break
                    print(temp.word, ": ", temp.meaning, " -->", end = ' ')
                    temp = temp.next    
    
    def find_chaining(self, word):
        index = hashfunction(word)
        temp = self.table[index]

        flag = False
        position = 0
        while (temp != None):
            if (word == temp.word):
                flag = True
                break
            temp = temp.next
            position += 1
        
        if(flag):
            print(word, ": ",temp.meaning, " is found at index ", index, " and position ", position)
        else:
            print(word, " not found in the dictionary")
    
    def delete_chaining(self, key):
        index = hashfunction(key)
        temp = self.table[index]

        if (temp.word == key):
            print("\n" + key + " has been deleted")
            self.table[index] = temp.next
            return

        flag = False
        while (temp != None):
            if (temp.next.word == key):
                flag = True
                break
            temp = temp.next
        
        if(flag):
            temp.next = temp.next.next
            print("\n" + key + " has been deleted")
        else:
            print("\n" + key + " was not found")
        
table = hashtable()

while True:
    Choice = int(input("Enter 1 for inserting, 2 for displaying, 3 for finding, 4 for deleting and 5 for Exiting: "))
    if(Choice != 1 and Choice != 2 and Choice != 3 and Choice != 4 and Choice != 5):
        print("Please enter either 1,2,3,4 or 5 only")
        continue

    if(Choice == 1):
        words = int(input("Enter number of words: ")) 

        for i in range(words):
            word = input("Enter word: ")
            meaning = input("Enter meaning: ")
            table.insert_chaining(word, meaning)

    if(Choice == 2):
        print("\nDisplaying hashtable...")
        table.display_chaining()

    if(Choice == 3):
        key_name = input("Enter the word you want to search: ")
        table.find_chaining(key_name)
    
    if(Choice == 4):
        key_name = input("Enter the word you want to delete: ")
        table.delete_chaining(key_name)

    if(Choice == 5):
        print("Exitiing...")
        break
