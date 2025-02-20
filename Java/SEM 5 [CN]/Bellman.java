import java.util.Arrays;
import java.util.Scanner;

public class Bellman {
    static final int INF = 999;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int v = scanner.nextInt(); 

        int[][] graph = new int[v + 1][v + 1]; 
        System.out.println("Enter adjacency matrix (0 for no edge, else weight):");
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                graph[i][j] = scanner.nextInt();
                if (i == j) graph[i][j] = 0;
                else if (graph[i][j] == 0) graph[i][j] = INF;
            }
        }

        System.out.print("Enter source vertex: ");
        int src = scanner.nextInt();
        System.out.print("Enter destination vertex: ");
        int dest = scanner.nextInt();

        shortestPath(graph, v, src, dest);
        scanner.close();
    }

    static void shortestPath(int[][] graph, int v, int src, int dest) {
        int[] dist = new int[v + 1];
        Arrays.fill(dist, INF); 
        dist[src] = 0; 

        for (int i = 1; i <= v - 1; i++) {
            for (int u = 1; u <= v; u++) {
                for (int w = 1; w <= v; w++) {
                    if (graph[u][w] != INF && dist[u] + graph[u][w] < dist[w]) {
                        dist[w] = dist[u] + graph[u][w];
                    }
                }
            }
        }

        for (int u = 1; u <= v; u++) {
            for (int w = 1; w <= v; w++) {
                if (graph[u][w] != INF && dist[u] + graph[u][w] < dist[w]) {
                    System.out.println("Graph contains a negative-weight cycle");
                    return;
                }
            }
        }

        System.out.println("Shortest distance from " + src + " to " + dest + " is: " + dist[dest]);
    }
}
// output
// Enter the number of vertices
// 5
// Enter the adjacency matrix
// 0 6 0 7 0
// 0 0 5 8 -4
// 0 -2 0 0 0
// 0 0 -3 0 9
// 2 0 7 0 0
// Enter the src vertex
// 1
// Enter the dest vertex:
// 4
// Distance of src 1 to 4 is 2