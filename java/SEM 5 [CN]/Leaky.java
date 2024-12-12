import java.util.*;

public class Leaky {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter bucket size: ");
        int bucketSize = sc.nextInt();
        System.out.print("Enter number of groups: ");
        int numGroups = sc.nextInt();

        int totalPackets = 0, totalBandwidth = 0;

        for (int i = 0; i < numGroups; i++) {
            System.out.print("Packets for group " + (i + 1) + ": ");
            int packets = sc.nextInt();
            System.out.print("Input bandwidth for group " + (i + 1) + ": ");
            int bandwidth = sc.nextInt();

            while (totalPackets + packets > bucketSize) {
                System.out.println("Bucket Overflow. Enter value <= " + (bucketSize - totalPackets));
                packets = sc.nextInt();
            }

            totalPackets += packets;
            totalBandwidth += packets * bandwidth;
        }

        System.out.println("Total required bandwidth: " + totalBandwidth);
        System.out.print("Enter output bandwidth: ");
        int outBandwidth = sc.nextInt();

        while (totalPackets > 0 && totalBandwidth > 0) {
            System.out.println("Data sent. " + (--totalPackets) + " packets remaining.");
            totalBandwidth -= outBandwidth;
            System.out.println("Remaining Bandwidth: " + Math.max(totalBandwidth, 0));
        }

        if (totalPackets > 0) {
            System.out.println(totalPackets + " packet(s) discarded due to insufficient bandwidth.");
        }
        sc.close();
    }
}
