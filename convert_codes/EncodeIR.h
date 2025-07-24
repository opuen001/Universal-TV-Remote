#ifndef ENCODE_IR_H
#define ENCODE_IR_H

struct protdef {
	const char *prot;
	const char *def;
};

extern struct protdef protdefs[];

void EncodeIR(char* buffer, int a, int b, int c);

#endif
