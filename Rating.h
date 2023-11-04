//
// Created by nguye on 10/7/2023.
//
#include <iostream>
#include <vector>
#ifndef MOTORBIKE_RENTAL_SYSTEM_RATING_H
#define MOTORBIKE_RENTAL_SYSTEM_RATING_H
using namespace std;
class Rating {
    // vector of score and comment
    friend ostream& operator<<(ostream& os, const Rating& rating); // display on console
    friend istream& operator>>(istream& is, Rating& rating); // write on console
public:
    Rating();
    ~Rating();
    bool operator==(const Rating& rating) const;
    // other method
    double getScore();
    void setScore(double score);
    string getComment();
    void setComment(const string& comment);
//    tm getDate();
//    void setDate(const tm& date);
    void setRating(double score, const string& comment);
    void displayRating();

private:
    double score;
    string comment;
    tm date{};
};
#endif //MOTORBIKE_RENTAL_SYSTEM_RATING_H
Rating::Rating(): score(0), comment() {};
Rating::~Rating() {
    delete this;
}

void Rating::setRating(double score, const string& comment) {
    this->score = score;
    this->comment = comment;
}

double Rating::getScore() {
    return this->score;
}

void Rating::setScore(double score) {
    this->score = score;
}

string Rating::getComment() {
    return this->comment;
}

void Rating::setComment(const string& comment) {
    this->comment = comment;
}

void Rating::displayRating() {
    cout << "Score: " << this->score << endl;
    cout << "Comment: " << this->comment << endl;
}

ostream& operator<<(ostream& os, const Rating& rating) {
    os << "Score: " << rating.score << endl;
    os << "Comment: " << rating.comment << endl;
    return os;
}

istream& operator>>(istream& is, Rating& rating) {
    is >> rating.score;
    is >> rating.comment;
    return is;
}

bool Rating::operator==(const Rating &rating) const {
    return (score == rating.score && comment == rating.comment);
}
