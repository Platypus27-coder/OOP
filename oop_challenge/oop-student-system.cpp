#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
using namespace std;

class Account {
private: 
    string user_name, password;
public:
    Account() {
        user_name = password = "";
    }
    void setName(string name) {
        this->user_name = name;
    }
    string getName() {
        return this->user_name;
    }
    void setPassword(string password) {
        this->password = password;
    }
    string getPassword() {
        return this->password;
    } 
};

class Date {
private:
    string Day , Month, Year;
public:
    Date() {
        Day = Month = Year = "";
    }
    Date(string Day, string Month, string Year) {
        this->Day = Day;
        this->Month = Month;
        this->Year = Year;
    }
    void setDay(string Day) {
        this->Day = Day;
    }
    string getDay() {
        return this->Day;
    }
    void setMonth(string Month) {
        this->Month = Month;
    } 
    string getMonth() {
        return this->Month;
    }
    void setYear(string Year) {
        this->Year = Year;
    }
    string getYear() {
        return this->Year;
    }
};

class Person {
private:
    string name, age, address;
    Date DateOfBirth;
public:
    Person(string name, string age, string address, Date DateOfBirth) {
        this->name = name;
        this->age = age;
        this->address = address;
        this->DateOfBirth = DateOfBirth;
    }
    void out() {
        cout << name << " " << age << " " << address << " " << DateOfBirth.getDay() << " " << DateOfBirth.getMonth() << " " << DateOfBirth.getYear() << endl;
    }
    string getName() {
        return this->name;
    }
    Date getDate() {
        return this->DateOfBirth;
    }
    string getAddress() {
        return this->address;
    }   
};

class Student : public Person {
private:
    string ID, class_student, email, email_pass_word;
    Account Acc;
    double gpa;
public:
    Student(string name, string age, string address, Date DateOfBirth, string ID, string class_student, double gpa) : Person(name, age, address, DateOfBirth) {
        this->ID = ID;
        this->class_student = class_student;
        this->gpa = gpa;
    }
    void setEmail() {
        string tmp = Person::getName();
        vector<string> v;
        stringstream ss(tmp);
        string word;
        while(ss >> word) {
            v.push_back(word);
        }
        string res = "";
        v[v.size() - 1][0] = tolower(v[v.size() - 1][0]);
        res += v[v.size() - 1];
        for (int i = 0; i < v.size() - 1; i++) {
            res += tolower(v[i][0]);
        }
        res += "@ptit.edu.vn";
        email = res;
    }
    void setPassWord() {
        string tmp = Person::getName();
        string res = "";
        stringstream ss(tmp);
        string word ;
        while(ss >> word) {
            res += word;
        }
        for (int i = 0; i < res.size(); i++) {
            res[i] = tolower(res[i]);
        }
        string tmp1 = ID;
        for (int i = 0; i < ID.size(); i++) {
            tmp1[i] = tolower(tmp1[i]);
        }
        res += tmp1;
        res += "@";
        email_pass_word = res;
    }
    void print() {
        Person::out();
        cout << email << " " << email_pass_word << " " << gpa << " " << ID << " " << class_student << endl;
        cout << Acc.getName() << " " << Acc.getPassword() << endl;
    }
    void setID(string newID) {
        this->ID = newID;
    }
    string getID() {
        return this->ID;
    }
    void setAcount() {
        Date x = Person::getDate();
        string tmp = "";
        tmp += x.getDay() + x.getMonth() + x.getYear() + "@";
        string tmp2 = Person::getName();
        string user = "";
        for (char c : tmp2) {
            if (c != ' ') user += toupper(c);
        }  
        Acc.setName(user);
        Acc.setPassword(tmp);
    }

};

int main() {
    Date exp("15", "01", "2001");
    Student x = Student("Nguyen Quang Huy", "24", "Kien Xuong, Thai Binh", exp, "B19DVT305", "B19VT03", 2.85);
    x.setEmail();
    x.setPassWord();
    x.setAcount();
    x.print();
    return 0;
}
