import java.util.Scanner;
class OOCException extends Exception{
    OOCException(String msg){
        super(msg);
    }
}
public class CustomException{
    static void divide(double a, double b) throws OOCException{
        if(b==0)
            throw new OOCException("Division by zero is not allowed");
        double c=a/b;
        System.out.println("c="+c);
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter two numbers");
        double a=sc.nextDouble();
        double b=sc.nextDouble();
        try{
            divide(a,b);
        }
        catch(OOCException e){
            System.out.println(e);
        }
        finally{
            System.out.println("This is Finally block");
        }
    }
}
