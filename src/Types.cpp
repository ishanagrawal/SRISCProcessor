#include "Types.h"

StageBuffer::StageBuffer() : dirtyNo_sReg1(0), amIdirty(0)
{
	str = "";
	operand1 = 0;
	operand2 = 0;
	address = -1;
}

Register::Register() : regVal(0), dirtyNo(0), alive(false)
{
}

Relation::Relation() : src(-1), value(0), dirtyNo(0), order(SrcOpValue), op(IADD)
{
}

void Relation::reset()
{
	this->src = -1;
	this->value = 0;
	this->order = SrcOpValue;
	this->op = IADD;
	this->dirtyNo = 0;
}

void Relation::set(int s, int val, Order ord, Type oper, int dNo)
{
	this->src = s;
	this->value = val;
	this->order = ord;
	this->op = oper;
	this->dirtyNo = dNo;
}