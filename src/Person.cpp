//
// Created by Gaby on 8/2/2024.
//

#include "Person.h"

Person::Person() {};

//Person::Person(string namePerson, string idPerson){}
Person::Person(const string &namePerson, const string &idPerson) : name(namePerson), id(idPerson) {}
Person::~Person() {};

//string Person::getName(){ return name; }
//string Person::getID(){ return id; }

string Person::getName() const {
    return name;
}

string Person::getID() const {
    return id;
}

void Person::setName(string namePerson) {
    name = namePerson;
}

void Person::setID(string idPerson) {
    id = idPerson;
}
