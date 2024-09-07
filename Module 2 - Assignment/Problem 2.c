#include <stdio.h>;
#include <stdlib.h>;

double calculateAverage(int arr[], int s) {
int sum = 0;
for (int i = 0; i &lt; s; i++) {
sum += arr[i];
}
return (double)(sum/s);
}

int main() {
int size;
printf("Enter the size of the array:");
scanf("%d" &size);
int arr[size];
printf("Enter array: ");
for (int i = 0; i &lt; size; i++) {
scanf("%d", &arr[i]);
}
double average = calculateAverage(arr, size);
printf("The average is: %.2f\n", average);
return 0;
}
