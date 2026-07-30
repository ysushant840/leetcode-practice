#include <string.h>
#include <stdlib.h>

char* simplifyPath(char* path) {
    char* stack[3000];
    int top = -1;

    char* token = strtok(path, "/");

    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
            // Ignore current directory
        } 
        else if (strcmp(token, "..") == 0) {
            if (top >= 0)
                top--;
        } 
        else {
            stack[++top] = token;
        }

        token = strtok(NULL, "/");
    }

    char* result = (char*)malloc(3001);
    result[0] = '\0';

    if (top == -1) {
        strcpy(result, "/");
        return result;
    }

    for (int i = 0; i <= top; i++) {
        strcat(result, "/");
        strcat(result, stack[i]);
    }

    return result;
}