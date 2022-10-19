import sys

class Graph:

    def __init__(self,vertices):
        self.V = vertices
        self.mat = [[sys.maxsize for col in range (vertices)] 
                    for row in range (vertices)]
        for i in range (vertices):
            self.mat[i][i]= 0
    
    def AddEdges(self,a,b,c):
        self.mat[a][b]=  c
        self.mat[b][a]= self.mat[a][b]

    def Floyd(self):
        for k in range (self.V):
            for i in range(self.V):
                for j in range(self.V):
                    if self.mat[i][k]+self.mat[k][j] <= self.mat[i][j]:
                        self.mat[i][j] = self.mat[i][k]+ self.mat[k][j]
    
    def Output(self):
        print("The shortest path of each vertice is:")
        print("Edge \tWeight")
        for i in range(self.V):
            for j in range(i,self.V):
                if self.mat[i][j] != sys.maxsize and self.mat[i][j]!=0:
                    print(i+1,"--",j+1,"\t",self.mat[i][j])


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
        g.AddEdges(a,b,c)
    print(g.mat)
    g.Floyd()
    g.Output()