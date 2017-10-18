#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#define FILENAME  "1.txt"

int main(void)
{
	int fd1 = -1;
	int fd2 = -1;
	
	fd1 = open(FILENAME,O_RDWR | O_CREAT | O_TRUNC,0644);
	
	if (fd1 < 0)
	{
		perror("open");
		return -1;
	}
	
	printf("fd1 = %d.\n",fd1);
	
	// 复制文件描述符
	//fd2 = dup(fd1);
	
	fd2 = dup2(fd1,16);
	
	printf("fd2 = %d.\n",fd2);
	
	while (1)
	{
		write(fd1,"asd",3);
		sleep(1);
		write(fd2,"fgh",3);
	}
	
	close(fd1);
	
	return -1;
}