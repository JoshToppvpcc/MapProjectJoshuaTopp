// ScheduleItem.cpp
#include "ScheduleItem.h"

ScheduleItem::ScheduleItem(const std::string& subj, const std::string& cat, const std::string& sec,
    const std::string& comp, const std::string& instrLastName)
    : subject(subj), catalog(cat), section(sec), component(comp), instructorLastName(instrLastName) {}

std::string ScheduleItem::getSubject() const { return subject; }
std::string ScheduleItem::getCatalog() const { return catalog; }
std::string ScheduleItem::getSection() const { return section; }
std::string ScheduleItem::getInstructorLastName() const { return instructorLastName; }

std::string ScheduleItem::toString() const {
    std::ostringstream oss;
    oss << std::left << std::setw(8) << subject << std::setw(8) << catalog << std::setw(8) << section
        << std::setw(12) << component << std::setw(15) << instructorLastName;
    return oss.str();
}
