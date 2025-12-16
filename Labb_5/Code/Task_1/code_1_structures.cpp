#include <iostream>
using namespace std;

struct employee {
string name;
int employee_id;
int salary;
};

int main (){
// variable declaration and initialization
employee emp_1 ={"Joe", 1001, 5000};

// Input struct datatype
cin >> emp_1.name >> emp_1. employee_id >> emp_1.salary;

// Modify struct datatype
emp_1.employee_id = 0001;
cout<< "Name: "<<emp_1.name <<"\n";
cout<< "ID: "<<emp_1.employee_id <<"\n";
cout<< "Salary: "<<emp_1.salary <<"\n";
}
