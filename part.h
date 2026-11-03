#ifndef PART_H
#define PART_H
#include<string>
#include<iostream>

class Part
{
	private:
		int partNumber;
		std::string material;
		std::string machineName;

	public:
		Part();
		~Part();
		void setPartNum(int);
		int getPartNum() const;
		void setMaterial(std::string);
		std::string getMaterial() const;
		void setMachine(std::string);
		std::string getMachine() const;
		bool operator!=(const Part&) const;
		Part& operator=(const Part&);
		friend std::ostream& operator<<(std::ostream&, const Part&);
};

Part::Part()
{
	this->partNumber = 0;
	this->material = "";
	this->machineName = "";
}

Part::~Part()
{
}

void Part::setPartNum(int num)
{
	this->partNumber = num;
}

int Part::getPartNum() const
{
	return partNumber;
}

void Part::setMaterial(std::string metal)
{
	this->material = metal;
}

std::string Part::getMaterial() const
{
	return material;
}

void Part::setMachine(std::string machName)
{
	this->machineName = machName;
}

std::string Part::getMachine() const
{
	return machineName;
}

bool Part::operator!=(const Part& rhs) const
{
	bool status = false;

	if (this->partNumber != rhs.partNumber)
	{
		status = true;
	}

	return status;
}

Part& Part::operator=(const Part& rhs)
{
	if (this != &rhs)
	{
		this->partNumber = rhs.partNumber;
		this->material = rhs.material;
		this->machineName = rhs.machineName;
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Part& rhs)
{
	os << rhs.partNumber << " " << rhs.material << " " << rhs.machineName;

	return os;
}
#endif
