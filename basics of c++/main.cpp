#include<iostream>
#include<iomanip>
using namespace std;
double taxs_product(double price,double taxs){
    double p;
    p=(taxs/100)*price;
    return p;
}
int main(){
cout<<"enter the available products: ";
int availableProducts;
cin>>availableProducts;
string productName;
string productCode;
float price;
float taxs;
string stringProduct[availableProducts][2];
float numberProduct[availableProducts][2];
int i=0;
while(i<availableProducts){
cout<<"enter the product name,product code,price,taxs: "<<endl;
cin>> productName >> productCode >> price >> taxs ;
stringProduct[i][0]=productName;
stringProduct[i][1]=productCode;
numberProduct[i][0]=price;
numberProduct[i][1]=taxs;
i++;
}
/*for(int i=0;i<availableProducts;i++){
    for(int z=0;z<2;z++){
        cout<<numberProduct[i][z]<<" ";
    }
    cout<<endl;
}*/
int g=0;
float final_price=0;
while(g>=0){
cout<<"enter the number of orders: "<<endl;
int x;
cin>>x;
string code2;
int quantity;
int detector[x];
int quantity_detect[x];
int t=0;
for(int z =0;z<x;z++){
    cout<<"enter the code and the quantity: "<<endl;
    cin>> code2 >> quantity ;
    quantity_detect[z]=quantity;
    for(int i=0;i<availableProducts;i++){
            if(code2==stringProduct[i][1]){
                    while(t<x){
                        detector[t]=i;
                        t++;
                        break;
                    }
              }

            else{
                continue;

            }
    }
}
cout<<"product name"<<setw(19)<<"price"<<setw(14)<<"tax"<<setw(20)<<"final price"<<setw(15)<<"quantity"<<setw(20)<<"total price"<<endl;
float total_price=0;
for(int i=0;i<x;i++){
    cout<<stringProduct[detector[i]][0]<<setw(20)<<numberProduct[detector[i]][0]<<setw(17)<<taxs_product(numberProduct[detector[i]][1],numberProduct[detector[i]][0])<<setw(17)<<taxs_product(numberProduct[detector[i]][0],numberProduct[detector[i]][1])+numberProduct[detector[i]][0]<<setw(14)<<quantity_detect[i]<<setw(19)<<(taxs_product(numberProduct[detector[i]][0],numberProduct[detector[i]][1])+numberProduct[detector[i]][0])*quantity_detect[i]<<endl;
    total_price=total_price+(taxs_product(numberProduct[detector[i]][0],numberProduct[detector[i]][1])+numberProduct[detector[i]][0])*quantity_detect[i];

}
cout<<"-------------------"<<endl;
cout<<"the total price is: "<<total_price<<endl;
cout<<"-------------------"<<endl;
cout<<"Do you want to start a new order?"<<endl;
string new_level;
int new_round=1;
cin>>new_level;
new_round+=g;
final_price+=total_price;
if(new_level=="no"){
cout<<"the number of served orders: ";
cout<<new_round<<endl;
cout<<"total amount of all orders: ";
cout<<final_price<<endl;
cout<<"Good Luck ^_^";
break;
}
else{
        g++;
}

}

return 0;
}