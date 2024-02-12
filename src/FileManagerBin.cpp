//
// Created by Gaby on 8/2/2024.
//

#include "FileManagerBin.h"

using namespace std;


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

    ofstream file(fileName, ios::binary);

    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& student : studentsList) {
        write(file, student);
    }
}

vector<Student> FileManagerBin::readDataStudentsList(const string &fileName) {

    vector<Student> studentsList;

    ifstream file(fileName, ios::binary);
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return studentsList;
    }

    Student student;

    while (read(file, student)) {
        studentsList.push_back(student);
    }
    return studentsList;
}

ostream &FileManagerBin::write(ostream &out, const Student &student) {

    // Serialize each member of Student individually

    // Name
    const string& name = student.getName();
    size_t len = name.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(name.data(), len);

    // ID
    const string& id = student.getID();
    len = id.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(id.data(), len);

    // Course
    const string& course = student.getCourse();
    len = course.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(course.data(), len);

    // Grade
    double grade = student.getGrade();
    out.write(reinterpret_cast<const char*>(&grade), sizeof(grade));

    return out;
}

istream &FileManagerBin::read(istream &in, Student &student) {

    // Deserialize each member of Student individually

    size_t len = 0;
    string temp;

    // Name
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    temp.resize(len);
    in.read(&temp[0], len);
    student.setName(temp);

    // ID
    len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    temp.resize(len);
    in.read(&temp[0], len);
    student.setID(temp);

    // Course
    len = 0;
    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    temp.resize(len);
    in.read(&temp[0], len);
    student.setCourse(temp);

    // Grade
    double grade = 0;
    in.read(reinterpret_cast<char*>(&grade), sizeof(grade));
    student.setGrade(grade);

    return in;
}