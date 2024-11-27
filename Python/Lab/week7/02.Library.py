class Library:
    def __init__(self):
        self.books=dict()
    def add_book(self,name):
        self.books[name]=True
    def borrow(self,name):
        if self.books[name]:
            self.books[name]=False
        else:
            print(f"Book not available!")
    def return_book(self,name):
        if name in self.books:
            self.books[name]=True
        else:
            print("We don't have this book in our library database")
    def list_available_books(self):
        availableBooks=[]
        for book in self.books:
            if self.books[book]:
                availableBooks.append(book)
        print("Available books:")
        print("|-|".join(availableBooks))


l=Library()
l.add_book("Kkoko")
l.add_book("Miki")
l.borrow("Kkoko")
l.borrow("Kkoko")
l.return_book("Kkoko")
l.return_book("Kkodko")
l.list_available_books()