# Определим структуру для узла в дереве
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Функция для вставки нового узла в дерево
def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    else:
        root.right = insert(root.right, data)
    return root

# Функция для выполнения обхода дерева по порядку
def inorder_traversal(root):
    if root:
        inorder_traversal(root.left)
        print(root.data, end=' ')
        inorder_traversal(root.right)

root = None
for value in [50, 30, 70, 20, 40, 60, 80]:
    root = insert(root, value)
    
# Обход по порядку
print("Обход по порядку: ")
inorder_traversal(root)
print()
