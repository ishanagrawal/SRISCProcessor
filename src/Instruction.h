#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

enum Type {
		LW,SW,LWI,IADD,ISUB,IMUL,IDIV,IMOD,ICMP,BNEQ,BEQ,BLT,BGT,JUMP,HALT,NOP
};

struct Instruction
{	
	Type type;
	short destReg, sReg1, sReg2;
	int offset;
        int value;

	Instruction();
	void init();
        bool isMemInstruction();
};
