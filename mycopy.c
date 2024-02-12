#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are passed
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 2;
    }

    // Open/Create the output file
    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        perror("Error opening/creating output file");
        fclose(inputFile); // Close input file before returning
        return 3;
    }

    // Copy process
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) { // Read character by character
        fputc(ch, outputFile); // Write character to output file
    }

    // Close both files
    fclose(inputFile);
    fclose(outputFile);

    printf("File has been copied successfully.\n");

    return 0;
}
