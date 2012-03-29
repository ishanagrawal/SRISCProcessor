#include "Retriever.h"
#include <map>

enum Result {
    ignored, YES, NO, MAYBE
};

enum Order {
	ValueOpSrc, SrcOpValue
};

struct Relation
{
	int src, value, dirtyNo;
	Order order;
	Type op;

	Relation();
	void set(int s, int val, Order ord, Type oper, int dNo);
	void reset();
};

struct StageBuffer {
	string str;
	Instruction IR;
	int operand1, operand2, result;
	int address;
	int dirtyNo_sReg1, amIdirty;
	int PC;
	Relation rel;

	//bool CF_LT, CF_GT, CF_EQ, branch_taken;

	StageBuffer();
};

struct Register {
    
    int regVal;    //register value
	int dirtyNo;	
    bool alive;

    //if the value is -1 it means it has not been filled yet
    //if the value is -2 it means it has been filled with unknown values
    
	Register();
};

