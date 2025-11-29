#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Student structure to hold student information
struct Student {
    int rollNo;
    string name;
    int age;
    string course;
    float gpa;
    Student* next;  // Pointer to next node in linked list
};

// Class for Student Record Management System
class StudentManagementSystem {
private:
    Student* head;  // Head pointer of linked list

public:
    // Constructor
    StudentManagementSystem() {
        head = nullptr;
    }

    // Function to add a new student record
    void addStudent() {
        Student* newStudent = new Student();
        
        cout << "\n--- Add New Student ---\n";
        cout << "Enter Roll Number: ";
        cin >> newStudent->rollNo;
        
        // Check if roll number already exists
        if (searchByRollNo(newStudent->rollNo) != nullptr) {
            cout << "Error: Student with Roll Number " << newStudent->rollNo << " already exists!\n";
            delete newStudent;
            return;
        }
        
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, newStudent->name);
        cout << "Enter Age: ";
        cin >> newStudent->age;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, newStudent->course);
        cout << "Enter GPA: ";
        cin >> newStudent->gpa;
        
        newStudent->next = nullptr;
        
        // If list is empty, make new student the head
        if (head == nullptr) {
            head = newStudent;
        } else {
            // Add at the end of the list
            Student* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        
        cout << "\nStudent record added successfully!\n";
    }

    // Function to display all student records
    void displayAllStudents() {
        if (head == nullptr) {
            cout << "\nNo student records found!\n";
            return;
        }
        
        cout << "\n--- All Student Records ---\n";
        cout << setw(10) << "Roll No" << setw(20) << "Name" << setw(8) << "Age" 
             << setw(20) << "Course" << setw(8) << "GPA" << endl;
        cout << string(66, '-') << endl;
        
        Student* temp = head;
        while (temp != nullptr) {
            cout << setw(10) << temp->rollNo 
                 << setw(20) << temp->name 
                 << setw(8) << temp->age
                 << setw(20) << temp->course 
                 << setw(8) << fixed << setprecision(2) << temp->gpa << endl;
            temp = temp->next;
        }
    }

    // Function to search student by roll number
    Student* searchByRollNo(int rollNo) {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->rollNo == rollNo) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Function to display search results
    void searchStudent() {
        int rollNo;
        cout << "\nEnter Roll Number to search: ";
        cin >> rollNo;
        
        Student* student = searchByRollNo(rollNo);
        
        if (student == nullptr) {
            cout << "Student with Roll Number " << rollNo << " not found!\n";
        } else {
            cout << "\n--- Student Details ---\n";
            cout << "Roll Number: " << student->rollNo << endl;
            cout << "Name: " << student->name << endl;
            cout << "Age: " << student->age << endl;
            cout << "Course: " << student->course << endl;
            cout << "GPA: " << fixed << setprecision(2) << student->gpa << endl;
        }
    }

    // Function to update student record
    void updateStudent() {
        int rollNo;
        cout << "\nEnter Roll Number of student to update: ";
        cin >> rollNo;
        
        Student* student = searchByRollNo(rollNo);
        
        if (student == nullptr) {
            cout << "Student with Roll Number " << rollNo << " not found!\n";
            return;
        }
        
        cout << "\n--- Current Details ---\n";
        cout << "Name: " << student->name << endl;
        cout << "Age: " << student->age << endl;
        cout << "Course: " << student->course << endl;
        cout << "GPA: " << student->gpa << endl;
        
        int choice;
        cout << "\nWhat would you like to update?\n";
        cout << "1. Name\n2. Age\n3. Course\n4. GPA\n5. Update All\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter new Name: ";
                getline(cin, student->name);
                break;
            case 2:
                cout << "Enter new Age: ";
                cin >> student->age;
                break;
            case 3:
                cout << "Enter new Course: ";
                getline(cin, student->course);
                break;
            case 4:
                cout << "Enter new GPA: ";
                cin >> student->gpa;
                break;
            case 5:
                cout << "Enter new Name: ";
                getline(cin, student->name);
                cout << "Enter new Age: ";
                cin >> student->age;
                cin.ignore();
                cout << "Enter new Course: ";
                getline(cin, student->course);
                cout << "Enter new GPA: ";
                cin >> student->gpa;
                break;
            default:
                cout << "Invalid choice!\n";
                return;
        }
        
        cout << "\nStudent record updated successfully!\n";
    }

    // Function to delete a student record
    void deleteStudent() {
        if (head == nullptr) {
            cout << "\nNo student records to delete!\n";
            return;
        }
        
        int rollNo;
        cout << "\nEnter Roll Number of student to delete: ";
        cin >> rollNo;
        
        Student* temp = head;
        Student* prev = nullptr;
        
        // If head node itself holds the key
        if (temp != nullptr && temp->rollNo == rollNo) {
            head = temp->next;
            delete temp;
            cout << "Student record deleted successfully!\n";
            return;
        }
        
        // Search for the key
        while (temp != nullptr && temp->rollNo != rollNo) {
            prev = temp;
            temp = temp->next;
        }
        
        // If key was not present
        if (temp == nullptr) {
            cout << "Student with Roll Number " << rollNo << " not found!\n";
            return;
        }
        
        // Unlink the node and delete it
        prev->next = temp->next;
        delete temp;
        cout << "Student record deleted successfully!\n";
    }

    // Function to count total students
    void countStudents() {
        int count = 0;
        Student* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "\nTotal number of students: " << count << endl;
    }

    // Destructor to free memory
    ~StudentManagementSystem() {
        Student* current = head;
        while (current != nullptr) {
            Student* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Main function
int main() {
    StudentManagementSystem sms;
    int choice;
    
    do {
        cout << "\n========================================\n";
        cout << "  STUDENT RECORD MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Add New Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Count Total Students\n";
        cout << "7. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.displayAllStudents();
                break;
            case 3:
                sms.searchStudent();
                break;
            case 4:
                sms.updateStudent();
                break;
            case 5:
                sms.deleteStudent();
                break;
            case 6:
                sms.countStudents();
                break;
            case 7:
                cout << "\nThank you for using the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}
