#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int is_valid_email(const char *email) {
    // check if email is valid
    return 1;
}

int main() {
    FILE *input_file, *output_file;
    char line[1024];
    int errno;

    printf("Enter the name of the input file: ");
    char input_filename[100];
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    printf("Enter the name of the output file for valid emails: ");
    char output_filename[100];
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        fclose(input_file);
        return 1;
    }

    while (fgets(line, sizeof(line), input_file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        if (is_valid_email(line)) {
            fprintf(output_file, "%s\n", line);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
