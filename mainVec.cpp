// v0.1 with vectors
#include "myLib.h"

struct student {
    string      name,
                surname;
    vector<int> grade;
    int         exam;
};
int randomizer(int beg, int end) { // interval beginning and ending
    return beg + (double)rand() / RAND_MAX * (end - beg + 1);
}
void input(student &tmp) {
    string opt;     // option
    int    grd,     // generated grade
           sum = 0, // sum of entered grades
           cnt = 0; // counter
    cout << "Enter the student's name and surname: "; cin >> tmp.name >> tmp.surname;
    cout << "Would you like to randomize the grades (type 'ran') or enter yourself? (any key to continue): "; cin >> opt;
    if(opt == "ran") {
        randomizer(0, 100); // tmp.exam always stays the same without this
        tmp.exam = randomizer(1, 10); // generated grade in a ten point system without 0 (student must participate in an exam)
        cout << "The exam grade: " << tmp.exam << endl;
        cnt = randomizer(1, 100); // maximum of 100 grades per student
        cout << "The grades: ";
        for(int i = 0; i < cnt; i ++) {
            grd = randomizer(0, 10); // generated grade in a ten point system with 0 (student may not submit his homework)
            tmp.grade.push_back(grd);
            sum += grd; // if sum equals 0 - error
            cout << grd << " ";
        }
        if(sum == 0) {
            cout << "0" << endl;
            cout << "RANDOMIZER ERROR: division by zero is not possible." << endl;
            input(tmp); // recursion
        }
        cout << endl;
    }
    else {
        cout << "Enter the exam grade: "; cin >> tmp.exam;
        while(cin.fail() || (tmp.exam < 0 || tmp.exam > 10)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Incorrect form. Try again: "; cin >> tmp.exam;
        }
        cout << "Enter the grades (any other symbol to stop): ";
        while(cin >> grd && (grd >= 0 && grd <= 10)) {
            if(cnt >= 100) {
                cout << "You can enter a maximum of 100 grades per student." << endl;
                break;
            }
            tmp.grade.push_back(grd);
            sum += grd;
            cnt ++;
        }
        if(cnt != 0) cout << "In total " << cnt << " grades entered." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(tmp.grade.size() == 0 || sum == 0) {
            cout << "At least one grade that is not a symbol and higher than 0 must be entered! Try from the beginning." << endl;
            input(tmp); // recursion
        }
    }
}
double medium(student &tmp) {
    int sum = 0;
    for(int i = 0; i < tmp.grade.size(); i ++) {
        sum += tmp.grade[i];
    }
    return 0.4 * (sum / (double)tmp.grade.size()) + 0.6 * tmp.exam;
}
double median(student &tmp) {
    bool srt = true; // bubble sort
    while(srt)
    {
        srt = false;
        for(int i = 0; i < tmp.grade.size() - 1; i ++) {
            if(tmp.grade[i] > tmp.grade[i + 1]) {
                swap(tmp.grade[i], tmp.grade[i + 1]);
                srt = true;
            }
        }
    }
    // sort(tmp.grade.begin(), tmp.grade.end());
    if(tmp.grade.size() % 2 == 0) return 0.4 * ((tmp.grade[tmp.grade.size() / 2 - 1] + tmp.grade[tmp.grade.size() / 2]) / 2.0) + 0.6 * tmp.exam;
    else return 0.4 * tmp.grade[tmp.grade.size() / 2] + 0.6 * tmp.exam;
}
void output(student &tmp, string opt) {
    if(opt == "vid") {
        cout << setw(10) << left << tmp.name << setw(14) << left << tmp.surname << setw(19) << left << fixed << setprecision(2) << medium(tmp) << "-" << endl;
    }
    else cout << setw(10) << left << tmp.name << setw(14) << left << tmp.surname << setw(19) << left << fixed << setprecision(2) << "-" << median(tmp) << endl;
}
int main() {
    srand(time(NULL));
    vector<student> arr; // array
    student         tmp; // temp
    string          req, // request
                    opt; // option
    //----------PERMANENT INPUT----------
    do {
        input(tmp);
        arr.push_back(tmp);
        tmp.grade.clear();
        cout << "Enter 'end' if all students are entered or any key to continue: "; cin >> req;
    } while(req != "end");
    //----------END OF THE PROGRAM----------
    while(opt != "vid" && opt != "med") {
        cout << "How would you like to calculate the final mark? Type 'vid' or 'med': "; cin >> opt;
    }
    cout << "-----------------------------------------------------------" << endl;
    cout << left << setw(10) << "Vardas" << left << setw(14) << "Pavarde" << left << setw(12) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------" << endl;
    //----------FINAL OUTPUT----------
    for(int i = 0; i < arr.size(); i ++) {
        output(arr[i], opt);
    }
    //----------FREE UP THE MEMORY----------
    for(int i = 0; i < arr.size(); i ++) {
        arr[i].grade.clear();
    }
    arr.clear();

    return 0;
}