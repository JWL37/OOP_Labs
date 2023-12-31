#pragma once

#include <iostream>
#include "Concept.h"

template<ScalarType T>
class Point {
public:
    Point() : _x{0}, _y{0} {}

    Point(const Point<T>& other) : _x(other._x), _y(other._y) {};

    Point(T x, T y) : _x{x}, _y{y} {};

    T getX() const {
        return _x;
    }

    T getY() const {
        return _y;
    }

    double distanceBetweenPoints(const Point<T>& other) const {
        return sqrt((_x - other._x) * (_x - other._x) + (_y - other._y) * (_y - other._y));
    }


    Point<T>& operator=(const Point<T>& other) {
        _x = other._x;
        _y = other._y;
        return *this;
    }


    Point<T>& operator=(Point<T>&& other) noexcept {
        _x = other._x;
        _y = other._y;
        other._x = 0;
        other._y = 0;
        return *this;
    }

    bool operator==(const Point<T>& other) const {
        double epsilon{1.0};
        while (1.0 + 0.5 * epsilon != 1.0) {
            epsilon *= 0.5;
        }
        return abs(_x - other._x) < epsilon && abs(_y - other._y) < epsilon;
    }


    friend std::ostream& operator<<(std::ostream& out, const Point<T>& point) {
        out << "(" << point._x << " " << point._y << ")";
        return out;
    }


    friend std::istream& operator>>(std::istream& input, Point<T>& point) {
        input >> point._x >> point._y;
        return input;
    }



private:
    T _x;
    T _y;
};

template<ScalarType T>
std::ostream& operator<<(std::ostream& out, const Point<T>& point);

template<ScalarType T>
std::istream& operator>>(std::istream& input, Point<T>& point);