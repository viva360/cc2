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
    
    def postorder_trav(self):
        trav = []
        if self.left:
            trav += self.left.postorder_trav()
        if self.right:
            trav += self.right.postorder_trav()
        trav.append(self.data)
        return trav
    
    def preorder_trav(self):
        trav = [self.data]
        if self.left:
            trav += self.left.preorder_trav()
        if self.right:
            trav += self.right.preorder_trav()
        return trav

bst = BinarySearchTreenode(5)
bst.add_child(3)
bst.add_child(7)
bst.add_child(2)
bst.add_child(4)
bst.add_child(6)
bst.add_child(8)
bst.add_child(9)

print(bst.inorder_trav())  
print(bst.preorder_trav())   
print(bst.postorder_trav()) 