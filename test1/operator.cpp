#include <iostream>
using namespace std;

class Position
{
private:
	double x_;
	double y_;
public:
	Position(double x, double y);	// 생성자 
	void Display();
	friend Position operator-(const Position& pos1, const Position& pos2);	// - 연산자 함수 
};

int main(void)
{
	Position pos1 = Position(3.3, 12.5);
	Position pos2 = Position(-14.4, 7.8);
	Position pos3 = pos1 - pos2;
	
	pos3.Display();
	return 0;
}

Position::Position(double x, double y)
{
	x_ = x;
	y_ = y;
}

Position operator-(const Position& pos1, const Position& pos2)
{
	return Position((pos1.x_ + pos2.x_)/2, (pos1.y_ + pos2.y_)/2);
}

void Position::Display()
{
	cout << "X middle point: " << this->x_ << endl;
    cout << "Y middle point: " << this->y_ << endl;
}