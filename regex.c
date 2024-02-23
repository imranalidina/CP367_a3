#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {
    char input_filename[100], output_filename[100], command[500];
    FILE *input_file, *output_file;

    printf("Enter the name of the input file: ");
    scanf("%99s", input_filename); // Limit input to prevent buffer overflow

    // Check if the input file is the correct one
    if (strcmp(input_filename, "emails.txt") != 0) {
        printf("Error opening input file: No such file or directory\n");
        return 1; // Exit with an error status if the file is not emails.txt
    }

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return 1; // Exit with an error status if the file cannot be opened
    }

    printf("Enter the name of the output file for valid emails: ");
    scanf("%99s", output_filename);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        fclose(input_file); // Close the input file before exiting
        return 1;
    }

    // Execute the grep command to extract valid emails and redirect to the output file
    sprintf(command, "grep -E '^[a-zA-Z0-9._%%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$' %s > %s",
            input_filename, output_filename);
    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "Error executing grep command\n");
        fclose(input_file);
        fclose(output_file);
        return 1; // Exit with an error status if the grep command fails
    }

    printf("Valid emails extracted and saved to %s\n", output_filename);

    fclose(input_file);
    fclose(output_file);

    return 0; // Success
}
