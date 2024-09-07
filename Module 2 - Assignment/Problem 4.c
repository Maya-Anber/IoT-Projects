#include <stdlib.h>;
#include <stdio.h>;
#include <ctype.h>;
int main() {
char str[100];
printf("Enter a string: ");
fgets(str, 100, stdin);
int count = 0;
char *ptr = str;
while (*ptr!='\0') {
char c = tolower(*ptr); // convert to lowercase
if (c =='a' || c =='e' || c =='i' || c =='o' || c =='u') {

count++;
}
ptr++;
}
printf("Number of vowels: %d\n", count);
return 0;
}
