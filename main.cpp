#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

int main() {

    int easy, medium, hard;
    int totalChapters, days;

    std::cout << "========================================\n";
    std::cout << " StudyBuddy - Your Study Compass\n";
    std::cout << "========================================\n\n";

    std::cout << "Enter total chapters: ";
    std::cin >> totalChapters;

    std::cout << "Enter study days: ";
    std::cin >> days;

    // Safety check 1
    if (totalChapters <= 0 || days <= 0) {
        std::cout << "\nError: Chapters and days must be at least 1\n";
        return 0;
    }

    std::cout << "\nEnter EASY chapters: ";
    std::cin >> easy;
    std::cout << "Enter MEDIUM chapters: ";
    std::cin >> medium;
    std::cout << "Enter HARD chapters: ";
    std::cin >> hard;

    if (easy + medium + hard != totalChapters) {
        std::cout << "\nError: Chapter count mismatch!\n";
        std::cout << "Easy + Medium + Hard = " << easy + medium + hard;
        std::cout << " but Total = " << totalChapters << "\n";
        return 0;
    }

    std::vector<std::string> chapters;
    std::string name;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "\nEnter chapter names (HARD first, then MEDIUM, then EASY):\n";

    // HARD
    for (int i = 0; i < hard; i++) {
        std::cout << "Hard chapter " << i + 1 << ": ";
        std::getline(std::cin, name);
        chapters.push_back(name + " [HARD]");
    }

    // MEDIUM
    for (int i = 0; i < medium; i++) {
        std::cout << "Medium chapter " << i + 1 << ": ";
        std::getline(std::cin, name);
        chapters.push_back(name + " [MEDIUM]");
    }

    // EASY
    for (int i = 0; i < easy; i++) {
        std::cout << "Easy chapter " << i + 1 << ": ";
        std::getline(std::cin, name);
        chapters.push_back(name + " [EASY]");
    }

    std::cout << "\n========================================\n";
    std::cout << " STUDY PLAN\n";
    std::cout << "========================================\n";

    int completed = 0;
    int chap = 0;

    // Fix divide-by-zero issue
    int studyDays = (days > 1) ? days - 1 : 1;

    int perDay = totalChapters / studyDays;
    int extra = totalChapters % studyDays;

    for (int d = 1; d <= days; d++) {

        std::cout << "\nDay " << d << "\n";
        std::cout << "----------------------------------------\n";

        // Revision day
        if (d > studyDays) {
            std::cout << "Revision Day\n";
            std::cout << "Revise all chapters\n";
            std::cout << "\nProgress: 100.0%\n";
            std::cout << "Super amazing. Revision time.\n";
            continue;
        }

        int today = perDay;
        if (extra > 0) {
            today++;
            extra--;
        }

        for (int i = 0; i < today; i++) {

            if (chap >= chapters.size()) break;

            char status;

            std::cout << "Study: " << chapters[chap] << "\n";
            std::cout << "Completed? (Y/N): ";
            std::cin >> status;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (status == 'y' || status == 'Y') {
                std::cout << "[✓] Marked complete\n";
                completed++;
            } else {
                std::cout << "[ ] Not done yet\n";
            }

            chap++;
        }

        double percent = (double)completed / totalChapters * 100;

        std::cout << "\nProgress: " << std::fixed << std::setprecision(1) << percent << "%\n";

        if (percent >= 100)
            std::cout << "Super amazing. All done.\n";
        else if (percent >= 50)
            std::cout << "Half way there. Keep going.\n";
        else
            std::cout << "Good start. Stay consistent.\n";
    }

    return 0;
}
