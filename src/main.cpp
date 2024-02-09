//
// Created by Maikol Guzman on 22/11/23.
//
#include <iostream>
#include <cstdlib>

#include "FileManagerBin.h"


int main() {
        // Clear console screen for Windows or Linux
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "Archivos binarios" << std::endl;

    try {
        srand (time(NULL));

        Student student1;
        student1.setName("Ana");
        student1.setID("100");
        student1.setCourse("Course 1");
        student1.setNoteCourse(0);

        Student student2;
        student2.setName("Bob");
        student2.setID("200");
        student2.setCourse("Course 2");
        student2.setNoteCourse(0);

        Student student3;
        student3.setName("Carlos");
        student3.setID("300");
        student3.setCourse("Course 2");
        student3.setNoteCourse(0);

        // Manager SRP
        FileManagerBin fileManager;

        // This function will saveStudent the information of the
        // Student in a file with the name studentsCourse1.dat
        fileManager.saveStudent(student1, "studentsCourse1.dat");

        // This function read a binary file
        Student studentData = fileManager.readDataStudent("studentsCourse1.dat");

        cout << "[FILE BINARY READ]" << endl;
        cout << studentData << endl;

        vector<Student> studentsList;
        studentsList.push_back(student1);
        studentsList.push_back(student2);
        studentsList.push_back(student3);

        // This function will saveStudent the information of the
        // Student in a file with the name studentsCourse.dat
        fileManager.saveStudentsList(studentsList, "studentsCourse2.dat");

        // This function read a binary file
        vector<Student> studentsListData = fileManager.readDataStudentList("studentsCourse2.dat");

        cout << "[FILE BINARY READ WITH VECTOR]" << endl;
        for (auto &student : studentsListData) {
            cout << student << endl;
        }
    } catch (exception& ex) {
        cerr << ex.what() << '\n' << std::endl;
    }

    std::cout << std::endl;
    return 0;
}