//
// Created by dengxin05 on 2019-10-05.
//

#ifndef LEARNALGORITHM_STUDENT_H
#define LEARNALGORITHM_STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student{
    string name;
    int score;
    bool operator<(const Student &otherStudent){
        return score < otherStudent.score;
    }

    friend ostream&operator << (ostream &os, const Student &student){
        os << "Student: " << student.name << ' ' << student.score << std::endl;
        return os;
    }
};



#endif //LEARNALGORITHM_STUDENT_H
