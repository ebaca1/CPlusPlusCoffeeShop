#include <iostream>
#include <string>
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
   	
   	int wbcselection;
   	double coffee_amount;
   	double total;
   	
   	const double tax = 0.07;
   	double salestax;
   	
   	const double P = 0.13;
	const double L = 0.23;
   	const double M = 0.25;
   	const double F = 0.28;
   	
   	string customer = "";
   	
   	//Coffee Selection
   	cout<<"Welcome to the World's Best Coffee Shop\n";
   	cout<<"\n1 - Plain Coffee";
   	cout<<"\n2 - Latte";
   	cout<<"\n3 - Macchiato";
   	cout<<"\n4 - Frappuccino\n";
   	cout<<"\nEnter your choice (1-4): ";
   	cin>>wbcselection;
   	
   	//Input Validation
   	if (wbcselection < 1)
    {
   	cout<<"You have input an invalid selection.\n";
	cout<< "Please restart the program and enter a number between 1 and 4.";
	return 0;
	}
	
   	if (wbcselection > 4)
   	{
	cout<<"You have input an invalid selection.\n";
	cout<< "Please restart the program and enter a number between 1 and 4.";
	return 0;
	}
	else if(wbcselection > 0) (wbcselection < 5);
	
	//Ounces amount
   	cout<<"\nEnter the amount of coffee in ounces: ";
   	cin>> ounces;
   	
   	//Input Validations
   	if (ounces <=0)
   	{
   	cout<<"You have input an invalid selection.\n";
	cout<< "Please restart the program and enter a number of ounces greater than 0.";
	return 0;
	}
	
	else if (ounces > 0);
   	
   	cin.clear();
   	cin.ignore();
   	
   	//Customer name
   	cout<<"Enter the name of the customer:";
   	getline(cin, customer, '\n');
   	
   	//Reciept Display
   	cout<<"\n"<<customer << endl;
   	
	   if (wbcselection = 1)
   	{cout<<"Order: Plain Coffee "<<ounces <<" oz\n";
   	coffee_amount = P * ounces;
	   }
	else if (wbcselection = 2)
   	{cout<<"Order: Latte "<<ounces <<" oz\n";
   	coffee_amount = L * ounces;
	   }
	else if (wbcselection = 3)
   	{cout<<"Order: Macchiato "<<ounces <<" oz\n";
   	coffee_amount = M * ounces;
	   }
	else if (wbcselection = 4);
   	{cout<<"Order: Frappuccino "<<ounces <<" oz\n";
   	coffee_amount = F * ounces;
	   }
	
	cout<<"Price of Coffee: $"<<coffee_amount;
	
	salestax = coffee_amount * tax / 100;
	cout<<"\nSales Tax: $"<<tax;
	
	total = coffee_amount + tax;
	cout<<"\nTotal Amount Owed: $"<<total;
	
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
   	 else if (ounces < 3)
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
	return 0;
}
