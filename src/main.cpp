//
// Created by Maikol Guzman on 22/11/23.
//

#include "FileManagerBin.h"

int main() {
        // Clear console screen for Windows or Linux
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

        cout << endl;
        cout << "BINARY FILES EXAMPLE" << endl << endl;

    try {
        srand(time(NULL));

        Student student1;
        student1.setName("Ana");
        student1.setID("100");
        student1.setCourse("Course 1");
        student1.setGrade(70.0);

        Student student2;
        student2.setName("Bob");
        student2.setID("200");
        student2.setCourse("Course 2");
        student2.setGrade(80.0);

        Student student3;
        student3.setName("Carlos");
        student3.setID("300");
        student3.setCourse("Course 2");
        student3.setGrade(90.0);

        // Manager SRP
        FileManagerBin fileManager;

        // This function will save the information of the Student in a file with the name studentsCourse1.dat
        fileManager.saveStudent(student1, "studentsCourse1.dat");

        // This function reads a binary file
        Student studentData = fileManager.readDataStudent("studentsCourse1.dat");

        cout << "[FILE BINARY READ]" << endl << endl;
        cout << studentData << endl;

        vector<Student> studentsList;
        studentsList.push_back(student1);
        studentsList.push_back(student2);
        studentsList.push_back(student3);

        // This function will save the information of the Student in a file with the name studentsCourse2.dat
        fileManager.saveStudentsList(studentsList, "studentsCourse2.dat");

        // This function reads a binary file
        vector<Student> studentsListData = fileManager.readDataStudentsList("studentsCourse2.dat");

        cout << endl;
        cout << "[FILE BINARY READ WITH VECTOR]" << endl << endl;
        for (const auto &student : studentsListData) {
            cout << student << std::endl;
        }
    } catch (exception& ex) {
        cerr << ex.what() << '\n' << std::endl;
    }

    cout << endl;

    return 0;
}