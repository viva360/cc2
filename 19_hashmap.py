class HashMap:
    def __init__(self, size):
        self.size = size
        self.hash_table = [None] * size

    def hash_function(self, key):
        return hash(key) % self.size #Each time a new hash value will be generated

    def insert(self, key, value):
        index = self.hash_function(key)
        if self.hash_table[index] is None:
            self.hash_table[index] = []   # creates a inner list to store the key value pair
        self.hash_table[index].append((key, value)) #append to innerlist.

    def get(self, key):
        index = self.hash_function(key)
        if self.hash_table[index] is not None:
            for k, v in self.hash_table[index]:
                if k == key:
                    return v
        return None
    
    def print_hashtable(self):
        print(self.hash_table)

# Create a hash map with a size of 10
hash_map = HashMap(10)

# Insert key-value pairs into the hash map
hash_map.insert('apple', 'red')
hash_map.insert('banana', 'yellow')
hash_map.insert('grape', 'purple')

#see how the hashmap is created
hash_map.print_hashtable()
# Retrieve values using keys
print("Color of apple:", hash_map.get('apple'))  # Output: red
print("Color of banana:", hash_map.get('banana'))  # Output: yellow
print("Color of grape:", hash_map.get('grape'))  # Output: purple
print("Color of orange:", hash_map.get('orange'))  # Output: None (key not found)
