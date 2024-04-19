class BinarySearchTreenode:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

    def is_mirror(self, root):
        if self.data is None and root is None:
            return True
        if self.data != root.data:
            return False
        if (self.left and root.right) or (self.right and root.left):
            return self.left.is_mirror(root.right) and self.right.is_mirror(root.left)
        return True
    
root = BinarySearchTreenode(5)
root.left = BinarySearchTreenode(7)
root.right = BinarySearchTreenode(7)
root.left.left = BinarySearchTreenode(8)
root.left.right = BinarySearchTreenode(11)
root.right.left = BinarySearchTreenode(11)
root.right.right = BinarySearchTreenode(8)

if root.is_mirror(root):
    print("The tree is Mirrored")
else:
    print("The tree is not Mirrored")
