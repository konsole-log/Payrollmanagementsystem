#include <iostream>
#include <iomanip>
#include <string>

void printLine(int width) {
    std::cout << "+" << std::setw(width - 1) << std::setfill('-') << "" << "+" << std::endl;
}

void printHeader(const std::string& header, int width) {
    int padding = (width - header.length() - 2) / 2;
    std::cout << "+" << std::setw(padding) << std::setfill('-') << ""
              << header << std::setw(width - padding - header.length() - 1) << "" << "+" << std::endl;
}

void printRow(const std::string& label1, const std::string& value1, 
              const std::string& label2, const std::string& value2, 
              const std::string& label3, const std::string& value3, int totalWidth) {
    int col1Width = label1.length() + value1.length() + 2; // 2 for ": "
    int col2Width = label2.length() + value2.length() + 2; // 2 for ": "
    int col3Width = label3.length() + value3.length() + 2; // 2 for ": "

    int spacing = (totalWidth - col1Width - col2Width - col3Width - 4) / 2; // Adjust spacing

    std::cout << "| " << label1 << ": " << value1
              << std::setw(spacing) << std::setfill(' ') << ""
              << label2 << ": " << value2
              << std::setw(spacing) << std::setfill(' ') << ""
              << label3 << ": " << value3 << " |\n";
}

int main() {
    // Variables with potentially varying lengths
    std::string empID = "21";
    std::string name = "Sangamfdsffs";
    std::string address = "Goldhungadsfsf";

    // Set total width for the table
    int totalWidth = 65;

    // Print the header
    printHeader("PAYSLIP", totalWidth);

    // Print the employee information row
    printRow("Employee ID", empID, "Name", name, "Address", address, totalWidth);

    // Print the footer line
    printLine(totalWidth);

    return 0;
}
