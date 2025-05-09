_**University Management System**_


A comprehensive University Management System implemented in C++ to demonstrate Object-Oriented Programming (OOP) principles. This project integrates key OOP concepts, including encapsulation, inheritance, polymorphism, and exception handling.

**Features
Encapsulation:**

Private attributes with public getter and setter methods.

Validation for input data to maintain system integrity.

**Inheritance:**

Hierarchical relationships between classes such as _Person_, _Student_, _Professor_, and their respective subclasses.

**Polymorphism:**

Overriding of methods like _displayDetails_ and _calculatePayment_ for dynamic behavior across different object types.

**Exception Handling:**

Custom exceptions for managing errors related to enrollment, grades, and payments.

Graceful handling of errors using _try-catch blocks_.

**System Integration:**

Relationships between _Department_, _Course_, _Professor_, and _Student_.

A menu-driven interface for demonstrating core functionalities.

**_Class Diagram_**
A brief overview of the classes and relationships:

**_Core Classes:_**

**Person**: Base class for all individuals.

**Student** (and its subclasses): UndergraduateStudent, GraduateStudent.

**Professor** (and its subclasses): AssistantProfessor, AssociateProfessor, FullProfessor.

**Other Components**:

**Course**: Represents university courses.

**Department**: Manages professors and courses.

**UniversitySystem**: The central manager integrating all components.

