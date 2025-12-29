class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self, root_data):
        self.root = TreeNode(root_data)
    
    def insert_left(self, parent, data):
        if parent.left is None:
            parent.left = TreeNode(data)
        else:
            new_node = TreeNode(data)
            new_node.left = parent.left
            parent.left = new_node
    
    def insert_right(self, parent, data):
        if parent.right is None:
            parent.right = TreeNode(data)
        else:
            new_node = TreeNode(data)
            new_node.right = parent.right
            parent.right = new_node
    
    def inorder_traversal(self, node):
        if node:
            self.inorder_traversal(node.left)
            print(node.data, end=' ')
            self.inorder_traversal(node.right)
    
    def preorder_traversal(self, node):
        if node:
            print(node.data, end=' ')
            self.preorder_traversal(node.left)
            self.preorder_traversal(node.right)
    
    def postorder_traversal(self, node):
        if node:
            self.postorder_traversal(node.left)
            self.postorder_traversal(node.right)
            print(node.data, end=' ')

tree = BinaryTree(1)
tree.insert_left(tree.root, 2)
tree.insert_right(tree.root, 3)
tree.insert_left(tree.root.left, 4)
tree.insert_right(tree.root.left, 5)

print("Inorder:", end=' ')
tree.inorder_traversal(tree.root)
print()

print("Preorder:", end=' ')
tree.preorder_traversal(tree.root)
print()

print("Postorder:", end=' ')
tree.postorder_traversal(tree.root)
print()

