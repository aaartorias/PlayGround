package main.java.strategy.duck;
import java.lang.*;

public abstract class Duck {
    private FlyBehavior flyBehavior;
    private QuackBehavior quackBehavior;

    public Duck() {}
    public abstract void display();

    public void swim () {
        System.out.println("All ducks float, even the rubber one");
    }

    public void setFlyBehavior(FlyBehavior flyBehavior) {
        this.flyBehavior = flyBehavior;
    }

    public void setQuackBehavior(QuackBehavior quackBehavior) {
        this.quackBehavior = quackBehavior;
    }

//    public void performQuack() {
    public void quack() {
        quackBehavior.quack();
    }

//    public void performFly() {
    public void fly() {
        flyBehavior.fly();
    }
}