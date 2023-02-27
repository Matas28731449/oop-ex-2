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
bool comparison(student &a, student &b) {
    return a.surname == b.surname ? a.surname < b.surname : a.name < b.name;
}
void output(vector<student> &arr, string tmp) {
    string opt = " ";
    //----------END OF THE PROGRAM----------
    while(opt != "vid" && opt != "med") {
        cout << "How would you like to calculate the final mark? Type 'vid' or 'med': "; cin >> opt;
    }
    //----------OUTPUT IN CONSOLE----------
    if(tmp == "in") {
        cout << "-----------------------------------------------------------\n";
        cout << left << setw(10) << "Vardas" << left << setw(14) << "Pavarde" << left << setw(12) << "Galutinis (Vid.) / Galutinis (Med.)\n";
        cout << "-----------------------------------------------------------\n";
        for(int i = 0; i < arr.size(); i ++) {
            opt == "vid" ? cout << setw(10) << left << arr[i].name << setw(14) << left << arr[i].surname << setw(19) << left << fixed << setprecision(2) << medium(arr[i]) << "-\n" : cout << setw(10) << left << arr[i].name << setw(14) << left << arr[i].surname << setw(19) << left << fixed << setprecision(2) << "-" << median(arr[i]) << "\n";
        }
    }
    //----------OUTPUT IN FILE----------
    else if(tmp == "rf") {
        cout << "Sorting data...\n";
        auto start = std::chrono::high_resolution_clock::now();
        sort(arr.begin(), arr.end(), comparison);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference = end - start;
        cout << "finished in: " << difference.count() << " s\n";
        cout << "Writing data...\n";
        start = std::chrono::high_resolution_clock::now();
        ofstream out("write/results.txt");
        out << "-------------------------------------------------------------------\n";
        out << left << setw(14) << "Vardas" << left << setw(18) << "Pavarde" << left << setw(16) << "Galutinis (Vid.) / Galutinis (Med.)\n";
        out << "-------------------------------------------------------------------\n";
        for(int i = 0; i < arr.size(); i ++) {
            opt == "vid" ? out << setw(14) << left << arr[i].name << setw(18) << left << arr[i].surname << setw(19) << left << fixed << setprecision(2) << medium(arr[i]) << "-\n" : out << setw(14) << left << arr[i].name << setw(18) << left << arr[i].surname << setw(19) << left << fixed << setprecision(2) << "-" << median(arr[i]) << "\n";
        }
        out.close();
        end = std::chrono::high_resolution_clock::now();
        difference = end - start;
        cout << "finished in: " << difference.count() << " s\n";
    }
}
void fileInput(vector<student> &arr) {
    student tmp;
    string  row,
            req;
    int     grd;

    cout << "Enter the name of the file to read from: "; cin >> req;
    ifstream in("read/" + req);
    if(in.fail()) cout << "File not found. Program may fail!\n"; // must use exception handling in v0.3!
    cout << "Reading data...\n";
    auto start = std::chrono::high_resolution_clock::now();
    getline(in, row); // reading just the first line of the data file
    int cnt = count(row.begin(), row.end(), 'N'); // searching for the amount of homework
    tmp.grade.reserve(cnt);
    arr.reserve(1000000);
    while(in) {
        if(!in.eof()) {
            in >> tmp.name >> tmp.surname;
            for(int i = 0; i < cnt; i ++) {
                in >> grd;
                tmp.grade.push_back(grd);
            }
            in >> tmp.exam;
            arr.push_back(tmp);
            tmp.grade.clear();
        }
        else break;
    }
    in.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    cout << "finished in: " << difference.count() << " s\n";
}
void randInput(student &tmp) {
    int cnt = 0, // counter
        grd = 0; // generated grade
    tmp.exam = randomize(1, 10); // generated grade in a ten point system without 0 (student must participate in an exam)
    cout << "The exam grade: " << tmp.exam << "\n";
    cnt = randomize(1, max);
    tmp.grade.reserve(cnt);
    cout << "The grades: ";
    for(int i = 0; i < cnt; i ++) {
        grd = randomize(0, 10); // generated grade in a ten point system with 0 (student may not submit his homework)
        tmp.grade.push_back(grd);
        i != cnt - 1 ? cout << grd << " " : cout << grd << "\n";
    }
}
void userInput(student &tmp) {
    string opt = "ran"; // option
    int    sum = 0,     // entered grade
           grd;         // sum of entered grades
    cout << "Enter the student's name and surname: "; cin >> tmp.name >> tmp.surname;
    cout << "Would you like to randomize the grades (type 'ran') or enter yourself? (any key to continue): "; cin >> opt;
    if(opt != "ran") {
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
                cout << "You can enter a maximum of " << max << " grades per student.\n";
                break;
            }
            tmp.grade.push_back(grd);
            sum += grd;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(sum == 0) {
            cout << "At least one grade that is not a symbol and higher than 0 must be entered! Try from the beginning.\n";
            tmp.grade.clear();
            userInput(tmp); // recursion
        }
        else cout << "In total " << tmp.grade.size() << " grades entered.\n";
    }
    else randInput(tmp);
}
void input(vector<student> &arr, string &opt) { // https://www.delftstack.com/howto/cpp/how-to-return-a-vector-from-a-function-efficiently-in-cpp/
    student tmp;
    string  req = " ";
    cout << "'in' to input the data manually ;\n'rf' to read the data from file .\n";
    cout << "Enter your choice: "; cin >> opt;
    while(cin.fail() or (opt != "in" && opt != "rf")) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Incorrect form. Try again: "; cin >> opt;
    }
    if(opt == "in") {
        do {
            userInput(tmp);
            arr.push_back(tmp);
            tmp.grade.clear();
            cout << "Enter 'end' if all students are entered or any key to continue: "; cin >> req;
        } while(req != "end");
    }
    else if(opt == "rf") fileInput(arr);
}
int main() {
    vector<student> arr; // array
    string          opt = " "; // option
    //----------INPUT----------
    input(arr, opt);
    //----------OUTPUT----------
    output(arr, opt);
    //----------FREE UP THE MEMORY----------
    cout << "\nFreeing memory...\nEnd of the program.\n";
    for(int i = 0; i < arr.size(); i ++) {
        arr[i].grade.clear();
    }
    arr.clear();

    return 0;
}
