#include "Schedule.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


// Initialize the schedule by reading from a file
void Schedule::initSchedule(std::ifstream& file) {
    std::string line;
    // Skip the header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string subject, catalog, section, component, session, instructor;
        int units, totEnrl, capEnrl;

        char delimiter; // For parsing commas
        iss >> subject >> delimiter >> catalog >> delimiter >> section >> delimiter
            >> component >> delimiter >> session >> delimiter >> units >> delimiter
            >> totEnrl >> delimiter >> capEnrl >> delimiter;

        std::getline(iss, instructor); // Instructor field may contain spaces

        ScheduleItem item(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor);
        addEntry(item);
    }
}

// Add a ScheduleItem to the map
void Schedule::addEntry(const ScheduleItem& item) {
    scheduleMap[item.getKey()] = item;
}

// Print all the schedule items
void Schedule::print() const {
    for (const auto& pair : scheduleMap) {
        pair.second.print();
    }
}

// Find by Subject
void Schedule::findBySubject(const std::string& subject) const {
    for (const auto& pair : scheduleMap) {
        if (pair.second.getSubject() == subject) {
            pair.second.print();
        }
    }
}

// Find by Subject and Catalog
void Schedule::findBySubjectCatalog(const std::string& subject, const std::string& catalog) const {
    for (const auto& pair : scheduleMap) {
        if (pair.second.getSubject() == subject && pair.second.getCatalog() == catalog) {
            pair.second.print();
        }
    }
}

// Find by Instructor's Last Name
void Schedule::findByInstructor(const std::string& instructorLastName) const {
    for (const auto& pair : scheduleMap) {
        if (pair.second.getInstructor().find(instructorLastName) != std::string::npos) {
            pair.second.print();
        }
    }
}
