#include <iostream>
using namespace std;

class employee {
  private:
    // Private attribute
    int salary;

  public:
    // Set function/ assignment function
    void set_salary(int s) {
      salary = s;
    }
    // Get function/ access function
    int get_salary() {
      return salary;
    }
};

int main() {
  employee naveen;
  naveen.set_salary(5000);
  cout << "Employee's Salary:"<<naveen.get_salary();
  return 0;
} 