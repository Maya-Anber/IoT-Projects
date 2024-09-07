#include <stdio.h>;
#include <stdlib.h>;

int main() {
int num[5] = {5, 10, 15, 20, 25};
int sum = 0;
for (int i = 0; i &lt; 5; i++) {
sum += num[i];
}
printf(&quot;The sum is: %d\n&quot;, sum);
return 0;
}
