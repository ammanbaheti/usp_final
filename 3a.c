#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    struct dirent* dir;
    DIR *dp;
    int fd, n;


    dp = opendir(argv[1]);


    while ((dir = readdir(dp)) != NULL) {
	    /*Purpose: When reading directory entries using readdir, the entries "." and ".." are returned, which represent the current directory and the parent directory, respectively. This check ensures that these entries are skipped and not processed.*/
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
            continue;
        }

        // Construct the full path
        char full_path[1024];
/*Purpose: The readdir function returns only the filename, not the full path. To open or manipulate the file, the full path is needed. This code constructs the full path by combining the directory path provided in argv[1] with the filename dir->d_name.*/
	snprintf(full_path, sizeof(full_path), "%s/%s", argv[1], dir->d_name);

        fd = open(full_path, O_RDWR);
        if (fd == -1) {
            perror("Error opening file");
            continue;
        }

        n = lseek(fd, 0, SEEK_END);
        if (n == -1) {
            perror("Error seeking in file");
            close(fd);
            continue;
        }

        if (n == 0) {
            printf("Deleting File: %s\n", full_path);
            if (unlink(full_path) == -1) {
                perror("Error deleting file");
            }
        }

        close(fd);
    }

    closedir(dp);
    return 0;
}

