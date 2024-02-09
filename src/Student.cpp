//
// Created by Gaby on 8/2/2024.
//

#include "Student.h"

Student::Student() {
    course = "";
    grade = 0.0;
    weight = 0.0;
}

string Student::getCourse() const {
    return course;
}

void Student::setCourse(const string &courseStudent) {
    this->course = courseStudent;
}

double Student::getGrade() const {
    return grade;
}

void Student::setGrade(double gradeStudent) {
    this->grade = gradeStudent;
}

ostream& operator<<(ostream& os, const Student &student) {
    os << "Name: " << student.getName() << ", ID: " << student.getID() << ", Course: " << student.getCourse() << ", Grade: " << student.getGrade();
    return os;
}

/*
string Student::toString() const {
    return "Name: " + getName() + ", ID: " + getID() + ", Course: " + course + ", Grade: " + to_string(grade);
}*/

string Student::toString() const {
    stringstream ss;
    ss << (*this);
    return ss.str();
}