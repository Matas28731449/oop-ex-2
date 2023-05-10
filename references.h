#ifndef REFERENCES_H
#define REFERENCES_H

#include "library.h"

const int max = 100;

class person {
    protected:
        string name,
               surname;
        person() : name(""), surname("") { }
        person(string a, string b) { name = a; surname = b; }
        virtual ~person() { name.clear(); surname.clear(); }
};

class student : public person {
    private:
        vector<int> grade;
        int         exam;
        float       medium,
                    median;
    public:
        student() : exam(0), medium(0), median(0) { }

        //! Get student's name.
        inline string getName() const { return name; }
        //! Get student's surname.
        inline string getSurname() const { return surname; }
        //! Get student's grades.
        inline vector<int> getGrade() const { return grade; }
        //! Get student's exam mark.
        inline int getExam() const { return exam; }
        //! Get student's final mark (calculated by medium).
        inline double getMedium() const { return medium; }
        //! Get student's final mark (calculated by median).
        inline double getMedian() const { return median; }

        //! Set student's name.
        void setName(string a) { name = a; }
        //! Set student's surname.
        void setSurname(string a) { surname = a; }
        //! Set student's grade.
        void setGrade(int a);
        //! Clear all student's grades.
        void clearGrade() { grade.clear(); }
        //! Set student's exam mark.
        void setExam(int a) { exam = a; }
        //! Set student's final mark (calculated by medium).
        void setMedium(double a) { medium = a; }
        //! Set student's final mark (calculated by median).
        void setMedian(double a) { median = a; }

        student(const student &other) : person(other.name, other.surname) {
            this->grade = std::move(other.grade);
            this->exam = other.exam;
            this->medium = other.medium;
            this->median = other.median;
        }
        student(student &&other) : person(other.name, other.surname) {
            this->grade = std::move(other.grade);
            this->exam = other.exam;
            this->medium = other.medium;
            this->median = other.median;
        }
        student &operator=(const student &other) {
            if(this != &other) {
                this->name = other.name;
                this->surname = other.surname;
                this->grade = std::move(other.grade);
                this->exam = other.exam;
                this->medium = other.medium;
                this->median = other.median;
            }
            return *this;
        }
        student &operator=(student &&other) {
            if(this != &other) {
                this->name = other.name;
                this->surname = other.surname;
                this->grade = std::move(other.grade);
                this->exam = other.exam;
                this->medium = other.medium;
                this->median = other.median;
                other.~student();
            }
            return *this;
        }
        ~student() { clearGrade(); }
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