class ListNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self.hash_function(key)
        if self.table[index] is None:
            self.table[index] = ListNode(key, value)
        else:
            current = self.table[index]
            while current.next:
                current = current.next
            current.next = ListNode(key, value)

    def search(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        while current:
            if current.key == key:
                return current.value
            current = current.next
        return None

    def delete(self, key):
        index = self.hash_function(key)
        current = self.table[index]
        if current is None:
            return None
        if current.key == key:
            self.table[index] = current.next
            return
        while current.next:
            if current.next.key == key:
                current.next = current.next.next
                return
            current = current.next

# Example usage:
hash_table = HashTable(10)
hash_table.insert('apple', 'red')
hash_table.insert('banana', 'yellow')
hash_table.insert('grape', 'purple')

print("Value of 'apple':", hash_table.search('apple'))  
print("Value of 'banana':", hash_table.search('banana')) 
print("Value of 'grape':", hash_table.search('grape')) 

hash_table.delete('banana')
print("Value of 'banana' after deletion:", hash_table.search('banana'))  
