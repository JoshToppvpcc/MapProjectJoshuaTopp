#pragma once
#include <string>
#include <iostream>

#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H

#include <string>
#include <iostream> // Required for std::cout

class ScheduleItem {
private:
    std::string subject, catalog, section, component, session, instructor;
    int units, totEnrl, capEnrl;

public:
    // Constructor with default parameters
    ScheduleItem(
        std::string subj = "", std::string cat = "", std::string sec = "",
        std::string comp = "", std::string sess = "", int unit = 0,
        int totEn = 0, int capEn = 0, std::string instr = "");

    // Getter methods
    std::string getKey() const;
    std::string getSubject() const;
    std::string getCatalog() const;
    std::string getSection() const;
    std::string getInstructor() const;
    int getUnits() const;
    int getTotEnrl() const;
    int getCapEnrl() const;

    // Overloaded operators
    bool operator==(const ScheduleItem& other) const;
    bool operator!=(const ScheduleItem& other) const;
    bool operator>=(const ScheduleItem& other) const;

    // Print method
    void print() const;
};

#endif // SCHEDULEITEM_H
