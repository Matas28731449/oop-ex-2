// v0.1 with vectors
#include "myLib.h"

struct student {
    string      name,
                surname;
    vector<int> grade;
    int         exam;
};
int randomize(int beg, int end) { // beginning, ending
    mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dis(beg, end);
    return dis(mt);
}
void input(student &tmp) {
    string opt;     // option
    int    grd,     // generated grade
           sum = 0, // sum of entered grades
           cnt = 0; // counter
    cout << "Enter the student's name and surname: "; cin >> tmp.name >> tmp.surname;
    cout << "Would you like to randomize the grades (type 'ran') or enter yourself? (any key to continue): "; cin >> opt;
    if(opt == "ran") {
        tmp.exam = randomize(1, 10); // generated grade in a ten point system without 0 (student must participate in an exam)
        cout << "The exam grade: " << tmp.exam << endl;
        cnt = randomize(1, max);
        tmp.grade.reserve(cnt);
        cout << "The grades: ";
        for(int i = 0; i < cnt; i ++) {
            grd = randomize(0, 10); // generated grade in a ten point system with 0 (student may not submit his homework)
            tmp.grade.push_back(grd);
            i != cnt - 1 ? cout << grd << " " : cout << grd << endl;
        }
    }
    else {
        cout << "Enter the exam grade: "; cin >> tmp.exam;
        while(cin.fail() || tmp.exam < 0 || tmp.exam > 10) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Incorrect form. Try again: "; cin >> tmp.exam;
        }
        tmp.grade.reserve(max);
        cout << "Enter the grades (any other symbol to stop): ";
        while(cin >> grd && grd >= 0 && grd <= 10) {
            if(tmp.grade.size() >= max) {
                cout << "You can enter a maximum of " << max << " grades per student." << endl;
                break;
            }
            tmp.grade.push_back(grd);
            sum += grd;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(sum == 0) {
            cout << "At least one grade that is not a symbol and higher than 0 must be entered! Try from the beginning." << endl;
            tmp.grade.clear();
            input(tmp); // recursion
        }
        else cout << "In total " << tmp.grade.size() << " grades entered." << endl;
    }
}
double medium(student &tmp) {
    int sum = 0;
    for(int i = 0; i < tmp.grade.size(); i ++) {
        sum += tmp.grade[i];
    }
    return 0.4 * ((double)sum / tmp.grade.size()) + 0.6 * tmp.exam;
}
double median(student &tmp) {
    vector<int> grd = tmp.grade; // temporary copy of grades
    sort(grd.begin(), grd.end());
    return grd.size() % 2 == 0 ? 0.4 * ((grd[grd.size() / 2 - 1] + grd[grd.size() / 2]) / 2.0) + 0.6 * tmp.exam : 0.4 * grd[grd.size() / 2] + 0.6 * tmp.exam;
}
void output(student &tmp, string opt) {
    opt == "vid" ? cout << setw(10) << left << tmp.name << setw(14) << left << tmp.surname << setw(19) << left << fixed << setprecision(2) << medium(tmp) << "-" << endl : cout << setw(10) << left << tmp.name << setw(14) << left << tmp.surname << setw(19) << left << fixed << setprecision(2) << "-" << median(tmp) << endl;
}
int main() {
    vector<student> arr; // array
    student         tmp; // temporary
    string          req, // request
                    opt; // option
    //----------INPUT----------
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
    //----------OUTPUT----------
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
