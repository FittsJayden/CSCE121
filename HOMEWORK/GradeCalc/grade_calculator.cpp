// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    int examNum = 0;
    int hwNum = 0;
    int lwNum = 0;
    int readingNum = 0;
    int engagementNum = 0;
    int progNum = 0;

    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double reading = 0;
    double engagement = 0;
    double finaltest = 0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            examNum += 1;
            exam_average += score;
        } else if (category == "final-exam") {
            finaltest = score;
            examNum += 1;
            exam_average += score;
        } else if (category == "hw") {
            hwNum += 1;
            hw_average += score;
        } else if (category == "lw") {
            lwNum += 1;
            lw_average += score;
        } else if (category == "reading") {
            readingNum += 1;
            reading += score;
        } else if (category == "engagement") {
            engagementNum += 1;
            engagement += score;
        }else if  (category == "program-check") {
            progNum += score;
        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages
    

    if (examNum == 2) {
        examNum += 1;
    }
    else if (examNum == 1) {
        examNum += 2;
    }

    if (examNum == 0) {
        exam_average = 0;
    }
    else {
        exam_average /= examNum;
    }


    if (hwNum == 0) {
        hw_average = 0;
    }
    else {
        hw_average /= hwNum;
    }


    if (lwNum == 0) {
        lw_average = 0;
    }
    else {
        lw_average /= lwNum;
        lw_average *= 100;
    }


    if (readingNum == 0) {
        reading = 0;
    }
    else {
        reading /= readingNum;
    }
    reading += 15;


    if (engagementNum == 0) {
        engagement = 0;
    }
    else {
        engagement /= engagementNum;
    }
    engagement += 15;


    if (exam_average < finaltest) {
        exam_average = finaltest;
    }
    if (reading > 100) {
        reading = 100;
    }
    if (engagement > 100) {
        engagement = 100;
    }
    if (progNum == 0) {
        lw_average *= .5;
    }
    else if (progNum == 1) {
        lw_average *= .75;
    }



    

    // TODO(student): compute weighted total of components
    double weighted_total = 0;

    weighted_total = (exam_average * .4) + (hw_average * .4) + (lw_average * .1) + (reading * .05) + (engagement * .05);



    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';

    if (weighted_total >= 90) {
        final_letter_grade = 'A';
    } 
    else if (weighted_total >= 80) {
        final_letter_grade = 'B';
    }
    else if (weighted_total >= 70) {
        final_letter_grade = 'C';
    }
    else if (weighted_total >= 60) {
        final_letter_grade = 'D';
    }
    else {
        final_letter_grade = 'F';
    }
    

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement | program-check" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
