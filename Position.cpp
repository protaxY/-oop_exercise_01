#include "Position.h"
//Конструкторы
void Position::check_limits(){
    latitude=fmod(latitude,90);
    longitude=fmod(longitude,180);
};
Position::Position(){latitude=0; longitude=0;}
Position::Position(double cur_latitude, double cur_longitude){
    latitude=cur_latitude; longitude=cur_longitude;
    check_limits();
}
//Методы класса
double Position::norm()const{
    return sqrt(latitude * latitude + longitude * longitude);
};
Position Position::set_position(double cur_latitude, double cur_longitude){
    latitude=cur_latitude; longitude=cur_longitude;
    check_limits();
    return *this;
}
void Position::print_position(){
    check_limits();
    std::cout << "[" << latitude << ", " << longitude << "]" << std::endl;
};
//Перегрузка операторов
Position operator+(const Position &lhs, const Position &rhs){
    return Position(fmod(lhs.latitude+rhs.latitude,90), fmod(lhs.longitude + rhs.longitude, 180));
}
Position operator-(const Position &lhs, const Position &rhs){
    return Position(fmod(lhs.latitude-rhs.latitude,90), fmod(lhs.longitude - rhs.longitude,180));
}
Position operator*(const Position &lhs, const Position &rhs){
    return Position(fmod(lhs.latitude*rhs.latitude,90), fmod(lhs.longitude * rhs.longitude,180));
}
Position operator/(const Position &lhs, const Position &rhs){
    return Position(fmod(lhs.latitude / rhs.latitude,90), fmod(lhs.longitude / rhs.longitude,180));
}
bool operator==(const Position &lhs, const Position &rhs){
    return (lhs.latitude == rhs.latitude && rhs.longitude == lhs.longitude);
}
bool operator!=(const Position &lhs, const Position &rhs){
    return (lhs.latitude != rhs.latitude && rhs.longitude != lhs.longitude);
}
bool operator>(const Position &lhs, const Position &rhs){
    return (lhs.norm()>rhs.norm())&&!(abs(lhs.norm()-rhs.norm())<DBL_EPSILON);
}
bool operator>=(const Position &lhs, const Position &rhs){
    return (lhs.norm()>rhs.norm())||(abs(lhs.norm()-rhs.norm())<DBL_EPSILON);
}
bool operator<(const Position &lhs, const Position &rhs){
    return (lhs.norm()<rhs.norm())&&!(abs(lhs.norm()-rhs.norm())<DBL_EPSILON);
}
bool operator<=(const Position &lhs, const Position &rhs){
    return (lhs.norm()<rhs.norm())||(abs(lhs.norm()-rhs.norm())<DBL_EPSILON);
}
