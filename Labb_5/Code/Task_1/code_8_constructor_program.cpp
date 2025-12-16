#include <iostream>
using namespace std;


class employee {
    public:
    string name;
    int employee_id;
    int salary;
    employee(string n, int id, int s)
    {
        name=n;
        employee_id=id;
        salary=s;
    }
};




int main (){
 // Create Car objects and call the constructor with different values
employee emp_1("Joe", 1001, 5000);

  // Print values
cout<< "Name: "<<emp_1.name <<"\n";
cout<< "ID: "<<emp_1.employee_id <<"\n";
cout<< "Salary: "<<emp_1.salary <<"\n";

}
