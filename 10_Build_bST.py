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
    
    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.data)
        if self.right:
            self.right.print_tree()

bst = BinarySearchTreenode(5)
bst.add_child(3)
bst.add_child(7)
bst.add_child(2)
bst.add_child(4)
bst.add_child(6)
bst.add_child(8)
bst.add_child(9)
print("Elements via Inorder traversal: ")
bst.print_tree()