/*
** EPITECH PROJECT, 2021
** Libarry
** File description:
** load_file_in_mem
*/

#include <stdio.h>
#include <stdlib.h>
// #include "my.h" // If my_putstr_error is used for errors

// Function to get file size using stdio
long get_file_size(FILE *fp)
{
    long size;
    if (fseek(fp, 0, SEEK_END) != 0) {
        // my_putstr_error("Error: fseek failed to go to end of file.\n");
        return -1L;
    }
    size = ftell(fp);
    if (size == -1L) {
        // my_putstr_error("Error: ftell failed to get file size.\n");
        return -1L;
    }
    if (fseek(fp, 0, SEEK_SET) != 0) {
        // my_putstr_error("Error: fseek failed to rewind to start of file.\n");
        return -1L;
    }
    return size;
}

char *load_file_in_mem(char const *filepath)
{
    FILE *fp = NULL;
    char *buffer = NULL;
    long file_size = 0; // Use long for ftell compatibility
    size_t bytes_read;

    if (filepath == NULL) {
        // my_putstr_error("Error: filepath is NULL.\n");
        return NULL;
    }

    fp = fopen(filepath, "rb"); // Open in binary read mode
    if (fp == NULL) {
        // my_putstr_error("Error: Could not open file: ");
        // my_putstr_error(filepath);
        // my_putstr_error("\n");
        perror("load_file_in_mem - fopen");
        return NULL;
    }

    file_size = get_file_size(fp);
    if (file_size < 0) { // Check if get_file_size encountered an error
        fclose(fp);
        return NULL;
    }

    if (file_size == 0) { // Handle empty file
        buffer = malloc(1);
        if (buffer == NULL) {
            // my_putstr_error("Error: malloc failed for empty file buffer.\n");
            perror("load_file_in_mem - malloc empty file");
            fclose(fp);
            return NULL;
        }
        buffer[0] = '\0';
        fclose(fp);
        return buffer;
    }

    buffer = malloc(file_size + 1); // +1 for the null terminator
    if (buffer == NULL) {
        // my_putstr_error("Error: malloc failed to allocate memory for file content.\n");
        perror("load_file_in_mem - malloc content");
        fclose(fp);
        return NULL;
    }

    bytes_read = fread(buffer, 1, file_size, fp);
    // bytes_read might be less than file_size if an error occurs or EOF is reached prematurely.
    // For text files, file_size from ftell might differ from bytes read on Windows due to CRLF->LF conversion
    // if not opened in binary mode. Since we use "rb", this should be consistent.
    if (bytes_read < (size_t)file_size && ferror(fp)) {
        // my_putstr_error("Error: fread failed to read the entire file: ");
        // my_putstr_error(filepath);
        // my_putstr_error("\n");
        perror("load_file_in_mem - fread");
        free(buffer);
        fclose(fp);
        return NULL;
    }
    buffer[bytes_read] = '\0'; // Null-terminate the buffer at actual bytes read

    fclose(fp);
    return buffer;
}