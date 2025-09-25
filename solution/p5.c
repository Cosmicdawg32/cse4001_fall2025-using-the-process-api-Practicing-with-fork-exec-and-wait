// p5
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
		printf("child is running\n");
		exit(0);
	} else { // parent path
		int rc_wait = wait(NULL); // wait for the child to finish
		printf("parent (pid:%d) waited for child (pid:%d)\n", (int)getpid(), rc_wait);
	}
	return 0;
}

