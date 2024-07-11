    // Choose a sport
    if (sports.empty()) {
        cout << "There are no sports available to join." << endl;
    }// if the sport  vector is empty
    else {
        cout << "Select a sport to join:" << endl;
        for (int i = 0; i < sports.size(); i++) {//give the selected sport and show the current caacity
            cout << i + 1 << ". " << sports[i].name << " (" << sports[i].currentCapacity << "/" << sports[i].maxCapacity << ")" << endl;
        }
        int sportSelection;
        cin >> sportSelection;
        while (sportSelection < 1 || sportSelection > sports.size()) {//if sport selection is less than 0ne or more than the maximum for sport selection
            cout << "Invalid selection. Please enter a valid selection:" << endl;
            cin >> sportSelection;
        }
        if (sports[sportSelection - 1].currentCapacity >= sports[sportSelection - 1].maxCapacity) {//if current capacity is more than the current capacity
            cout << "Sorry, " << sports[sportSelection - 1].name << " is already full." << endl;
        }
        else {
            // Check gender limit for sport
            if (s.gender == "M" && ((double)sports[sportSelection - 1].maleCount / (double)sports[sportSelection - 1].maxCapacity) >= 0.75) {
                cout << "Sorry, there is not enough space for males in " << sports[sportSelection - 1].name << "." << endl;
            }//if the ration of malecount is more than 0.75
            else if (s.gender == "F" && ((double)sports[sportSelection - 1].femaleCount / (double)sports[sportSelection - 1].maxCapacity) >= 0.75) {
                cout << "Sorry, there is not enough space for females in " << sports[sportSelection - 1].name << "." << endl;
            }// if the ratoi for female count is more tham 0.75
            else {
                sports[sportSelection - 1].currentCapacity++;//the current capacity of the selected sport increase
                s.sport = sports[sportSelection - 1].name;
                if (s.gender == "M") {//malecount
                    sports[sportSelection - 1].maleCount++;
                }
                else if (s.gender == "F") {//gender count
                    sports[sportSelection - 1].femaleCount++;
                }
            }
        }
    }

    // Choose clubs
    if (clubs.empty()) {// if the vector club is empty
        cout << "There are no clubs/societies available to join." << endl;
    }
    else {
        cout << "Select up to 2 clubs/societies to join (Enter 0 to stop):" << endl;
        for (int i = 0; i < clubs.size(); i++) {// for the clubselection is less than the max for club selection
            cout << i + 1 << ". " << clubs[i].name << " (" << clubs[i].currentCapacity << "/" << clubs[i].maxCapacity << ") - " << clubs[i].description << endl;
        }
        int clubSelection;
        int count = 0;// to count the club chosen by a student
        cin >> clubSelection;
        while (clubSelection != 0 && count < 2) {//as long as a club want to be selected and that the club selected are less than two
            if (clubSelection < 1 || clubSelection > clubs.size()) {//if the clubselection is less than 1 or more than the max for clubselection
                cout << "Invalid selection. Please enter a valid selection:" << endl;
            }
            else if (clubs[clubSelection - 1].currentCapacity >= clubs[clubSelection - 1].maxCapacity) {
                cout << "Sorry, " << clubs[clubSelection - 1].name << " is already full." << endl;//verify is the club is full
            }
            else if (find(s.clubs.begin(), s.clubs.end(), clubs[clubSelection - 1].name) != s.clubs.end()) {// to check if you have already joined a club
                cout << "You have already joined " << clubs[clubSelection - 1].name << ". Please select a different club/society." << endl;
            }
            else {
                // Check gender limit for club
                if (s.gender == "M" && ((double)clubs[clubSelection - 1].maleCount / (double)clubs[clubSelection - 1].maxCapacity) >= 0.5) {
                    cout << "Sorry, there is not enough space for males in " << clubs[clubSelection - 1].name << "." << endl;// if the male ratio is more than 0.5
                }
                else if (s.gender == "F" && ((double)clubs[clubSelection - 1].femaleCount / (double)clubs[clubSelection - 1].maxCapacity) >= 0.5) {
                    cout << "Sorry, there is not enough space for females in " << clubs[clubSelection - 1].name << "." << endl;
                }
                else {
                    clubs[clubSelection - 1].currentCapacity++;//to increase the capacity of the club selected
                    s.clubs.push_back(clubs[clubSelection - 1].name);
                    count++;// to add the club selected in the student's club
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

    students.push_back(s);// to add succcessfully a student
    cout << "Student added successfully." << endl;
    cout << endl;
}