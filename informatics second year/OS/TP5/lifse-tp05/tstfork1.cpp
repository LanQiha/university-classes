#include <unistd.h>
#include <sys/wait.h>

#include <iostream>
#include <string>

int main() {
	std::string let = "abcdefghi";
	
	int ret = fork();
	
	if(ret > 0) {
		for(int i = 0; i < 9; i++) {
			sleep(1);
			std::cout << let[i] << std::endl;
		}
	std::cout << "fin du fils" << std::endl;
	waitpid(ret, NULL, 0);
	return 0;
	}
	
	if(ret == 0) {
		for(int i = 0; i < 9; i++) {
			sleep(1);
			std::cout << i+1 << std::endl;
		}
	std::cout << "fin du père" << std::endl;
	return 0;
	}
}
