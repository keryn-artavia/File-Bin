//
// Created by Gaby on 8/2/2024.
//

#ifndef MAIN_FILEMANAGERBIN_H
#define MAIN_FILEMANAGERBIN_H


#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Student.h"

class FileManagerBin {
public:
    static void saveStudent(Student& student, const string &fileName);

    static Student readDataStudent(const string &fileName);

    static void saveStudentList(vector<Student>& studentsList, const string &fileName);

    static vector<Student> readDataStudentsList(const string &fileName);

    static ostream& write(ostream& out, Student &student);

    static istream& read(istream& in, Student &student);

};


#endif //MAIN_FILEMANAGERBIN_H
