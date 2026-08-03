#include<iostream>
#include<string>
using namespace std;
#include<vector>



class Book{
   
  private:

    string title;
    string author;
    string publisher;
    int yearPublished;
    int ISBN;
    bool isBorrowed;
    string member;
  

    public:

    Book(string title,string author,string publisher,int yearPublished,int ISBN,bool isBorrowed){
            this -> title = title;
            this->author = author;
            this->publisher= publisher;
            this->yearPublished = yearPublished;
            this->ISBN = ISBN;
            this->isBorrowed = isBorrowed;
            

    }
    
  string borrowBook(string member){
   
    
    
    if (isBorrowed)
    {
      

      return "book unvailable";

      
    }

    else 
    {
      isBorrowed = true;
      this ->member = member;
      return "borrowed succeffuly  :" + member;
    }
    
    
  }

  string returnBook(){
    if (isBorrowed == true){
       isBorrowed = false;
       member ="";
      return "book returned";
     

}

else{
  return "Book is already available.";
}
  
}

int getISBN(){

  return ISBN;

}

 string getTitle(){
  return title;
 }
    string getAuthor(){
      return author;
    }
    string getPublisher(){
      return publisher;
    }
    int getYearPublished(){
      return yearPublished;
    }
    
    bool getIsBorrowed(){
      return isBorrowed;
    }
    string getMember(){
      return member;
    }

    void displayBook(){
    cout<< "book tittle"  <<getTitle()<< endl;
    
    cout <<"book auther"  <<getAuthor()<< endl;
    
    cout<<"book availability status"  <<getIsBorrowed()<< endl;
    
    cout<<"book ISBN"  <<getISBN()<< endl;
    
    cout<<"year published " << getYearPublished() << endl;

    cout<<"publisher"  <<getPublisher()<<endl;

    cout<<"borrowed by:"  <<getMember()<< endl;
}



};





class Library{
    private:
vector<string> members;
int copiesOfbooks;
vector<Book>books;

public:

void addBook(Book book)
{
  books.push_back(book);

}

void removeBook( Book book){

  for(int i= 0 ; i <books.size() ; i++ ){
    cout<< books[i].getISBN();
    

    if(books[i].getISBN()== book.getISBN()){

      books.erase(books.begin() + i);

       break;
      
    }
   

  }
  
  

}

string returnBook(int ISBN){
  for(int i = 0 ;i < books.size(); i++){
    

  

  if (books[i].getISBN()== ISBN ){
  {
    books[i].returnBook();
    break;
  }
  
}

}
return "Book not found.";

}


void displayBooks(){
  for(int i = 0; i< books.size() ; i++){
    
    books[i].displayBook()  ;
  }
}

void searchBook(Book book){
  bool found = false;
  for(int i = 0 ; i< books.size() ; i++ ){
    if (books[i].getISBN() == book.getISBN()){
       found = true;
      books[i].displayBook() ;
       break;

      
     
    }
  }
  if(!found){
    cout<<"book not found"<< endl ;
   }
}

void borrowBook(string member,Book book){
  for (int i = 0; i < books.size(); i++)
  {

    if(books[i].getISBN() == book.getISBN( ) ){

      books[i].borrowBook( member);
      break;
     
    }

  
    else{
      cout <<"book unvailable "<< endl ;
    }
  }
  
}
};


int main (){
  Book book1("COCO","Dorothee","Didier house",2015,1999,true);
  Book book2("Navigation","Marcin","tychy publishing",2026,2022,false);
  
  Library myLibrary;
  myLibrary.addBook(book1);
  myLibrary.addBook(book2);
  myLibrary.displayBooks();
  myLibrary.searchBook(book1);
  myLibrary.searchBook(book2);
 


  
}  

