//
// Created by Gaby on 8/2/2024.
//

#ifndef MAIN_STUDENT_H
#define MAIN_STUDENT_H

#include "Person.h"

class Student: public Person{
private:
    string course;
    double weight;   // ponderado
    double note;

public:
    Student();
    Student(string namePerson, string idPerson);
    virtual ~Student();


    string getCourse();
    double getWeight();
    double getNoteCourse();

    void setCourse(string courseStudent);
    void setWeight(double weightStudent);
    void setNoteCourse(double noteStudent);

    virtual string toString();

};


#endif //MAIN_STUDENT_H
