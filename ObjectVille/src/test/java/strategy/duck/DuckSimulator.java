package test.java.strategy.duck;

import main.java.strategy.duck.DecoyDuck;
import main.java.strategy.duck.Duck;
import main.java.strategy.duck.MallardDuck;
import main.java.strategy.duck.RubberDuck;

public class DuckSimulator {

        public static void main (String[] args) {
            testMallardDuck();
            testDecoyDuck();
            testRubberDuck();
        }

        public static void simpleBehaviorTest(Duck duck)
        {
            String packageName = duck.getClass().getSimpleName(); // .split(".");
            System.out.println("Started Testing Duck " + packageName);
            testDisplay(duck);
            testQuack(duck);
            testFly(duck);
            System.out.println("Finished Testing Duck " + packageName +  "\n");
        }

        public static void testMallardDuck() {
            Duck mallardDuck = new MallardDuck();
            simpleBehaviorTest(mallardDuck);
        }

        public static void testRubberDuck() {
            Duck rubberDuck = new RubberDuck();
            simpleBehaviorTest(rubberDuck);
        }

        public static void testDecoyDuck() {
            Duck decoyDuck = new DecoyDuck();
            simpleBehaviorTest(decoyDuck);
        }

        public static void testFly(Duck duck) {
            duck.fly();
        }

        public static void testQuack(Duck duck) {
            duck.quack();
        }

        public static void testDisplay(Duck duck) {
            duck.display();
        }

}
