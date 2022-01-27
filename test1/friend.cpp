#include <iostream>
using namespace std;

class Rect
{
private:
	double height_;
	double width_;
public:
	Rect(double height, double width);	// 생성자 
	void DisplaySize();
	Rect operator*(double mul) const;
    Rect operator/(double mul) const;
    friend Rect operator*(double mul, const Rect& origin);	// 프렌드 함수 
};

Rect operator/(double mul, const Rect& origin);

int main(void)
{
	Rect origin_rect(10, 20);
	Rect rect01 = origin_rect / 2;
	Rect rect02 = 3 / origin_rect;
	
	rect01.DisplaySize();
	rect02.DisplaySize();
	return 0;
}

Rect::Rect(double height, double width)
{
	height_ = height;
	width_ = width;
}

void Rect::DisplaySize()
{
	cout << "height: " << this->height_ << endl; 
    cout << "width: " << this->width_ << endl;
}

Rect Rect::operator*(double mul) const
{
	return Rect(height_ * mul, width_ * mul);
}

Rect Rect::operator/(double mul) const
{
    return Rect(height_ / mul, width_ / mul);
}

Rect operator/(double mul, const Rect& origin)
{
	return origin / mul;
}

Rect operator*(double mul, const Rect& origin)
{
	return origin * mul;
}