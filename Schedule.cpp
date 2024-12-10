#include "Schedule.h"
#include <sstream>
#include <iostream>
#include <fstream>

// Function to initialize the schedule data
void Schedule::initSchedule(std::ifstream& file) {
    std::string line;

    // Skip the header line
    if (!std::getline(file, line)) {
        std::cerr << "Error reading file header" << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        ScheduleItem item;

        if (parseRecord(line, item)) {
            std::cout << "Loaded record: "; // Debugging output
            item.print();
            records.push_back(item);
        }
        else {
            std::cerr << "Failed to parse record line: " << line << std::endl;
        }
    }
}

// Function to parse a record from a CSV-like line
bool Schedule::parseRecord(const std::string& line, ScheduleItem& item) {
    std::istringstream ss(line);
    std::string subj, cat, sec, comp, sess, instr;
    int minUnits, units, totEnrl, capEnrl;

    // Handle CSV parsing with proper quotes
    if (std::getline(ss, subj, ',') &&
        std::getline(ss, cat, ',') &&
        std::getline(ss, sec, ',') &&
        std::getline(ss, comp, ',') &&
        std::getline(ss, sess, ',') &&
        ss >> minUnits >> units >> totEnrl >> capEnrl) {

        // Handle quoted string for instructor
        std::string quotedField;
        if (ss.peek() == '"') { // Detect quoted fields
            ss.get(); // Consume the starting quote
            std::getline(ss, instr, '"'); // Read until the ending quote
        }
        else {
            ss >> instr; // Otherwise read normally
        }

        // Populate the ScheduleItem
        
        return true;
    }

    std::cerr << "Error parsing record fields" << std::endl;
    return false;
}


// Prints all loaded records
void Schedule::print() const {
    if (records.empty()) {
        std::cout << "No schedule items to print." << std::endl;
        return;
    }

    std::cout << "\nPrinting Schedule Records:\n";
    for (const auto& item : records) {
        item.print();
    }
}

// Search by subject
bool Schedule::findBySubject(const std::string& subject) const {
    bool found = false;

    for (const auto& item : records) {
        if (item.getSubject() == subject) {
            item.print();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching records found for subject: " << subject << std::endl;
    }
    return found;
}

// Search by subject and catalog combination
bool Schedule::findBySubjectCatalog(const std::string& subject, const std::string& catalog) const {
    bool found = false;

    for (const auto& item : records) {
        if (item.getSubject() == subject && item.getCatalog() == catalog) {
            item.print();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching records found for subject + catalog combination." << std::endl;
    }
    return found;
}

// Search by instructor's last name
bool Schedule::findByInstructor(const std::string& instructorLastName) const {
    bool found = false;

    for (const auto& item : records) {
        if (item.getInstructor().find(instructorLastName) != std::string::npos) {
            item.print();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching records found for instructor's last name." << std::endl;
    }
    return found;
}
