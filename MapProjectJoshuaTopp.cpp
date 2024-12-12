// main.cpp
#include "Schedule.h"
#include <iostream>

int main() {
    Schedule schedule;
    schedule.loadFromFile("Cdata.txt");

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Print all records\n";
        std::cout << "2. Find by Subject\n";
        std::cout << "3. Find by Subject and Catalog\n";
        std::cout << "4. Find by Instructor Last Name\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            schedule.printAll();
            break;
        case 2: {
            std::string subject;
            std::cout << "Enter Subject: ";
            std::cin >> subject;
            schedule.findBySubject(subject);
            break;
        }
        case 3: {
            std::string subject, catalog;
            std::cout << "Enter Subject: ";
            std::cin >> subject;
            std::cout << "Enter Catalog: ";
            std::cin >> catalog;
            schedule.findBySubjectAndCatalog(subject, catalog);
            break;
        }
        case 4: {
            std::string lastName;
            std::cout << "Enter Instructor Last Name: ";
            std::cin >> lastName;
            schedule.findByInstructorLastName(lastName);
            break;
        }
        case 5:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
