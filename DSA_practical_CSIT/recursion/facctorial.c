#include<stdio.h>
long int factorial(int);
int main(){
    int n;
    long int fact;
    printf("ENter the value of the number of which you want factorial of:\n");
    scanf("%d" , &n);
    fact = factorial(n);
    printf("The factorial of %d is %lld" , n, fact);
    return 0;
}

long int factorial(int n){
    if (n == 0 || n == 1)
        return 1;
    else{
        return n*factorial(n-1);
    }
}