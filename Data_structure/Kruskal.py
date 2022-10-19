from collections import defaultdict

class Graph:

    def __init__(self,vertices):
        self.V = vertices # count the how many vertices are there in the graph
        self.graph = []

    def addEdge(self,u,v,w):
        self.graph.append([u,v,w])

    def find(self,parent,i):
        if parent[i]==i:
            return i # 并查集中若父母节点就是自己，证明已经达到树的顶端
        return self.find(parent, parent[i]) # recursion
    
    def union(self,parent,rank,x,y):
        xroot = self.find(parent,x)
        yroot = self.find(parent,y)
        #print(xroot)
        #print(yroot)

        if rank[xroot] < rank[yroot]:
            parent[xroot]= yroot # 如果x树的高度比y小，x就认y抱大腿
              
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
    
        else:
            parent[yroot] = xroot
            rank[xroot] +=1

    def KruskalMST(self):
        result = []
        i = 0 # used to sorted edges
        e = 0 # used for result[]
        self.graph2 = sorted(self.graph,
        key= lambda item:item[2])  # sort the weight edges of this graph in ascending order
        parent = []
        rank = [] # 并查集的秩
        for node in range(self.V):
            parent.append(node) # 初始时，所有节点的树都仅有自身一个元素
            rank.append(0)# 初始时，所有节点的秩都设成0

        while e < (self.V-1):
        # pick up the smallest edge and increment index
        # u是边上的第一个顶点，v是第二个顶点，w就是权值
            u,v,w= self.graph2[i]
            i +=1
            x = self.find(parent,u)
            #分别找到u,v的根节点
            y = self.find(parent,v)
             # to judge if these edges can form a cycle
            if x!= y:
                e +=1
                result.append([u,v,w])
                self.union(parent, rank, x,y)

        miniCost = 0
        print("Edges in the constrcuted MST:\n")

        for u,v,weight in result:
            miniCost += weight
            print("%d -- %d == %d" %(u,v,weight))

        print("The minimum Spanning tree is ",miniCost)

print("How many vertices are there in this graph:\n")
Ver_num = int(input())
g = Graph(Ver_num)

print("How many edges are there in this graph?")
Edge_num = int(input())


for i in range(Edge_num):
    print("Please input the edge "+str((i+1))+" of this graph:")
    a,b,c = input().split(',')
    a = int(a)-1
    b = int(b)-1
    c = int(c)
    g.addEdge(a,b,c)
    
g.KruskalMST()





