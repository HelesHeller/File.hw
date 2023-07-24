#include <iostream>
#include <fstream>
#include <string>

class Employee {
private:
    std::string firstName;
    std::string lastName;
    std::string position;
    double salary;

public:
    Employee(const std::string& firstName, const std::string& lastName, const std::string& position, double salary)
        : firstName(firstName), lastName(lastName), position(position), salary(salary) {}

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << "Name: " << employee.firstName << " " << employee.lastName << std::endl;
        os << "Position: " << employee.position << std::endl;
        os << "Salary: " << employee.salary << std::endl;
        return os;
    }
};

class Company {
private:
    std::ofstream outputFile;

public:
    Company(const std::string& filename) {
        outputFile.open(filename);
        if (!outputFile.is_open()) {
            std::cerr << "Error: Unable to open the file." << std::endl;
            exit(1);
        }
    }

    ~Company() {
        outputFile.close();
    }

    void addEmployee(const Employee& employee) {
        outputFile << employee;
        outputFile << "--------------------------------------" << std::endl;
    }
};

int main() {
    Company company("employees.txt");

    std::string firstName, lastName, position;
    double salary;

    std::cout << "Enter employee information or enter 'exit' to finish:" << std::endl;

    while (true) {
        std::cout << "First name: ";
        std::cin >> firstName;
        if (firstName == "exit") {
            break;
        }

        std::cout << "Last name: ";
        std::cin >> lastName;

        std::cout << "Position: ";
        std::cin >> position;

        std::cout << "Salary: ";
        std::cin >> salary;
        while (salary < 0) {
            std::cout << "Invalid salary. Please enter a positive value: ";
            std::cin >> salary;
        }

        Employee employee(firstName, lastName, position, salary);
        company.addEmployee(employee);
    }

    std::cout << "Employee information has been saved to 'employees.txt'." << std::endl;

    return 0;
}
