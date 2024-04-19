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

    def boundary_traversal(self):
        if self.data is None:
            return []
        left_boundary = self._left_boundary()
        right_boundary = self._right_boundary()
        leaves = self._leaves()
        return left_boundary + leaves + right_boundary[::-1]
    
    def _left_boundary(self):
        node = self.left
        left_boundary = []
        while node:
            left_boundary.append(node.data)
            if node.left:
                node = node.left
            else:
                node = node.right
        return left_boundary[:-1]
    
    def _right_boundary(self):
        node = self.right
        right_boundary = []
        while node:
            right_boundary.append(node.data)
            if node.right:
                node = node.right
            else:
                node = node.left
        return right_boundary[:-1]
    
    def _leaves(self):
        leaves = []
        if self.left is None and self.right is None:
            return [self.data]
        if self.left:
            leaves += self.left._leaves()
        if self.right:
            leaves += self.right._leaves()
        return leaves

bst = BinarySearchTreenode(5)
bst.add_child(3)
bst.add_child(7)
bst.add_child(2)
bst.add_child(4)
bst.add_child(6)
bst.add_child(8)
bst.add_child(9)

print(bst.boundary_traversal())