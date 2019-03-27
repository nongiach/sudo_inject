#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av) {
	if (ac <= 1) {
		fprintf(stderr, "Usage: %s [tty]\n", av[0]);
		return 1;
	}
	close(0);
	setsid();
	setpgid(0, 0);
	int fd = open(av[1], O_RDONLY);
	printf("fd == %d\n", fd);
	execlp("/bin/sudo", "/bin/sudo", "-S", "ls", 0);
	return 1;
}
