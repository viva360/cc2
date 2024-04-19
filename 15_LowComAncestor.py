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
    
    def lowest_common_ancestor(self, node1, node2):
        if self.data is None:
            return None
        if self.data == node1 or self.data == node2:
            return self.data
        left_lca = self.left.lowest_common_ancestor(node1, node2) if self.left else None
        right_lca = self.right.lowest_common_ancestor(node1, node2) if self.right else None
        
        if left_lca and right_lca:
            return self.data
        return left_lca if left_lca else right_lca

bst = BinarySearchTreenode(5)
bst.add_child(3)
bst.add_child(7)
bst.add_child(2)
bst.add_child(4)
bst.add_child(6)
bst.add_child(8)
bst.add_child(9)
print("Lowest Common Ancestor: ")
print(bst.lowest_common_ancestor(2, 4))