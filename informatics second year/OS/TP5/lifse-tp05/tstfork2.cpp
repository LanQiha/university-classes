#include <unistd.h>
#include <sys/wait.h>

#include <iostream>

#include <errno.h>

int main() {
	int ret = fork();
	
	if(ret < 0) {
		std::cout << errno << std::endl;
	}
	
	if(ret == 0) {
		sleep(5);
		std::cout << "pid du père : " << getppid() << std::endl;
		std::cout << "pid du fils : " << getpid() << std::endl;
		int ret2 = fork();
		
		if(ret2 < 0) {
			std::cout << errno << std::endl;
		}
		
			if(ret2 == 0) {
				sleep(5);
				std::cout << "pid du père : " << getppid() << std::endl;
				std::cout << "pid du fils : " << getpid() << std::endl;
				return 0;
			}
			
		if(waitpid(ret2, NULL, 0) < 0) {
			std::cout << errno << std::endl;
		}
			
		waitpid(ret2, NULL, 0);
		return 0;
	}
	
	if(ret > 0) {
		std::cout << "pid du père : " << getppid() << std::endl;
		std::cout << "pid du fils : " << getpid() << std::endl;
		
		if(waitpid(ret, NULL, 0) < 0) {
			std::cout << errno << std::endl;
		}
		
		waitpid(ret, NULL, 0);
		return 0;
	}
	
	return 0;
}
