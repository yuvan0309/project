import java.util.Scanner;

public class MatrixAddition {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        System.out.print("Enter the number of rows for the matrices: ");
        int m = s.nextInt();
        System.out.print("Enter the number of columns for the matrices: ");
        int n = s.nextInt();

        int[][] matrix1 = new int[m][n];
        int[][] matrix2 = new int[m][n];
        int[][] sum = new int[m][n];

        System.out.println("Enter elements for matrix 1:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix1[i][j] = s.nextInt();
            }
        }

        System.out.println("Enter elements for matrix 2:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix2[i][j] = s.nextInt();
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        System.out.println("Sum of the matrices:");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(sum[i][j] + " ");
            }
            System.out.println();
        }
        s.close();
    }
}
