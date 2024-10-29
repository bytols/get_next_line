#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int main()
{
	char    letter;
	char    buffer[256];
	int     fd;

	fd = open("text.txt", O_RDWR);
    read(fd, buffer, 400);
    printf("%s" , buffer);
	close(fd);
}