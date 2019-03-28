#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <pty.h>
#include <termios.h>
#include <fcntl.h>

#include <sys/select.h>
#include <sys/wait.h>

#define SHELL "/bin/sh"

#define error(msg, ...) { fprintf(stderr, #__VA_ARGS__); exit(1); }

int main() {
	int master;
	pid_t pid;

	printf("start\n");
	pid = forkpty(&master, NULL, NULL, NULL);
	if (pid < 0) error("ERROR: fork_pty\n");
	if (pid == 0) {
		printf("child\n");
		execlp(SHELL, SHELL, "-c", "tty >> /tmp/tty", NULL);
	} else {
		printf("parent\n");
		int wstatus = 0;
		waitpid(pid, &wstatus, 0);
	}
	return 0;
}
