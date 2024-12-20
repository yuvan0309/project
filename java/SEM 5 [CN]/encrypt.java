import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;

public class Encrypt {
    private BigInteger p, q, N, phi, e, d;
    private final int BIT_LENGTH = 1024;

    public Encrypt() {
        Random r = new Random();
        p = BigInteger.probablePrime(BIT_LENGTH, r);
        q = BigInteger.probablePrime(BIT_LENGTH, r);
        N = p.multiply(q);
        phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));

        e = BigInteger.probablePrime(BIT_LENGTH / 2, r);
        while (!phi.gcd(e).equals(BigInteger.ONE)) {
            e = e.add(BigInteger.ONE); 
        }

        d = e.modInverse(phi); 
    }

    public byte[] encrypt(byte[] message) {
        return new BigInteger(message).modPow(e, N).toByteArray();
    }

    public byte[] decrypt(byte[] message) {
        return new BigInteger(message).modPow(d, N).toByteArray();
    }

    public static void main(String[] args) {
        Encrypt rsa = new Encrypt();
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the plain text: ");
        String input = sc.nextLine();

        byte[] encrypted = rsa.encrypt(input.getBytes());
        byte[] decrypted = rsa.decrypt(encrypted);

        System.out.println("Encrypted: " + new BigInteger(encrypted));
        System.out.println("Decrypted: " + new String(decrypted));

        sc.close();
    }
}
