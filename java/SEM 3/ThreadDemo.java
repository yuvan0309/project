public class ThreadDemo{
    public static void main(String[] args) {
        Thread t=Thread.currentThread();
        System.out.println("Current Thread is "+t);
        t.setName("My Thread");
        System.out.println("After Changing "+t);
        System.out.println("name of the thread is "+t.getName());

        for(int i=5;i>0;i--){
            System.out.println(i);
            try{
                Thread.sleep(1000);
            }
            catch(InterruptedException e){
                System.out.println("main thread Interrupted");
            }
        }
    }
}