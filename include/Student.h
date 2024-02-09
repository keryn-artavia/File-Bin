//
// Created by Gaby on 8/2/2024.
//

#ifndef MAIN_STUDENT_H
#define MAIN_STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    string course;
    double grade;
    double weight;

public:
    Student();
    Student(const string &course, double grade);

    string getCourse() const;
    void setCourse(const string &course);

    double getGrade() const;
    void setGrade(double grade);

    friend ostream& operator<<(ostream& os, const Student &student);

    string toString() const;
};

#endif //MAIN_STUDENT_H
