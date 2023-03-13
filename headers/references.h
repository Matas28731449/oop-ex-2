#ifndef REFERENCES_H
#define REFERENCES_H

#include "library.h"

const int max = 100;

struct student {
    string      name,
                surname;
    vector<int> grade;
    int         exam;
    double      medium,
                median;
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