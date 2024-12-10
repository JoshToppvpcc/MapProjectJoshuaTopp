#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

// Function to trim whitespace from strings
std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" ");
    if (start == std::string::npos) return "";
    size_t end = s.find_last_not_of(" ");
    return s.substr(start, end - start + 1);
}

// Function to parse 
bool parseRecord(const std::string& line, const std::string& subjectToSearch, const std::string& catalogToSearch, const std::string& teacherToSearch) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> fields;

    while (std::getline(ss, token, ',')) {
        fields.push_back(trim(token)); 
    }

    // Check for subject match
    if (!subjectToSearch.empty() && fields[0].find(subjectToSearch) == std::string::npos) {
        return false;
    }

    // Check for catalog match 
    if (!catalogToSearch.empty() && fields[1].find(catalogToSearch) == std::string::npos) {
        return false;
    }

    // Check for instructor last name match 
    if (!teacherToSearch.empty() && fields[10].find(teacherToSearch) == std::string::npos) {
        return false;
    }

    return true;
}

// Function to print all records from the file
void printAllRecords(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

// Function to search and print records by subject
void searchBySubject(const std::string& fileName, const std::string& subjectToSearch) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(file, line)) {
        if (parseRecord(line, subjectToSearch, "", "")) {
            std::cout << "Found record: " << line << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching records found for subject: " << subjectToSearch << std::endl;
    }
}

// Function to search and print records by subject and catalog
void searchBySubjectAndCatalog(const std::string& fileName, const std::string& subjectToSearch, const std::string& catalogToSearch) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(file, line)) {
        if (parseRecord(line, subjectToSearch, catalogToSearch, "")) {
            std::cout << "Found record: " << line << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching records found for subject: " << subjectToSearch << " and catalog: " << catalogToSearch << std::endl;
    }
}

// Function to search and print records by instructor's last name
void searchByTeacherLastName(const std::string& fileName, const std::string& teacherToSearch) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    std::string line;
    bool found = false;
    while (std::getline(file, line)) {
        if (parseRecord(line, "", "", teacherToSearch)) {
            std::cout << "Found record: " << line << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching records found for instructor: " << teacherToSearch << std::endl;
    }
}

int main() {
    int choice;
    std::string subjectToSearch, catalogToSearch, teacherToSearch;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Print all records\n";
        std::cout << "2. Find by Subject\n";
        std::cout << "3. Find by Subject and Catalog\n";
        std::cout << "4. Find by Instructor Last Name\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  

        switch (choice) {
        case 1:
            printAllRecords("Cdata.txt");
            break;
        case 2:
            std::cout << "Enter Subject: ";
            std::getline(std::cin, subjectToSearch);
            searchBySubject("Cdata.txt", subjectToSearch);
            break;
        case 3:
            std::cout << "Enter Subject: ";
            std::getline(std::cin, subjectToSearch);
            std::cout << "Enter Catalog: ";
            std::getline(std::cin, catalogToSearch);
            searchBySubjectAndCatalog("Cdata.txt", subjectToSearch, catalogToSearch);
            break;
        case 4:
            std::cout << "Enter Instructor Last Name: ";
            std::getline(std::cin, teacherToSearch);
            searchByTeacherLastName("Cdata.txt", teacherToSearch);
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again" << std::endl;
        }
    } while (choice != 5);

    return 0;
}
