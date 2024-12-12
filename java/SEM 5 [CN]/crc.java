import java.io.*;

class crc {
    public static void main(String a[]) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int[] message;
        int[] gen;
        int[] app_msg;
        int[] rem;
        int[] trans_msg;
        int msg_bits, gen_bits, total_bits;

        System.out.println("\n Enter number of bits in message : ");
        msg_bits = Integer.parseInt(br.readLine());
        message = new int[msg_bits];

        System.out.println("\n Enter message bits : ");
        for (int i = 0; i < msg_bits; i++)
            message[i] = Integer.parseInt(br.readLine());

        System.out.println("\n Enter number of bits in gen : ");
        gen_bits = Integer.parseInt(br.readLine());
        gen = new int[gen_bits];

        System.out.println("\n Enter gen bits : ");
        for (int i = 0; i < gen_bits; i++)
            gen[i] = Integer.parseInt(br.readLine());

        total_bits = msg_bits + gen_bits - 1;
        app_msg = new int[total_bits];
        rem = new int[total_bits];
        trans_msg = new int[total_bits];

        for (int i = 0; i < message.length; i++)
            app_msg[i] = message[i];

        System.out.print("\n Message bits are : ");
        for (int i = 0; i < msg_bits; i++)
            System.out.print(message[i]);

        System.out.print("\n Generators bits are : ");
        for (int i = 0; i < gen_bits; i++)
            System.out.print(gen[i]);

        System.out.print("\n Appended message is : ");
        for (int i = 0; i < app_msg.length; i++)
            System.out.print(app_msg[i]);

        for (int j = 0; j < app_msg.length; j++)
            rem[j] = app_msg[j];

        rem = computecrc(app_msg, gen, rem);

        for (int i = 0; i < app_msg.length; i++)
            trans_msg[i] = (app_msg[i] ^ rem[i]);

        System.out.println("\n Transmitted message from the transmitter is : ");
        for (int i = 0; i < trans_msg.length; i++)
            System.out.print(trans_msg[i]);

        System.out.println("\n Enter received message of " + total_bits + " bits at receiver end : ");
        for (int i = 0; i < trans_msg.length; i++)
            trans_msg[i] = Integer.parseInt(br.readLine());

        System.out.println("\n Received message is :");
        for (int i = 0; i < trans_msg.length; i++)
            System.out.print(trans_msg[i]);

        for (int j = 0; j < trans_msg.length; j++)
            rem[j] = trans_msg[j];

        rem = computecrc(trans_msg, gen, rem);

        for (int i = 0; i < rem.length; i++) {
            if (rem[i] != 0) {
                System.out.println("\n There is Error in the received message!!!");
                break;
            }
            if (i == rem.length - 1)
                System.out.println("\n There is No Error in the received message!!!");
        }
    }

    static int[] computecrc(int app_msg[], int gen[], int rem[]) {
        int current = 0;
        while (true) {
            for (int i = 0; i < gen.length; i++)
                rem[current + i] = (rem[current + i] ^ gen[i]);

            while (rem[current] == 0 && current != rem.length - 1)
                current++;

            if ((rem.length - current) < gen.length)
                break;
        }
        return rem;
    }
}