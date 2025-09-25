// p1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int x = 100;

	printf("Before fork (pid:%d)\n x = %d\n", (int) getpid(), x);
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n"); // fork failed
		exit(1);
	} else if (rc == 0) { // childs path
		x = 200; // change childs copy
		printf("Child (pid:%d)\n x = %d\n", (int) getpid(), x); // child (new process)
	} else { // parents path
		x = 300; // change parents copy
		int rc_wait = wait(NULL);
		printf("Parent of %d (pid:%d) \n x = %d\n",
			rc_wait, (int) getpid(), x);
	}

	return 0;
}
