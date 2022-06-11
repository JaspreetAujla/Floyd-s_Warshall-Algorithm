
nV = 4

INF = 999999


def floydWar(M):
    dist = list(map(lambda i: list(map(lambda j: j, i)), M))


    for k in range(nV):
        for i in range(nV):
            for j in range(nV):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    print_sol(dist)


def print_sol(dist):
    for i in range(nV):
        for j in range(nV):
            if(dist[i][j] == INF):
                print("INF", end=" ")
            else:
                print(dist[i][j], end=" ")
        print(" ")


M = [[1, 5, INF, 6],
         [2, INF, 0, 4],
         [INF, 4, 2, INF],
         [INF, 2, INF, 0]]

floydWar(M)
