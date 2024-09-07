#include <stdlib.h>;
#include <stdio.h>;
void findMaxProduct(int arr[], int n) {
int max1 = arr[0], max2 = arr[0], max3 = arr[0];
int min1 = arr[0], min2 = arr[0];
// find the three maximum numbers and the two minimum numbers
for (int i = 1; i < n; i++) {
if (arr[i] >; max1) {
max3 = max2;
max2 = max1;

max1 = arr[i];
} else if (arr[i] >; max2) {
max3 = max2;
max2 = arr[i];
} else if (arr[i] >; max3) {
max3 = arr[i];
}
if (arr[i] < min1) {
min2 = min1;
min1 = arr[i];
} else if (arr[i] < min2) {
min2 = arr[i];
}
}
// calculate the maximum product if in negative or positive
int product1 = max1 * max2 * max3;
int product2 = max1 * min1 * min2;
if (product1 >; product2) {
printf("The maximum product is: %d * %d * %d = %d\n", max1, max2, max3, product1);
} else {
printf("The maximum product is: %d * %d * %d = %d\n", max1, min1, min2, product2);

}
}
int main() {
int n;
printf("Enter the size of the array: ");
scanf("%d", &n);
int arr[n];
printf("Enter array: ");
for (int i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
findMaxProduct(arr, n);
return 0;
}
