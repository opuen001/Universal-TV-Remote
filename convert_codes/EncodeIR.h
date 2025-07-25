#ifndef ENCODE_IR_H
#define ENCODE_IR_H
#include <string>
#include <sstream>
#include <iostream>

struct protdef {
	const char *prot;
	const char *def;
};

extern struct protdef protdefs[];

std::string EncodeIR(char* buffer, int D, int S, int F);

#endif
