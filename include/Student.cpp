//
// Created by Gaby on 8/2/2024.
//

#include "Student.h"

Student::Student(){
    course = "";
    note = 0.0;
    weight = 0.0;

}
Student::Student(string namePerson, string idPerson)
        :Person(namePerson, idPerson) {}


Student::~Student(){};


string Student::getCourse() { return course; }
double Student::getWeight() { return weight; }
double Student::getNoteCourse() { return note; }

void Student::setCourse(string courseStudent) { course = courseStudent; }
void Student::setWeight(double weightStudent) { weight = weightStudent; }
void Student::setNoteCourse(double noteStudent) { note = noteStudent; }


string Student::toString(){
    stringstream s;

    s << "Name: " << name << endl
      << "ID: " << id << endl
      << "Course: " << course << endl
      << "Note: " << note << endl
      << "Weight: " << endl;

    return s.str();
}
