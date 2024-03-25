#include <iostream>
#include <string>
#include <cstring>

int main() {
	char tab[11] = "abcdefghij";
	std::string str = "abcdefghij";
	for(unsigned int i = 0; i < 11; ++i) {
		std::cout << tab[i];
	}
	std::cout << " " << std::endl;
	std::cout << str << std::endl;
	std::cout << tab[2] << std::endl;
	std::cout << str[2] << std::endl;
	char big_tab[21];
	for(unsigned int i = 0; i < 20; ++i) {
		big_tab[i] = '-';
	}
	big_tab[21] = '\0';
	memcpy(big_tab + 15, tab + 5, sizeof(char) * 5);
	std::cout << big_tab << std::endl;
	memcpy(big_tab + 3, str.c_str() + 3, sizeof(char) * 5);
	std::cout << big_tab << std::endl;
	std::cout << "hello" << std::endl;
	return 0;
}
