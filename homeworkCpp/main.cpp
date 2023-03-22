#include <iostream>
#include <stdio.h>
using namespace std;
class StockItem{
    private:
        int ItemNumber;
        int Quantity;
        float UnitPrice;
    public:
        //Constructor with arguments.
        StockItem(int,int,float);
        //Copy Constructor.
        StockItem(const StockItem &source);
        //Destructor.
        ~StockItem();
        void SetItemNumber(int);
        void SetQuantity(int);
        void SetUnitPrice(float);
        void setAll(int,int,float);
        void printItem();
};
void StockItem::SetItemNumber(int Item){
    ItemNumber=Item;
}
void StockItem::SetQuantity(int Quant){
    Quantity=Quant;
}
void StockItem::SetUnitPrice(float Unit){
    UnitPrice=Unit;
}
void StockItem::setAll(int Item,int Quant,float Unit){
    SetItemNumber(Item);
    SetQuantity(Quant);
    SetUnitPrice(Unit);
}
StockItem::StockItem(int Item=0,int Quant=0,float Unit=0.0){
    setAll(Item,Quant,Unit);
}
//Copy constructor implementation.
StockItem::StockItem(const StockItem &source){
    ItemNumber=source.ItemNumber;
    Quantity=source.Quantity;
    UnitPrice=source.UnitPrice;
}
StockItem::~StockItem(){
    //'Delete' requires to get the address of data.
    delete &ItemNumber;
    delete &Quantity;
    delete &UnitPrice;
}
void StockItem::printItem(){
    cout<<"Item Number: "<<ItemNumber<<endl;
    cout<<"Quantity: "<<Quantity<<endl;
    cout<<"Unit Price: "<<UnitPrice<<endl;
    cout<<"-------------------"<<endl;
}
int main()
{
    StockItem Item1;
    Item1.printItem();
    StockItem Item2(100,20,5.5);
    StockItem Item3(Item2);
    Item3.SetItemNumber(300);
    Item2.printItem();
    Item3.printItem();
    return 0;
}
