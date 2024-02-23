#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_filename[100], command[500];

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    sprintf(command, "grep -E '([a-zA-Z0-9. _%+/-]+)@([a-zA-Z0-9]+\\.)+[a-zA-Z0-9]{2,}' %s > valid.txt", input_filename);
    system(command);

    printf("Enter the name of the output file for valid emails: ");
    char output_filename[100];
    scanf("%s", output_filename);

    sprintf(command, "mv valid.txt %s", output_filename);
    system(command);

    printf("Valid emails extracted and saved to %s\n", output_filename);

    return 0;
}
