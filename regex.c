#include <stdio.h>
#include <stdlib.h>

int main() {
    char input_file_name[100], output_file_name[100];
    char command[300];
    FILE *input_file, *output_file;

    // Ask the user to enter the name of the email text input file
    printf("Enter the name of the email text input file: ");
    scanf("%s", input_file_name);

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", input_file_name);
        return 1;
    }

    printf("Enter the name of the output file for valid emails: ");
    scanf("%s", output_file_name);

    output_file = fopen(output_file_name, "a");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", output_file_name);
        fclose(input_file);
        return 1;
    }

    snprintf(command, sizeof(command), "grep -E '^[a-zA-Z0-9]+([._+-][a-zA-Z0-9]+)*@[a-zA-Z0-9]+([.-][a-zA-Z0-9]+)*\\.[a-zA-Z]{2,}$' %s > %s", input_file_name, output_file_name);

    system(command);

    printf("Valid emails have been extracted and saved to %s\n", output_file_name);

    fclose(input_file);
    fclose(output_file);
    

    return 0;
}
