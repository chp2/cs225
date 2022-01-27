#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
#define MAX_SIZE 100
using namespace std;

char Select()
{
    cout << "1. add" << endl;
    cout << "2. search" << endl;
    cout << "3. delete" << endl;
    cout << "4. exit" << endl;
    cout << "5. all" << endl;
    return getch();
}

class Person
{
private:
    char* firstName;
    char* lastName;
    char* phone;
    char* email;
public:
    void Input(char* buffirst, char* buflast, char* bufphone, char* bufemail);
    char* GetFirstName()
    {
        return firstName;
    }
    char* GetLastName()
    {
        return lastName;
    }
    char* Getphone()
    {
        return phone;
    }
    char* Getemail()
    {
        return email;
    }
    void printinfo()
    {
        cout << firstName << " " << lastName << " : " << phone << " : " << email << endl;
    }
};

class PersonBook 
{
private:
    Person book[MAX_SIZE];
    int count;
public:
    PersonBook()
    {
        count=0;
    }
    void WritePersonBook();
    void WritePersonBook(char* _buffirst, char* _buflast, char* _bufphone, char* _bufemail);
    void WriteFile(ofstream& ofs)
    {
        for(int i = 0; i < count; i++)
        {
            ofs << book[i].GetFirstName() << " " << book[i].GetLastName() << " " << book[i].Getphone() << " " << book[i].Getemail() << endl;
        }
        ofs << "0";
        ofs.close();
    }
    void PrintPerson()
    {
        for(int i = 0; i < count; i++)
        {
            book[i].printinfo();
        }
    }
    void Search();
    void Delete();
};

int main()
{   
    /*
    char first[100];
    char last[100];
    char phone[100];
    char email[100];
    */
    ifstream ifs;
    ofstream ofs;
    ifs.open("address.txt");
    if(!ifs.is_open())
    {
        cout << "File cannot open!" << endl;
        exit(1);
    }

    PersonBook book;
    while(true)
    {
        char *first = new char[100];
        ifs >> first;
        if(strcmp(first, "0") == 0)
        {
            break;
        }
        char *last = new char[100];
        char *phone = new char[100];
        char *email = new char[100];
        ifs >> last >> phone >> email;
        cout << first << " " << last << " " << phone << " " << email << endl;
        book.WritePersonBook(first, last, phone, email);
    }
    ifs.close();
    bool run = true;
    while(run)
    {
        switch(Select())
        {
            case '1':
                book.WritePersonBook();
                break;
            case '2':
                book.Search();
                break;
            case '3':
                book.Delete();
                break;
            case '4':
                run = false;
                break;
            case '5':
                book.PrintPerson();
                break;
        }
    }
    ofs.open("address.txt",ios_base::trunc);
    book.WriteFile(ofs);
    ofs.close();
    return 0;
}

void Person::Input(char* buffirst, char* buflast, char* bufphone, char* bufemail)
{
    firstName = buffirst;
    lastName = buflast;
    phone = bufphone;
    email = bufemail;
}

void PersonBook::WritePersonBook()
{
    cout<<"Input first name, last name, phone, email"   <<endl;
    char* _buffirst = new char[100];
    char* _buflast = new char[100];
    char* _bufphone = new char[100];
    char* _bufemail = new char[100];
    cin >> _buffirst >> _buflast >> _bufphone >> _bufemail;
    book[count++].Input(_buffirst, _buflast, _bufphone, _bufemail);
}

void PersonBook::WritePersonBook(char* _buffirst, char* _buflast, char* _bufphone, char* _bufemail)
{
    book[count++].Input(_buffirst, _buflast, _bufphone, _bufemail);
}

void PersonBook::Search()
{
    cout << "1.phone" << endl << "2.Last name" << endl << "3.First name" << endl << "4.email" << endl;
    char buf[100];
    switch(getch())
    {
        case '1':
            cout << "enter the phone: ";
            cin >> buf;
            for(int i = 0; i < count; i++)
            {
                if(strcmp(book[i].Getphone(), buf) == 0)
                {
                    book[i].printinfo();
                }
                break;
            }
            break;
        case '2':
            cout << "enter last name: ";
            cin >> buf;
            for(int i = 0; i < count; i++)
            {
                if(strcasecmp(book[i].GetLastName(), buf) == 0)
                {
                    book[i].printinfo();
                }
                //break;
            }
            break;
        case '3':
            cout << "enter first name: ";
            cin >> buf;
            for(int i = 0; i < count; i++)
            {
                if(strcasecmp(book[i].GetFirstName(), buf) == 0)
                {
                    book[i].printinfo();
                }
                //break;
            }
            break;      
        case '4':
            cout << "enter email: ";
            cin >> buf;
            for(int i = 0; i < count; i++)
            {
                if(strcmp(book[i].Getemail(), buf) == 0)
                {
                    book[i].printinfo();
                }
                break;
            }
            break;
    }
}


void PersonBook::Delete()
{
    char buf[100];
    cout << "1.phone" << endl << "2.Last name" << endl << "3.First name" << endl << "4.email" << endl;
    switch(getch())
    {
        case '1':
            cout << "enter the phone: ";
            cin >> buf;
            for(int i = 0; i < count; i++)
            {
                if(strcmp(book[i].Getphone(), buf) == 0)
                {
                    delete[] book[i].GetFirstName();
                    delete[] book[i].GetLastName();
                    delete[] book[i].Getphone();
                    delete[] book[i].Getemail();
                    book[i].Input(book[count-1].GetFirstName(), book[count-1].GetLastName(), book[count-1].Getphone(), book[count-1].Getemail());
                    count--;
                }
                break;
            }
            break;
        case '2':
            cout << "enter last name: ";
            cin >> buf;
            for(int i = 0; i < count; i++)
            {
                if(strcasecmp(book[i].GetLastName(), buf) == 0)
                {
                    delete[] book[i].GetFirstName();
                    delete[] book[i].GetLastName();
                    delete[] book[i].Getphone();
                    delete[] book[i].Getemail();
                    book[i].Input(book[count-1].GetFirstName(), book[count-1].GetLastName(), book[count-1].Getphone(), book[count-1].Getemail());
                    count--;
                }
                //break;
            }
            break;
        case '3':
            cout << "enter first name: ";
            cin >> buf;
            for(int i = 0; i < count; i++)
            {
                if(strcasecmp(book[i].GetFirstName(), buf) == 0)
                {
                    delete[] book[i].GetFirstName();
                    delete[] book[i].GetLastName();
                    delete[] book[i].Getphone();
                    delete[] book[i].Getemail();
                    book[i].Input(book[count-1].GetFirstName(), book[count-1].GetLastName(), book[count-1].Getphone(), book[count-1].Getemail());
                    count--;
                }
                //break;
            }
            break;      
        case '4':
            cout << "enter email: ";
            cin >> buf;
            for(int i = 0; i < count; i++)
            {
                if(strcmp(book[i].Getemail(), buf) == 0)
                {
                    delete[] book[i].GetFirstName();
                    delete[] book[i].GetLastName();
                    delete[] book[i].Getphone();
                    delete[] book[i].Getemail();
                    book[i].Input(book[count-1].GetFirstName(), book[count-1].GetLastName(), book[count-1].Getphone(), book[count-1].Getemail());
                    count--;
                }
                break;
            }
            break;
    }
}