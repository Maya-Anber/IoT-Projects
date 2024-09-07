#include <stdlib.h>;
#include <stdio.h>;
int main() {
int n;
printf("Enter an integer: ");
scanf("%d", &n);
if (n < 0) {
printf("Error\n");
return 1;
}
int factorial = 1;
for (int i = n; i >;= 1; i--) {
factorial *= i;
}
printf("Factorial of %d: %d\n", n, factorial);
return 0;
}
