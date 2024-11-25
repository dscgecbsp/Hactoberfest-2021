package Switch;

import java.util.Scanner;

public class Calculator {

	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		int a = 0 , b = 0;
		try {
			System.out.println("Enter first number ");
			a = sc.nextInt();			
			System.out.println("Enter second number  ");
			b = sc.nextInt();
			
		}
		catch(Exception e){
			System.out.println("Error!! Enter valid number !!");
			System.exit(0);
			
		}
		
		System.out.println("Enter the operator ");
		sc.nextLine();
		char c = sc.nextLine().charAt(0);
		int result=0;
		
		switch (c) {
		case '+': result = a+b;
		          System.out.println(a+ " + " + b + " = " + result );
		  break ;
		case '-': result = a-b;
		          System.out.println(a+ " - " + b + " = " + result );
		 break;
		case '*': result = a*b;
				  System.out.println(a+ " * " + b + " = " + result );
		 break ;
		case '/': 
				  if (b==0) {
					  System.out.println("Undefined");
					  break;
				  }
				  result = a/b;
				  System.out.println(a+ " / " + b + " = " + result );
	     break ;
		default : System.out.println(" invalid choice ");
		}
	   
		}

	}


