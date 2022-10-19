class Node(object): # 这裏的树采用的是链式存储结构，即每一个节点都分别存取其左，右孩子
    def __init__(self,elem=-1,lchild=None, rchild=None):
        self.elem = elem
        self.lchild = lchild
        self.rchild = rchild

class Tree(object):
    def __init__(self):
        self.root = Node() # 继承了Node类,初始时树只有一个Node节点
        self.myQue= []
    def insert(self,elem):
        node = Node(elem) # 是一个对象，首次插入根节点时就把根节点的数值插进去了
        if self.root.elem == -1:
            self.root = node
            self.myQue.append(self.root)
        else:
            treenode = self.myQue[0]
            # 这时已经线性表中已经增加了根节点的元素，是一个对象而不是一个数值
            if treenode.lchild == None:
                treenode.lchild= node
                self.myQue.append(treenode.lchild) # 这时添加的仍是一个对象
            else:
                treenode.rchild = node
                self.myQue.append(treenode.rchild)
                self.myQue.pop(0) # 根节点出队

    def pre_stack(self,root):
        if root == None:
            return
        stack = [root] # 栈，元素是节点对象
        while stack:
            s = stack.pop()
            if(s):
                print(s.elem) # 打印出栈的元素
                stack.append(s.rchild)
                stack.append(s.lchild) 

    def mid_stack(self,root):
        if root == None:
            return
        stack = []
        p = root
        while stack or p:
            while p:
                stack.append(p)  
                p = p.lchild # 一直向下搜寻找左子树，压入栈，直到找不到为止 # 第二步，搜寻这颗右子树下是否有左孩子，也压入栈
            if stack:
                p = stack.pop() # 记录被弹出的元素
                print(p.elem)
                p = p.rchild # 如果被弹出的元素有右孩子，就也将其压入栈

    def post_stack(self,root):
        """
        stack = []
        while stack or root:
            while root:                 # 下行循环，直到找到第一个叶子节点
                stack.append(root)
                if root.lchild:           # 能左就左，不能左就右
                    root = root.lchild 
                else:
                    root = root.rchild     
            s = stack.pop()
            print(s.elem)
        #如果当前节点是上一节点的左子节点，则遍历右子节点
 
            if stack and s == stack[-1].lchild: 
                root = stack[-1].rchild
            else:
                root = None
        """
        if root == None:
            return
        self.post_stack(root.lchild)
        self.post_stack(root.rchild)
        print(root.elem)



if __name__== '__main__':
    elems = range(1,11)
    tree= Tree()
    print("The level traversal of this binary tree is:\n")
   
    for elem in elems:
        print(elem)
        tree.insert(elem)

    print("The preorder traversal of this binary tree is:\n")
    tree.pre_stack(tree.root)

    print("The inorder traversal of this binary tree is:\n")
    tree.mid_stack(tree.root)
    
    print("The postorder traversal of this binary tree is:\n")
    tree.post_stack(tree.root)