#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <string>
//class Employee definition
class Employee
{

private:std::string employeeName;
		int employeeNumber;
		std::string hiringDate;

//default constructor
public:  Employee()
{
	employeeName = " ";
	employeeNumber = 0;
	hiringDate = " ";
}
		  //Parameterized constructor
		  Employee(std::string name, int id, std::string date)
		  {
			  employeeName = name;
			  employeeNumber = id;
			  hiringDate = date;
		  }
		  //exception for invalid ID number
		  class InvalidEmployeeNumber {};
		  //Member functions
		  void setEmployeeName(std::string);
		  void setEmployeeNumber(int);
		  void setHiringDate(std::string);
		  std::string getEmployeeName();
		  int getEmployeeNumber();
		  std::string getHiringDate();
};
//setters
void Employee::setEmployeeName(std::string name)
{
	employeeName = name;
}

void Employee::setEmployeeNumber(int id)
{
	if (id < 0 || id >9999)
		throw InvalidEmployeeNumber();
	else
		employeeNumber = id;
}
void Employee::setHiringDate(std::string date)
{
	hiringDate = date;
}
//Getters 
std::string Employee::getEmployeeName()
{
	return employeeName;
}

int Employee::getEmployeeNumber()
{
	return employeeNumber;
}

std::string Employee::getHiringDate()
{
	return hiringDate;
}

//defining derived class ProductionWorker
class ProductionWorker:public Employee
{

private:
	int shift;	
	double hourlyPay;
		
//Default constructor
public: ProductionWorker()
{
	shift = 0;
	hourlyPay = 0;
}
		//Parameterized constructor
		ProductionWorker(int timeShift, double wage)
		{
			shift = timeShift;
			hourlyPay = wage;
		}
		//Exception class for Invalid shift
		class invalidShift {};
		//Exception class for Invalid Pay rate
		class invalidPayRate {};
		void setShift(int);
		void setHourlyPay(double);
		int getShift();
		double getHourlyPay();
};

//Defining member functions
void ProductionWorker::setShift(int timeShift)
{
	if (timeShift <= 0 || timeShift>2)
		throw invalidShift();
	else
		shift = timeShift;
}//end setShift
void ProductionWorker::setHourlyPay(double pay)
{
	if (pay < 1)
		throw invalidPayRate();
	else
		hourlyPay = pay;
}//end setHourlyPay
int ProductionWorker::getShift()
{
	return shift;
}//end getShift
double ProductionWorker::getHourlyPay()
{
	return hourlyPay;
}//end getHourlyPay


//Main function
int main()
{ 
	//Start main
	int shift;
	double pay;
	//Inputting data
	std::cout << " 1-Day Shift \n 2-Night Shift" << std::endl;
	std::cout << "Enter shift:";
	std::cin >> shift;
	std::cout << "Enter hourly pay:";
	std::cin >> pay;
	//creating ProductionWorker object
	ProductionWorker emp1(0, 0);
	//setting the values to employee class using
	//emp1 object
	emp1.setEmployeeName("Winston");
	emp1.setHiringDate(" June:11");
	try
	{
		emp1.setEmployeeNumber(1000);
		emp1.setShift(shift);
		emp1.setHourlyPay(pay);

	}
	catch (Employee::InvalidEmployeeNumber)
	{
		std::cout << "Error invalid Employee number" << std::endl;
	}
	catch (ProductionWorker::invalidShift)
	{
		std::cout << "Error Invalid Shift" << std::endl;
	}
	catch (ProductionWorker::invalidPayRate)
	{
		std::cout << "Error Invalid PayRate" << std::endl;
	}

	std::cout << "Employee Details:" << std::endl << std::endl;
	std::cout << "Employee Name:" << emp1.getEmployeeName();
	std::cout << std::endl;
	std::cout << "Employee Number:" << emp1.getEmployeeNumber() << std::endl;
	std::cout << "Employee Hire Date: " << emp1.getHiringDate();
	std::cout << std::endl;
	std::cout << "Employee Shift:" << emp1.getShift() << std::endl;
	std::cout << "Employee HourlyPay:"<< emp1.getHourlyPay() << std::endl;
	
	return 0;
}