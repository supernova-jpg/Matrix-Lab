import sys

class Graph():

    def __init__(self,vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                    for row in range(vertices)]
    # 初始化的图邻接矩阵的元素全部为0

    def addEdge(self,a,b,c):
        self.graph[a][b]= self.graph[b][a] = c

    def printMST(self, parent):
        print("Edge \tWeight")
        for i in range(1,self.V):
            print(parent[i]+1,"--",i+1,"\t",self.graph[i][parent[i]])

    def minikey(self,key, mstSet):

        min = sys.maxsize
        for v in range(self.V):
            if key[v] < min and mstSet[v]== False: # 距离最小生成树最近且未被纳入最小生成树的点
                min = key[v]
                min_index = v  
        
        return min_index

    def primMST(self):

        key= [sys.maxsize]*self.V
        parent = [None]* self.V
        key[0] = 0
        mstSet = [False] *self.V  
        parent[0] = -1

        for i in range(self.V):
            u = self.minikey(key, mstSet)
            mstSet[u]= True # 找到距离最小生成树最近的点,第一轮循环自然就是第一个顶点了

            for v in range(self.V):
                if (self.graph[u][v] > 0 and mstSet[v]==False
                and self.graph[u][v]< key[v]): # 将这个点向其他点的路径延伸，>0表示该顶点可以到达，选择权最短的那条边

                    key[v] = self.graph[u][v]
                    parent[v] = u

        self.printMST(parent)

if __name__== '__main__':
    print("Please input the vertices of this matrix:")
    g = Graph(int(input()))
    print("How many edges are there in this graph?")
    num = int(input())

    for i in range(num):
        print("Please input the edge "+str((i+1))+" of this graph:")
        a,b,c = input().split(',')
        a = int(a)-1
        b = int(b)-1
        c = int(c)
        g.addEdge(a,b,c)
        
    print(g.graph)
    g.primMST()
    