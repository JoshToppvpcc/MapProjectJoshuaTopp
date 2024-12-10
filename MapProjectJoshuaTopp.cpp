// MapProjectJoshuaTopp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Schedule.h"
#include <fstream>
#include <iostream>

int main() {
    Schedule schedule;
    std::ifstream file("data.csv");

    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    schedule.initSchedule(file);
    file.close();

    int choice;
    std::string input1, input2;
    do {
        std::cout << "\nMenu:\n"
            << "1. Print all records\n"
            << "2. Find by Subject\n"
            << "3. Find by Subject and Catalog\n"
            << "4. Find by Instructor Last Name\n"
            << "5. Exit\n"
            << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            schedule.print();
            break;
        case 2:
            std::cout << "Enter Subject: ";
            std::cin >> input1;
            schedule.findBySubject(input1);
            break;
        case 3:
            std::cout << "Enter Subject: ";
            std::cin >> input1;
            std::cout << "Enter Catalog: ";
            std::cin >> input2;
            schedule.findBySubjectCatalog(input1, input2);
            break;
        case 4:
            std::cout << "Enter Instructor's Last Name: ";
            std::cin >> input1;
            schedule.findByInstructor(input1);
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
