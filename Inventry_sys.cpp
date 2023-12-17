#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x,int y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) ,pos);
}

void esteric(int r);

//global variable use in display product.
long inc = 01;
int addrow = 61;

class Product {
	private:
		string name;
    	int id ;
    	double price ;
    	int quantity ;
    public:
   		Product() {
  			name = "";
 			 id = 0;
  			price = 0.0;
  			quantity = 0;
		}
		     
		Product(string N,int I,double P,int Q){
			name = N;
			id = I;
			price = P;
			quantity = Q;
		}
		
		void displayProduct(){
		
		//		values shows.
			gotoxy(5,addrow);
			cout<<id;
			gotoxy(25,addrow);
			cout<<"000"<<inc;
			gotoxy(50,addrow);
			cout<<name;
			gotoxy(100,addrow);
			cout<<price;
			gotoxy(125,addrow);
			cout<<quantity<<endl;
		
			inc++;
			addrow++;
		}	
};
class Inventory {
	private:
		int maxProducts = 100;
		int productCount = 0;
		Product products[100];
	public:
		
		void addProduct(string name,double price,int quantity){
				if (productCount < maxProducts) {
            			products[productCount++] = Product(name, productCount + 1, price, quantity);
            			gotoxy(2,50);
            			cout << "Product added successfully." << endl;
        		}
				else {
            		cout << "Error: Maximum products reached." << endl;
        		}
    	}
    	
    	void displayInventory() {
        	if (productCount == 0) {
        		gotoxy(68,32);
            	cout << "Inventory is empty." << endl;
        	} 
			else {
				//  styling row.
				esteric(53);
				
				gotoxy(75,56);
            	cout << "Current Inventory" << endl;
            	
				//     	headings.
					gotoxy(5,59);
					cout<<"No.";
            		gotoxy(25,59);
					cout<<"product ID";
					gotoxy(50,59);
					cout<<"Name";
					gotoxy(100,59);
					cout<<"Price";
					gotoxy(125,59);
					cout<<"Quantity";
            	
            	for (int i = 0; i < productCount; ++i) {
                	products[i].displayProduct();
            	}
        	}
    	}
		
};

// function initialize.

void styling (int);
void mainBorder();
void innerBox();


int main (){
	
	Inventory inventory;
	int choice; 
	while(true){
		mainBorder();
	// border inner working.
	   
		gotoxy(75,12);
		cout<<"WELLCOME"<<endl;
		gotoxy(52,18);
		cout<<"=> Enter 1 for Add Product."<<endl;
		gotoxy(52,20);
		cout<<"=> Enter 2 for Display Inventry."<<endl;
		gotoxy(52,22);
		cout<<"=> Enter 3 for Quit.";
		innerBox();          //  inner box style.
		gotoxy(52,26);
		cin>>choice;
	
		switch (choice){
			case 1:
				{
					//  styling row.
						esteric(40);
					// add product.
			 		string name1;
            		double price;
                	int quantity;
                
					gotoxy(15,42);
					cout<< "New Product";
					gotoxy(5,45);
        	        cout << "Enter product name: ";
					cin >> name1;
					gotoxy(5,46);
					cout << "Enter product price: $";
            	    cin >> price;
        	        gotoxy(5,47);
    	            cout << "Enter product quantity: ";
        	        cin >> quantity;
					//add product in array.
					inventory.addProduct(name1, price, quantity);
				}
				break;
			case 2:
				//function calling.
				inventory.displayInventory();
				break;
			case 3:
				gotoxy(68,32);
				cout<<"Exiting program.  GOODBYE!";
				break;
			default:
				gotoxy(65,32);
				cout<<"Invalid Choice.Please try again.";
		}

	}
	return 0;
}

// function for ASCII code.

void styling (int sym)
{
	char symbol = sym;
	cout<<symbol;
}

void innerBox()
{
	gotoxy(51,26);
	styling(179);        //  left side |
	gotoxy(51,25);      
	styling(218);        //  upper left corner.
	gotoxy(51,27);
	styling(192);        //  lower left corner.
	gotoxy(109, 26);
	styling(179);        //    right side |.
	gotoxy(109,25);
	styling(191);        //    upper right corner.	
	gotoxy(109,27);
	styling(217);       //   lower right corner.
	for(int e=52; e<=108; e++)
	{
		int row = 25;
		gotoxy(e,row);
		styling(196);     //   upper row.
	}
	for(int f=52; f<=108; f++)
	{
		int row = 27;
		gotoxy(f,row);
		styling(196);     //   lower row.
	}
     	
}

void mainBorder()
{
	
// main heading.	
	
	gotoxy(65,8);
	cout << " Inventory Management System " << endl;

//  upper left corner.

	gotoxy(49,6);
	styling(201);

// upper straight row.
	
for(int b=50;b<=110;b++)
	{
		int row = 6;
		gotoxy(b,row);
		styling(205);
	}

// upper right corner.
	
	gotoxy(111,6);
	styling(187);

// left column.

	for(int a=7;a<=35;a++)
	{
		int coln = 49 ;
		gotoxy(coln,a);
		styling(186);
		
	}  

// right column.
	
	for(int c=7;c<=35;c++)
	{
		int coln = 111;
		gotoxy(coln,c);
		styling(186);
	}
	
// left lower corner.

	gotoxy(49,36);
	styling(200);
	
// right lower corner.

	gotoxy(111,36);
	styling(188);  
	
// lower straight row.

for(int d=50;d<=110;d++)
	{
		int row = 36;
		gotoxy(d,row);
		styling(205);
	} 
	
	
}
void esteric(int r){
	for(int g=3;g<=165;g++)
	{
		int row = r;
		gotoxy(g,row);
		cout<<'*';
	} 
}
