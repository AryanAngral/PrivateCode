class Parent {
    public void Fun1(){
        System.out.println("Parent Class Function");
    }
}
class Child extends Parent{
    public void Fun2(){
        System.out.println("Child Class Function");
    }
}
class inheritance{
    public static void main(String[] args) {
        Child obj1 = new Child();
        obj1.Fun1();
        obj1.Fun2();
    }
}
