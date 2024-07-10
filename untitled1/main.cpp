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