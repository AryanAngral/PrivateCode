public class Program {
    public static void main(String args[]) {
       Program obj= new Program();
       obj.Sum(5, 9);
    }
    public void Sum(int n1, int n2){
        int res;
        res = n1+n2;
        System.out.println("sum of number is "+res);
    }
    public void Sum(int n1, int n2, int n3){
        int res;
        res = n1+n2+n3;
        System.out.println("sum of number is "+res);
    } 
    public void Sum(int n1, int n2, int n3, int n4){
        int res;
        res = n1+n2+n3+n4;
        System.out.println("sum of number is "+res);
    }
}