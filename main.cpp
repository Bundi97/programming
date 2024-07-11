

void viewClubsSocieties(vector<Club>& clubs) {
    cout << "List of available clubs/societies:" << endl;
    for (Club c : clubs) {
        cout << c.name << " - " << c.description << " (" << c.currentCapacity << "/" << c.maxCapacity << ")" << endl;
    }
    cout << endl;
}

void viewSports(vector<Sport>& sports) {
    cout << "List of available sports:" << endl;
    for (Sport s : sports) {
        cout << s.name << " - " << s.description << " (" << s.currentCapacity << "/" << s.maxCapacity << ")" << endl;
    }
    cout << endl;
}

void viewGroupedStudents(vector<Student>& students, vector<Club>& clubs, vector<Sport>& sports) {
    int option;
    cout << "Please select an activity:" << endl;
    cout << "1. Club/Society" << endl;
    cout << "2. Sport" << endl;
    cin >> option;
    if (option == 1) {
        string club;
        cout << "Enter the name of the club/society:" << endl;
        cin.ignore();
        getline(cin, club);
        cout << "List of students in " << club << ":" << endl;
        for (Student s : students) {
            if (find(s.clubs.begin(), s.clubs.end(), club) != s.clubs.end()) {
                cout << s.firstName << " " << s.surname << " - BBIT Group " << s.bbitGroup << endl;
            }
        }
    }
    else if (option == 2) {
        string sport;
        cout << "Enter the name of the sport:" << endl;
        cin.ignore();
        getline(cin, sport);
        cout << "List of students in " << sport << ":" << endl;
        for (Student s : students) {
            if (s.sport == sport) {
                cout << s.firstName << " " << s.surname << " - BBIT Group " << s.bbitGroup << endl;
            }
        }
    }
    cout << endl;
}

void saveData(vector<Student>& students) {
    ofstream outputFile;
    outputFile.open("bbityear1.csv");
    outputFile << "First Name,Surname,Gender,Age,BBIT Group,activity 1,activity 2,activity 3\n";
    for (Student s : students) {
        outputFile << s.firstName << "," << s.surname << "," << s.gender << "," << s.age << "," << s.bbitGroup << ","
            << s.sport << ",";
        if (s.clubs.empty()) {
            outputFile << ",,," << endl;
        }
        else {
            for (int i = 0; i < s.clubs.size(); i++) {
                if (i == s.clubs.size() - 1) {
                    outputFile << s.clubs[i] << "," << "," << endl;
                }
                else {
                    outputFile << s.clubs[i] << ",";
                }
            }
        }
    }
    outputFile.close();
    cout << "Data saved successfully to bbityear1.csv" << endl;
    cout << endl;
}

int main() {
    // Initialize data
    vector<Club> clubs = { {"Journalism Club", "Learn about and practice journalism.", 60},
                           {"Red Cross Society", "Join the Red Cross and help those in need.", 60},
                           {"AISEC", "Join the AISEC international exchange program.", 60},
                           {"Business Club", "Get practical business experience.", 60},
                           {"Computer Science Club", "Learn and practice computer science concepts and projects.", 60} };
    vector<Sport> sports = { {"Rugby", "Play competitive rugby matches.", 20},
                             {"Athletics", "Train and compete in athletic events.", 20},
                             {"Swimming", "Train and compete in swimming events.", 20},
                             {"Soccer", "Play competitive soccer matches.",20} };
    vector<Student> students;

    int option;
    while (true) {
        cout << "Welcome to the BBIT Year 1 Co-Curricular Activities Program" << endl;
        cout << "Please select an option from the menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. View Clubs/Societies" << endl;
        cout << "4. View Sports" << endl;
        cout << "5. View Grouped Students" << endl;
        cout << "6. Save all Files" << endl;
        cout << "7. Exit" << endl;
        cin >> option;

        switch (option) {
        case 1:
            addStudent(students, clubs, sports);
            break;
        case 2:
            int viewOption;
            cout << "Please select an option:" << endl;
            cout << "1. View All Students" << endl;
            cout << "2. View Students by BBIT Group" << endl;
            cin >> viewOption;
            if (viewOption == 1) {
                viewAllStudents(students);
            }
            else if (viewOption == 2) {
                viewStudentsByGroup(students);
            }
            break;
        case 3:
            viewClubsSocieties(clubs);
            break;
        case 4:
            viewSports(sports);
            break;
        case 5:
            viewGroupedStudents(students, clubs, sports);
            break;
        case 6:
            saveData(students);
            break;
        case 7:
            cout << "Thanks !!" << endl;
            return 0;
        default:
            cout << "Invalid option. Please select a valid option from the menu." << endl;
            break;
        }
    }
    return 0;
}