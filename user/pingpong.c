#include <kernel/types.h>
#include <user/user.h>

int main() {
    int pipe1[2], pipe2[2];
    char buf = 'X';
    int iter = 1000;

    if (pipe(pipe1) < 0 || pipe(pipe2) < 0) {
		fprintf(2, "pingpong: pipe error\n");
        exit(1);
    }

    int pid = fork();
    if (pid < 0) {
		fprintf(2, "pingpong: fork error\n");
        exit(1);
    }

    if (pid == 0) { // Child process 
        close(pipe1[1]);
        close(pipe2[0]);
        while (1) {
            if (read(pipe1[0], &buf, 1) <= 0) break;
            if (write(pipe2[1], &buf, 1) <= 0) break;
        }
        close(pipe1[0]);
        close(pipe2[1]);
        exit(0);
    } else { // Parent process
        close(pipe1[0]);
        close(pipe2[1]);
        int start = uptime();
        for (long i = 0; i < iter; i++) {
            if (write(pipe1[1], &buf, 1) <= 0) break;
            if (read(pipe2[0], &buf, 1) <= 0) break;
        }
		int end = uptime();
        close(pipe1[1]);
        close(pipe2[0]);
        wait(0);
        printf("Test time: %d ticks, Iterations: %d\n", end - start, iter);
    }

    return 0;
}
