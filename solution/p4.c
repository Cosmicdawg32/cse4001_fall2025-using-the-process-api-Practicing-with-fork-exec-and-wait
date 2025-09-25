// p4.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}

	if (rc == 0) { // child replaces itself with /bin/ls
		char *argv[] = {"ls", NULL};
		execv("/bin/ls", argv);
		fprintf(stderr, "execv failed\n"); // prints if execv fails
		exit(1);
	} else { // parent: waits for child
		wait(NULL);
	}
	return 0;
}
