
import java.util.Scanner;

public class oops {
    // import java.io;
    // import java.util;

    public void Diaplay(){
        int n;
        Scanner in;
        in= new Scanner(System.in);
        System.out.println( "Enter Number");
        n=in.nextInt();
        System.out.println("Number entered by the user is "+n);
        in.close();
    }
    public static void main(String[] args){
        oops obj =  new oops();
        obj.Diaplay();
    }
}
