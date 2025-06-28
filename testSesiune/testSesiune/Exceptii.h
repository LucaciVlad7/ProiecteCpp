#pragma once
#include <string>
using namespace std;

class Exceptie : public exception {
private:
    string message;
public:
    explicit Exceptie(const string& message) :message(message) {}
    [[nodiscard]] const string& getMessage()const {
        return message;
    }
};

class ValidationError : public Exceptie {
public:
    explicit ValidationError(const string& message) :Exceptie(message) {}
};

class RepoError : public Exceptie {
public:
    explicit RepoError(const string& message) :Exceptie(message) {}
};