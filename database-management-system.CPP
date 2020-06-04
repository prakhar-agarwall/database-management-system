/* DATABASE MANAGEMENT SYSTEM - By Prakhar Agarwal */

//password=allstars

#include<fstream.h>
#include<conio.h>
#include<iomanip.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>

ifstream ifs;
ofstream ofs;
fstream fs;

class penss
{       char name[20];
	float price;
	int qty,serialno;
	char cusname[20],arname[20];
	int age,cusno;
	public:
	void getidata();
	int getqty()
		{ return qty; }
	int getserialno()
		{ return serialno; }
	float getprice()
		{ return price; }
	char getname()
		{ return name[20]; }
	void display2();
	void qtychange(int q);
	void deletee();
	void modify();
	void add();
	void display();
	void search();
	void menu();
	void admin();
	void cusdisplay();
	void getcusdata();
	int getcusno()
	{ return cusno; }
	void cusview();
	void cusmodify();
	void cusdelete();
	void cusadd();
	void display3();
}pen;

void asd();		//Declaring the prototype for the functions
void asf();
void asg();
void custo();
void menu();
void admin();
void bill();
void password(int cho);
int q,bno=0;

void main()
{	clrscr();
	menu();		//Calling the menu function
	getch();
}
void menu()
{	textcolor(10);
	textbackground(20);
	int choice;
	do
	{	textcolor(20);
		textbackground(10);
		clrscr();
		cout<<"\n\n\n\t      Welcome to the T_H_E  A_L_L  S_T_A_R_S  P_E_N  S_H_O_P\n\n\n";
		cout<<setw(81)<<setfill('-')<<" "<<endl;
		cout<<"\t\t\t\t    M.E.N.U\n"<<endl;
		cout<<setw(81)<<setfill('-')<<" "<<endl;
		cout<<"\n\t\t1. A.D.M.I.N\n";
		cout<<"\n\t\t2. U.S.E.R\n";
		cout<<"\n\t\t3. E.X.I.T\n";
		cout<<"\n\n\t\t\tEnter your choice:";
		cin>>choice;
		switch(choice)
			{	case 1:password(0);		//Calling the function for password
				case 2:asf();
				       asd();
				       asg();
				       custo();			//Calling the function for users

				case 3:cout<<"\n\t\t Thank You For Visiting THE ALL STARS PEN SHOP\n";
				       cout<<"\t\t Visit Again Soon..!!!";
				       getch();
				       exit(0);
			       default:cout<<"\n\t\t\tSorry..!!!Wrong choice\n";
				       cout<<"\t\t\tExiting the shop";
				       getch();
				       exit(0);
				       break;
			}
	}while(choice!=3);
		getch();
}

void password(int cho)			//This function is used to check the password
{	clrscr();
	textcolor(10);
	textbackground(1);
	char pass[20],ch;
	int i,j;
	cout<<"\n\n\n\t\tT_H_E  A_L_L  S_T_A_R_S  P_E_N  S_H_O_P\n\n\n";
	cout<<"\nComplete the password setup to enter the shop\n\n";
	for(j=1;j<=3;j++)
	{	cout<<"Enter the password\n";
		i=0;
		while((ch=getch())!=13)
		{	pass[i]=ch;
			i++;
			cout<<"*";
		}
		pass[i]='\0';
		if(strcmp(pass,"allstars")==0)
		       {	cout<<"\n\n\n\t\tAccess granted\n";
				cout<<"\t\tEntering the The All Stars Pen Shop.....\n";
				cout<<"\n\n\n\n\n\n\n\n	\t\t\t\t\t";
				asd();
				asf();
				asg();
				admin();		//If entered password is correct
				break;			//then admin function is called*/
		       }
		if(j<2)
		{	cout<<"\nIncorrect password";
			cout<<"\nSorry..!!! Try again\n";
			cout<<"\n";
		}
		else if(j<3)
		{	cout<<"\nIncorrect password";
			cout<<"\nSorry..!!! Try again last time\n";
			cout<<"\n";
		}
		else
		{	cout<<"\n\n\t\t\tAccess not granted";
			cout<<"\n\t\t\tSorry..!!! Try again later";
			cout<<"\n\t\t\tReturning to the main menu \n";
			getch();
			menu();			//If entered password is not correct
		}				// then menu function is called
	}
}

void asd()
{        clrscr();
	 textcolor(10);
	 textbackground(6);
	 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\tLOADING";
	 for(int i=0;i<50;i++)
	 {	 delay(17);
		 cout<<"_";
	 }
}

void asf()
{        clrscr();
	 textcolor(10);
	 textbackground(4);
	 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\tLOADING";
	 for(int i=0;i<50;i++)
	 {	 delay(17);
		 cout<<"_";
	 }
}

void asg()
{        clrscr();
	 textcolor(10);
	 textbackground(8);
	 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\tLOADING";
	 for(int i=0;i<50;i++)
	 {	 delay(17);
		 cout<<"_";
	 }
}

void admin()
{  	textcolor(BLUE);
	int cho;
	textbackground(YELLOW);
	do{
	clrscr();
	cout<<"\n\t\t  T_H_E  A_L_L  S_T_A_R_S  P_E_N  S_H_O_P\n\n";
	cout<<"\t\t\t\t###############";
	cout<<"\n\t\t\t\t### M.E.N.U ###";			//Displaying the menu for admin
	cout<<"\n\t\t\t\t###############";
	cout<<"\n\n\n\t\t  ***************************************";
	cout<<"\n\t\t  *  1. A.D.D pen details               * \n";
	cout<<"\t\t  *  2. D.I.S.P.L.A.Y all pen details   * \n";
	cout<<"\t\t  *  3. M.O.D.I.F.Y the pen details     * \n";
	cout<<"\t\t  *  4. S.E.A.R.C.H pen by serial number*\n";
	cout<<"\t\t  *  5. D.E.L.E.T.E pen detail          *\n";
	cout<<"\t\t  *  6. A.D.D customer details          *\n";
	cout<<"\t\t  *  7. D.I.S.P.L.A.Y customer details  *\n";
	cout<<"\t\t  *  8. M.O.D.I.F.Y customer details    *\n";
	cout<<"\t\t  *  9. D.E.L.E.T.E customer detail     *\n";
	cout<<"\t\t  * 10. R.E.T.U.R.N to main menu        *\n";
	cout<<"\t\t  ***************************************";
	cout<<"\nEnter your choice:";
	cin>>cho;
	switch(cho)
		{       case 1:pen.add();		//Calling the function for
			       break ;		        //adding a pen entry
			case 2:clrscr();
			       pen.display();		//Calling the function for
			       break;			//displaying a pen entry

			case 3:pen.modify();		//Calling the function for
			       break;			//modifying a pen entry

			case 4:pen.search();		//Calling the function to
			       break;			//search pen by serial number

			case 5:pen.deletee();		//Calling the function for
			       break;			//deleting a pen entry

			case 6:pen.cusadd();		//Calling the function for
			       break ;			//adding a customer entry
			case 7:clrscr();
			       pen.cusview();		//Calling the function for
			       break;			//displaying a customer entry

			case 8:pen.cusmodify();	//Calling the function for
			       break;			//modifying a customer entry

			case 9:pen.cusdelete();	//Calling the function for
			       break;			//deleting a customer entry

			case 10:cout<<"\nReturning to main menu";
			       cout<<"\nVisit again soon ";
			       getch();
			       clrscr();
			       menu();
			       return;
		       default:cout<<"\nSorry..!!!Wrong choice\n";
			       cout<<"Returning to the main menu\n";
			       getch();
			       menu();
			       break;
		}
	}while(cho!=11);
}

void custo()		//This function is for users
{       int ccho;
	do{	textcolor(10);
		textbackground(1);
		clrscr();
		cout<<"\n\n\n\t\t  T_H_E  A_L_L  S_T_A_R_S  P_E_N  S_H_O_P\n\n\n";
		cout<<"\t\t\t\t###############";
		cout<<"\n\t\t\t\t### M.E.N.U ###";
		cout<<"\n\t\t\t\t###############";
		cout<<"\n\n\n\n\t        ***************************************";
		cout<<"\n\t\t*1. P.R.O.D.U.C.T  M.E.N.U            * ";
		cout<<"\n\t\t*2. B.I.L.L.I.N.G                     * ";
		cout<<"\n\t\t*3. S.E.A.R.C.H                       * ";
		cout<<"\n\t\t*4. R.E.T.U.R.N  T.O  M.A.I.N  M.E.N.U* ";
		cout<<"\n\t        ***************************************";
		cout<<"\n\nEnter your choice:";
		cin>>ccho;
		switch(ccho)
			{	case 1: clrscr();
					pen.display();
					break;
				case 2: clrscr();
					bill();
					break;
				case 3: pen.search();
					break;
				case 4: cout<<"\n\nReturning to main menu";
					cout<<"\nVisit again soon ";
					getch();
					clrscr();
					menu();
					return;
			       default: cout<<"Sorry..!!!Wrong choice\n";
					getch();
					menu();
					break;
			}
	}while(ccho!=5);
}
void penss::getidata()
{	cout<<"\n\nPen Serial Number: ";
	cin>>serialno;
	cout<<"\nPen Name: ";
	cin>>name;
	cout<<"\nPen Price: ";
	cin>>price;
	cout<<"\nPen Quantity: ";
	cin>>qty;
}

void penss::display2()
{	cout<<"\n\nPens Serial Number: "<<serialno;
	cout<<"\nPens Name: "<<name;
	cout<<"\nPens Price: "<<price;
	cout<<"\nPens Quantity: "<<qty;
}

void penss::add()		//This function is used to add the pen entries
{	clrscr();
	cout<<"\n\n Add the details for pen "<<endl;
	char ch='y';
	ofs.open("pen.dat",ios::app|ios::binary);
	while(ch=='y')
	{	pen.getidata();
		 ofs.write((char*)&pen,sizeof(pen));
		 cout<<"\nRecord added";
		 cout<<"\nDo you want to enter more records(Y/N)?";
		 cin>>ch;
	}
	ofs.close();
	cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
	getch();
}

void penss::display()		//This function is used to display the pen entries
{       clrscr();
	cout<<"\n\n\t\t\t:::::::::PRODUCT DETAILS:::::::::\n\n\n";
	ifs.open("pen.dat",ios::in);
	if(!ifs)
	{	cout<<"\nNo pen details found";
		cout<<"\nTry first adding the details";
		getch();
	}
	else
	{	while(!ifs.eof())
		{	ifs.read((char*)&pen,sizeof(pen));
			if(ifs.eof())
			break;
			cout<<"Pen name is            : "<<name<<endl;
			cout<<"Pen  serial number is  : "<<serialno<<endl;
			cout<<"Pen  quantity is       : "<<qty<<endl;
			cout<<"Pen price is           : "<<price<<endl;
			cout<<"\n\n";
		}
	}
	ifs.close();
	cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
	getch();
}

void penss::modify()		//This function is used to modify the pen entries
{       clrscr();
	int no,pos,newprice,newqty,flag=0;
	char newname[20]=" ";
	fs.open("pen.dat",ios::in|ios::out|ios::binary);
	cout<<"\nEnter the pen serial number to modify:";
	cin>>no;
	while(!fs.eof())
	{	pos=fs.tellg();
		fs.read((char*)&pen,sizeof(pen));
		if(pen.getserialno()==no)
		{	cout<<"Old details of pen are \n";
			pen.display2();
			cout<<"\n\nEnter new details";
			cout<<"\nEnter new name or enter'.' to skip\n";
			cin>>newname;
			cout<<"\nEnter new pen price or enter '-1' to skip\n";
			cin>>newprice;
			cout<<"\nEnter new pen left in stock or enter '-1' to skip\n";
			cin>>newqty;
			if(strcmp(newname,".")!=0)
				strcpy(name,newname);
			if(newprice!=-1)
			    {	price=newprice; }
			if(newqty!=-1)
			   {	qty=newqty;  }
			fs.seekg(pos);
			fs.write((char*)&pen,sizeof(pen));
			flag=1;
			cout<<"\nPen details modified";
			cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
			getch();
			break;
		 }
	}
	fs.close();
	if(flag==0)
	    {	cout<<"\nNo pen details found";
		cout<<"\nTry first adding the details\n";
		cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
		getch();
	    }
}

void penss::search()		//This function is used to search pen by serial number
{       clrscr();
	int snumber,flag=0;
	ifs.open("pen.dat");
	cout<<"\nEnter pen serial number to be searched for: ";
	cin>>snumber;
	while(!ifs.eof())
		{	ifs.read((char*)&pen,sizeof(pen));
			if(pen.getserialno()==snumber)
			{	pen.display2();
				flag=1;
				cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
				getch();
				break;
			}
		}
	if(flag==0)
	{	cout<<"\nPen details not found";
		cout<<"\nTry again";
		cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
	}
	ifs.close();
	getch();
}

void penss::deletee()		//This function is used to delete the pen entries
{	clrscr();
	ifs.open("pen.dat",ios::in|ios::binary);
	ofs.open("temp.dat",ios::out|ios::binary);
	int psno,count=0;
	char confirm;
	cout<<"\nEnter pen serial number to be deleted: ";
	cin>>psno;
	while(ifs.read((char*)&pen,sizeof(pen)))
		{	if(pen.getserialno()!=psno)
			{	ofs.write((char*)&pen,sizeof(pen));
			}
			else
			{	cout<<"\nPen details found\n";
				pen.display2();
				cout<<"\n\nAre you sure you want to delete this record?(y/n):";
				cin>>confirm;
				if(confirm=='n'||confirm=='N')
				{	ofs.write((char*)&pen,sizeof(pen));
					count=2;
				}
				else
				count=1;
			}
		}
	ifs.close();
	ofs.close();
	if(count==0)
	{	cout<<"\nPen details not found";
		cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
		getch();
	}
	else if(count==2)
	{	cout<<"Record Not Deleted";
		cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
		getch();
	}
	else
	{	cout<<"\nRecord deleted";
		cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
		getch();
	}
	remove("pen.dat");
	rename("temp.dat","pen.dat");
}

void penss::qtychange(int q)
{     qty-=q;	 }

void penss::getcusdata()
{     	cout<<"\nCustomer Order Number: ";
	cin>>cusno;
	cout<<"\nCustomer Name: ";
	gets(cusname);
	cout<<"\nCustomer Age: ";
	cin>>age;
	cout<<"\nCustomer Area Name: ";
	gets(arname);
}

void penss::cusadd()			//This function is used to add the customer details
{	clrscr();
	char ch='y';
	ofs.open("customer.dat",ios::app|ios::binary);
	while(ch=='y')
	{	pen.getcusdata();
		ofs.write((char*)&pen,sizeof(pen));
		cout<<"\nRecord added to file";
		cout<<"\nDo you want to enter more records(Y/N)?";
		cin>>ch;
	}
	ofs.close();
	cout<<"\n\n\nPRESS ANY KEY TO CONTINUE\n";
	getch();
}

void penss::cusdisplay()
{	cout<<"\nCustomer Order Number: "<<cusno;
	cout<<"\nCustomer Name        : "<<cusname;
	cout<<"\nAge                  : "<<age;
	cout<<"\nArea Name            : "<<arname;
	cout<<"\n\n";
	getch();
}

void penss::cusview()		//This function is used to display the customer details
{ 	clrscr();
	ifs.open("customer.dat");
	if(!ifs)
	{	cout<<"\n\nSorry,no item bought from the shop ";
		getch();
	}
	else
	{       cout<<"\n\n\t\t\t:::::::::CUSTOMER DETAILS:::::::::\n\n";
		while(!ifs.eof())
		{	ifs.read((char*)&pen,sizeof(pen));
		if(ifs.eof())
			break;
		pen.cusdisplay();
		}
	}
	ifs.close();
	cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
	getch();
}

void penss::cusmodify()		//This function is used to modify the customer details
{       clrscr();
	int id,pos,st;
	char found='f',newname[200]=" ",ar[400]=" ";
	fs.open("customer.dat",ios::in|ios::out|ios::binary);
	cout<<"\nEnter Customer order number whose record is to be modified:";
	cin>>id;
	while(!fs.eof())
		{	pos=fs.tellg();
			fs.read((char*)&pen,sizeof(pen));
			if(pen.getcusno()==id)
				{	cout<<"\n\nOrignal Record\n";
					pen.cusdisplay();
					cout<<"\nEnter new details";
					cout<<"\nEnter customer name or enter '.'to skip\n";
					cin>>newname;
					cout<<"\nEnter area name of customer or enter '.' to skip\n";
					cin>>ar;
					if(strcmp(newname,".")!=0)
						strcpy(cusname,newname);
					if(strcmp(ar,".")!=0)
						strcpy(arname,ar);
					fs.seekg(pos);
					fs.write((char*)&pen,sizeof(pen));
					found='t';
					cout<<"\nRecord modified";
					break;
				}
		}
	fs.close();
	if(found=='f')
	cout<<"\nCustomer details not found ";
	cout<<"\n\n\nPRESS ANY KEY TO CONTINUE\n";
	getch();
}
void penss::cusdelete()		//This function is used to delete the customer details
{	clrscr();
	ifs.open("customer.dat",ios::in);
	fs.open("temp.dat",ios::out);
	int id;
	char confirm='n',found='f';
	cout<<"\nEnter customer order number whose record is to be deleted:";
	cin>>id;
	while(!ifs.eof())
	{	ifs.read((char*)&pen,sizeof(pen));
		if(ifs.eof())
		break;
		if(pen.getcusno()==id)
		{       cout<<"\n\nOld details are\n";
			pen.cusdisplay();
			found='t';
			cout<<"\nAre you sure you want to delete this record?(y/n):";
			cin>>confirm;
			if(confirm=='n')
			{	fs.write((char*)&pen,sizeof(pen));
				cout<<"\nRecord not deleted\n";
			}
			else
			{	cout<<"\nRecord deleted";
				getch();
			}
		}
		else
		fs.write((char*)&pen,sizeof(pen));
	}
	if(found=='f')
	{	cout<<"\nCustomer details not found";
		getch();
	}
	ifs.close();
	fs.close();
	remove("customer.dat");
	rename("temp.dat","customer.dat");
	cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
	getch();
}

void bill()		//This function is used to generate the invoice
{       textcolor(0);
	textbackground(15);
	char custname[30],custaddr[300],ans,ch=1;
	int bqty[50],q,pos;
	float rate,total=0,price;
	int i=0, id[50];
	long double mno;
	cout<<"\nEnter customer name:";
	gets(custname);
	cout<<"\nEnter mobile number(5 digit):";
	cin>>mno;
	ofs.write((char*)&pen,sizeof(pen));
	pen.display();
	do
	{       int flag=0;
		fs.open("pen.dat",ios::in|ios::out|ios::binary);
		cout<<"\nEnter the pen serial number you want to purchase:";
		cin>>id[i];
		while(!fs.eof())
		{	pos=fs.tellg();
			fs.read((char*)&pen,sizeof(pen));
			if(ifs.eof())
			break;
			if(pen.getserialno()==id[i])
			{	 cout<<"\n\tEnter reqiured quantity:";
				 cin>>bqty[i];
				 flag=1;
				 if(bqty[i]<=pen.getqty())
				 {	 q=bqty[i];
					 pen.qtychange(q);
					 fs.seekg(pos);
					 fs.write((char*)&pen,sizeof(pen));
				 }
				 else
				 {	cout<<"\nInsufficient quantity in the shop";
					bqty[i]=0;
					break;}
					break;
				 }
			}
			if(flag==0)
			{	cout<<"Pen details not found";
			}
			fs.close();
			cout<<"\nDo you want to purchase more items?(Y/N)";
			cin>>ans;
			i++;
	}while(ans=='y'||ans=='Y');
	clrscr();
	float nz=0,newtotal=0;
	cout<<"\n\n\t\tT_H_E  A_L_L  S_T_A_R_S  P_E_N  S_H_O_P\n\n";
	cout<<"\n34-B,Sector-13,GP Road,Mumbai-386732";
	cout<<"        E-mail:allstarpenshop1998@yahoo.com";
	cout<<"\n\n\t\t\t    Mumbai's No.1 Pen Shop\n";
	cout<<"\n\t\t\t___________INVOICE____________";
	cout<<"\n\t\t\t______________________________";
	cout<<"\n\n\tBill Number :"<<++bno;
	cout<<"\n\tCustomer name:"<<custname;
	cout<<"\n\tCustomer mobile number:+91"<<mno;
	cout<<"\n--------------------------------------------------------------------------------";
	cout<<"\tQuantity    Pen Serial Number     Name        Rate       Price\n";
	cout<<"--------------------------------------------------------------------------------";
	ifs.open("pen.dat");
	while(!ifs.eof())
		{	 ifs.read((char*)&pen,sizeof(pen));
			 if(ifs.eof())
			 break;
			 for(i=0;id[i]!='\0',i<50;i++)
			 {	if(pen.getserialno()==id[i])
				{     	price=bqty[i]*pen.getprice();
					cout<<"\t    "<<bqty[i];
					pen.display3();
					cout<<"\t "<<price<<endl;
					total+=price;
					break;
				}
			 }
		}
		ifs.close();
		nz=total/10;
		newtotal=nz+total;
		cout<<"\n\tGST Tax:5%";
		cout<<"\n\tCST Tsx:5%";
		cout<<"\n\tYour Total Amount is Rs."<<newtotal;
		cout<<"\n\n\t----------- "<<ch<<" Thank You For Shopping With Us "<<ch<<" -------------";
		getch();
}

void penss::display3()
{
	cout<<"\t\t  "<<serialno<<"\t          "<<name<<"      "<<price;
}
