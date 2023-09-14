#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string author;
    string title;
    int page;

public:
    void setAuthor(string author)
    {
        this->author = author;
    }

    void setTitle(string title)
    {
        this->title = title;
    }

    void setPage(int page)
    {
        this->page = page;
    }

    string getAuthor()
    {
        return this->author;
    }

    string getTitle()
    {
        return this->title;
    }

    int getPage()
    {
        return this->page;
    }
};

int main()
{
    Book book;
    book.setAuthor("Basari");
    book.setTitle("Self-Taught");
    book.setPage(300);

    cout << book.getPage() << endl;
    return 0;
};