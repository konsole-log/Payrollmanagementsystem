#include <iostream>
#include <iomanip>
#include <string>

// Function to print a row with two fields (for Name and Address)
void printTwoColumnRow(const std::string& label1, const std::string& value1, 
                       const std::string& label2, const std::string& value2, 
                       int totalWidth) {
    int col1Width = label1.length() + value1.length() + 2; // 2 for ": "
    int col2Width = label2.length() + value2.length() + 2; // 2 for ": "

    std::cout << "| " << label1 << ": " << value1
              << std::setw(totalWidth - col1Width - col2Width - 4) << std::setfill(' ') << "" // -4 for padding and "|"
              << label2 << ": " << value2 << " |\n";
}

// Function to print a row with one field (for Salary, Allowance, and Tax)
void printSingleColumnRow(const std::string& label, const std::string& value, int totalWidth) {
    int colWidth = label.length() + value.length() + 2; // 2 for ": "

    std::cout << "| " << label << ": " << value
              << std::setw(totalWidth - colWidth - 3) << std::setfill(' ') << " |\n";
}

int main() {
    // Variables with potentially varying lengths
    std::string name = "Anushfdsfasfswfs";
    std::string address = "Kharibofdsfsfst";
    std::string salary = "1000";
    std::string allowance = "xyz";
    std::string tax = "50";

    // Set total width for the table (adjust this as needed)
    int totalWidth = 59;
    int innerWidth = totalWidth - 2;

    // Print the header
    std::cout << "+" << std::setw(innerWidth) << std::setfill('-') << std::left << "PAYSLIP" << "+" << std::endl;

    // Print the name and address row
    printTwoColumnRow("Name", name, "Address", address, totalWidth);

    // Print a separator line
    std::cout << "|" << std::setw(innerWidth) << std::setfill('-') << "" << "|\n";

    // Print the salary, allowance, and tax rows
    printSingleColumnRow("Salary", salary, totalWidth);
    printSingleColumnRow("allowance", allowance, totalWidth);
    printSingleColumnRow("tax", tax, totalWidth);

    // Print the footer
    std::cout << "|" << std::setw(innerWidth) << std::setfill('-') << "" << "|\n";
    
    return 0;
}
