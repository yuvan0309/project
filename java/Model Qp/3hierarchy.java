class Animal {
    String name;
  
    public Animal(String name) {
      this.name = name;
    }
  
    public void eat() {
      System.out.println(name + " is eating.");
    }
  }
  
  class Mammal extends Animal {
    boolean hasFur;
  
    public Mammal(String name, boolean hasFur) {
      super(name); 
      this.hasFur = hasFur;
    }
  
    public void giveBirth() {
      System.out.println(name + " is giving birth.");
    }
  }
  
  class Dog extends Mammal {
    String breed;
  
    public Dog(String name, boolean hasFur, String breed) {
      super(name, hasFur);  
      this.breed = breed;
    }
  
    public void bark() {
      System.out.println(name + " (" + breed + ") is barking.");
    }
  }
  
  public class Main {
    public static void main(String[] args) {
      Dog dog = new Dog("Buddy", true, "Labrador");
      dog.eat();  // Inherited from Animal
      dog.giveBirth();  // Inherited from Mammal
      dog.bark();  // Specific to Dog
    }
  }
  