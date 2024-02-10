#include <iostream>
#include <fstream>
#include <iomanip> // For setprecision

using namespace std;

int main() {
    ifstream inFile("SalaryData.txt");
    ofstream outFile("SalaryOut.txt");

    string firstName, lastName;
    double currentSalary, payIncrease, updatedSalary;

    // Check if files are opened correctly
    if (!inFile || !outFile) {
        cerr << "Error opening files!" << endl;
        return 1; // Return error code 1
    }

    // Set precision for decimal output
    outFile << fixed << setprecision(2);

    // Read from inFile and write updated data to outFile
    while (inFile >> lastName >> firstName >> currentSalary >> payIncrease) {
        updatedSalary = currentSalary * (1 + payIncrease / 100);
        outFile << firstName << " " << lastName << " " << updatedSalary << endl;
    }

    // Close files
    inFile.close();
    outFile.close();

    cout << "Process completed. Check 'SalaryOut.txt' for results." << endl;

    return 0;
}
