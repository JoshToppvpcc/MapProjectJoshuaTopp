#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ScheduleItem.h"
#include <map>
#include <string>
#include <fstream>
#include <iostream>

class Schedule {
private:
    std::map<std::string, ScheduleItem> scheduleMap;

public:
    void initSchedule(std::ifstream& file);
    void addEntry(const ScheduleItem& item);

    void print() const;
    void findBySubject(const std::string& subject) const;
    void findBySubjectCatalog(const std::string& subject, const std::string& catalog) const;
    void findByInstructor(const std::string& instructorLastName) const;
};

#endif // SCHEDULE_H
