//
// Created by Gaby on 8/2/2024.
//

#ifndef MAIN_PERSON_H
#define MAIN_PERSON_H


#include "IPerson.h"

using namespace std;

class Person: public IPerson {
protected:
    string name;
    string id;


public:
    Person();
    //Person(const string& namePerson, const string& idPerson);
    Person(const string& namePerson, const string& idPerson);
    virtual ~Person();

    //string getName();
    //string getID();
    string getName() const;
    string getID() const;


    void setName(string namePerson);
    void setID(string idPerson);

    virtual string toString() = 0;
};


#endif //MAIN_PERSON_H
