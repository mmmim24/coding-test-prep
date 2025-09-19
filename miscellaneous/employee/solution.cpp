#include <bits/stdc++.h>
using namespace std;

// Interface (Pure Abstract Class)
class IPayable
{
public:
    virtual double calculatePay() const = 0;
    virtual void displayPaymentInfo() const = 0;
    virtual ~IPayable() = default;
};

// Abstract Base Class
class Person
{
protected:
    string name;
    int age;

public:
    // Constructor
    // default
    Person() = default;
    // with parameters
    Person(const string &n, int a)
    {
        name = n;
        age = a;
        // cout << "Person Constructor" << endl;
    }

    // Virtual Method
    virtual void introduce() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Pure Virtual Method (makes the class abstract)
    virtual string getRole() const = 0;

    // Destructor
    virtual ~Person()
    {
        // cout << "Person Destructor" << endl;
    }

    // Static Method
    static int compareAge(const Person &p1, const Person &p2)
    {
        return p1.age - p2.age;
    }
};

// Derived Class with Multiple Inheritance and Encapsulation
class Employee : public Person, public IPayable
{
private:
    // Private member
    double monthlySalary;
    static int totalEmployees; // Static member

protected:
    string department;

public:
    // Constructor with Initialization List
    Employee(const string &name, int age, double salary, const string &dept)
    // : Person(name, age)
    {
        this->name = name;
        this->age = age;
        monthlySalary = salary;
        department = dept;
        // cout << "Employee Constructor" << endl;
        totalEmployees++;
    }

    // Destructor
    ~Employee() override
    {
        // cout << "Employee Destructor" << endl;
        totalEmployees--;
    }

    // Polymorphic Method Overriding
    void introduce() const override
    {
        Person::introduce();
        cout << "Department: " << department << endl;
    }

    // Implementation of Interface Method
    double calculatePay() const override
    {
        return monthlySalary * 12;
    }

    // Another Interface Method Implementation
    void displayPaymentInfo() const override
    {
        cout << "Annual Salary: $" << calculatePay() << endl;
    }

    // Implementing Pure Virtual Method from Base Class
    string getRole() const override
    {
        return "Employee";
    }

    // Getter Methods (Encapsulation)
    double getSalary() const { return monthlySalary; }
    string getDepartment() const { return department; }

    // Static Method
    static int getTotalEmployees()
    {
        return totalEmployees;
    }
};

// Initialize static member
int Employee::totalEmployees = 0;

// Another Derived Class with Polymorphism
class Manager : public Employee
{
private:
    vector<Employee *> subordinates;

public:
    // Constructor Chaining
    Manager(const string &name, int age, double salary, const string &dept)
        : Employee(name, age, salary, dept)
    {
        // cout << "Manager Constructor" << endl;
    }

    // Destructor
    ~Manager() override
    {
        // cout << "Manager Destructor" << endl;
        // Clean up subordinates
        for (auto *emp : subordinates)
        {
            delete emp;
        }
    }

    // Polymorphic Method
    string getRole() const override
    {
        return "Manager";
    }

    // Method to add subordinate
    void addSubordinate(Employee *emp)
    {
        subordinates.push_back(emp);
    }

    // Method to display subordinates
    void displaySubordinates() const
    {
        cout << "Subordinates of " << name << ":" << endl;
        for (const auto *emp : subordinates)
        {
            emp->introduce();
        }
    }
};

// Demonstration of Composition
class Company
{
private:
    string companyName;
    vector<unique_ptr<Employee>> employees;

public:
    Company(const string &name) : companyName(name)
    {
        cout << "\nCompany Constructor" << endl;
    }
    ~Company()
    {
        cout << "Company Destructor" << endl;
    }
    void addEmployee(unique_ptr<Employee> emp)
    {
        employees.push_back(move(emp));
    }

    void displayAllEmployees() const
    {
        cout << "Employees of " << companyName << ":" << endl;
        for (const auto &emp : employees)
        {
            emp->introduce();
        }
    }
};

void solve()
{
    // Polymorphic object creation
    Person *emp1 = new Employee("John Doe", 30, 5000, "IT");
    Employee emp2("Alice Bob", 30, 5000, "Management");
    Person *mgr1 = new Manager("Jane Smith", 40, 8000, "Management");

    // Polymorphic method calls
    emp1->introduce();
    emp2.introduce();
    mgr1->introduce();

    // Interface method calls
    IPayable *payableEmp = dynamic_cast<IPayable *>(emp1);
    if (payableEmp)
    {
        payableEmp->displayPaymentInfo();
    }

    // Static method usage
    cout << "Total Employees: " << Employee::getTotalEmployees() << endl;
    cout << "Compare age: " << Person::compareAge(*emp1, *mgr1) << endl;

    // Composition example
    Company tech = Company("TechCorp");
    tech.addEmployee(make_unique<Employee>("Alice", 25, 4000, "HR"));
    tech.addEmployee(make_unique<Manager>("Bob", 35, 7000, "Sales"));
    tech.displayAllEmployees();

    // Clean up
    delete emp1;
    delete mgr1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    int T = 1;
    // cin>>T;
    // for(int caseno=1;caseno<=T;caseno++)
    while (T--)
    // while(!cin.eof())
    {
        // int n;
        // cin>>n;
        solve();
    }
    return 0;
}