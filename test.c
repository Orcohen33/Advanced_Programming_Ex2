#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create sample text file
    FILE *file = fopen("sample.txt", "w");
    if (file == NULL) {
        printf("Failed to create sample.txt\n");
        return 1;
    }

    system("make all");
    sleep(5);
    const char *sample_text = "This is a test file for the multithreaded encryption and decryption tool.";
    fwrite(sample_text, 1, strlen(sample_text), file);
    fclose(file);

    printf("Created sample.txt\n");

    // Encrypt the sample text file
    printf("Encrypting sample.txt...\n");
    system("cat sample.txt | ./coder 2 -e > encrypted_file");
    printf("Encryption complete, output written to encrypted_file\n");

    // Decrypt the encrypted file
    printf("Decrypting encrypted_file...\n");
    system("cat encrypted_file | ./coder 2 -d > decrypted_file");
    printf("Decryption complete, output written to decrypted_file\n");

    // Compare the original and decrypted files
    printf("Comparing sample.txt and decrypted_file...\n");
    int diff_result = system("diff sample.txt decrypted_file");
    if (diff_result == 0) {
        printf("Test passed: The contents of sample.txt and decrypted_file are the same.\n");
    } else {
        printf("Test failed: The contents of sample.txt and decrypted_file are not the same.\n");
    }

    return 0;
}