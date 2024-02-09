//
// Created by Gaby on 8/2/2024.
//

#ifndef MAIN_FILEMANAGERBIN_H
#define MAIN_FILEMANAGERBIN_H

#include "Student.h"

class FileManagerBin {
public:
    static void saveStudent(const Student &student, const string &fileName);

    static Student readDataStudent(const string &fileName);

    static void saveStudentsList(const vector<Student>& studentsList, const string &fileName);

    static vector<Student> readDataStudentsList(const string &fileName);

    static ostream& write(ostream& out, const Student &student);

    static istream& read(istream& in, Student &student);

};


#endif //MAIN_FILEMANAGERBIN_H
