#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	int fd[2];
	pipe(fd);
	pid_t child;
	child = fork();
	char buff[15];
	char data[] = "hello!";
	if (child == -1)
	{
		perror("child: ");
		exit(1);
	}
	else if (child == 0)
	{
		close(fd[1]);
		if (read(fd[0], buff, 15) > 0);
			printf("pid = %d\t ppid = %d\t | %s\t <read>\n", getpid(), getppid(), buff);
		close(fd[0]);
		exit(0);
	}
	else
	{
		close(fd[0]);
		if (write(fd[1], data, 15) > 0)
			printf("pid = %d\t ppid = %d\t | %s\t <write>\n", getpid(), getppid(), data);
		close(fd[1]);
		exit(0);
	}
	waitpid(child, NULL, 0);
	exit(0);
}
