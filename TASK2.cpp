#include<iostream>
using namespace std;

class Product{
    private :
    int productID;
    string productName;
    double price;
    static int totalProducts;
    static double totalRevenue;

    public :
    Product(){
        productID = 0;
        productName = " ";
        price = 0.0;
    }

    Product(int pi , string pn , double p){
        productID = pi;
        productName = pn;
        price = p;

        totalProducts ++;
    }

    void sell(int quantity){
        totalRevenue += price * quantity;
    }

    double getPrice() const{
        return price;
    }

    static int getTotalProducts(){
        return totalProducts;
    }

    static double getTotalRevenue(){
        return totalRevenue;
    }

    void display() const{
        cout << "PRODUCT NAME : " << productName << endl;
        cout << "PRODUCT ID : " << productID << endl;
    }
    
    
};

int Product :: totalProducts = 0;
double Product :: totalRevenue = 0;


int main(){

    Product p1(20 , "TABLE" , 35000);
    p1.display();
    cout << "PRICE : " << p1.getPrice() << endl;
    cout << "TOTAL PRODUCTS : " << p1.getTotalProducts() << endl;
    cout << endl;
    p1.sell(1);

    Product p2(19 , "BOOK" , 1500);
    p2.display();
    cout << "PRICE : " << p2.getPrice() << endl;
    cout << "TOTAL PRODUCTS : " << p2.getTotalProducts() << endl;
    cout << endl;
    p2.sell(1);

    Product p3(18 , "CHAIR" , 15000);
    p3.display();
    cout << "PRICE : " << p3.getPrice() << endl;
    cout << "TOTAL PRODUCTS : " << p3.getTotalProducts() << endl;
    cout << endl; 
    p3.sell(1);
    cout << "TOTAL REVENUE : " << p3.getTotalRevenue() << endl;
    
    return 0;
}
