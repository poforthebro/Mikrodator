#include <iostream>
#include <string>
using namespace std;


class employee {
    //Private with counter, id , name and id.
    private:
    string name;
    int id;
    int salary;
    static int counter;

    public: 
    //Takes in string and s and makes them the name or salary and generates an id.
    employee(string n = "", int s = 0) : name(n),salary(s) {

        id = counter;
        counter++;
    }

    // Set name and salary
    void setName(string n) {name = n;}
    void setSalary(int s) {salary = s;}


    // Get name, ID and salary
    string getName() const {return name;}
    int getId() const {return id;}
    int getSalary() const {return salary;}
    
};
// Derived employee class with the employee function
class employee_function: public employee {
    // private department and manager status
    private:
    string department;
    bool manager;
// if empty or not given, all other things get defaulted to rookie, 0 salary and empty name
// debuggining with maybe erroring if no name is given
    public:
    employee_function(
        string n = "", 
        int s = 0, 
        string d = "Rookie", 
        bool m = false
    ) 
    : 
    // uses the employee normal and department and manager extras.
    employee(n, s),
    department(d), 
    manager(m) 
    {}
    void setDep(string d) {department = d;}
    void setmanstatus(bool m) {manager = m;}
    string getDep() const {return department;}
    bool isman() const {return manager;}

};
//display function
void GETINFO(employee_function emp) {
    cout << "--- Employee Details ---" << "\n";
    cout << "Name: " << emp.getName() << "\n";
    cout << "ID: " << emp.getId() << "\n";
    cout << "Salary: " << emp.getSalary() << "\n";
    cout << "Department: " << emp.getDep() << "\n";
    cout << "Is a manager: " << emp.isman() << "\n";
}
//static counter from where to begin
    int employee::counter = 1;

int main()
{
    employee_function emp1("John Blackthorne",2000);
    employee_function emp2("Joh2",20020);
    employee_function emp3("John Bl41241ackthorne",205150,"CEO",true);
    employee_function emp4("John Blac12414kthorne",2000);
    GETINFO(emp1);
    GETINFO(emp2);
    GETINFO(emp3);
    emp4.setSalary(808080);
    GETINFO(emp4);
    return 0;
}