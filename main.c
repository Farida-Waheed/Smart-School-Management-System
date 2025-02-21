#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_TEACHERS 50
#define MAX_SUBJECTS 6
#define MAX_CLASSES 10
#define PREDEFINED_SUBJECTS 6

// Predefined list of subjects
const char* predefined_subjects[PREDEFINED_SUBJECTS] = {
    "Math",
    "Science",
    "English",
    "Arabic",
    "French",
    "History"
};

// Structure to store student information
struct student {
    char name[50];
    int id;
    char phone_number[12];
    int age;
    float total_grade;
    float subject_grades[MAX_SUBJECTS];
    char subjects[MAX_SUBJECTS][50];
    int no_of_subjects;
    char s_class[50];
};

// Structure to store teacher information
struct teacher {
    char name[50];
    int id;
    char subject[50];
    float salary;
    char phone_number[12];
};

// Global arrays and counters
struct student students[MAX_STUDENTS];
struct teacher teachers[MAX_TEACHERS];
char classes[MAX_CLASSES][50];
int num_students = 0;
int num_teachers = 0;
int num_classes = 0;

// Function prototypes
void input_menu();
void output_menu();

void input_student_details();
void input_teachers();

void display_class_students(char *class_name);
void print_students();
void print_teachers();
void print_student(int id);
void print_teacher(int id);
void edit_student(int id);
void edit_teacher(int id);
void find_top_salary_teacher();
void find_top_student();
int is_subject_duplicate(char subjects[][50], int count, const char *new_subject);

int main() {
    int main_choice = 0; // Variable to store the user's menu choice

    while (1) { // Infinite loop to keep the menu active until the user chooses to exit
        printf("\nMain Menu:\n");
        printf("1. Input Menu\n");
        printf("2. Output Menu\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &main_choice); // Read user input

        switch (main_choice) {
            case 1:
                input_menu(); // Call the input menu function
                break;
            case 2:
                output_menu(); // Call the output menu function
                break;
            case 3:
                return 0; // Exit the program
            default:
                printf("Invalid choice, please try again.\n"); // Handle invalid input
                break;
        }
    }
}

void input_menu() {
    int choice = 0; // Variable to store the user's menu choice

    while (1) { // Infinite loop to keep the input menu active until the user chooses to return to the main menu
        printf("\nInput Menu:\n");
        printf("1. Input Student Details\n");
        printf("2. Input Teacher Details\n");
        printf("3. Edit Student Details\n");
        printf("4. Edit Teacher Details\n");
        printf("5. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user input

        switch (choice) {
            case 1:
                input_student_details(); // Call function to input student details
                break;
            case 2:
                input_teachers(); // Call function to input teacher details
                break;
            case 3: {
                int id;
                printf("Enter student ID to edit: ");
                scanf("%d", &id);
                edit_student(id); // Edit details of a specific student
                break;
            }
            case 4: {
                int id;
                printf("Enter teacher ID to edit: ");
                scanf("%d", &id);
                edit_teacher(id); // Edit details of a specific teacher
                break;
            }
            case 5:
                return; // Return to the main menu
            default:
                printf("Invalid choice, please try again.\n"); // Handle invalid input
                break;
        }
    }
}

void output_menu() {
    int choice = 0;
    while (1) {
        printf("\nOutput Menu:\n");
        printf("1. Display Students in a Class\n");
        printf("2. Print All Students\n");
        printf("3. Print All Teachers\n");
        printf("4. Print Student Details\n");
        printf("5. Print Teacher Details\n");
        printf("6. Top Salary\n");
        printf("7. Top Student\n");
        printf("8. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char class_name[50];
                printf("Enter class name: ");
                scanf("%s", class_name);  // Consider using fgets to handle spaces
                display_class_students(class_name); // Function to display students in a specific class
                break;
            }
            case 2:
                print_students(); // Print all students
                break;
            case 3:
                print_teachers(); // Print all teachers
                break;
            case 4: {
                int id;
                printf("Enter student ID: ");
                scanf("%d", &id);
                print_student(id); // Print details of a specific student
                break;
            }
            case 5: {
                int id;
                printf("Enter teacher ID: ");
                scanf("%d", &id);
                print_teacher(id); // Print details of a specific teacher
                break;
            }
            case 6:
                find_top_salary_teacher(); // Print top salary of teacher
                break;
            case 7:
                find_top_student(); // Print top student
                break;
            case 8:
                return; // Return to the main menu
            default:
                printf("Invalid choice, please try again.\n"); // Handle invalid input
        }
    }
}

int is_subject_duplicate(char subjects[][50], int count, const char *new_subject) {
    for (int i = 0; i < count; i++) {
        if (strcmp(subjects[i], new_subject) == 0) {
            return 1; // Subject is a duplicate
        }
    }
    return 0; // Subject is not a duplicate
}

void input_student_details() {
    // Prompt for the number of students and read the input
    printf("Enter the number of students:\n");
    scanf("%d", &num_students);

    // Loop to input details for each student
    for (int i = 0; i < num_students; i++) {
        printf("Enter details for student %d:\n", i + 1);

        // Input student details
        printf("Name: ");
        scanf("%s", students[i].name);
        // Ensure phone number is exactly 11 digits
        do {
            printf("Phone Number (11 digits): ");
            scanf("%s", students[i].phone_number);

            if (strlen(students[i].phone_number) != 11) {
                printf("Phone number must be exactly 11 digits. Please try again.\n");
            } else {
                break; // Valid phone number entered
            }
        } while (1);
        printf("Age: ");
        scanf("%d", &students[i].age);

        int no_of_subjects = 0; // Initialize number of subjects to zero
        float total_mark = 0; // Initialize total mark to zero

        // Ensure the number of subjects is within the acceptable range (4 to 6)
        do {
            printf("Please enter the number of subjects you are taking (4 to 6):\n");
            scanf("%d", &no_of_subjects);

            if (no_of_subjects < 4 || no_of_subjects > 6) {
                printf("The number of subjects is not within the range. Please try again.\n");
            }
        } while (no_of_subjects < 4 || no_of_subjects > 6);

        students[i].no_of_subjects = no_of_subjects;

        // Display predefined subjects
        printf("Available subjects:\n");
        for (int j = 0; j < PREDEFINED_SUBJECTS; j++) {
            printf("%d. %s\n", j + 1, predefined_subjects[j]);
        }

        // Loop to input subjects and corresponding grades
        for (int j = 0; j < no_of_subjects; j++) {
            int subject_choice;
            int is_duplicate;
            char subject[50];

            do {
                printf("Select subject %d by entering the corresponding number:\n", j + 1);
                scanf("%d", &subject_choice);

                // Validate subject choice
                if (subject_choice < 1 || subject_choice > PREDEFINED_SUBJECTS) {
                    printf("Invalid choice. Please try again.\n");
                    is_duplicate = 1;
                    continue;
                } else {
                    // Assign chosen subject
                    strcpy(subject, predefined_subjects[subject_choice - 1]);
                }
                // Assign chosen subject
                strcpy(subject, predefined_subjects[subject_choice - 1]);

                // Check for duplicate subject
                is_duplicate = is_subject_duplicate(students[i].subjects, j, subject);
                if (is_duplicate) {
                    printf("This subject has already been entered. Please choose a different subject.\n");
                }
            } while (is_duplicate);

            strcpy(students[i].subjects[j], subject);

            printf("Enter the mark for %s:\n", students[i].subjects[j]);
            float mark = 0; // Initialize mark to zero
            scanf("%f", &mark);

            // Validate mark input
            if (mark >= 0 && mark <= 100) {
                students[i].subject_grades[j] = mark;
                total_mark += mark;
            } else {
                printf("Invalid mark, it should be between 0 and 100. Please try again.\n");
                j--; // Repeat the input for this subject
            }
        }

        students[i].total_grade = total_mark / no_of_subjects;

        // Input student class
        printf("Enter class: ");
        scanf("%s", students[i].s_class);
        students[i].id = (num_students * 10 )+ i;
        printf("ID: %d\n",students[i].id);
    }
}

void input_teachers() {
    printf("Enter the number of teachers:\n");
    scanf("%d", &num_teachers);

    for (int i = 0; i < num_teachers; i++) {
        printf("Enter details for teacher %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", teachers[i].name);
        // Display available subjects
        printf("Available subjects:\n");
        for (int j = 0; j < PREDEFINED_SUBJECTS; j++) {
            printf("%d. %s\n", j + 1, predefined_subjects[j]);
        }

        int subject_choice = 0;
        printf("Select a subject (1-%d): ", PREDEFINED_SUBJECTS);
        scanf("%d", &subject_choice);

        // Validate subject choice
        if (subject_choice < 1 || subject_choice > PREDEFINED_SUBJECTS) {
            printf("Invalid choice. Defaulting to Math.\n");
            subject_choice = 1;
            continue;
        }

        strcpy(teachers[i].subject, predefined_subjects[subject_choice - 1]);
        printf("Salary: ");
        scanf("%f", &teachers[i].salary);
        // Ensure phone number is exactly 11 digits
        do {
            printf("Phone Number (11 digits): ");
            scanf("%s", teachers[i].phone_number);

            if (strlen(teachers[i].phone_number) != 11) {
                printf("Phone number must be exactly 11 digits. Please try again.\n");
            } else {
                break; // Valid phone number entered
            }
        } while (1);

        teachers[i].id = (num_teachers * 10 )+ i ; // Unique ID for each teacher
        printf("ID: %d\n", teachers[i].id);

    }
}

void display_class_students(char *class_name) {
    // Print the header for the list of students in the specified class
    printf("Students in class %s:\n", class_name);

    // Loop through all students to find those in the specified class
    for (int i = 0; i < num_students; i++) {
        // Compare the current student's class with the input class name
        if (strcmp(students[i].s_class, class_name) == 0) {
            // Print the name of each student in the specified class
            printf("%s\n", students[i].name);
        }
    }
}

void print_students() {
    // Print the header for the student data
    printf("The students' data:\n");

    // Loop through all students to print their details
    for (int i = 0; i < num_students; i++) {
        // Print details of each student: index, name, ID, phone number, age, and class
        printf("%d. Name: %s, ID: %d, Phone Number: %s, Age: %d, Class: %s,Grade: %f\n",
               i + 1,                             // Index of the student in the list (1-based)
               students[i].name,                  // Student's name
               students[i].id,                    // Student's ID
               students[i].phone_number,          // Student's phone number
               students[i].age,                   // Student's age
               students[i].s_class,                // Student's class
               students[i].total_grade);           // Student's total grade
    }
}

void print_teachers() {
    // Print the header for the teacher data
    printf("The teachers' data:\n");

    // Loop through all teachers to print their details
    for (int i = 0; i < num_teachers; i++) {
        // Print details of each teacher: index, name, ID, subject, salary, and phone number
        printf("%d. Name: %s, ID: %d, Subject: %s, Salary: %.2f, Phone Number: %s\n",
               i + 1,                             // Index of the teacher in the list (1-based)
               teachers[i].name,                  // Teacher's name
               teachers[i].id,                    // Teacher's ID
               teachers[i].subject,               // Subject taught by the teacher
               teachers[i].salary,                // Teacher's salary (formatted to 2 decimal places)
               teachers[i].phone_number);         // Teacher's phone number
    }
}

void print_student(int id) {
    // Loop through all students to find the one with the specified ID
    for (int i = 0; i < num_students; i++) {
        // Check if the current student's ID matches the input ID
        if (students[i].id == id) {
            // Print the header for the student's details
            printf("Student Details:\n");
            // Print individual details of the student
            printf("Name: %s\n", students[i].name);
            printf("ID: %d\n", students[i].id);
            printf("Phone Number: %s\n", students[i].phone_number);
            printf("Age: %d\n", students[i].age);
            printf("Class: %s\n", students[i].s_class);
            printf("Total Grade: %f\n", students[i].total_grade);
            printf("Subjects and Grades:\n");

            // Loop through the student's subjects to print each subject and grade
            for (int j = 0; j < students[i].no_of_subjects; j++) {
                printf("Subject: %s, ", students[i].subjects[j]);
                if (students[i].subject_grades[j] >= 85) {
                    printf("Grade: A,", students[i].subjects[j]);
                } else if (students[i].subject_grades[j] >= 75) {
                    printf("Grade: B,", students[i].subjects[j]);
                } else if (students[i].subject_grades[j] >= 65) {
                    printf("Grade: C,", students[i].subjects[j]);
                } else if (students[i].subject_grades[j] >= 50) {
                    printf("Grade: D,", students[i].subjects[j]);
                } else {
                    printf("Grade: F,", students[i].subjects[j]);
                }
                printf(" Grade: %.2f\n",students[i].subject_grades[j]);
            }
            // Return after printing the student's details
            return;
        }
    }
    // Print a message if the student with the specified ID was not found
    printf("Student not found.\n");
}

void print_teacher(int id) {
    int teacher_found = 0;
    for (int i = 0; i < num_teachers; i++) {
        if (teachers[i].id == id) {
            teacher_found = 1;
            printf("Teacher Details:\n");
            printf("Name: %s\n", teachers[i].name);
            printf("ID: %d\n", teachers[i].id);
            printf("Subject: %s\n", teachers[i].subject);
            printf("Salary: %.2f\n", teachers[i].salary);
            printf("Phone Number: %s\n", teachers[i].phone_number);
            break;
        }
    }

    if (!teacher_found) {
        printf("Teacher not found.\n");
    }
}

void edit_student(int id) {
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            int choice = 0;
            printf("Editing Student Details:\n");
            printf("1. Name\n");
            printf("2. Phone Number\n");
            printf("3. Age\n");
            printf("4. Class\n");
            printf("5. Subjects and Grades\n");
            printf("6. Return to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    // Update student name
                    printf("Name (current: %s): ", students[i].name);
                    scanf("%s", students[i].name);
                    printf("Name updated to %s.\n", students[i].name);
                    break;
                }
                case 2: {
                    // Update phone number
                    printf("Phone Number (current: %s): ", students[i].phone_number);
                    // Ensure phone number is exactly 11 digits
                    do {
                        printf("Phone Number (11 digits): ");
                        scanf("%s", students[i].phone_number);

                       if (strlen(students[i].phone_number) != 11) {
                           printf("Phone number must be exactly 11 digits. Please try again.\n");
                       } else {
                           break; // Valid phone number entered
                       }
                    } while (1);
                    printf("Phone Number updated to %s.\n", students[i].phone_number);
                    break;
                }
                case 3: {
                    // Update age
                    printf("Age (current: %d): ", students[i].age);
                    scanf("%d", &students[i].age);
                    printf("Age updated to %d.\n", students[i].age);
                    break;
                }
                case 4: {
                    // Update class
                    printf("Class (current: %s): ", students[i].s_class);
                    scanf("%s", students[i].s_class);
                    printf("Class updated to %s.\n", students[i].s_class);
                    break;
                }
                case 5: {
                    // Update subject details
                    float total_mark = 0;
                    printf("Update subject details:\n");
                    for (int j = 0; j < students[i].no_of_subjects; j++) {
                        printf("Subject %d (current: %s): ", j + 1, students[i].subjects[j]);
                        scanf("%s", students[i].subjects[j]);

                        printf("Grade for %s (current: %.2f): ", students[i].subjects[j], students[i].subject_grades[j]);
                        scanf("%f", &students[i].subject_grades[j]);

                        // Print grade based on the updated mark
                        float mark = students[i].subject_grades[j];
                        if (mark >= 85) {
                            printf("Grade for %s: A\n", students[i].subjects[j]);
                        } else if (mark >= 75) {
                            printf("Grade for %s: B\n", students[i].subjects[j]);
                        } else if (mark >= 65) {
                            printf("Grade for %s: C\n", students[i].subjects[j]);
                        } else if (mark >= 50) {
                            printf("Grade for %s: D\n", students[i].subjects[j]);
                        } else {
                            printf("Grade for %s: F\n", students[i].subjects[j]);
                        }

                        total_mark += mark;
                    }
                    students[i].total_grade = total_mark / students[i].no_of_subjects;
                    printf("Overall average grade: %.2f\n", students[i].total_grade);
                    break;
                }
                case 6:
                    return; // Return to the main menu
                default:
                    printf("Invalid choice, please try again.\n");
                    break;
            }
            return; // Exit after editing the details
        }
    }
    printf("Student not found.\n"); // If no student with the given ID is found, print a not-found message
}


void edit_teacher(int id) {
    for (int i = 0; i < num_teachers; i++) {
        if (teachers[i].id == id) {
            int choice;
            printf("Editing Teacher Details:\n");
            printf("1. Name\n");
            printf("2. Phone Number\n");
            printf("3. Salary\n");
            printf("4. Subject\n");
            printf("5. Return to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    // Update teacher name
                    printf("Name (current: %s): ", teachers[i].name);
                    scanf("%s", teachers[i].name);
                    printf("Name updated to %s.\n", teachers[i].name);
                    break;
                }
                case 2: {
                    // Update phone number
                    printf("Phone Number (current: %s): ", teachers[i].phone_number);
                    // Ensure phone number is exactly 11 digits
                    do {
                        printf("Phone Number (11 digits): ");
                        scanf("%s", teachers[i].phone_number);

                        if (strlen(teachers[i].phone_number) != 11) {
                            printf("Phone number must be exactly 11 digits. Please try again.\n");
                       } else {
                            break; // Valid phone number entered
                    }
                    } while (1);
                    printf("Phone Number updated to %s.\n", teachers[i].phone_number);
                    break;
                }
                case 3: {
                    // Update salary
                    printf("Salary (current: %.2f): ", teachers[i].salary);
                    scanf("%f", &teachers[i].salary);
                    printf("Salary updated to %.2f.\n", teachers[i].salary);
                    break;
                }
                case 4: {
                    // Update subject
                    printf("Subject (current: %s): ", teachers[i].subject);
                    scanf("%s", teachers[i].subject);
                    printf("Subject updated to %s.\n", teachers[i].subject);
                    break;
                }
                case 5:
                    return; // Return to the main menu
                default:
                    printf("Invalid choice, please try again.\n");
                    break;
            }
            return; // Exit after editing the details
        }
    }
    printf("Teacher not found.\n"); // If no teacher with the given ID is found, print a not-found message
}

void find_top_salary_teacher() {
    if (num_teachers == 0) {
        printf("No teachers available.\n");
        return;
    }

    int top_index = 0; // Start by assuming the first teacher has the highest salary
    for (int i = 1; i < num_teachers; i++) {
        if (teachers[i].salary > teachers[top_index].salary) {
            top_index = i; // Update the index if a higher salary is found
        }
    }

    // Print the details of the teacher with the highest salary
    printf("Teacher with the highest salary:\n");
    printf("Name: %s\n", teachers[top_index].name);
    printf("ID: %d\n", teachers[top_index].id);
    printf("Subject: %s\n", teachers[top_index].subject);
    printf("Salary: %.2f\n", teachers[top_index].salary);
    printf("Phone Number: %s\n", teachers[top_index].phone_number);
}

void find_top_student() {
    if (num_students == 0) {
        printf("No students available.\n");
        return;
    }

    int top_index = 0; // Start by assuming the first student has the highest grade
    for (int i = 1; i < num_students; i++) {
        if (students[i].total_grade > students[top_index].total_grade) {
            top_index = i; // Update the index if a higher grade is found
        }
    }

    // Print the details of the student with the highest grade
    printf("Top student:\n");
    printf("Name: %s\n", students[top_index].name);
    printf("ID: %d\n", students[top_index].id);
    printf("Phone Number: %s\n", students[top_index].phone_number);
    printf("Age: %d\n", students[top_index].age);
    printf("Class: %s\n", students[top_index].s_class);
    printf("Total Grade: %.2f\n", students[top_index].total_grade);
    printf("Subjects and Grades:\n");

    // Loop through the student's subjects to print each subject and grade
    for (int j = 0; j < students[top_index].no_of_subjects; j++) {
        printf("Subject: %s, Grade: %.2f\n", students[top_index].subjects[j], students[top_index].subject_grades[j]);
    }
}





