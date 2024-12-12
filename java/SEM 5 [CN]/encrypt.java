import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;

public class encrypt {
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
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the plain text:");
        String input = scanner.nextLine();

        byte[] encrypted = rsa.encrypt(input.getBytes());
        byte[] decrypted = rsa.decrypt(encrypted);

        System.out.println("Encrypting String: " + input);
        System.out.println("String in Bytes: " + new BigInteger(input.getBytes()));
        System.out.println("Decrypting Bytes: " + new BigInteger(decrypted));
        System.out.println("Decrypted String: " + new String(decrypted));

        scanner.close();
    }
}
