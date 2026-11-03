#ifndef OPERATION_H
#define OPERATION_H
#include <string>

class Operation
{
	private:
		int operationNumber;
		std::string description;
		std::string toolID;

	public:
		Operation();
		~Operation();
		void setOpNum(int);
		int getOpNum() const;
		void setDescription(std::string);
		std::string getDescription() const;
		void setToolID(std::string);
		std::string getToolID() const;
		

};

Operation::Operation()
{
	this->operationNumber = 0;
	this->description = "";
	this->toolID = "";
}

Operation::~Operation()
{
}

void Operation::setOpNum(int opNum)
{
	this->operationNumber = opNum;
}

int Operation::getOpNum() const
{
	return operationNumber;
}

void Operation::setDescription(std::string des)
{
	this->description = des;
}

std::string Operation::getDescription() const
{
	return description;
}

void Operation::setToolID(std::string id)
{
	this->toolID = id;
}

std::string Operation::getToolID() const
{
	return toolID;
}
#endif 