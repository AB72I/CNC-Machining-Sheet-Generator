#ifndef SETUPSHEET_H
#define SETUPSHEET_H

#include "part.h"
#include "Operation.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


class SetupSheet
{
	private:
		Part partInfo;
		std::vector<Operation> operations;


	public:
		SetupSheet();
		~SetupSheet();
		void setPartInfo(const Part&);
		Part getPartInfo() const;
		void addOp(Operation&);
		void printOp() const;
		void display();
		void ExporttoFile(std::ofstream&);

};

SetupSheet::SetupSheet()
{
	this->partInfo = Part();
}

SetupSheet::~SetupSheet()
{
}

void SetupSheet::setPartInfo(const Part& p)
{
	partInfo = p;
}

Part SetupSheet::getPartInfo() const
{
	return partInfo;
}

void SetupSheet::addOp(Operation& o)
{
	operations.push_back(o);
}

void SetupSheet::printOp() const
{
	for (const Operation& op : operations)
	{
		std::cout << op.getOpNum() << ". "
			<< op.getDescription()
			<< " | Tool: " << op.getToolID()
			<< '\n';
	}
}

void SetupSheet::display()
{
	std::cout << "\n=== MACHINING SETUP SHEET ===\n";
	std::cout << "Part Number: " << partInfo.getPartNum() << std::endl;
	std::cout << "Material:    " << partInfo.getMaterial() << std::endl;
	std::cout << "Machine:     " << partInfo.getMachine() << std::endl;
	std::cout << "\nMachining operations:" << std::endl;

	printOp();
}

void SetupSheet::ExporttoFile(std::ofstream& outPut)
{
	outPut << "==================================\n" << "       MACHINING SETUP SHEET\n";
	outPut << "==================================\n";
	outPut << "Part Number: " << partInfo.getPartNum() << "\n";
	outPut << "Material:    " << partInfo.getMaterial() << "\n";
	outPut << "Machine:     " << partInfo.getMachine() << "\n";
	outPut << "\nMachining operations:\n";

	for (const Operation& op: operations)
	{
		outPut << op.getOpNum() << ". "
			<< op.getDescription()
			<< " | Tool: " << op.getToolID()
			<< '\n';
	}
}
#endif
