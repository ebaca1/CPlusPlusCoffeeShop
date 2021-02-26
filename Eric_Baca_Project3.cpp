#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;


int main()  
 {  
      int VENTI=24; 
	int GRANDE=16;
    int REGULAR=8;
	int amt_VENTI;
	int amt_GRANDE;
	int amt_REGULAR;
	int amt_SHOT;
   	int ounces;
   	int orders;
   	bool numordersvalid = false;
   	bool wbcselectionvalid = false;
   	bool ouncesvalid = false;
   	
   	int wbcselection;
   	double coffee_amount;
   	double total;
   	
   	const double taxrate = 0.07;
   	double salestax;
   	
   	const double P = 0.13;
	const double L = 0.23;
   	const double M = 0.25;
   	const double F = 0.28;
   	
   	string customer = "";
   	
   
   	cout<<"Welcome to the World's Best Coffee Shop\n";
   	//number of orders
   	cout<<"Enter the number of orders:";
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
		if (orders > 3)
	{
		//for reading text file
		string fileinput;
		int counter = 1;
		
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
			counter = 1;
			fileinput = "";
			loopname = "";
			looptype = "";
			loopouncesint = 0;
			loopounces = "";
			
			}
		}
		myfile.close();
	}
		else 
	{
		while (orders > 0)
		{
	   	//Coffee Selection
	   	cout<<"\n1 - Plain Coffee";
	   	cout<<"\n2 - Latte";
	   	cout<<"\n3 - Macchiato";
	   	cout<<"\n4 - Frappuccino\n";
	   	cout<<"\nEnter your choice (1-4): ";
	   	cin>>wbcselection;
	   	
	   	//input validation
	   	if (wbcselection > 0 && wbcselection < 5)
	   	{
	   		wbcselectionvalid=true;
		}
		while (wbcselectionvalid == false)
		{
			cout<<"You have input an invalid number.\nPlease input a number 1-4.";
			cin>>wbcselection;
			
			if (wbcselection > 0 && wbcselection < 5)
	   		{
	   			wbcselectionvalid=true;
			}
		}
		
		//Ounces amount
	   	cout<<"\nEnter the amount of coffee in ounces: ";
	   	cin>> ounces;
	   	
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
	   	
	   	cin.clear();
	   	cin.ignore();
	   	
	   	//Customer name
	   	cout<<"Enter the name of the customer:";
	   	getline(cin, customer, '\n');
	   	
	   	//Reciept Display
	   	cout<<"\n"<<customer << endl;
	   	
		   if (wbcselection == 1)
	   	{cout<<"Order: Plain Coffee "<<ounces <<" oz\n";
	   	coffee_amount = P * ounces;
		   }
		else if (wbcselection == 2)
	   	{cout<<"Order: Latte "<<ounces <<" oz\n";
	   	coffee_amount = L * ounces;
		   }
		else if (wbcselection == 3)
	   	{cout<<"Order: Macchiato "<<ounces <<" oz\n";
	   	coffee_amount = M * ounces;
		   }
		else if (wbcselection == 4)
	   	{cout<<"Order: Frappuccino "<<ounces <<" oz\n";
	   	coffee_amount = F * ounces;
		   }
		
		cout<<"Price of Coffee: $"<<coffee_amount;
		
		salestax = coffee_amount * taxrate;
		cout<<setprecision(2)<<fixed;
		cout<<showpoint<<"\nSales Tax: $"<<salestax;
		
		total = coffee_amount + salestax;
		cout<<showpoint<<"\nTotal Amount Owed: $"<<total;
		
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
		orders = orders - 1;
		}
	}
		return 0;
	}
