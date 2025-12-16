#include <iostream>
#include <string>
using namespace std;


class employee {

    private:
    int salary;

    public: 
    string name;
    int id;

    // Set and get salary
    void setSalary(int s) {salary = s; }
    int getSalary() const {return salary;}
    
};
// Derived employee class with the employee function
class employee_task: private employee {
    // private department and manager status
    private:
    bool manager;
    public:
    string department;
    void setsalaryinside(int s) {
     setSalary(s);
    }
    int getsalaryinside() const {
        return getSalary();
    }
    void setName(string n) {name = n; }
    string getName() const {return name;}
    void setID(int i) {id = i;}
    int getID() const {return id;}
    void setDep(string d) {department = d;} 
    void setmanstatus(bool m) {manager = m;}
    string getDep() const {return department;}
    bool isman() const {return manager;}

};
//display function
int main()
{
    employee_task emp1;
    emp1.setName("John");
    emp1.setID(231);
    emp1.setsalaryinside(2000);
 
    emp1.department = "Rookie";
    emp1.setmanstatus(true);

    cout << emp1.getID() << " \n";
    cout << emp1.getsalaryinside() << " \n";
    cout << emp1.getDep() << " \n";
    cout << emp1.isman() << "\n";
    return 0;
}
//WHY WORK? BECAUSE THE PRIVATE CHANGE IN THE FUNCTION BECOMES UNUSABLE FOR MORE DERIVED CLASSES
// IF I WERE TO CREATE ANOTHER CLASS THATS DERIVED FROM employee TASK, ALL THE VARIABLES IN BASE CLASS WOULD BE PRIVATE IN THE NEW DOUBLE DERIVED CLASS 