#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
double calculateAverage(int arr[], int s) {
int sum = 0;
for (int i = 0; i &lt; s; i++) {
sum += arr[i];
}
return (double)(sum/s);
}

int main() {
int size;
printf(&quot;Enter the size of the array: &quot;);
scanf(&quot;%d&quot;, &amp;size);
int arr[size];
printf(&quot;Enter array: &quot;);
for (int i = 0; i &lt; size; i++) {
scanf(&quot;%d&quot;, &amp;arr[i]);
}
double average = calculateAverage(arr, size);
printf(&quot;The average is: %.2f\n&quot;, average);
return 0;
}
