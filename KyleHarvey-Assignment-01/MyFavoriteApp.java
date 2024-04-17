
package calculator;

import java.util.ArrayList;

import java.util.List;

import java.util.Scanner;

public class MyFavoriteApp {
static List<String> res = new ArrayList<>();

public static void main(String[] args) {

boolean a = true;

int input = 0;

Scanner sc = new Scanner(System.in);

int num1, num2;

while(input != 5){

System.out.println("Select an operation:\n1) Addition\n2) Subtraction\n3) Multiplication\n4) Division\n5) Review History");

try{

input = sc.nextInt();

if(input == 1)

{

System.out.println("Enter Two Numbers");

num1 = sc.nextInt();

num2 = sc.nextInt();

addition(num1 , num2);

//res.add("Result: "+a+ " + "+ b+" = "+ (a+b));

}

else if(input == 2)

{

System.out.println("Enter Two Numbers");

num1 = sc.nextInt();

num2 = sc.nextInt();

subtraction(num1 , num2);

}

else if(input == 3)

{

System.out.println("Enter Two Numbers");

num1 = sc.nextInt();

num2 = sc.nextInt();

multiplication(num1 , num2);

}

else if(input == 4)

{

System.out.println("Enter Two Numbers");

num1 = sc.nextInt();

num2 = sc.nextInt();

division(num1 , num2);

}

else if(input == 5)

{

System.out.println("Which previous answer would you like to review?:");

num1 = sc.nextInt();

System.out.println(res.get(num1-1));

}

else{

System.out.println("Please choose between 1 to 5");

}

}

catch(Exception ex){

System.out.println("Please Enter Valid INput");

}

}

}

static void addition(int a, int b){

System.out.println("Result: "+a+ " + "+ b+" = "+ (a+b));

res.add("Result: "+a+ " + "+ b+" = "+ (a+b));

}

static void subtraction(int a, int b){

System.out.println("Result: "+a+ " - "+ b+" = "+ (a-b));

res.add("Result: "+a+ " - "+ b+" = "+ (a-b));

}

static void multiplication(int a, int b){

System.out.println("Result: "+a+ " * "+ b+" = "+ (a*b));

res.add("Result: "+a+ " * "+ b+" = "+ (a*b));

}

static void division(int a, int b){

System.out.println("Result: "+a+ " / "+ b+" = "+ (a/b));

res.add("Result: "+a+ " / "+ b+" = "+ (a/b));

}

}



