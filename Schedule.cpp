// Schedule.cpp
#include "Schedule.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Schedule::loadFromFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string subject, catalog, section, component, instructor;

        std::getline(ss, subject, ',');
        std::getline(ss, catalog, ',');
        std::getline(ss, section, ',');
        std::getline(ss, component, ',');
        for (int i = 0; i < 7; ++i) {
            std::string temp;
            std::getline(ss, temp, ',');
        }
        std::getline(ss, instructor, ',');

        size_t commaPos = instructor.find(',');
        std::string instructorLastName = (commaPos != std::string::npos) ? instructor.substr(0, commaPos) : instructor;

        std::string key = subject + " " + catalog + " " + section;
        records[key] = ScheduleItem(subject, catalog, section, component, instructorLastName);
    }

    std::cout << "Loaded " << records.size() << " records." << std::endl;
}

void Schedule::printAll() const {
    if (records.empty()) {
        std::cout << "No records available." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(8) << "Subject" << std::setw(8) << "Catalog"
        << std::setw(8) << "Section" << std::setw(12) << "Component"
        << std::setw(15) << "Instructor" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    for (const auto& pair : records) {
        std::cout << pair.second.toString() << std::endl;
    }
}

void Schedule::findBySubject(const std::string& subject) const {
    bool found = false;
    for (const auto& pair : records) {
        if (pair.second.getSubject() == subject) {
            std::cout << pair.second.toString() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No records found for subject: " << subject << std::endl;
    }
}

void Schedule::findBySubjectAndCatalog(const std::string& subject, const std::string& catalog) const {
    bool found = false;
    for (const auto& pair : records) {
        if (pair.second.getSubject() == subject && pair.second.getCatalog() == catalog) {
            std::cout << pair.second.toString() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No records found for subject and catalog: " << subject << " " << catalog << std::endl;
    }
}

void Schedule::findByInstructorLastName(const std::string& lastName) const {
    bool found = false;
    for (const auto& pair : records) {
        if (pair.second.getInstructorLastName() == lastName) {
            std::cout << pair.second.toString() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No records found for instructor last name: " << lastName << std::endl;
    }
}
