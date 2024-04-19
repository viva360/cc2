class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def left_view_helper(root, level, max_level):
    if root is None:
        return
    
    # If the current level is greater than the maximum level seen so far,
    # print the value of the current node and update the maximum level
    if level > max_level[0]:
        print(root.data, end = " ")
        max_level[0] = level

    # Recursively visit the left and right subtrees
    left_view_helper(root.left, level + 1, max_level)
    left_view_helper(root.right, level + 1, max_level)

def left_view(root):
    max_level = [0]  # List to store the maximum level seen so far
    left_view_helper(root, 1, max_level)

# Create a binary tree
root = BinaryTreeNode(1)
root.left = BinaryTreeNode(2)
root.right = BinaryTreeNode(3)
root.left.left = BinaryTreeNode(4)
root.left.right = BinaryTreeNode(5)
root.right.left = BinaryTreeNode(6)
root.right.right = BinaryTreeNode(7)

# Display the left view of the binary tree
print("Left view of the binary tree:")
left_view(root)
