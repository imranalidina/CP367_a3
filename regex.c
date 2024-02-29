#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_OUTPUT_LENGTH 1000

void filter_valid_emails(const char *input_file_name, const char *output_file_name) {
    FILE *input_file, *output_file;
    char email[MAX_EMAIL_LENGTH];
    char command[300];

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", input_file_name);
        exit(1);
    }

    output_file = fopen(output_file_name, "a");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", output_file_name);
        fclose(input_file);
        exit(1);
    }

    while (fgets(email, MAX_EMAIL_LENGTH, input_file) != NULL) {
        char *at_symbol = strchr(email, '@');
        if (at_symbol == NULL) {
            continue;
        }

        char *dot = strchr(at_symbol + 1, '.');
        if (dot == NULL) {
            continue;
        }

        char *domain = dot + 1;
        if (strlen(domain) < 2) {
            continue;
        }

        fputs(email, output_file);
    }

    printf("Valid emails have been redirected to %s\n", output_file_name);

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file_name> <output_file_name>\n", argv[0]);
        return 1;
    }

    filter_valid_emails(argv[1], argv[2]);

    return 0;
}
