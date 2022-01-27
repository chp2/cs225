#include <iostream>
using namespace std;

class Book
{
private:
	int current_page_;
	void set_percent();
public:
	Book(const string& title, int total_page);
	Book(const Book&);	// 복사 생성자의 원형 정의 
	string title_;
	int total_page_;
	double percent_;
	void Move(int page);
	void Open();
	void Read();
};

int main(void)
{
	Book web_book("HTML and CSS", 350);
	Book html_book(web_book);
	
	cout << "first book title is " << web_book.title_ << " and total page is " << web_book.total_page_ << endl;
	cout << "Second book title is " << html_book.title_ << " and total page is " << html_book.total_page_;
	return 0;
}

Book::Book(const string& title, int total_page)
{
	title_ = title;
	total_page_ = total_page;
	current_page_ = 0;
	set_percent();
}

Book::Book(const Book& origin)	// 복사 생성자의 선언 
{
	title_ = origin.title_;
	total_page_ = origin.total_page_;
	current_page_ = origin.current_page_;
	percent_ = origin.percent_;
}

void Book::set_percent()
{
	percent_ = (double) current_page_ / total_page_ * 100;
}