#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;
//function prototypes
int pickcoffeetype();
int calculateounces();
double calculatecost(int,int);
void displaycoffeereceipt();
void calculatefromfile();

	//constant variables
	const double P = 0.13;
	const double L = 0.23;
   	const double M = 0.25;
   	const double F = 0.28;
   	const double taxrate = 0.07;
   	
int main()  
 {  
 	int orders;
 	bool numordersvalid = false;
 	
 		cout<<"Welcome to the World's Best Coffee Shop"<<endl;
 		cout<<"Enter the number of orders: ";
 		cin>>orders;
 		
	//input validation
   	if (orders > 0)
	{
		numordersvalid=true;
	}
   	while (numordersvalid == false)
	{
		cout<<"You have input an invalid number.\nPlease input a number greater than 0.\n";
		cin>>orders;
		
		if (orders > 0)
		{
			numordersvalid=true;
	    }
	    
	}
    	
    	//Read from file if order number input is greater than 3
		if (orders > 3)
		{
		calculatefromfile();
		}
		else
		{
		//loop through process until there are no more orders to take
			while (orders > 0)
			{
				displaycoffeereceipt();
				orders = orders - 1;
			}
		}
		return 0;
	}
	//Function for menu display and selection
	int pickcoffeetype()
	{
		int myselection;
		bool wbcselectionvalid = false;
		//Coffee Selection
	   	cout<<"\n1 - Plain Coffee";
	   	cout<<"\n2 - Latte";
	   	cout<<"\n3 - Macchiato";
	   	cout<<"\n4 - Frappuccino\n";
	   	cout<<"\nEnter your choice (1-4): ";
	   	cin>>myselection;
	   	
	   	//input validation
	   	if (myselection > 0 && myselection < 5)
	   	{
	   		wbcselectionvalid=true;
		}
		while (wbcselectionvalid == false)
		{
			cout<<"You have input an invalid number.\nPlease input a number 1-4.";
			cin>>myselection;
			
			if (myselection > 0 && myselection < 5)
	   		{
	   			wbcselectionvalid=true;
			}
		}
	   	return myselection;
	}
	//Ounces calculation function
	int calculateounces()
	{
		int VENTI=24; 
		int GRANDE=16;
    	int REGULAR=8;
    	int ounces;
    	bool ouncesvalid = false;
    	int amt_VENTI;
		int amt_GRANDE;
		int amt_REGULAR;
		int amt_SHOT;
		int totalounces;
    
		//Ounces amount
	   	cout<<"\nEnter the amount of coffee in ounces: ";
	   	cin>> ounces;
	   	totalounces = ounces;
	   	
	   	//Input Validation
	   	if (ounces > 0)
		{
			ouncesvalid = true;
		}
		while (ouncesvalid == false)
		{
			cout<<"You have input an invalid number.\nPlease enter a number greater than 0.";
			cin>>ounces;
			
			if (ounces > 0)
			{
				ouncesvalid = true;
			}
		}
		
		//Cup Calculation
		amt_VENTI = ounces / VENTI;
	   	ounces = ounces % VENTI;
	   	
	   	amt_GRANDE = ounces / GRANDE;
	   	ounces = ounces % GRANDE;
	   	
	   	amt_REGULAR = ounces / REGULAR;
	   	ounces = ounces % REGULAR;
	   	
	   	//Functionality: If amount of shot cups exceeds 3, put ounces in regular cup.
	   	if (ounces > 3)
	   	{
	   	amt_REGULAR = amt_REGULAR + 1;
		amt_SHOT = 0;	
		}
	   	 else if (ounces < 4)
	   	{
	   	amt_SHOT = ounces;
	    }
	   	
	   	//Display
	   	cout<<"\nCup size	Number Needed"<<endl;
	   	cout<<"-----------------------------"<<endl;
		cout<<"Venti: 		"<<amt_VENTI<<endl;
		cout<<"Grande: 	"<<amt_GRANDE<<endl;
		cout<<"Regular: 	"<<amt_REGULAR<<endl;
		cout<<"Shot: 		"<<amt_SHOT<<endl;
		return totalounces;
	}
	//cost calculation
	double calculatecost(int wbcselection, int ounces)
	{
		double mycost;
		if (wbcselection == 1)
		{
	   	mycost = P * ounces;
		   }
		else if (wbcselection == 2)
	   	{
	   	mycost = L * ounces;
		   }
		else if (wbcselection == 3)
	   	{
	   	mycost = M * ounces;
		   }
		else if (wbcselection == 4)
	   	{
	   	mycost = F * ounces;
		   }
		
		return mycost;
	}
	//Coffee receipt display function
	void displaycoffeereceipt()
	{
		int mycoffeetype;
		int myounces;
		double total;
		string typetext = "";
		string customer = "";
		double cost;
		double totaltax;
		
	
	   	mycoffeetype = pickcoffeetype();
	   	
	   //Customer name
	   	cin.clear();
	   	cin.ignore();
	   	cout<<"Enter the name of the customer:";
	   	getline(cin, customer, '\n');
	   	
	   	if (mycoffeetype == 1)
	   	{
	   		typetext = "Plain Coffee";	
		}
		else if (mycoffeetype == 2)
		{
			typetext = "Latte";
		}
	   	else if (mycoffeetype == 3)
		{
			typetext = "Macchiato";
		}
		else if (mycoffeetype == 4)
		{
			typetext = "Frappuccino";
		}
	   	
	   	myounces = calculateounces();
	   	
	   	cost = calculatecost(mycoffeetype,myounces);
	   	cout<<"\n"<<customer;
	   	cout<<"\nOrder: "<<typetext<<" "<<myounces<<" oz";
	   	cout<<"\nPrice of Coffee: $"<< cost;
	   	totaltax = taxrate * cost;
	   	total = totaltax + cost;
		cout<<setprecision(2)<<fixed;
		cout<<"\nSales Tax: $"<<totaltax<<endl;
		cout<<"Total Amount Owed: $"<<total<<endl;
	   	
	}
	//File reading function
	void calculatefromfile()
	{
		string fileinput;
		int counter = 1;
		double salestax;
		double coffee_amount;
		double total;
		double totalbill = 0;
		double highestprice = 0;
		string biggestspender = "";
		
		ifstream myfile;
		myfile.open("CoffeeOrders.txt");
		string loopounces;
		int loopouncesint;
		string looptype;
		string loopname;
		while (getline(myfile,fileinput,'\n'))
		{
			
			if (counter == 1)
			{
			loopname = fileinput;
			counter = 2;
			fileinput = "";
			}
			else if (counter == 2)
			{
			loopounces = fileinput;
			loopouncesint = atoi(loopounces.c_str());
			counter = 3;
			fileinput = "";
			}
			else if (counter == 3)
			{
			looptype = fileinput;
			counter = 4;
			fileinput = "";	
			}
			else if (counter == 4)
			{
			//Do calculations
			cout<<loopname<<endl;
			cout<<"Order: "<<looptype <<" "<<loopouncesint << "oz\n";
			if(looptype == "Plain Coffee")
			{
				coffee_amount = loopouncesint * P;
			}
			else if (looptype == "Latte")
			{
				coffee_amount = loopouncesint * L;
			}
			else if (looptype == "Macchiato")
			{
				coffee_amount = loopouncesint * M;
			}
			else if (looptype == "Frappuccino")
			{
				coffee_amount = loopouncesint * F;
			}
			cout << "Price of Coffee: $"<<coffee_amount<<endl;
			salestax = taxrate * coffee_amount;
			cout<<setprecision(2)<<fixed;
			cout << "Sales Tax: $"<<salestax<<endl;
			total = coffee_amount + salestax;
			cout << "Total Amount Owed: $"<<total<<endl<<endl<<endl;
			totalbill = totalbill + total;
			if (total > highestprice)
			{
				highestprice = total;
				biggestspender = loopname;
			}
			counter = 1;
			fileinput = "";
			loopname = "";
			looptype = "";
			loopouncesint = 0;
			loopounces = "";
			
			}
			
		}
		myfile.close();
		cout<<"The total amount of all of the bills in the file is $"<<totalbill<<endl;
		cout<<biggestspender<<" had the highest bill at $"<<highestprice;
	}
