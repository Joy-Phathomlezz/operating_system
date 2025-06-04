#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2];

    // Creating two pipes
    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    int id = fork();
    
    if (id == 0) {
        // Child Process
        close(fd1[0]); // Close read end of first pipe
        close(fd2[1]); // Close write end of second pipe

        int x;
        printf("Input: ");
        scanf("%d", &x);

        // Send `x` to the parent
        write(fd1[1], &x, sizeof(int));
        close(fd1[1]); // Close write end

        // Read the processed value from the parent
        read(fd2[0], &x, sizeof(int));
        close(fd2[0]); // Close read end

        printf("Final output: %d\n", x);
    } 
    else if (id > 0) {
        // Parent Process
        close(fd1[1]); // Close write end of first pipe
        close(fd2[0]); // Close read end of second pipe

        int y;
        read(fd1[0], &y, sizeof(int)); // Read from child
        close(fd1[0]); // Close read end

        y *= y; // Multiply by 3 as per question

        // Send the modified value back to the child
        write(fd2[1], &y, sizeof(int));
        close(fd2[1]); // Close write end

        wait(NULL); // Wait for child to finish
    } 
    else {
        perror("Fork failed");
    }

    return 0;
}
