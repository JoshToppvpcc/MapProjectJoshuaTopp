#include "ScheduleItem.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

// Define the constructor
ScheduleItem::ScheduleItem(
    std::string subj, std::string cat, std::string sec,
    std::string comp, std::string sess, int unit,
    int totEn, int capEn, std::string instr)
    : subject(subj), catalog(cat), section(sec), component(comp),
    session(sess), units(unit), totEnrl(totEn), capEnrl(capEn), instructor(instr) {}

// Getter methods
std::string ScheduleItem::getKey() const {
    return subject + "_" + catalog + "_" + section;
}

std::string ScheduleItem::getSubject() const {
    return subject;
}

std::string ScheduleItem::getCatalog() const {
    return catalog;
}

std::string ScheduleItem::getSection() const {
    return section;
}

std::string ScheduleItem::getInstructor() const {
    return instructor;
}

int ScheduleItem::getUnits() const {
    return units;
}

int ScheduleItem::getTotEnrl() const {
    return totEnrl;
}

int ScheduleItem::getCapEnrl() const {
    return capEnrl;
}

// Overloaded operators
bool ScheduleItem::operator==(const ScheduleItem& other) const {
    return this->getKey() == other.getKey();
}

bool ScheduleItem::operator!=(const ScheduleItem& other) const {
    return !(*this == other);
}

bool ScheduleItem::operator>=(const ScheduleItem& other) const {
    return this->getKey() >= other.getKey();
}

// Print method
void ScheduleItem::print() const {
    std::cout << subject << " " << catalog << " " << section << " "
        << component << " " << session << " " << units << " "
        << totEnrl << " " << capEnrl << " " << instructor << "\n";
}
