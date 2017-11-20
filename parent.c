#include "parent.h"

#include <stdio.h>

int parent_main(int fd_write, int fd_read) {
    int data = 10000;
    write(fd_write, &data, sizeof(data));

    read(fd_read, &data, sizeof(data));
    printf("parent received: %d\n", data);

    return 0;
}
