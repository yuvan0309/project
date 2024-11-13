import java.util.Scanner;

public class BellmanFord {
    private int distances[];
    private int noofvertices;
    public static final int MAX_VAL = 999;

    public BellmanFord(int noofvertices) {
        this.noofvertices = noofvertices;
        distances = new int[noofvertices + 1];
    }

    public void BellmanFordEvaluation(int src, int dest, int adjmatrix[][]) {
        for (int node = 1; node <= noofvertices; node++) {
            distances[node] = MAX_VAL;
        }
        distances[src] = 0;

        for (int node = 1; node <= noofvertices - 1; node++) {
            for (int srcnode = 1; srcnode <= noofvertices; srcnode++) {
                for (int destnode = 1; destnode <= noofvertices; destnode++) {
                    if (adjmatrix[srcnode][destnode] != MAX_VAL) {
                        if (distances[destnode] > distances[srcnode] + adjmatrix[srcnode][destnode]) {
                            distances[destnode] = distances[srcnode] + adjmatrix[srcnode][destnode];
                        }
                    }
                }
            }
        }

        for (int srcnode = 1; srcnode <= noofvertices; srcnode++) {
            for (int destnode = 1; destnode <= noofvertices; destnode++) {
                if (adjmatrix[srcnode][destnode] != MAX_VAL) {
                    if (distances[destnode] > distances[srcnode] + adjmatrix[srcnode][destnode]) {
                        System.out.println("The Graph contains negative edge cycle");
                    }
                }
            }
        }

        for (int vertex = 1; vertex <= noofvertices; vertex++) {
            if (vertex == dest) {
                System.out.println("Distance of src " + src + " to " + vertex + " is " + distances[vertex]);
            }
        }
    }

    public static void main(String... arg) {
        int noofvertices = 0;
        int src, dest;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of vertices");
        noofvertices = scanner.nextInt();
        int adjmatrix[][] = new int[noofvertices + 1][noofvertices + 1];
        System.out.println("Enter the adjacency matrix");
        for (int srcnode = 1; srcnode <= noofvertices; srcnode++) {
            for (int destnode = 1; destnode <= noofvertices; destnode++) {
                adjmatrix[srcnode][destnode] = scanner.nextInt();
                if (srcnode == destnode) {
                    adjmatrix[srcnode][destnode] = 0;
                    continue;
                }
                if (adjmatrix[srcnode][destnode] == 0) {
                    adjmatrix[srcnode][destnode] = MAX_VAL;
                }
            }
        }
        System.out.println("Enter the src vertex");
        src = scanner.nextInt();
        System.out.println("Enter the dest vertex: ");
        dest = scanner.nextInt();
        BellmanFord bellmanford = new BellmanFord(noofvertices);
        bellmanford.BellmanFordEvaluation(src, dest, adjmatrix);
        scanner.close();
    }
}