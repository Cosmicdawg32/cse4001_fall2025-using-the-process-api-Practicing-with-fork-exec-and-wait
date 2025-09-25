// p6
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
		int rc_wait = waitpid(rc, NULL, 0); // waits for child
		printf("parent (pid:%d) waited for child (pid:%d)\n", (int)getpid(), rc_wait);
	}
	return 0;
}
