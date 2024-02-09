//
// Created by Gaby on 8/2/2024.
//

#include "Person.h"

Person::Person() {
    name = "";
    id = "";
}

//Person::~Person() {}

string Person::getName() const {
    return name;
}

void Person::setName(const string &namePerson) {
    this->name = namePerson;
}

string Person::getID() const {
    return id;
}

void Person::setID(const string &idPerson) {
    this->id = idPerson;
}
