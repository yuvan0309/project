public class SlidingWindowProtocol {
    private final int windowSize;
    private int sendBase = 0, nextSeqNum = 0;

    public SlidingWindowProtocol(int windowSize) {
        this.windowSize = windowSize;
    }

    public void sendData(char[] data) {
        while (nextSeqNum < sendBase + windowSize && nextSeqNum < data.length) {
            System.out.println("Sending packet: " + nextSeqNum + " -> " + data[nextSeqNum]);
            nextSeqNum++;
        }
    }

    public void receiveAck(int ackNum) {
        sendBase = ackNum + 1;
        System.out.println("Received ACK for packet: " + ackNum);
    }

    public static void main(String[] args) {
        char[] data = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
        SlidingWindowProtocol swp = new SlidingWindowProtocol(4);
        swp.sendData(data);
        for (int i = 0; i < 4; i++)
            swp.receiveAck(i);
    }
}
/*
 * Output:
 * Sending packet: 0 -> A
 * Sending packet: 1 -> B
 * Sending packet: 2 -> C
 * Sending packet: 3 -> D
 * Received ACK for packet: 0
 * Received ACK for packet: 1
 * Received ACK for packet: 2
 * Received ACK for packet: 3
 */