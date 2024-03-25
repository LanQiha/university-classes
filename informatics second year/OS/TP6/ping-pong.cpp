#include <iostream>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>

int main() {
	int pid;
	if((pid=fork()) == 0) {
		for(int i = 0; i < 10; i++) {
			kill(getpid(), SIGSTOP);
			std::cout << "FILS : pong" << std::endl;
		}
	}
	else {
		for(int i = 0; i < 10; i++) {
			sleep(1);
			kill(pid, SIGCONT);
			std::cout << "PERE : ping" << std::endl;
		}
		wait(NULL);
	}
	
	
}
