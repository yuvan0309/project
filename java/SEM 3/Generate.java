import java.util.Random;
class Square implements Runnable{
    Thread t;
    int x;
    Square(int n){
        x=n;
        t=new Thread(this,"Square");
        t.start();
    }
    public void run(){
        System.out.println("Square of "+x+"="+x*x);
    }
}
class Cube implements Runnable{
    Thread t;
    int x;
    Cube(int n){
        x=n;
        t=new Thread(this,"Cube");
        t.start();
    }
    public void run(){
        System.out.println("Cube of "+x+"="+x*x*x);
    }
}
class Generate implements Runnable{
    Thread t;
    Generate(){
        t=new Thread(this,"Random");
        t.start();
    }
    public void run(){
        int n;
        Random r=new Random(); 
        while(true){
            n=r.nextInt(100);
            System.out.println("Random number="+n);
            Square s=new Square(n);
            Cube c=new Cube(n);
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                System.out.println(e);
            }
        }
    }

public static void main(String[] args) {
    Generate r=new Generate();
}
}