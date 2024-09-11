//
// Created by drews on 3/19/2021.
//
#include "Question.h"
#include "Quiz.h"
#include <iostream>

using namespace std;

bool testQuestion();
bool testQuiz();


int main (){
    cout << "Hello World" << endl;
    if(testQuestion()){
        cout << "Passed all test cases for Question" << endl;
    }
    if(testQuiz()){
        cout << "Passed all test cases for Quiz" << endl;
    }

    return 0;
}

bool testQuestion(){
    bool passed = true;
    Question q;
    if(q.getPoints() != 0){
        passed = false;
        cout << "FAILED Question default constructor test" << endl;
    }

    // test case for add answer by string and bool
    q.addAnswer("This is a test", true);
    if(q.getNumAnswers() != 1){
        passed = false;
        cout << "FAILED Question add answer by string and boolean test" << endl;
    }

    // test case for add answer by string
    answer a;
    a.correct = true;
    a.text = "Test string";
    q.addAnswer(a);
    if(q.getNumAnswers() != 2){
        passed = false;
        cout << "Failed Question add answer by struct test" << endl;
    }

    // test case for if isCorrect functions properly
    Question q2;
    q2.addAnswer(a);
    if(!(q2.isCorrect(0))){
        passed = false;
        cout << "FAILED Question is correct test" << endl;
    }

    // test case for remove answer by index
    if(!(q2.removeAnswer(0))){
        passed = false;
        cout << "FAILED Question remove answer by index test" << endl;
    }

    // test case for remove answer by string
    if(!(q.removeAnswer("This is a test"))){
        passed = false;
        cout << "FAILED Question remove answer by string test" << endl;
    }

    return passed;
}


bool testQuiz(){
    bool passed = true;
    // test default constructor
    Quiz q;
    if(q.getTotalPointsPossible() != 0 || q.getTotalPointsCorrect() != 0){
        passed = false;
        cout << "FAILED Quiz default constructor test" << endl;
    }

    // test case for remove question by index
    Question ques;
    q.addQuestion(ques);
    if(!(q.removeQuestion(0))){
        passed = false;
        cout << "FAILED Quiz remove question by index test" << endl;
    }

    // test case for remove question by string
    q.addQuestion(ques);
    if(!(q.removeQuestion(""))){
        passed = false;
        cout << "FAILED Quiz remove question by string test" << endl;
    }

    return passed;
}