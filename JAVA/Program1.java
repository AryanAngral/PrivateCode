public class Program1 {
    public static void main(String args[]){
        Child1 obj1 = new Child1();
    obj1.Fun1();
    obj1.Fun2();
    Child2 obj2 = new Child2();
    obj2.Fun1();
    obj2.Fun3();
    }
}
class Parent{
    public void Fun1(){
        System.out.println("Parent class");
    }
}
class Child1 extends Parent{
    public void Fun2(){
        System.out.println("child class");
    }
}
class Child2 extends Parent{
    public void Fun3(){
        System.out.println("Child Class Function");
    }
}
