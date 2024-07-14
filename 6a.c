#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd1 = open("6asample.txt", O_RDWR | O_APPEND);
    char buf[100] = {0};
    if (fd1 < 0) {
        perror("FD error");
        exit(EXIT_FAILURE);
    }

    lseek(fd1, 0, SEEK_SET);
    ssize_t bytes_read = read(fd1, buf, 20);
    if (bytes_read < 0) {
        perror("Error in Reading File");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    int fd2 = open("6asample2.txt", O_RDWR | O_APPEND | O_CREAT, 0666);
    if (fd2 < 0) {
        perror("Error opening 6asample2.txt");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    fd2 = dup2(fd1, fd2);
    if (fd2 < 0) {
        perror("Error duplicating file descriptor");
        close(fd1);
        exit(EXIT_FAILURE);
    }

    lseek(fd2, 0, SEEK_END);
    ssize_t bytes_written = write(fd2, buf, bytes_read);
    if (bytes_written < 0) {
        perror("Error writing to file");
        close(fd1);
        close(fd2);
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buf);

    close(fd1);
    close(fd2);

    return 0;
}

