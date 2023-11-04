#ifndef MOTORBIKEDETAIL_H
#define MOTORBIKEDETAIL_H



#include <iostream>
using namespace std;

class MotorbikeDetail
{
    friend ostream& operator<<(ostream& os, const MotorbikeDetail& detail); // display on console
    friend istream& operator>>(istream& is, MotorbikeDetail& detail); // get from console
public:
    MotorbikeDetail();
    ~MotorbikeDetail();
    // other method
    string getUmodel() const;
    string getDescription() const;
    int getYearMade() const;
    string getTransmissionMode() const;
    int getEngineSize() const;
    string getColor() const;
    void setUmodel(string umodel);
    void setDescription(string description);
    void setYearMade(int yearMade);
    void setTransmissionMode(string transmissionMode);
    void setEngineSize(int engineSize);
    void setColor(string color);

    void setMDetail(const string& umodel, const string& description, int yearMade, const string& transmissionMode, int engineSize, const string& color);
private:
    string umodel;
    string description;
    int yearMade;
    string transmissionMode;
    int engineSize;
    string color;
};

#endif //MOTORBIKEDETAIL_H



MotorbikeDetail::MotorbikeDetail(): umodel(), description(), yearMade(0), transmissionMode(), engineSize(0), color() {};
MotorbikeDetail::~MotorbikeDetail() {
    delete this;
}

void MotorbikeDetail::setMDetail(const string &umodel, const string &description, int yearMade,
                                 const string &transmissionMode, int engineSize, const string &color) {
    this->umodel = umodel;
    this->description = description;
    this->yearMade = yearMade;
    this->transmissionMode = transmissionMode;
    this->engineSize = engineSize;
    this->color = color;

}


string MotorbikeDetail::getUmodel() const {
    return this->umodel;
}

string MotorbikeDetail::getDescription() const {
    return this->description;
}

int MotorbikeDetail::getYearMade() const {
    return this->yearMade;
}

string MotorbikeDetail::getTransmissionMode() const {
    return this->transmissionMode;
}

int MotorbikeDetail::getEngineSize() const {
    return this->engineSize;
}

string MotorbikeDetail::getColor() const {
    return this->color;
}

void MotorbikeDetail::setUmodel(string umodel) {
    this->umodel = std::move(umodel);
}

void MotorbikeDetail::setDescription(string description) {
    this->description = std::move(description);
}

void MotorbikeDetail::setYearMade(int yearMade) {
    this->yearMade = yearMade;
}

void MotorbikeDetail::setTransmissionMode(string transmissionMode) {
    this->transmissionMode = std::move(transmissionMode);
}

void MotorbikeDetail::setEngineSize(int engineSize) {
    this->engineSize = engineSize;
}

void MotorbikeDetail::setColor(string color) {
    this->color = std::move(color);
}


ostream& operator<<(ostream& os, const MotorbikeDetail& detail) {
    os << detail.getUmodel() << endl;
    os << detail.getDescription() << endl;
    os << detail.getYearMade() << endl;
    os << detail.getTransmissionMode() << endl;
    os << detail.getEngineSize() << endl;
    os << detail.getColor() << endl;
    return os;
}

istream& operator>>(istream& is, MotorbikeDetail& detail) {
    getline(is, detail.umodel);
    getline(is, detail.description);
    is >> detail.yearMade;
    getline(is, detail.transmissionMode);
    is >> detail.engineSize;
    getline(is, detail.color);
    return is;
}


