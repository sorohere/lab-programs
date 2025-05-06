#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s num1 num2\n", argv[0]);
        exit(0);
    }
    
    int num1 = atoi(argv[1]);  // Convert first argument to integer
    int num2 = atoi(argv[2]);  // Convert second argument to integer
    
    int sum = num1 + num2;  // Calculate sum
    
    printf("Sum: %d\n", sum);  // Print the sum
    
    return 0;
}
