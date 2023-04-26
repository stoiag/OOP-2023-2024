//
// Created by Darius on 4/12/2023.
//
#include "Student.h"
#include <string.h>
#ifndef STUDENT_BURSIER_H
#define STUDENT_BURSIER_H

class StudentBursier : public Student {
private:
    char* IBAN;
public:
    StudentBursier(): Student() {
        this->IBAN = new char[256];
    };
    StudentBursier(const char* name, int age, const char* IBAN): Student(name, age) {
        this->IBAN = new char[strlen(IBAN) + 1];
        strcpy_s(this->IBAN, strlen(IBAN) + 1, IBAN);
    };
    StudentBursier(const StudentBursier& s): Student(s) {
        this->IBAN = new char[strlen(s.IBAN) + 1];
        strcpy_s(this->IBAN, strlen(s.IBAN) + 1, s.IBAN);
    };
    ~StudentBursier() {
        cout << "Destructor student bursier" << endl;
        if (this->IBAN) delete[] this->IBAN;
    }
    char* getIBAN() {
        return this->IBAN;
    };
    void setIBAN(char* newIBAN) {
        if (this->IBAN)
            delete[] this->IBAN;
        this->IBAN = new char[strlen(newIBAN) + 1];
        strcpy_s(this->IBAN, strlen(newIBAN) + 1, newIBAN);
    }
    //IO operators
    friend istream& operator>>(istream& is, StudentBursier& s) {
        //cout << "Citim studentul";
        char* name = new char[10];
        is >> name;
        s.setName(name);
        is >> s.age;
        char* IBAN = new char[256];
        is >> IBAN;
        s.setIBAN(IBAN);
        cout << "Student bursier citit: " << s.name << " " << s.age << " " << s.IBAN << endl;

        delete[] name;
        delete[] IBAN;
        return is;
    }

    //IO operators
    friend ostream& operator<<(ostream& os, StudentBursier& s) {
        os << "Student bursier: " << s.name << " " << s.age << " " << s.IBAN << endl;
        return os;
    }
};
#endif //SEM4_STUDENT_BURSIER_H