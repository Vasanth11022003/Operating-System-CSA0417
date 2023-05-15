#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES 2

struct File {
    char name[50];
};

struct UserDirectory {
    char name[50];
    struct File files[MAX_FILES];
};

struct RootDirectory {
    struct UserDirectory userDirs[MAX_USERS];
};

int main() {
    struct RootDirectory rootDir;
    int i, j;


    for (i = 0; i < MAX_USERS; i++) {
        printf("Enter the name of user directory %d: ", i + 1);
        scanf("%s", rootDir.userDirs[i].name);

        printf("Creating files for user directory %s:\n", rootDir.userDirs[i].name);
        for (j = 0; j < MAX_FILES; j++) {
            printf("Enter the name of file %d: ", j + 1);
            scanf("%s", rootDir.userDirs[i].files[j].name);
        }
        printf("\n");
    }

    printf("User Directories and Files:\n");
    for (i = 0; i < MAX_USERS; i++) {
        printf("User Directory: %s\n", rootDir.userDirs[i].name);
        printf("Files:\n");
        for (j = 0; j < MAX_FILES; j++) {
            printf("- %s\n", rootDir.userDirs[i].files[j].name);
        }
        printf("\n");
    }

    return 0;
}

