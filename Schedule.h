#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ScheduleItem.h"
#include <vector>
#include <string>
#include <fstream>

class Schedule {
private:
    std::vector<ScheduleItem> records;

public:
    void initSchedule(std::ifstream& file);
    void print() const;

    bool findBySubject(const std::string& subject) const;
    bool findBySubjectCatalog(const std::string& subject, const std::string& catalog) const;
    bool findByInstructor(const std::string& instructorLastName) const;

private:
    bool parseRecord(const std::string& line, ScheduleItem& item);
};

#endif // SCHEDULE_H
