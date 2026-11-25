// Grade Calculator
// Enter marks and credit hours for each subject to get percentage,
// letter grade and a credit-weighted GPA on a 4.0 scale.
// The grade boundaries below are a generic scale: edit gradeFor() to match yours.
//
// Build:  g++ -std=c++17 -Wall -o grade_calculator grade_calculator.cpp
// Usage:  ./grade_calculator

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Subject {
    std::string name;
    double marks;
    int credits;
};

void gradeFor(double marks, std::string& letter, double& points) {
    if (marks >= 85)      { letter = "A";  points = 4.0; }
    else if (marks >= 80) { letter = "A-"; points = 3.67; }
    else if (marks >= 75) { letter = "B+"; points = 3.33; }
    else if (marks >= 70) { letter = "B";  points = 3.0; }
    else if (marks >= 65) { letter = "B-"; points = 2.67; }
    else if (marks >= 60) { letter = "C+"; points = 2.33; }
    else if (marks >= 55) { letter = "C";  points = 2.0; }
    else if (marks >= 50) { letter = "D";  points = 1.0; }
    else                  { letter = "F";  points = 0.0; }
}

int main() {
    int n;
    std::cout << "=== Grade Calculator ===\nNumber of subjects: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Please enter a positive number.\n";
        return 1;
    }

    std::vector<Subject> subjects;
    for (int i = 1; i <= n; ++i) {
        Subject s;
        std::cout << "\nSubject " << i << " name (no spaces): ";
        std::cin >> s.name;
        do {
            std::cout << "  Marks (0-100): ";
            if (!(std::cin >> s.marks)) return 1;
        } while (s.marks < 0 || s.marks > 100);
        do {
            std::cout << "  Credit hours (1-6): ";
            if (!(std::cin >> s.credits)) return 1;
        } while (s.credits < 1 || s.credits > 6);
        subjects.push_back(s);
    }

    double totalPoints = 0, totalMarks = 0;
    int totalCredits = 0;

    std::cout << "\n" << std::left << std::setw(16) << "Subject" << std::setw(8) << "Marks"
              << std::setw(8) << "Grade" << std::setw(8) << "Points" << "Credits\n"
              << std::string(46, '-') << "\n";
    for (const auto& s : subjects) {
        std::string letter;
        double pts;
        gradeFor(s.marks, letter, pts);
        std::cout << std::left << std::setw(16) << s.name << std::setw(8) << s.marks
                  << std::setw(8) << letter << std::setw(8) << pts << s.credits << "\n";
        totalPoints += pts * s.credits;
        totalMarks += s.marks;
        totalCredits += s.credits;
    }

    std::cout << std::fixed << std::setprecision(2)
              << "\nAverage percentage: " << totalMarks / subjects.size() << "%\n"
              << "Semester GPA      : " << totalPoints / totalCredits << " / 4.00\n";
    return 0;
}
