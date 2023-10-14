import java.util.Scanner;

public class prime {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number to check for prime:");
        int n = sc.nextInt();
        int k = checkPrime(n);
        if (k == 1)
            System.out.println("True");
        else
            System.out.println("False");
    }

    public static int checkPrime(int n) {
        if (n < 1) {
            return 0;

        } else {
            for (int i = 2; i < n; i++) {
                if (n % i == 0) {
                    return 1;

                } else
                    return 0;
            }

        }
        return n;
    }
}
