import java.io.*;
public class Buffer {
    static void read()throws FileNotFoundException,IOException{
        FileReader f=new FileReader("C:\\Yuvan\\mypack\\src\\mypack\\subpack\\Demo.txt");
        try{
            BufferedReader r=new BufferedReader(f);
            System.out.println(r.readLine());
            throw new IOException ("Unexpected halt");
        }
        finally{
            System.out.println("File closed");
            f.close();
        }
    }
    public static void main(String[] args) {
        try{
            read();
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}