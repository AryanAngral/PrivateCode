import java.util.Scanner;

public class manage {
    public static void main(String[] args) {
        StudentGroup obj1 = new StudentGroup();
        obj1.welcome();
        obj1.groupDistribution();
    }
}

class Student {
    private Scanner sc = new Scanner(System.in); // Use a single Scanner instance

    public void welcome() {
        System.out.print("Enter your name: ");
        String name = sc.nextLine();
        System.out.println("Welcome to JAVA-101, " + name + "!");
    }

    public Scanner getScanner() {
        return sc; // Provide the Scanner instance to subclasses
    }
}

class StudentGroup extends Student {
    public void groupDistribution() {
        Scanner sc = getScanner(); // Reuse the Scanner from the parent class

        System.out.print("Enter your registration number: ");
        if (sc.hasNextInt()) { // Validate input to prevent runtime errors
            int regNo = sc.nextInt();

            if (regNo > 0 && regNo < 201) {
                if (regNo > 0 && regNo < 51) {
                    System.out.println("You are in Group 1");
                } else if (regNo > 50 && regNo < 101) {
                    System.out.println("You are in Group 2");
                } else if (regNo > 100 && regNo < 151) {
                    System.out.println("You are in Group 3");
                } else if (regNo > 150 && regNo < 201) {
                    System.out.println("You are in Group 4");
                }
            } else {
                System.out.println("Enter a valid registration number between 1 and 200.");
            }
        } else {
            System.out.println("Invalid input. Please enter a numeric registration number.");
        }
    }
}
