/*
 * testHash.cpp
 *
 *  Created on: 18 Mar 2016
 *      Author: Michael
 */

#include <iostream>
#include <functional>

int main() {
	std::string str = "HelloWasdasdasdasdasdasdasdasfsdghaksjfhksjdhgkjahsdkjhdfkgjhskdjghksjdghkjshdgkj";
	std::size_t str_hash = std::hash<std::string>{}(str);
	printf("%x\n", str_hash);
	std::cout << str_hash << std::endl;

	std::cout << sizeof(std::size_t) << std::endl;

	return 0;
}

