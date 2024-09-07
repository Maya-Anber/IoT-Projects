#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
void findMaxProduct(int arr[], int n) {
int max1 = arr[0], max2 = arr[0], max3 = arr[0];
int min1 = arr[0], min2 = arr[0];
// find the three maximum numbers and the two minimum numbers
for (int i = 1; i &lt; n; i++) {
if (arr[i] &gt; max1) {
max3 = max2;
max2 = max1;

max1 = arr[i];
} else if (arr[i] &gt; max2) {
max3 = max2;
max2 = arr[i];
} else if (arr[i] &gt; max3) {
max3 = arr[i];
}
if (arr[i] &lt; min1) {
min2 = min1;
min1 = arr[i];
} else if (arr[i] &lt; min2) {
min2 = arr[i];
}
}
// calculate the maximum product if in negative or positive
int product1 = max1 * max2 * max3;
int product2 = max1 * min1 * min2;
if (product1 &gt; product2) {
printf(&quot;The maximum product is: %d * %d * %d = %d\n&quot;, max1, max2, max3, product1);
} else {
printf(&quot;The maximum product is: %d * %d * %d = %d\n&quot;, max1, min1, min2, product2);

}
}
int main() {
int n;
printf(&quot;Enter the size of the array: &quot;);
scanf(&quot;%d&quot;, &amp;n);
int arr[n];
printf(&quot;Enter array: &quot;);
for (int i = 0; i &lt; n; i++) {
scanf(&quot;%d&quot;, &amp;arr[i]);
}
findMaxProduct(arr, n);
return 0;
}
