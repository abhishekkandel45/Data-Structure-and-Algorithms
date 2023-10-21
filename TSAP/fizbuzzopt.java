// Program to print Fizz when number is divisible by 3, Buzz when divisible by 5 and FizzBuzz when divisible by both 3 and 5, using three counters operator; 1 for Fizz, 2 for Buzz and 3 for FizzBuzz

import java.util.Scanner;

public class fizbuzzopt 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of terms: ");
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) 
        {
            int c = 0;
            c += (i % 3 == 0) ? 1 : 0; 
            c += (i % 5 == 0) ? 2 : 0; 

            switch (c) 
            {
                case 0:
                    System.out.println(i);
                    break;
                case 1:
                    System.out.println("Fizz");
                    break;
                case 2:
                    System.out.println("Buzz");
                    break;
                case 3:
                    System.out.println("FizzBuzz");
                    break;
            }
        }
    }
}
