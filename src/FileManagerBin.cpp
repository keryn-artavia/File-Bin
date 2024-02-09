//
// Created by Gaby on 8/2/2024.
//

#include "FileManagerBin.h"

void FileManagerBin::saveStudent(const Student &student, const string &fileName) {

    // Create and open a binary file
    ofstream myFile(fileName, ios::binary);

    // Write to the file
    write(myFile, student);

    // Close the file
    myFile.close();
}

Student FileManagerBin::readDataStudent(const string &fileName) {

    // Create file variable
    Student student;

    // Read from the text file
    ifstream myReadFile(fileName, ios::binary);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + fileName + "]");
    }

    // Read the binary file
    myReadFile.seekg (0);
    read(myReadFile, student);

    // Close the file
    myReadFile.close();

    return student;
}

void FileManagerBin::saveStudentsList(const vector<Student> &studentsList, const string &fileName) {

    // Create and open a binary file
    ofstream myFile(fileName, ios_base::binary);

    // Write to the file
    for (auto &student : studentsList) {
        write(myFile, student);
    }

    // Close the file
    myFile.close();
}

vector<Student> FileManagerBin::readDataStudentsList(const string &fileName) {

    // Create file variable
    vector<Student> studentsList;
    Student student;

    // Read from the text file
    ifstream myReadFile(fileName, ios::binary);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + fileName + "]");
    }

    // Read the binary file
    // myReadFile.seekg (sizeof(physicalProduct),ios::beg);  // Reading the last value
    myReadFile.seekg (0);
    while(myReadFile.good()){
        read(myReadFile, student);
        if (student.getName() != "") {
            studentsList.push_back(student);
        }
    }

    // Close the file
    myReadFile.close();

    return studentsList;
}

ostream &FileManagerBin::write(ostream &out, const Student &student) {
    string name = student.getName();
    string id = student.getID();

    size_t len = name.size();
    out.write((char*)&len, sizeof(len));
    out.write(name.c_str(), len);

    len = id.size();
    out.write((char*)&len, sizeof(len));
    out.write(id.c_str(), len);

    return out;
}

istream &FileManagerBin::read(istream &in, Student &student) {
    string name, id;
    size_t len = 0;

    in.read((char*)&len, sizeof(len));
    name.resize(len);
    in.read(&name[0], len);
    student.setName(name);

    len = 0;
    in.read((char*)&len, sizeof(len));
    id.resize(len);
    in.read(&id[0], len);
    student.setID(id);

    return in;
}