#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class UniversitySystemException : public exception {
public:
    virtual const char* what() const throw() {
        return "University System Exception";
    }
};

class EnrollmentException : public UniversitySystemException {
public:
    const char* what() const throw() {
        return "Enrollment Exception";
    }
};

class GradeException : public UniversitySystemException {
public:
    const char* what() const throw() {
        return "Grade Exception";
    }
};

class PaymentException : public UniversitySystemException {
public:
    const char* what() const throw() {
        return "Payment Exception";
    }
};

class Person {
protected:
    string name;
    int age;
    string personID;
    string contactInfo;

public:
    Person(string n, int a, string id, string contact) : name(n), age(a), personID(id), contactInfo(contact) {}

    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << personID << ", Contact: " << contactInfo << endl;
    }

    virtual double calculatePayment() const = 0;
};

class Student : public Person {
protected:
    string enrollmentDate;
    string program;
    double gpa;

public:
    Student(string n, int a, string id, string contact, string enrollDate, string prog, double g)
        : Person(n, a, id, contact), enrollmentDate(enrollDate), program(prog), gpa(g) {}

    void setGPA(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        } else {
            throw GradeException();
        }
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollmentDate << ", Program: " << program << ", GPA: " << gpa << endl;
    }

    double calculatePayment() const override {
        return 10000.0;
    }
};

class UndergraduateStudent : public Student {
    string major;
    string minor;
    string graduationDate;

public:
    UndergraduateStudent(string n, int a, string id, string contact, string enrollDate, string prog, double g,
                         string maj, string min, string gradDate)
        : Student(n, a, id, contact, enrollDate, prog, g), major(maj), minor(min), graduationDate(gradDate) {}

    void displayDetails() const override {
        Student::displayDetails();
        cout << "Major: " << major << ", Minor: " << minor << ", Graduation Date: " << graduationDate << endl;
    }
};

class GraduateStudent : public Student {
    string researchTopic;
    string advisor;
    string thesis;

public:
    GraduateStudent(string n, int a, string id, string contact, string enrollDate, string prog, double g,
                    string topic, string adv, string thes)
        : Student(n, a, id, contact, enrollDate, prog, g), researchTopic(topic), advisor(adv), thesis(thes) {}

    void displayDetails() const override {
        Student::displayDetails();
        cout << "Research Topic: " << researchTopic << ", Advisor: " << advisor << ", Thesis: " << thesis << endl;
    }
};

class Professor : public Person {
protected:
    string department;
    string specialization;
    string hireDate;

public:
    Professor(string n, int a, string id, string contact, string dept, string spec, string hire)
        : Person(n, a, id, contact), department(dept), specialization(spec), hireDate(hire) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department << ", Specialization: " << specialization << ", Hire Date: " << hireDate << endl;
    }

    double calculatePayment() const override {
        return 70000.0;
    }
};

class AssistantProfessor : public Professor {
public:
    AssistantProfessor(string n, int a, string id, string contact, string dept, string spec, string hire)
        : Professor(n, a, id, contact, dept, spec, hire) {}

    double calculatePayment() const override {
        return 50000.0;
    }
};

class AssociateProfessor : public Professor {
public:
    AssociateProfessor(string n, int a, string id, string contact, string dept, string spec, string hire)
        : Professor(n, a, id, contact, dept, spec, hire) {}

    double calculatePayment() const override {
        return 75000.0;
    }
};

class FullProfessor : public Professor {
public:
    FullProfessor(string n, int a, string id, string contact, string dept, string spec, string hire)
        : Professor(n, a, id, contact, dept, spec, hire) {}

    double calculatePayment() const override {
        return 100000.0;
    }
};

class Course {
    string code;
    string title;
    int credits;
    string description;
    Professor* professor;

public:
    Course(string c, string t, int cr, string desc, Professor* prof = nullptr)
        : code(c), title(t), credits(cr), description(desc), professor(prof) {}

    void assignProfessor(Professor* prof) {
        professor = prof;
    }

    void displayDetails() const {
        cout << "Course Code: " << code << ", Title: " << title << ", Credits: " << credits
             << ", Description: " << description;
        if (professor) {
            cout << ", Professor: ";
            professor->displayDetails();
        } else {
            cout << ", Professor: None" << endl;
        }
    }
};

class Department {
    string name;
    string location;
    double budget;
    vector<Professor*> professors;
    vector<Course*> courses;

public:
    Department(string n, string loc, double bud) : name(n), location(loc), budget(bud) {}

    void addProfessor(Professor* prof) {
        professors.push_back(prof);
    }

    void addCourse(Course* course) {
        courses.push_back(course);
    }

    void displayDetails() const {
        cout << "Department Name: " << name << ", Location: " << location << ", Budget: " << budget
             << ", Professors: " << professors.size() << ", Courses: " << courses.size() << endl;
    }
};

class UniversitySystem {
    vector<Department*> departments;

public:
    void addDepartment(Department* dept) {
        departments.push_back(dept);
    }

    void displaySystemDetails() const {
        for (const auto& dept : departments) {
            dept->displayDetails();
        }
    }
};

int main() {
    try {
        UniversitySystem system;

        Department* csDept = new Department("Computer Science", "Building A", 500000);
        Department* mathDept = new Department("Mathematics", "Building B", 300000);

        Professor* prof1 = new FullProfessor("Prof.Rahul", 45, "P1001", "Rahul@example.com", "CS", "AI", "2005-08-15");
        Professor* prof2 = new AssociateProfessor("Prof.Maya", 50, "P1002", "Maya@example.com", "Math", "Topology", "2000-06-10");

        csDept->addProfessor(prof1);
        mathDept->addProfessor(prof2);

        Course* course1 = new Course("CS101", "Intro to Programming", 3, "Learn programming basics", prof1);
        Course* course2 = new Course("MATH201", "Linear Algebra", 4, "Advanced mathematics concepts", prof2);

        csDept->addCourse(course1);
        mathDept->addCourse(course2);

        system.addDepartment(csDept);
        system.addDepartment(mathDept);

        system.displaySystemDetails();
    } catch (const UniversitySystemException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
