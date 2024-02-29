#include <stdio.h>
#include <stdlib.h>

int main() {
    char inputFileName[100], outputFileName[100];
    char command[300];
    FILE *input_file, *output_file;

    // Ask the user to enter the name of the email text input file
    printf("Enter the name of the email text input file: ");
    scanf("%s", inputFileName);

    input_file = fopen(inputFileName, "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", inputFileName);
        return 1;
    }

    printf("Enter the name of the output file for valid emails: ");
    scanf("%s", outputFileName);

    output_file = fopen(outputFileName, "a");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", outputFileName);
        fclose(input_file);
        return 1;
    }

    snprintf(command, sizeof(command), "grep -E '^[a-zA-Z0-9]+([._+-][a-zA-Z0-9]+)*@[a-zA-Z0-9]+([.-][a-zA-Z0-9]+)*\\.[a-zA-Z]{2,}$' %s > %s", inputFileName, outputFileName);

    system(command);

    printf("Valid emails have been redirected to %s\n", outputFileName);

    fclose(input_file);
    fclose(output_file);
    

    return 0;
}
