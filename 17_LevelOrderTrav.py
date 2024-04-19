class BinarySearchTreenode:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
    
    def add_child(self,data):
        if data == self.data:
            return
        if data < self.data:
            if self.left:
                self.left.add_child(data)
            else:
                self.left = BinarySearchTreenode(data)
        else:
            if self.right:
                self.right.add_child(data)
            else:
                self.right = BinarySearchTreenode(data)
                
    def level_order_trav(self):
        result = []
        current_level = [self]  # Start with the root node in the current level
        while current_level:
            next_level = []  # List to store nodes of the next level
            for node in current_level:
                result.append(node.data)  # Add data of nodes in the current level to the result
                
                # Add left and right children of the current node to the next level list
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            
            current_level = next_level  # Update current level to be the next level
        
        return result

bst = BinarySearchTreenode(5)
bst.add_child(3)
bst.add_child(7)
bst.add_child(2)
bst.add_child(4)
bst.add_child(6)
bst.add_child(8)
bst.add_child(9)
print("Level_order_traversal: ")
print(bst.level_order_trav())