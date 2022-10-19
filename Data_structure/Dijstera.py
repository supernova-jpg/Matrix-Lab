import sys

class Graph():

    def __init__(self,vertices):
        self.V = vertices
        self.Mat = [[0 for column in range (vertices)]
        for row in range (vertices)]

    def addEdge(self,a,b,weight):
        self.Mat[a][b] = weight
        self.Mat[b][a] = self.Mat[a][b]

    def Show(self,dist):
        print("Vertex \t Distance from the source")
        for node in range(self.V):
            print(node+1, "\t", dist[node])

    def Vertice_select(self, dist, MSTree):
        min = sys.maxsize
        #index = 2
        for v in range(self.V):
            if dist[v] < min and MSTree[v] == False:
                min = dist[v]
                index = v
        return index

    def Dijstera(self, Start_V):
        dist = [sys.maxsize]* self.V
        dist[0] = 0
        MSTree = [False] *self.V

        for out in range(self.V):
            u = self.Vertice_select(dist, MSTree)
            print(u)
            MSTree[u] = True
            for v in range(self.V):
                if MSTree[v] == False \
                and dist[v] >= self.Mat[u][v] + dist[u] \
                and self.Mat[u][v]>0:
                    dist[v] = self.Mat[u][v] + dist[u]
        
        self.Show(dist)

if __name__ == "__main__":
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
    print(g.Mat)
    print("Which vertices do you want to select to begin?")
    g.Dijstera(0) 

