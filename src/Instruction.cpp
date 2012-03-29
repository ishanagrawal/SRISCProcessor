#include "Instruction.h"

Instruction::Instruction()
{
	init();
}

void Instruction::init()
{
	destReg = -1;
	sReg1 = -1;
	sReg2 = -1;
	type = NOP;
	offset = 0;
}

bool Instruction::isMemInstruction()
{
    if(type == SW || type == LW)
        return true;
    return false;
}
