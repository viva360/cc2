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

    def maxDepth(self):
        if self.data is None:
            return 0
        left_depth = self.left.maxDepth() if self.left else 0
        right_depth = self.right.maxDepth() if self.right else 0
        return max(left_depth, right_depth) + 1

bst = BinarySearchTreenode(5)
bst.add_child(3)
bst.add_child(7)
bst.add_child(2)
bst.add_child(4)
bst.add_child(6)
bst.add_child(8)
bst.add_child(9)

print("Max Depth of the tree: " + str(bst.maxDepth()))
