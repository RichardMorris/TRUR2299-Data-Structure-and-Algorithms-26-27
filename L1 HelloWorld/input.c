/** simple input example */

#include <stdio.h>
#include <string.h>


int main() {
    
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("You entered: %d\n", number);

    short snum;
    printf("Enter a short number: ");
    scanf("%hd", &snum);
    printf("You entered: %hd\n", snum);

    int longnum;
    printf("Enter a long number: ");
    scanf("%ld", &longnum);
    printf("You entered: %ld\n", longnum);

    // input a name on a single line
    // char name[10]="123456789";
    // name[4] = '\0';

    char before[256];
    char name[16];
    char after[256];
    printf("Memory address: name %p before %p after %p\n", (void*)name, (void*)before, (void*)after);

    printf("Enter your name, 9 characters max: ");
    scanf("%s", name);
    printf("You entered: [%s]\n", name);
    printf("Before value: [%s]\n", before);
    printf("After value: [%s]\n", after);

    getchar(); // consume the newline character left by previous input
    // read a complete line of text

    char line[200];
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);
    printf("You entered: [%s]\n", line);
    for(int i=0; i < 20; ++i) {
        printf("You entered: [%c]  ASCII code %d at index %d\n", line[i], line[i], i);
    }
    // strip last character from line
    if (line[strlen(line) - 1] == '\n') {
        line[strlen(line) - 1] = '\0';
    }
    printf("You entered (stripped): [%s]\n", line);


    // read a single characters until end of file
    int ch;
    printf("Enter characters (Ctrl+D to end, Ctrl+Z, enter in vscode):\n");
    while ((ch = getchar()) != EOF) {
        printf("You entered: [%c] code %d 0x%02x\n", ch,  ch, ch);
    }
    printf("End of input.\n");
    return 0;
}