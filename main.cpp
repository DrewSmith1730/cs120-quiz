#include "Quiz.h"
#include <iostream>
using namespace std;

int main() {
    Quiz q;
    q.takeQuiz("NewQuiz.txt", cout, cin);
    return 0;
}
