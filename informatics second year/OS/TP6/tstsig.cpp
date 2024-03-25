#include <iostream>
#include <unistd.h> 

#include <stdio.h>
#include <signal.h>

bool stop = false;
int cnt = 0;
 
void fct(int sig) {
	cnt++;
	if(cnt > 4)
		stop = true;	
}

int main() {
	struct sigaction s;
	sigaction(SIGUSR1, NULL, &s);
	s.sa_handler = fct;
	sigaction(SIGUSR1, &s, NULL);
	
	while(!stop) {
		std::cout << "mise en someil" << std::endl << std::flush;
		sleep(60);
	}
	return 0;
}
