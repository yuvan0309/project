import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.InputStreamReader;
import java.io.DataOutputStream;
import java.net.Socket;
import java.io.File;
import java.io.FileOutputStream;
import java.util.Scanner;

class client {
    public static void main(String args[]) throws Exception {
        String address = "";
        Scanner sc = new Scanner(System.in);
        System.out.println("eneter server address");
        address = sc.nextLine();
        Socket s = new Socket(address, 5000);
        DataInputStream din = new DataInputStream(s.getInputStream());
        DataOutputStream dout = new DataOutputStream(s.getOutputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("snd get to start");
        String str = "", filename = "";
        try {
            while (!str.equals("start"))
                str = br.readLine();
            dout.writeUTF(str);
            dout.flush();
            filename = din.readUTF();
            System.out.println("receiveing file:" + filename);
            filename = "client" + filename;
            System.out.println("saving as file" + filename);
            long sz = Long.parseLong(din.readUTF());
            System.out.println("filesize:" + (sz / (1024)) + "KB");
            byte b[] = new byte[1024];
            System.out.println("receiving file");
            FileOutputStream fos = new FileOutputStream(new File(filename), true);
            long bytesRead;
            do {
                bytesRead = din.read(b, 0, b.length);
                fos.write(b, 0, b.length);
            } while (!(bytesRead < 1024));
            System.out.println("completed");
            fos.close();
            dout.close();
            s.close();
        } catch (Exception e) {
            // do nothing;
        }
    }
}