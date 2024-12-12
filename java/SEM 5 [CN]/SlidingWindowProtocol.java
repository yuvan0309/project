public class SlidingWindowProtocol {
    private final int windowSize;
    private int sendBase;
    private int nextSeqNum;

    public SlidingWindowProtocol(int windowSize) {
        this.windowSize = windowSize;
        this.sendBase = 0;
        this.nextSeqNum = 0;
    }

    public void sendData(char[] data) {
        while (nextSeqNum < sendBase + windowSize && nextSeqNum < data.length) {
            Packet packet = createPacket(data[nextSeqNum]);
            simulateSendPacket(packet);
            nextSeqNum++;
        }
    }

    public void receiveAck(int ackNum) {
        sendBase = ackNum + 1;
    }

    private Packet createPacket(char data) {
        return new Packet(nextSeqNum, data);
    }

    private void simulateSendPacket(Packet packet) {
        System.out.println("Sending packet: " + packet);
    }

    private void simulateAckPacket(int ackNum) {
        System.out.println("Received ACK for packet: " + ackNum);
        receiveAck(ackNum);
    }

    private static class Packet {
        private final int seqNum;
        private final char data;

        public Packet(int seqNum, char data) {
            this.seqNum = seqNum;
            this.data = data;
        }

        public String toString() {
            return "Packet{" +
                    "seqNum=" + seqNum +
                    ", data=" + data +
                    '}';
        }
    }

    public static void main(String[] args) {
        char[] data = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
        SlidingWindowProtocol swp = new SlidingWindowProtocol(4);
        swp.sendData(data);
        // Simulate receiving ACKs
        swp.simulateAckPacket(0);
        swp.simulateAckPacket(1);
        swp.simulateAckPacket(2);
        swp.simulateAckPacket(3);
    }
}
/* Output:
 * Sending packet: Packet{seqNum=0, data=A}
 * Sending packet: Packet{seqNum=1, data=B}
 * Sending packet: Packet{seqNum=2, data=C}
 * Sending packet: Packet{seqNum=3, data=D}
 * Received ACK for packet: 0
 * Received ACK for packet: 1
 * Received ACK for packet: 2
 * Received ACK for packet: 3
 */