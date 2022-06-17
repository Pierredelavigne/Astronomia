/*
** EPITECH PROJECT, 2021
** Libarry
** File description:
** load_file_in_mem
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *load_file_in_mem(char const *filepath)
{
    struct stat st;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    char *buffer;
    int file_size;

    stat(filepath, &st);
    file_size = st.st_size;
    buffer = malloc(sizeof(char) * 1024);
    read(fd, buffer, file_size);
    close(fd);
    return (buffer);
}