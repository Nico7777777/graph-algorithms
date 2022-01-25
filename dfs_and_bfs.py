from queue import Queue

class graph:
    def __init__(self, n:int):
        self.n = n
        self.vecini = {i:set({}) for i in range(n+1)}
        #self.visited = [ False for i in range(self.n + 1) ]
    def addEdge(self, x:int, y:int)->None:
        self.vecini[x].add(y)
        self.vecini[y].add(x)
    
    def DFS(self,node:int)->None:
        visited = [False for i in range(self.n + 1)]
        self.DFS_wrapped_function(node, visited)
    
    def DFS_wrapped_function(self, node: int, visited:list) -> None:
        visited[ node ] = True
        print(node, end=" ")
        for i in self.vecini[ node ]:
            if not visited[ i ]:
                self.DFS(i, visited)

    def BFS(self, node: int)->None:
        visited = [False for i in range(self.n + 1)]
        q = [node]
        visited[ node ] = True
        while( len(q) > 0 ):
            print(q[0], end=" ")
            for i in self.vecini[ q[0] ]:
                if not visited[ i ]:
                    q.append(i)
                    visited[i] = True
            q.pop(0)
            
    def liste_de_adiacenta(self):
        for i in range(self.n+1):
            print(i, end=": ")
            for j in self.vecini[i]:
                print(j, end=", ")
            print("")


if __name__ == "__main__":
    alfa = graph(8)
    alfa.addEdge(2, 4)
    alfa.addEdge(5, 3)
    alfa.addEdge(6, 2)
    alfa.addEdge(2, 5)
    alfa.liste_de_adiacenta()
    
    alfa.DFS(2)
    alfa.BFS(2)