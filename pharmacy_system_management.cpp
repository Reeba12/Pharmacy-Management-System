#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;

//variables
const int MAX_ITEMS = 30;
string drugNames[MAX_ITEMS];
int drugPrices[MAX_ITEMS];
int drugCounts[MAX_ITEMS];
int drugSold[MAX_ITEMS];
int nStocks = 0;
int back;
string orderReturns[MAX_ITEMS];
int returnCount = 0;
int tmpInt,tmpNum, totalCash = 0, couponAmout = 0;
string tmpString;


//Functions
void pause();
void sortArray(int[]);
void banner(string);
int getItemIndex(string);
int getMaxIndex(int[], int);
void swap(int, int);

//classes
class LoginSystem{
	public:
		void Login();
		void Register(); 
		LoginSystem(); //constructor
};

LoginSystem::LoginSystem(){
}
class Admin{
	public:
		int adminMenu();
		void drugDealerLicense();
		void listReturns();
		void transactions();
		bool newItem(int,string, int, int);
		Admin(); //constructor
};
Admin::Admin(){
}
class Customer{
	public:
		void order_list();
		void take_order();
		Customer(); //constructor
};
Customer::Customer(){
}

//Structure
struct drugData{
	int slip_number,x;
	string customer_name,date;
	int quantity[10];
	int menu2[10];
	double amount[10];
	double total;
	string medicineName[10]={"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet","Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	
	drugData *next;
	drugData *prev;
	drugData *link;
};
drugData *start_ptr = NULL;
drugData *head = NULL;
drugData *last = NULL;
int main(){
	int select;
	LoginSystem loginObj;
	cout<<endl;
	cout<<endl;
	wcout<<"\t\t***************************** WELCOME TO SUPER PHARMACY ********************************\n";
	cout<<"\t\t1 : Login"<<endl;
	cout<<"\t\t2 : Register"<<endl;
	cout<<"\t\t3 : Exist"<<endl;
	cout<<"\t\tPlease select:"<<endl;
	cin>>select;
	cout<<endl;
	
	switch(select){
		case 1:
			system("cls");
			loginObj.Login();
			break;
		case 2:
			system("cls");
			loginObj.Register();
			break;	
		case 3:
			cout<<"\t\t\t\tThanks for Your Time";
			break;
		default:
			cout<<"\t\t\t\tPlease select anyone from above"<<endl;	
	};
	
	
}
void LoginSystem::Register(){
	string newUsername,newId,newPass,newPassword,newRole;
	cout<<endl;
	cout<<endl;
	cout<<"================Create your Acoount==============="<<endl;
	cout<<"Enter Username: ";
	cin>>newUsername;
	cout<<"Enter Password: ";
	cin>>newPassword;
	cout<<"Enter Role: ";
	cin>>newRole;
	
	ofstream addUser("user.txt",ios::app);
	addUser<<newUsername<<' '<<newPassword<<' '<<newRole<<endl;
	system("cls");
	main();
}
void LoginSystem::Login(){
	int count;
	string username,password,id,pass,role,checkrole;
	cout<<endl;
	cout<<endl;
	cout<<"================Login to your Acoount==============="<<endl;
	cout<<"Enter Username and Password"<<endl;
	cout<<"USERNAME: ";
	cin>>username;
	cout<<"PASSWORD: ";
	cin>>password;
	cout<<"ROLE: ";
	cin>>role;
	
	ifstream checkUser("user.txt");
	while(checkUser>>id>>pass>>checkrole){
		if(id==username && pass==password && checkrole==role){
			count=1;
			cout<<role;
			system("cls");
		}
	}
	checkUser.close();
	
	if(count==1 && role=="admin"){
		while(true){
		Admin adminObj;
		int option = adminObj.adminMenu();

				if(option == 1){
					system("cls");
					banner("User > Admin > transcation");
					adminObj.transactions();
							cout<<"<--Go Back! press 0"<<endl;
					cin>>back;
					if(back==0){
//						adminObj.adminMenu();
					}
				}
				else if(option == 2){
					int opt;
					system("cls");
					banner("User > Admin > Add New item");
					cout << "Drug Number: ";
					cin >> tmpNum;
					cout << "Drug Name: ";
					cin >> tmpString;
					cout << "Price: ";
					cin >> tmpInt;
					cout << "Stock Quantity: ";
					cin>>option;
					adminObj.newItem(tmpNum,tmpString, tmpInt, option);
			
//					if(!adminObj.newItem(tmpString, tmpInt, option)){
//						cout << "We cannot add more new items" << endl;
//					}
				}
				else if(option == 3){
					system("cls");
					banner("User > Admin > Drug Dealer License");
					adminObj.drugDealerLicense();
						cout<<"<--Go Back! press 0"<<endl;
					cin>>back;
					if(back==0){
						adminObj.adminMenu();
					}
				}
				else if(option == 4){
					system("cls");
					banner("User > Admin > Returns");
					adminObj.listReturns();
					cout<<"<--Go Back! press 0"<<endl;
					cin>>back;
					if(back==0){
						adminObj.adminMenu();
					}
				}
				else if(option == 5){
					break;
				}
				else {
					cout << "Invalid option" << endl;
				}
		}
	}
	else if(count==1 && role=="customer"){
		cout<<"i am customer";
		banner("User > Customer");
		Customer customerObj;
		customerObj.take_order();
	}
	else{
		system("cls");
		cout<<"Account with this name does not exist"<<endl;
		main();
	}
}
void banner(string s){
	cout << s << endl;
	wcout << L"\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4\u00c4" << endl;
}
int getItemIndex(string name){
	for(int i = 0; i < nStocks; i++){
		if(drugNames[i] == name){
			return i;
		}
	}

	return -1;
}
void sortArray(int array[]){
	for(int i = 0; i < nStocks; i++){
		swap(i, getMaxIndex(array, i));
	}
}
int getMaxIndex(int array[], int start){
	int max = start;

	for(int i = start; i < nStocks; i++){
		if(array[i] > array[max]){
			max = i;
		}
	}

	return max;
}
void swap(int idx1, int idx2){
	tmpString = drugNames[idx1];
	drugNames[idx1] = drugNames[idx2];
	drugNames[idx2] = tmpString;

	tmpInt = drugPrices[idx1];
	drugPrices[idx1] = drugPrices[idx2];
	drugPrices[idx2] = tmpInt;

	tmpInt = drugCounts[idx1];
	drugCounts[idx1] = drugCounts[idx2];
	drugCounts[idx2] = tmpInt;

	tmpInt = drugSold[idx1];
	drugSold[idx1] = drugSold[idx2];
	drugSold[idx2] = tmpInt;
}
void pause(){
	cin.ignore();
	getchar();
}

int Admin::adminMenu(){
	int opt;
	system("cls");
	banner("User > Admin");
	cout<< "1. View sales and total cash" << endl
		<< "2. Add new item" << endl
		<< "3. Show drug dealer license" << endl
		<< "4. View returned orders" << endl
		<< "5. Go back to main menu" << endl;
	cin >> opt;

	return opt;
}

void Admin::transactions(){
	if(nStocks != 0){
		sortArray(drugSold);

		for(int i = 0; i < nStocks; i++){
			cout << drugNames[i] << ": " << drugSold[i] << endl; 
		}
	}
	else {
		cout << "No item sold" << endl;
	}

	cout << "Total Cash: Rs. " << totalCash << "/-" << endl;
}


bool Admin::newItem(int medicineNum,string medicineName, int medicinePrice, int count){
	ofstream addmedicine("drug.txt",ios::app);
	addmedicine<<medicineNum<<'--'<<medicineName<<' '<<medicinePrice<<' '<<count<<endl;

}
void Admin::drugDealerLicense(){
	cout<<endl;
	cout <<"\t\t\t\t\t\tPHARMACY OF PAKISTAN\t\t\t\t" << endl;
	cout<<"\t\t\t**************************************************************************"<<endl;
	cout<<"\t\t\t**\t\t\t\t\t\t\t\t\t**"<<endl;
	cout<<"\t\t\t**\t\t\t\t\t\t\t\t\t**"<<endl;
	cout<<"\t\t\t**\t\t\t\t\t\t\t\t\t**"<<endl;
	cout <<"\t\t\t**\t\t\tIssued to: Reeba Siddiqui\t\t\t**" << endl
		<< "\t\t\t**\t\t\tLicense number: 123456-DRA\t\t\t**" << endl
		<< "\t\t\t**\t\t\tIssuer: Drug Regulatory Authority\t\t**" << endl
		<< "\t\t\t**\t\t\tExpiry Date: 30-12-2035\t\t\t\t**" << endl;
	cout<<"\t\t\t**\t\t\t\t\t\t\t\t\t**"<<endl;
	cout<<"\t\t\t**\t\t\t\t\t\t\t\t\t**"<<endl;
	cout<<"\t\t\t**\t\t\t\t\t\t\t\t\t**"<<endl;
	cout<<"\t\t\t**************************************************************************"<<endl;
}

void Admin::listReturns(){
	if(returnCount > 0){
		for(int i = 0; i < returnCount; i++){
			cout << i + 1 << ". " << orderReturns[i] << endl;
		}
	}
	else {
		cout << "No product has been returned yet" << endl;
	}
}
void listItems(){
	sortArray(drugCounts);

	tmpInt = 0;
	for(int i = 0; i < nStocks; i++){
		if(drugCounts[i] != 0){
			cout << tmpInt + 1 << ". " << drugNames[i] << endl;
			tmpInt++;
		}
	}
}

void Customer::take_order()		//function to take_order
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";

	drugData *temp;
		
//	string getcontent;
//    ifstream openfile ("drug.txt");
//    if(openfile.is_open())
//    {
//    	cout <<"******************************************************************************************\n";
//				cout<<"\t\tDRUGS TYPE"<<"   \tDRUGS NAME"<<"           \tDRUGS PRICE(RM)"<<"\t\tDRUG STOCK"<<endl;
//				cout <<"*************************************************************************************\n";
//        while(! openfile.eof())
//        {
//            getline(openfile, getcontent);
//            cout <<"\t"<<"\tOTC"<<"\t\t"<< getcontent << endl;
//        }
//    }
//	sortArray(drugCounts);
	tmpInt = 0;
	for(int i = 0; i < nStocks; i++){
		if(drugCounts[i] != 0){
			cout <<"medicine"<< tmpInt + 1 << ". " << drugNames[i] << endl;
			tmpInt++;
		}
	}
				cout <<"**************************************************************************\n";
				cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"   \t\tDRUGS NAME"<<"           DRUGS PRICE(RM)"<<endl;
				cout <<"**************************************************************************\n";
                cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Probiotics"<<"			RM 2.00"<<endl;
                cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin C(500mg)"<<"		RM 3.00"<<endl;
                cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Acid Free C(500mg)"<<"		RM 1.00"<<endl;
                cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Women'S Multivate"<<"		RM 4.00"<<endl;
                cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Marino Tablet"<<"	 	RM 1.00"<<endl;
                cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maxi Cal Tablet"<<" 		RM 5.00"<<endl;
                cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amino Zinc Tablet"<<"		RM 7.00"<<endl;
                cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Burnex"<<"			RM 4.00"<<endl;
                cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Fabuloss 5"<<"			RM 3.00"<<endl;
                cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Royal Propollen"<<"		RM 5.00"<<endl;
                cout<<" "<<endl;
    
	temp = new drugData;
	cout << "Type Order no: ";
    cin >> temp->slip_number;
	cout<< "Enter Customer Name: ";
	cin>> temp->customer_name;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order: ";
//	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection : "<<endl;
		cin>> temp->menu2[i];
		cout<<temp->menu2[i];
        cout<< "Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay is: " << temp->amount[i]<<" RM"<<endl;
        system("PAUSE");
                      
	}
	cout<<"==========================================================================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"==========================================================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}//End function take_order

void Customer::order_list()		//Function to display receipt
{
	int i, num, num2;	
	bool found;			//variable to search 
	system("cls");
	drugData *temp;

	temp=start_ptr;
	found = false;
	
	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\t\tHere is the Order list\n"; 
	cout<<"==========================================================================="<<endl;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->slip_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
		cout <<"Reciept Number : "<<temp->slip_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customer_name<<endl;
				
		cout<<"Order Date : "<<temp->date<<endl;
				
		cout<<"_____________________________________________________________________________"<<endl;
			
		cout << "===============================================================================" << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
//			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" RM"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}
	}
}
