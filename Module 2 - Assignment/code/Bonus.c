#include <stdlib.h>;
#include <stdio.h>;
#include <stdlib.h>;
#include <time.h>;

void merge(int arr[], int left, int mid, int right) {
int n1 = mid - left + 1;
int n2 = right - mid;

int *L = (int *)malloc(n1 * sizeof(int));
int *R = (int *)malloc(n2 * sizeof(int));

for (int i = 0; i < n1; i++)
L[i] = arr[left + i];
for (int j = 0; j < n2; j++)
R[j] = arr[mid + 1 + j];

int i = 0, j = 0, k = left;
while (i < n1 &amp;&amp; j < n2) {
if (L[i] <= R[j]) {
arr[k++] = L[i++];
} else {
arr[k++] = R[j++];
}
}

while (i < n1) {
arr[k++] = L[i++];
}

while (j < n2) {
arr[k++] = R[j++];
}

free(L);

free(R);
}

void mergeSort(int arr[], int left, int right) {
if (left < right) {
int mid = left + (right - left) / 2;

mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);

merge(arr, left, mid, right);
}
}

void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");

}

int main() {
int size;
printf("Enter the size of the array: ");
scanf("%d", &amp;size);

if (size <= 0) {
printf("Array size must be greater than 0.\n");
return 1;
}

int *arr = (int *)malloc(size * sizeof(int));
if (arr == NULL) {
printf("Memory allocation failed.\n");
return 1;
}

srand(time(NULL));

for (int i = 0; i < size; i++) {
arr[i] = rand() % 100 + 1;
}

printf("Original array:\n");
printArray(arr, size);

mergeSort(arr, 0, size - 1);

printf("Sorted array:\n");
printArray(arr, size);

// Find and display the median value
if (size % 2 == 0) {
int mid1 = size / 2;
int mid2 = mid1 - 1;
float median = (arr[mid1] + arr[mid2]) / 2.0;
printf("Median value: %.2f\n", median);
} else {

int mid = size / 2;
printf("Median value: %d\n", arr[mid]);
}

// Deallocate memory
free(arr);

return 0;
}
