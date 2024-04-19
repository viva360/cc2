def two_sum(nums_list, target):
    # Create a hashmap to store each number and its index
    hashmap = {}

    # Iterate through the list of numbers
    for i, num in enumerate(nums_list):
        # Calculate the complement (target - current number)
        complement = target - num
        
        # Check if the complement exists in the hashmap
        if complement in hashmap:
            # If the complement exists, return the indices of the two numbers
            return [hashmap[complement], i]
        
        # If the complement doesn't exist, store the current number and its index in the hashmap
        hashmap[num] = i
    # If no solution is found, return an empty list
    return []

nums_list = [2, 7, 11, 15]
target = 26                 # 11 + 15 = 26 i.e. index 2 and 3 has the values 
print("Indices of the two numbers:", two_sum(nums_list, target))


