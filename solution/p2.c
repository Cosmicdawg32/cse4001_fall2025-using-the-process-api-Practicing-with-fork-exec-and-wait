// p2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(void) {
	int fd = open("p2.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0) {
		fprintf(stderr, "open failed\n");
		exit(1);
	}

	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { // child process
		write(fd, "child\n", 6);
		exit(0);
	} else {	// parent process
		write(fd, "parent\n", 7);
		wait(NULL);
	}
	close(fd);
	return 0;
}
