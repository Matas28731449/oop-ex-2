#ifndef REFERENCES_H
#define REFERENCES_H

#include "library.h"

const int max = 100;

class student {
    private:
        string      name,
                    surname;
        vector<int> grade;
        int         exam;
        double      medium,
                    median;
    public:
        student() : name(""), surname(""), exam(0), medium(0), median(0) { }
        // getters
        inline string getName() const { return name; }
        inline string getSurname() const { return surname; }
        inline vector<int> getGrade() const { return grade; }
        inline int getExam() const { return exam; }
        inline double getMedium() const { return medium; }
        inline double getMedian() const { return median; }
        // setters
        void setName(string a) { name = a; }
        void setSurname(string a) { surname = a;}
        void setGrade(int a);
        void clearGrade() { grade.clear(); }
        void setExam(int a) { exam = a; }
        void setMedium(double a) { medium = a; }
        void setMedian(double a) { median = a; } 
};

void input(vector<student> &arr, string &opt);
void output(vector<student> &arr, string tmp);
void fileInput(vector<student> &arr);
void userInput(student &tmp);
void randInput(student &tmp);
double medium(student &tmp);
double median(student &tmp);
bool comparison(student &a, student &b);
int randomize(int beg, int end);
void fileGenerator();

#endif