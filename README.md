# 🏫 Smart School Management System

A console-based school management system developed in **C language**, designed to manage student and teacher records, subject enrollment, class grouping, grading, and performance analysis. The system features structured menus for input and output, allowing comprehensive interaction with school data in real time.

---

## 📌 Project Overview

The system is designed to:

* Record and edit student and teacher information.  
* Assign subjects and record student grades.  
* Display students by class and calculate grade averages.  
* Identify top-performing students and highest-salaried teachers.  
* Present data in a structured console interface for ease of use.

---

## 🧠 System Features

* **Student Management:** Input, update, display, and search students by ID or class  
* **Teacher Management:** Input, update, display, and search by ID  
* **Subject Enrollment:** From a list of 6 predefined subjects (Math, Science, English, Arabic, French, History)  
* **Grade Handling:** Student GPA calculation and letter grade assignment  
* **Top Performance Queries:** Best student by average and teacher with highest salary  
* **Input Validation:** Ensures 11-digit phone numbers, marks between 0–100, and correct subject selections  

---

## ⚙️ Functional Structure

| Functionality               | Description                                      |
|-----------------------------|--------------------------------------------------|
| `input_student_details()`   | Adds new students with subject & grades         |
| `input_teachers()`          | Adds new teachers and their subject/salary      |
| `edit_student(id)`          | Modifies student fields by ID                   |
| `edit_teacher(id)`          | Modifies teacher fields by ID                   |
| `print_students()`          | Displays all students and their grades          |
| `print_teachers()`          | Displays all teachers and subjects              |
| `display_class_students()`  | Lists students by class                         |
| `print_student(id)`         | Shows details and grades of a specific student  |
| `print_teacher(id)`         | Shows teacher info by ID                        |
| `find_top_salary_teacher()` | Displays the teacher with highest salary        |
| `find_top_student()`        | Displays the student with highest GPA           |

---

## 🧾 How It Works

1. **Main Menu**  
   - Choose to enter input, output, or exit.

2. **Input Menu**  
   - Add or edit student/teacher records.

3. **Output Menu**  
   - View all records, search by ID or class, and display top performers.

4. **Grades**  
   - Letter grade is auto-assigned:  
     `A ≥ 85`, `B ≥ 75`, `C ≥ 65`, `D ≥ 50`, `F < 50`.

5. **Student IDs**  
   - Automatically generated from index.

---

## 📐 Program Flow

```text
START → Main Menu
      ↳ Input Menu → [Add/Edit Students & Teachers]
      ↳ Output Menu → [View, Search, Rank]
      ↳ Exit → END
````

---

## 🧪 Testing Results

| Test Case                       | Expected Output                  | Passed |
| ------------------------------- | -------------------------------- | ------ |
| Add student with valid subjects | Stored and averaged correctly    | ✅      |
| Add teacher with valid phone    | Stored and salary displayed      | ✅      |
| Find top student                | Displays correct name and grades | ✅      |
| Find top salary teacher         | Highest paid teacher info shown  | ✅      |
| Display students in class "A1"  | Correct filtered list printed    | ✅      |
| Edit student and verify update  | Data reflects changes            | ✅      |

---

## 💾 Project Files

* `main.c` – Full source code
* `Smart School Management System.cbp` – Code::Blocks project file
* `Smart School Management System.layout` – Code::Blocks layout configuration
* `Video.mp4` – Live demonstration of system usage

---

## 📷 Screenshots 

* Input/output menus

  ![image](https://github.com/user-attachments/assets/7155d516-cc01-4582-a7ee-8e766203d04d)
  ![image](https://github.com/user-attachments/assets/b2a6ee14-007f-4712-94ba-a331d07fd6cc)
  ![image](https://github.com/user-attachments/assets/9298faff-bc16-4c06-acfa-60dd48e5edd2)
* Grade calculations

  ![image](https://github.com/user-attachments/assets/3e24042c-a72a-4ed3-b5f4-6436dbb0a482)
* Student and teacher printout

  ![image](https://github.com/user-attachments/assets/a8c87342-80e1-4a06-913e-44b656a654d9)


---

## 🛠 Tools Used

* **C Language (GCC / Code::Blocks)** – Core development
* **Console I/O** – User interaction
* **Structs and Arrays** – Data management
* **Functions & Modularity** – For clean architecture
