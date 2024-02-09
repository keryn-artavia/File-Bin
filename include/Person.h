//
// Created by Gaby on 8/2/2024.
//

#ifndef MAIN_PERSON_H
#define MAIN_PERSON_H

#include "IPerson.h"

class Person: public IPerson {
private:
    string name;
    string id;

public:
    Person();
    //virtual ~Person();

    string getName() const;
    void setName(const string &name);

    string getID() const;
    void setID(const string &id);
};

#endif //MAIN_PERSON_H
