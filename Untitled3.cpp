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
