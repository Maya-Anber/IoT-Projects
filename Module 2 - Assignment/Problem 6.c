#include <stdlib.h>;
#include <stdio.h>;
int main() {
int n;
printf("Enter the size of the array: ");
scanf("%d", &n);
int arr[n];
printf("Enter array: ");
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
int sum = 0;
for (int i = 0; i < n; i++) {
sum += arr[i];
}
printf("Sum of elements: %d\n", sum);
return 0; 
}
