#pragma once
// Schedule.h
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "ScheduleItem.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>

class Schedule {
private:
    std::map<std::string, ScheduleItem> records;

public:
    void loadFromFile(const std::string& fileName);
    void printAll() const;
    void findBySubject(const std::string& subject) const;
    void findBySubjectAndCatalog(const std::string& subject, const std::string& catalog) const;
    void findByInstructorLastName(const std::string& lastName) const;
};

#endif // SCHEDULE_H
