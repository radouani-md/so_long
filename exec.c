#include "get_file_next/get.h"
#include <stdio.h>
#include <fcntl.h>



int main()
{
    int fd = open("file_util/map.ber", O_RDONLY);
    char *line;
    while(line = get_next_line(fd))
    {
        printf("%s", line);
        free(line);
    }
    free(line);
}