#include "child.h"

int child_main(int fd_read, int fd_write) {
    int data;
    read(fd_read, &data, sizeof(data));

    data *= 3;
    write(fd_write, &data, sizeof(data));

    return 0;
}
