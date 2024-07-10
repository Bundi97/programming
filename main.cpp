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

void viewClubsSocieties(vector<Club>& clubs) {
    cout << "List of available clubs/societies:" << endl;
    for (Club c : clubs) {
        cout << c.name << " - " << c.description << " (" << c.currentCapacity << "/" << c.maxCapacity << ")" << endl;
    }
    cout << endl;
}