#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Student {
    string firstName;
    string surname;
    string gender;
    int age;
    int bbitGroup;
    string sport;
    vector<string> clubs;
};
//definition of the different structures
struct Club {
    string name;
    string description;
    int maxCapacity;
    int currentCapacity;
    int maleCount;
    int femaleCount;
};

struct Sport {
    string name;
    string description;
    int maxCapacity;
    int currentCapacity;
    int maleCount;
    int femaleCount;
};

// Functions for main menu options

void addStudent(vector<Student>& students, vector<Club>& clubs, vector<Sport>& sports) {
    Student s;
    cout << "Please enter the student's details:" << endl;
    cout << "First Name: ";
    cin >> s.firstName;
    cout << "Surname: ";
    cin >> s.surname;
    cout << "Gender (M/F): ";
    cin >> s.gender;
    cout << "Age: ";
    cin >> s.age;
    cout << "BBIT Group (1/2/3): ";
    cin >> s.bbitGroup;

    // Choose a sport
    if (sports.empty()) {
        cout << "There are no sports available to join." << endl;
    }
    else {
        cout << "Select a sport to join:" << endl;
        for (int i = 0; i < sports.size(); i++) {
            cout << i + 1 << ". " << sports[i].name << " (" << sports[i].currentCapacity << "/" << sports[i].maxCapacity << ")" << endl;
        }
        int sportSelection;
        cin >> sportSelection;
        while (sportSelection < 1 || sportSelection > sports.size()) {
            cout << "Invalid selection. Please enter a valid selection:" << endl;
            cin >> sportSelection;
        }
        if (sports[sportSelection - 1].currentCapacity >= sports[sportSelection - 1].maxCapacity) {
            cout << "Sorry, " << sports[sportSelection - 1].name << " is already full." << endl;
        }
        else {
            // Check gender limit for sport
            if (s.gender == "M" && ((double)sports[sportSelection - 1].maleCount / (double)sports[sportSelection - 1].maxCapacity) >= 0.75) {
                cout << "Sorry, there is not enough space for males in " << sports[sportSelection - 1].name << "." << endl;
            }
            else if (s.gender == "F" && ((double)sports[sportSelection - 1].femaleCount / (double)sports[sportSelection - 1].maxCapacity) >= 0.75) {
                cout << "Sorry, there is not enough space for females in " << sports[sportSelection - 1].name << "." << endl;
            }
            else {
                sports[sportSelection - 1].currentCapacity++;
                s.sport = sports[sportSelection - 1].name;
                if (s.gender == "M") {
                    sports[sportSelection - 1].maleCount++;
                }
                else if (s.gender == "F") {
                    sports[sportSelection - 1].femaleCount++;
                }
            }
        }
    }

    // Choose clubs
    if (clubs.empty()) {
        cout << "There are no clubs/societies available to join." << endl;
    }
    else {
        cout << "Select up to 2 clubs/societies to join (Enter 0 to stop):" << endl;
        for (int i = 0; i < clubs.size(); i++) {
            cout << i + 1 << ". " << clubs[i].name << " (" << clubs[i].currentCapacity << "/" << clubs[i].maxCapacity << ") - " << clubs[i].description << endl;
        }
        int clubSelection;
        int count = 0;
        cin >> clubSelection;
        while (clubSelection != 0 && count < 2) {
            if (clubSelection < 1 || clubSelection > clubs.size()) {
                cout << "Invalid selection. Please enter a valid selection:" << endl;
            }
            else if (clubs[clubSelection - 1].currentCapacity >= clubs[clubSelection - 1].maxCapacity) {
                cout << "Sorry, " << clubs[clubSelection - 1].name << " is already full." << endl;
            }
            else if (find(s.clubs.begin(), s.clubs.end(), clubs[clubSelection - 1].name) != s.clubs.end()) {
                cout << "You have already joined " << clubs[clubSelection - 1].name << ". Please select a different club/society." << endl;
            }
            else {
                // Check gender limit for club
                if (s.gender == "M" && ((double)clubs[clubSelection - 1].maleCount / (double)clubs[clubSelection - 1].maxCapacity) >= 0.5) {
                    cout << "Sorry, there is not enough space for males in " << clubs[clubSelection - 1].name << "." << endl;
                }
                else if (s.gender == "F" && ((double)clubs[clubSelection - 1].femaleCount / (double)clubs[clubSelection - 1].maxCapacity) >= 0.5) {
                    cout << "Sorry, there is not enough space for females in " << clubs[clubSelection - 1].name << "." << endl;
                }
                else {
                    clubs[clubSelection - 1].currentCapacity++;
                    s.clubs.push_back(clubs[clubSelection - 1].name);
                    count++;
                    if (s.gender == "M") {
                        clubs[clubSelection - 1].maleCount++;
                    }
                    else if (s.gender == "F") {
                        clubs[clubSelection - 1].femaleCount++;
                    }
                }
            }
            cin >> clubSelection;
        }
    }

    students.push_back(s);
    cout << "Student added successfully." << endl;
    cout << endl;
}

void viewAllStudents(vector<Student>& students) {
    cout << "List of all students:" << endl;
    for (Student s : students) {
        cout << s.firstName << " " << s.surname << " - " << s.gender << " - " << s.age << " - BBIT Group " << s.bbitGroup << " - ";
        if (s.sport == "") {
            cout << "No sport";
        }
        else {
            cout << "Sport: " << s.sport;
        }
        if (s.clubs.empty()) {
            cout << ", No clubs." << endl;
        }
        else {
            cout << ", Clubs: ";
            for (int i = 0; i < s.clubs.size(); i++) {
                if (i == s.clubs.size() - 1) {
                    cout << s.clubs[i] << "." << endl;
                }
                else {
                    cout << s.clubs[i] << ", ";
                }
            }
        }
    }
    cout << endl;
}

void viewStudentsByGroup(vector<Student>& students) {
    int group;
    cout << "Enter the BBIT Group (1/2/3): ";
    cin >> group;
    cout << "List of students in BBIT Group " << group << ":" << endl;
    for (Student s : students) {
        if (s.bbitGroup == group) {
            cout << s.firstName << " " << s.surname << " - " << s.gender << " - " << s.age << " - ";
            if (s.sport == "") {
                cout << "No sport";
            }
            else {
                cout << "Sport: " << s.sport;
            }
            if (s.clubs.empty()) {
                cout << ", No clubs." << endl;
            }
            else {
                cout << ", Clubs: ";
                for (int i = 0; i < s.clubs.size(); i++) {
                    if (i == s.clubs.size() - 1) {
                        cout << s.clubs[i] << "." << endl;
                    }
                    else {
                        cout << s.clubs[i] << ", ";
                    }
                }
            }
        }
    }
    cout << endl;
}

