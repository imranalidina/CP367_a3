#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_filename[100], output_filename[100], command[500];
    FILE *file;

    // Prompt for input filename and check if it's "emails.txt"
    printf("Enter the name of the input file: ");
    scanf("%99s", input_filename); // Using %99s to prevent buffer overflow
    if (strcmp(input_filename, "emails.txt") != 0) {
        printf("Error opening input file: No such file or directory\n");
        return 1; // Exit with non-zero status code for error
    }

    // Prompt for output filename
    printf("Enter the name of the output file for valid emails: ");
    scanf("%99s", output_filename);

    // Check if the output file can be opened/created
    file = fopen(output_filename, "w");
    if (!file) {
        perror("Error opening output file");
        return 1; // Exit with non-zero status code for error
    }
    fclose(file); // Close the file as system call will be used for writing

    // Form and execute the command to filter valid emails using grep
    sprintf(command, "grep -E '^[a-zA-Z0-9._%%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$' %s > %s",
            input_filename, output_filename);
    int result = system(command);
    if (result != 0) {
        printf("Error executing grep command\n");
        return 1; // Exit with non-zero status code for error
    }

    // Inform the user of success
    printf("Valid emails extracted and saved to %s\n", output_filename);

    return 0;
}
