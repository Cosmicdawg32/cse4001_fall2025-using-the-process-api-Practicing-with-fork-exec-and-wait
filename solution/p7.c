// p7
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { // child path
		close(STDOUT_FILENO);
		printf("Hello world!\n");
		exit(0);
	} else { // parent path
		wait(NULL);
	}
	return 0;
}
