/** simple input example */

#include <stdio.h>
#include <string.h>

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("You entered: %d\n", number);

    // input a name on a single line
    char name[10];
    printf("Enter your name, 10 characters max: ");
    scanf("%s", name);
    printf("You entered: [%s]\n", name);
    getchar(); // consume the newline character left by previous input
    // read a complete line of text

    char line[200];
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);
    printf("You entered: [%s]\n", line);
    // strip last character from line
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }
    printf("You entered (stripped): [%s]\n", line);

    // read a single characters until end of file
    int ch;
    printf("Enter characters (Ctrl+D to end, Ctrl+Z, enter in vscode):\n");
    while ((ch = getchar()) != EOF) {
        printf("You entered: [%c] code %d\n", ch,  ch);
    }
    printf("End of input.\n");
    return 0;
}