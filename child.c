#include "child.h"

#include <stdio.h>
#include <unistd.h>

int child_main(int fd_read, int fd_write) {
    int data;
    read(fd_read, &data, sizeof(data));
    printf("child received: %d\n", data);

    data *= 3;
    printf("child sending: %d\n", data);
    write(fd_write, &data, sizeof(data));

    return 0;
}
