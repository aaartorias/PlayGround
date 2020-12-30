package main.java.strategy.duck;

public class RubberDuck extends Duck {

    public RubberDuck() {
        setFlyBehavior(new FlyNoWay());
        setQuackBehavior(new Squeak());
    }

    @Override
    public void display() { System.out.println("Hello, I am a Rubber Duck"); }
}
