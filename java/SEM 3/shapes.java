abstract class Shape{
    abstract void CalcArea();
    abstract void CalcPeri();
}
class Circle extends Shape{
    double r;
    Circle(double r){
        this.r=r;
    }
    void CalcArea(){
        System.out.printf("Area of Circle is %.3f\n",Math.PI*r*r);
    }
    void CalcPeri(){
        System.out.printf("Perimeter of Cicrle is %.3f\nb ",2*Math.PI*r);
    }
}
class Triangle extends Shape{
    double a,b,c;
    Triangle(double a,double b, double c){
        this.a=a;
        this.b=b;
        this.c=c;
    }
    void CalcArea(){
        double s=(a+b+c)/2;
        System.out.printf("Area of Triangle is %.3f\n",Math.sqrt(s*(s-a)*(s-b)*(s-c)));
    }
    void CalcPeri(){
        System.out.printf("Perimeter of Triangle is %.3f",(a+b+c));
    }
}
public class shapes{
    public static void main(String[] args) {
        Shape obj=new Circle(10);
        obj.CalcArea();
        obj.CalcPeri();
        obj=new Triangle(3,4,5);
        obj.CalcArea();
        obj.CalcPeri();
    }
} 