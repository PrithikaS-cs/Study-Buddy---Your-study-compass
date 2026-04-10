#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>

using namespace std;

int main() {

    cout << "Study Buddy v3 (Simple Smart Planner)\n";
    cout << "-------------------------------------\n";

    int totalChapters, days, easy, medium, hard, dailyHours;

    cout << "Enter total chapters: ";
    cin >> totalChapters;

    cout << "Enter study days: ";
    cin >> days;

    cout << "Enter EASY chapters: ";
    cin >> easy;

    cout << "Enter MEDIUM chapters: ";
    cin >> medium;

    cout << "Enter HARD chapters: ";
    cin >> hard;

    if (easy + medium + hard != totalChapters) {
        cout << "Error: Chapter mismatch!\n";
        return 1;
    }

    cout << "Enter study hours per day: ";
    cin >> dailyHours;

    if (days <= 0 || dailyHours <= 0) {
        cout << "Invalid input!\n";
        return 1;
    }

    int availableTime = days * dailyHours;
    int requiredTime = (easy * 1) + (medium * 2) + (hard * 3);

    cout << "\n--- TIME CHECK ---\n";
    cout << "Required Time : " << requiredTime << " hrs\n";
    cout << "Available Time: " << availableTime << " hrs\n";

    if (availableTime >= requiredTime)
        cout << "Status: Feasible plan\n";
    else
        cout << "Status: Time is tight\n";

    // ---------------- CHAPTER INPUT ----------------

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> chapters;
    string name;

    cout << "\nEnter chapter names:\n";

    for (int i = 0; i < totalChapters; i++) {
        cout << "Chapter " << i + 1 << ": ";
        getline(cin, name);

        if (name.empty())
            name = "Chapter " + to_string(i + 1);

        chapters.push_back(name);
    }

    // ---------------- SIMPLE DAILY PLAN ----------------

    cout << "\n--- DAILY STUDY PLAN ---\n";

    int perDay = totalChapters / days;
    int extra = totalChapters % days;

    int index = 0;

    for (int d = 0; d < days; d++) {

        cout << "Day " << d + 1 << ": ";

        int todayCount = perDay;

        if (extra > 0) {
            todayCount++;
            extra--;
        }

        for (int i = 0; i < todayCount && index < totalChapters; i++) {
            cout << chapters[index] << " | ";
            index++;
        }

        cout << endl;
    }

    // ---------------- CHECKLIST ----------------

    int completed = 0;
    char status;

    cout << "\n--- PROGRESS TRACKER ---\n";

    for (int i = 0; i < totalChapters; i++) {

        cout << "\n" << chapters[i] << endl;
        cout << "Completed? (y/n): ";
        cin >> status;

        if (status == 'y' || status == 'Y')
            completed++;

        double percent = (double)completed / totalChapters * 100;

        cout << "Progress: " << fixed << setprecision(1)
             << percent << "%\n";
    }

    // ---------------- SAVE REPORT ----------------

    ofstream file("study_report.txt");

    file << "Study Buddy Report\n";
    file << "------------------\n";
    file << "Total Chapters: " << totalChapters << "\n";
    file << "Days: " << days << "\n";
    file << "Completed: " << completed << "\n";
    file << "Progress: " << (completed * 100.0 / totalChapters) << "%\n";

    file.close();

    cout << "\nReport saved to study_report.txt\n";
    cout << "Study tracking completed.\n";

    return 0;
}
