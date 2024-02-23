#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {
    char input_filename[100], output_filename[100];
    FILE *input_file, *output_file;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    printf("Enter the name of the output file for valid emails: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        fclose(input_file);
        return 1;
    }

    char command[500] = "grep -E '([a-zA-Z0-9._+-]+)@([a-zA-Z0-9]+\\.)+[a-zA-Z0-9]{2,}' ";
    strcat(command, input_filename);
    strcat(command, " >> ");
    strcat(command, output_filename);

    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "Error executing grep command\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    printf("Valid emails extracted and saved to %s\n", output_filename);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
