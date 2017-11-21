#include <unistd.h>

#include "child.h"
#include "parent.h"

#define READ 0
#define WRITE 1

int main() {
    // TODO: Check everything for errors.
    int forward_fds[2];
    pipe(forward_fds);

    int backward_fds[2];
    pipe(backward_fds);

    if (fork() == 0) {
        // Child process: read from forward, write to backward
        close(forward_fds[WRITE]);
        close(backward_fds[READ]);
        return child_main(forward_fds[READ], backward_fds[WRITE]);
    }
    else {
        // Parent process: write to forward, read from backward
        close(forward_fds[READ]);
        close(backward_fds[WRITE]);
        return parent_main(forward_fds[WRITE], backward_fds[READ]);
    }
}
