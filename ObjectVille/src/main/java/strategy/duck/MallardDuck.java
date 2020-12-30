package main.java.strategy.duck;

public class MallardDuck extends Duck{

    public MallardDuck() {
        setFlyBehavior(new FlyWithWings());
        setQuackBehavior(new Quack());
    }

    @Override
    public void display() { System.out.println("Hello, I am a Mallard Duck"); }
}
