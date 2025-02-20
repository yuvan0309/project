import java.util.Scanner;

public class Leaky {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the bucket size: ");
        int bucket = sc.nextInt(), packets = 0, bandwidth = 0;

        System.out.print("Enter the no of groups: ");
        for (int groups = sc.nextInt(), g = 1; groups-- > 0; g++) {
            System.out.print("Enter the no of packets for group" + g + ": ");
            int p = sc.nextInt();
            System.out.print("Enter the input bandwidth for the group" + g + ": ");
            int b = sc.nextInt();
            while (packets + p > bucket) {
                System.out.println("Bucket Overflow. Enter value <= " + (bucket - packets));
                p = sc.nextInt();
            }
            packets += p;
            bandwidth += p * b;
        }

        System.out.println("The total required bandwidth is " + bandwidth);
        System.out.print("Enter the output bandwidth: ");
        int out = sc.nextInt();

        while (packets > 0 && bandwidth > 0) {
            System.out.println("Data sent");
            packets--;
            bandwidth -= out;
            System.out.println(packets + " packets remaining");
            System.out.println("Remaining Bandwidth: " + Math.max(bandwidth, 0));
        }

        if (packets > 0) System.out.println(packets + " packets discarded due to insufficient bandwidth");
        sc.close();
    }
}
