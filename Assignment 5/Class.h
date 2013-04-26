#include<iostream>
#include<string>
using namespace std;

struct Employee{
double Salary;
string Name; 
int ID;
	};


struct Data{
double Salary;
string Name; 
int ID;
	};

template<class T>

class Heap{
public:

	Heap(int n);
	~Heap(){delete [] Element;}
	void insertEmployee(T N);
	T deleteEmployee();
	int isFull();
	int isEmpty();
	int size();
	
private:
	
	T *Element;
	int Current_Size;
	int Max_Size;
};