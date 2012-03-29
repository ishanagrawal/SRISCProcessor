#include "Types.h"

class Processor
{
private:
	Register reg[32];
	Relation rel[32];
	
	Instruction IR;
    int PC;
        
	// Processor configuration
	int memBanks;
        
	// memory
	map<int, int> mem;
	map<int,int>::iterator memIter;
	StageBuffer prevMem;
	StageBuffer currentMem;
	ofstream fout;

	// Instruction memory
	vector<string> instructions;
	
	Retriever *retriever;
	Type getEnumFromString(string instr);
	string getStringFromEnum(Type type);
        
	Result applyAllRules(StageBuffer&, StageBuffer&);
	Result checkMemBanks(StageBuffer&, StageBuffer&);
	Result sameMemAddrReg(StageBuffer&, StageBuffer&);
	Result directAddrRegDependency(StageBuffer&, StageBuffer&);
	Result multiLevelIndirection(StageBuffer &currentMem, StageBuffer &prevMem);	

	Relation getAbsSrc(int reg_index, StageBuffer &buf);		

	void setDataForRule3(StageBuffer& buf, Type op);
	
	string getStringFromResult(Result);
	
protected:
	void ID(StageBuffer &buf);
	void ALU(StageBuffer &buf);

public:
	Processor(Retriever *r);
	void execute();
};
