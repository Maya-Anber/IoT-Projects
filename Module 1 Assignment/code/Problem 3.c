#include <stdio.h>
#include <stdlib.h>
int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);
    printf("  %c %c %c\n", ch, ch, ch);
    printf(" %c    %c\n", ch, ch);
    printf("%c\n", ch);
    printf("%c\n", ch);
    printf("%c\n", ch);
    printf("%c\n", ch);
    printf("%c\n", ch);
    printf(" %c    %c\n", ch, ch);
    printf("  %c %c %c\n", ch, ch, ch);

    return 0;
}
