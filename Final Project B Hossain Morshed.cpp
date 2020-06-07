//Name: Hossain Ahmad Sobhen Morshed
// Date: 7 May 2020.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
using namespace std;

void printStudentInfo(string name[], int studentID[], int test1[], int test2[], int test3[], int test4[], int test5[], const int SIZE);
double testsum(int test[], int size);
char grade(double num);
void printToFile(string name[], int studentID[], int test1[], int test2[], int test3[], int test4[], int test5[], const int SIZE, string filename);

int main() {
    const int SIZE = 6;
    string name[SIZE];
    int studentID[SIZE];
    int test1[SIZE];
    int test2[SIZE];
    int test3[SIZE];
    int test4[SIZE];
    int test5[SIZE];
    string file_name = "StudentData.txt";
    ifstream fileIn(file_name);// our data file
    int count = 0;
    string Namefile1;
    char choice;
    // loading data for each array. if there is no file programe show error messgage otherwise it will load the file.
    if (!fileIn) {
        cout << "Error opening " << file_name << endl;
    }
    else {
        while (!fileIn.eof() && (count != SIZE)) {
            getline(fileIn, name[count]);
            if (fileIn.eof()) break;
            fileIn >> studentID[count];
            fileIn >> test1[count];
            fileIn >> test2[count];
            fileIn >> test3[count];
            fileIn >> test4[count];
            fileIn >> test5[count];
            // file pointer is at the New Line, Need to  ignor it. 
            fileIn.ignore();
            count++;
        }
    }
    
    fileIn.close(); // closing  the file after done.

    cout << " " << endl;
    // program start from here.
    // we are using a do while loop and switch so programe will run until user choice to quite the programe.
    do {
        // showing the Menu option for User.
        cout << "++++++ User Menu for this Programm. ++++++\n";
        cout << "P - Print the data file to console\n" << "A - Average the grades for a student, and determine the overall grade.\n";
        cout << "G - print the overall grade for the students to file\n" << "S - Average the grades for the tests\n" << "Q - Quit\n";
        cout << endl;
        cout << "Choice which programm you want to use. Enter p, a, g, s or q for quite the program : ";
        cin >> choice; // asking user to input their choice.
        cout << endl;
        // switch option give user to choice different option.
        switch (choice) {
        case 'P':
        case 'p':
            cout << "Student grade information are given below." << endl;
            printStudentInfo(name, studentID, test1, test2, test3, test4, test5, SIZE);
            cout << endl;
            break; // break will break this program and return back to the main menu.
        case 'A':
        case 'a':
            cout << "-----Student Average grades and as well as students overall grade-----" << endl;
            for (int i = 0; i < SIZE; i++) {
                int space = name[i].find(" "); // looking for space between the sentence. so that  we can use substr and seperate firstname and last name.
                double avg = (static_cast<double>(test1[i]) + static_cast<double>( test2[i]) + static_cast<double>(test3[i]) + static_cast<double>(test4[i]) + static_cast<double> (test5[i])) / 5.0;
                char sGrade = grade(avg); // This function help to find student grade letter.
                cout << right << setw(10);
                cout << fixed << showpoint << setprecision(2);
                cout << name[i].substr(space + 1) << ", " << name[i].substr(0, space) << "\t" << " (" << studentID[i] << ")    " << avg << "     " << sGrade << endl;
            }
            cout << endl;
            break;// break will break this program and return back to the main menu.
        case 'G':
        case 'g':
            cout << "Printing Student Name, studentID, average point and overall grade into a file." << endl;
            Namefile1 = "FinalGrades.txt";// name of the stored file.
            printToFile(name, studentID, test1, test2, test3, test4, test5, SIZE, Namefile1);// printing file into hard drive.
            cout << "Print is done." << endl;
            cout << endl;
            break;// break will break this program and return back to the main menu.
        case 'S':
        case 's':
            cout << "-------Average the grades for the tests-----" << endl;
            cout << "which test average grade you would like to see, test 1, 2, 3, 4 or 5" << endl;
            int testchoice;
            cout << "Please enter the test Number :";
            cin >> testchoice;
            cout << endl;
            // we have in total five test, to view each test we creat another switch so user can see particular test average.
            switch (testchoice) {
            case 1:
                cout << "Test 1 average is : ";
                cout << testsum(test1, SIZE) / SIZE << endl;
                cout << endl;
                break;
            case 2:
                cout << "Test 2 average is : ";
                cout << testsum(test2, SIZE) / SIZE << endl;
                cout << endl;
                break;
            case 3:
                cout << "Test 3 average is : ";
                cout << testsum(test3, SIZE) / SIZE << endl;
                cout << endl;
                break;
            case 4:
                cout << "Test 4 average is : ";
                cout << testsum(test4, SIZE) / SIZE << endl;
                cout << endl;
                break;
            case 5:
                cout << "Test 5 average is : ";
                cout << testsum(test5, SIZE) / SIZE << endl;
                cout << endl;
                break;
            default:
                cout << "You did not enter the right test." << endl;
                cout << endl;
            }
            break;
        case 'Q':
        case 'q':
            cout << "Thank you for using the Program" << endl;
            break;
        default:
            cout << "You did not enter the  valid choice!\n";
            cout << "Enter p, a, g, s or q for quite the program : ";
        }
    } while (choice != 'q' && choice != 'Q');// programe will quite if user choice  Q or q.

    return 0;
}
// This function print student data file.
void printStudentInfo(string name[], int studentID[], int test1[], int test2[], int test3[], int test4[], int test5[], const int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        int space = name[i].find(" ");// from name we find space so later we can seperately print first name and last name.
        cout << right << setw(10);
        cout << fixed << showpoint << setprecision(2);
        cout << name[i].substr(space + 1) << ", " << name[i].substr(0, space) << "\t" << " (" << studentID[i] << ") : " << test1[i] << ", " << test2[i] << ", " << test3[i] << ", " << test4[i] << ", "  << test5[i] << endl;
    }
}
// sum all the value in a particular test
double testsum(int test[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += test[i];
    }
    return sum;
}
// This function take number as a input and catagorize which grade that number belongs to.
char grade(double num) {
    char result;
    if (num >= 90) {
        result = 'A';
        return result;
    }
    else if (num >= 80) {
        result = 'B';
        return result;
    }
    else if (num >= 70) {
        result = 'C';
        return result;
    }
    else if (num >= 60) {
        result = 'D';
        return result;
    }
    else {
        result = 'F';
        return result;
    }
}
//This function  save or write data into  hard disk.
void printToFile(string name[], int studentID[], int test1[], int test2[], int test3[], int test4[], int test5[], const int SIZE, string filename) {
    ofstream outputFile;// setup output file
    outputFile.open(filename);
    for (int i = 0; i < SIZE; i++) {
        int space = name[i].find(" ");
        double avg = (static_cast<double>(test1[i]) + static_cast<double>(test2[i]) + static_cast<double>(test3[i]) + static_cast<double>(test4[i]) + static_cast<double>(test5[i])) / 5.0;
        char sGrade = grade(avg);
        outputFile << right << setw(10); // set the data to right align
        outputFile << fixed << showpoint << setprecision(2);// show the two digit after decimal point.
        outputFile << name[i].substr(space + 1) << ", " << name[i].substr(0, space) << "\t" << " (" << studentID[i] << ")    " << avg << "     " << sGrade << endl;
    }
    outputFile.close();
}