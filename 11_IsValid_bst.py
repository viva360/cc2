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
    
    def inorder_trav(self):
        trav = []
        if self.left:
            trav += self.left.inorder_trav()
        trav.append(self.data)
        if self.right:
            trav += self.right.inorder_trav()
        return trav
    
    def is_valid_bst(self):
        in_order_sequence = self.inorder_trav()
        for i in range(1, len(in_order_sequence)):
            if in_order_sequence[i] <= in_order_sequence[i - 1]:
                return False
        return True

bst = BinarySearchTreenode(5)
bst.add_child(3)
bst.add_child(7)
bst.add_child(2)
bst.add_child(4)
bst.add_child(6)
bst.add_child(8)
bst.add_child(9)

if bst.is_valid_bst():
    print("Bst is Valid")
else:
    print("Bst is Invalid")