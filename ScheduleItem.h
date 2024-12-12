#pragma once
// ScheduleItem.h
#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H

#include <string>
#include <sstream>
#include <iomanip>

class ScheduleItem {
private:
    std::string subject;
    std::string catalog;
    std::string section;
    std::string component;
    std::string instructorLastName;

public:
    ScheduleItem() = default; // Default constructor
    ScheduleItem(const std::string& subj, const std::string& cat, const std::string& sec,
        const std::string& comp, const std::string& instrLastName);

    std::string getSubject() const;
    std::string getCatalog() const;
    std::string getSection() const;
    std::string getInstructorLastName() const;

    std::string toString() const;
};

#endif // SCHEDULEITEM_H