#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include <cstdlib>
using namespace std;
static int p = 0;
class a
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
  void install();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);
}
bus[10];
void login();
void registration();
void forgot();
void req();
void staff();
void Bus();
void deletes();
void booking();
void display();
void insert();
void install();
void allotment();
void empty();
void show();
void avail();
void position(int i);
int couns,Aid,salary,age;
char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
string nam,experience,Contact;
class staffs
{
	private:
		string name,id_s,contact,mail, address;
	public:
		
		void enter();           //use this to enter details of student
		void show();            //use this to see details of student
		void delete_record();   //use this to delete the details of student
		void update();          //use this to update the details of any student
		void search();          // use this to search the specific student through their roll no
		

};

void staffs::enter()
{
    system("cls");
    fstream inFile;
    cout << "Please enter staff details .." << endl;
    cout << " " << endl;
    cout << " Enter Staff Name : ";
    cin >> name;
    cout << " Enter Staff Id : ";
    cin >> id_s;
    cout << " Enter mail Id : ";
    cin >> mail;
    cout << " Enter Contact No.: ";
    cin >> contact;
    cout << " Enter Address: ";
    cin >> address;
    inFile.open("staffRecord.txt", ios::app | ios::out);
    inFile << "  " << name << "  " << id_s << "  " << mail << "  " << contact <<  "  " << address <<"\n";  //add all details in file
    inFile.close(); 
} 
void staffs::show()
{
    system("cls");
    fstream inFile;
    int total = 0;
    cout << "Staff Recorded Data is" << endl;
    inFile.open("staffRecord.txt", ios::in);
    if (!inFile)
    {
        cout << "\n\n Data not found....";
        inFile.close();
    }
    else
    {
        inFile >> name >> id_s>> mail >> contact >> address;
        while (!inFile.eof())
        {
            cout<<"\n Staff No. :" << total++ << endl;
            cout<<"\n Staff Name : " << name << endl;
            cout<<"\n Staff Id: " << id_s << endl;
            cout<<"\n Staffmail Id : " << mail << endl;
            cout<<"\n Staff Contact No.: " << contact <<endl;
            cout<<"\n Staff Address : " << address << endl;
            inFile >> name >> id_s  >> mail >> contact  >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t Data not found....";
        }
    }
    inFile.close();
}
void staffs::update()
{
    system("cls");
    fstream file, file1;
    string rollno;
    int match = 0;
    cout << "Edit Staff Details" << endl;
    file.open("staffRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t No Data is Found...."; 
        file.close();
    }
    else
    {
        cout << "\n Enter the Staff's Td. you wish to edit: ";
        cin >> rollno;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> id_s >> mail >> contact >> address;
        while (!file.eof())
        {
            if (rollno != id_s)
            {
                file1 << " " << name << " " << id_s  << " " << mail << " " << contact  << " " << address << "\n";
            }
            else
            {
                cout << "\n Enter Staff Name: ";
                cin >> name;
                cout << "\n Enter Id: ";
                cin >> id_s;
                cout << "\n Enter E-mail Id: ";
                cin >> mail;
                cout << "\n Enter Contact No.: ";
                cin >> contact;
                cout << "\n Enter Address: ";
                cin >> address;
                file1 << " " << name << " " << id_s << " " << mail << " " << contact << " " << address << "\n";
                match++;
            }
            file >> name >> id_s >> mail >> contact >> address;
            if (match == 0)
            {
                cout << "\n\t\t Staff Not found, Invalid data!";
            }
        }
        file1.close();
        file.close();
        remove("staffRecord.txt");
        rename("Record.txt", "staffRecord.txt");
    }
}
void staffs::search()
{
    system("cls");
    fstream file;
    int match = 0;
    file.open("staffRecord.txt", ios::in);
    if (!file)
    {
        cout << "Search Staff" << endl;
        cout << "\n No data Found...";
    }
    else
    {
        string rollno;
        cout << "Search Staff" << endl;
        cout << "\n Enter Id you wish to Search Staff: ";
        cin >> rollno;
        file >> name >> id_s  >> mail >> contact >> address;
        while (!file.eof())
        {
            if (rollno == id_s)
            {
                cout<<" Staff Name : " << name << endl;
                cout<<" Staff Id : " << id_s << endl;
                cout<<" Staff E-mail Id: " << mail << endl;
                cout<<" Staff Contact No. : " << contact <<endl;
                cout<<" Staff Address: " << address << endl;
                match++;
            }
            file >> name >> id_s >> mail >> contact >> address;
        }
        if (match == 0)
        {
            cout << (" Sorry ! Staff Data Not Found.");
        }
        file.close();
    }
}
void staffs::delete_record()
{
    system("cls");
    fstream file, file1;
    string roll;
    int match = 0;
    cout << "Delete Staff Details" << endl;
    file.open("staffRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t Data not found.";
    }
    else
    {
        cout << "\n Enter Id of Staff which you want to delete data: ";
        cin >> roll;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> id_s >>  mail >> contact >> address;
        while (!file.eof())
        {
            if (roll != id_s)
            {
                file1 << " " << name << " " << id_s << " " << mail << " " << contact << " " << address << "\n";
            }
            else
            {
                match++;
                cout << "\n\t\t Operation Deletion Done";
            }
            file >> name >> id_s >>  mail >> contact >>  address;
        }
        if (match == 0)
        {
            cout << "\n\t\t Sorry ! Record not found.";
        }
        file1.close();
        file.close();
        remove("staffRecord.txt");
        rename("Record.txt", "staffRecord.txt");
    }
}
int main()
{
    int c;
    cout<<"\t\t\t\t                            \n\n\n";
    cout<<"\t\t\t\t               Welcome to Login page of Tourism Management System             \n\n\n";
    cout<<"\t\t\t\t                                     MENU                                       \n\n";
    cout<<"                                                                                         \n\n";
    cout<<"\t|Press 1 to LOGIN                                        |"<<endl;
    cout<<"\t|Press 2 to REGISTER                                     |"<<endl;
    cout<<"\t|Press 3 if you forgot your password                     |"<<endl;
    cout<<"\t|Press 4 to EXIT                                         |"<<endl;
    cout<<"\n\t\t\t Please Enter your Choice : ";
    cin>>c;
    cout<<endl;
    switch(c)
    {
        case 1:
            login();
            break;
        case 2:
             registration();
             break;
        case 3:
             forgot();
             break;
        case 4:
             cout<<"\t\t\t Thankyou! For Visiting \n\n";
             break;
        default:
            system("cls");
            cout<<"\t\t\t Please select from the options given above \n"<<endl;
            main();
    }
}
void login()
{
    int count;
    string userId,password,id,pass;
    system("cls");
    cout<<"\t\t\t Please enter the username :"<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass);
    {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");
        }
    }
    input.close(); 
    if(count==1)
    {
        cout<<userId<<"\n Your LOGIN is successful \n Thanks for logging in !\n";
        req();
    }
    else{
         cout<<"\n LOGIN ERROR \n Please check your username and password\n";
         main();
    }
}
void registration()
{
    string ruserId,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username : ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the Password : ";
    cin>>rpassword;
    ofstream f1("records.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\t\t\t Registration is successful!\n";
    main();   
}
void forgot()
{
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the Password? No worries \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to the main menu  "<<endl;
    cout<<"\t\t\t Enter your choice :  ";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserId,sId,spass;
            cout<<"\n\t\t\t Enter the username which you remembered :";
            cin>>suserId;

            ifstream f2("records.txt");
            while(f2>>sId>>spass)
            {
                if(sId==suserId)
                {
                    count=1;
                    } 
                }
                f2.close();
                if(count==1)
                {
                    cout<<"\n\n Your account is found! \n";
                    cout<<"\n\n Your password is : "<<spass;
                    main();
                }
                else{
                    cout<<"\n\t Sorry! your account is not found! \n";
                    main();
                }
                break;
            }
               case 2 :
               {
                     main();
                    }
                    default:
                        cout<<"\t\t\t Wrong choice ! Please try again"<<endl;
                        forgot();
                        break;
        }
    }

void req()
{
    int choice;
    cout<<"                                                                                         \n\n";
    cout<<"\t|Press 1 to  STAFF MANAGEMENT                            |"<<endl;
    cout<<"\t|Press 2 to  BUS MANAGEMENT                              |"<<endl;
    cout<<"\t|Press 3 to  BOOKING MANAGEMENT                          |"<<endl;
    cout<<"\t|Press 4 to  EXIT                                        |"<<endl;
    cout<<"\n\t\t\t Please Enter your Choice : ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:
            staff();
            break;
        case 2:
            Bus();
            break;
        case 3:
            booking();
             break;
        case 4:
             break;
        default:
            system("cls");
            cout<<"\t\t\t Please select from the options given above \n"<<endl;
            main();
    }
}
void staff()
{
   staffs pr;
	int value;
	while(true)         // i created this because this gives benefit to not run program again and again you can entered value till you not exit program
	{
    cout<<"\t\t\t\t                            \n\n\n";
    cout<<"\t\t\t\t                           STAFF MANAGEMENT                                \n\n\n";
    cout<<"\t\t\t\t                                MENU                                       \n\n";
    cout<<"                                                                                    \n\n";
	cout<<"\t|   Press 1 to enter data             |"<<endl;
	cout<<"\t|   Press 2 to show data              |"<<endl;
	cout<<"\t|   Press 3 to search data            |"<<endl;
	cout<<"\t|   Press 4 to update data            |"<<endl;
	cout<<"\t|   Press 5 to delete data            |"<<endl;
	cout<<"\t|   Press 6 to exit                   |"<<endl;
  cout<<"\n\t\t\t Please Enter your Choice : ";
	cin>>value;
	switch(value)
	{
		case 1:
			 pr.enter();
			break;
		case 2:
			pr.show();
			break;
		case 3:
			pr.search();
			break;
		case 4:
			pr.update();
			break;
		case 5:
			pr.delete_record();
			break;
		case 6:
			exit(0);
			break;
				main();
		default:
			cout<<"Wrong Choice...!!\n\n\n\n Please Press again Between [1 to 6].."<<endl;
			break;
	}
}
}

void Bus()
{
int bchoice,b2choice;
cout<<"**********************************************************************************\n";
  cout<<"\t\t                       BUS TRACK                               \n";
  cout<<"**********************************************************************************\n";
  cout<<"\n\n";
  cout<<"       1.GUNTUR                   \n"<<endl;
  cout<<"       2.VIJAYAWADA               \n"<<endl;
  cout<<" Enter the city:               "<<endl;
  cin>>bchoice;
  switch(bchoice)
  {
    case 1: 
    {
  cout<<"                       GUNTUR                     \n";
  cout<<"                Time               "<<endl;
	cout<<"\t|  G1. 7.00AM              |"<<endl;
	cout<<"\t|  G2. 7.05AM              |"<<endl;
	cout<<"\t|  G3. 7.08AM              |"<<endl;
	cout<<"\t|  G4. 7.12AM              |"<<endl;
	cout<<"\t|  G5. 7.20AM              |"<<endl;
  cout<<"\t|  G6. 7.25AM              |"<<endl;
  cout<<"\t|  G7. 7.30AM              |"<<endl;
  cout<<"\t|  G8. 7.35AM              |"<<endl;
  cout<<"\t|  G9.7.40AM              |"<<endl;
  cout<<"\t|  G10.7.45AM              |"<<endl;
  cout<<"\t|  G11.8.30AM              |"<<endl;
  cout<<"\t|  G12.6.15PM              |"<<endl;
	cout<<"\t|  G13.6.45PM              |"<<endl;
	cout<<"\t|  G14.7.00PM              |"<<endl;
	cout<<"\t|  G15.7.08PM              |"<<endl;
	cout<<"\t|  G16.7.15PM              |"<<endl;
  cout<<"\t|  G17.7.20PM              |"<<endl;
  cout<<"\t|  G18.7.30PM              |"<<endl;
  cout<<"\t|  G19.7.35PM              |"<<endl;
  cout<<"\t|  G20.7.40PM              |"<<endl;
  cout<<"\t|  G21.7.45PM              |"<<endl;
  cout<<"\t|  G22.8.00PM              |"<<endl;
  cout<<"\n\t\t\tEnter the time :  ";
  cin>>b2choice;
  switch(b2choice)
  {
    case 1:
    {
      cout<<"HANUMAIAH COMPANY"<<endl;
      break;
    }
    case 2:
    {
      cout<<"GUJJNAGUNDLA"<<endl;
      break;
    }
    case 3:
    {
      cout<<"JKC BUS STOP"<<endl;
      break;
    }
    case 4:
    {
      cout<<"KORITAPADU"<<endl;
      break;
    }
    case 5:
    {
      cout<<"SANKARAVILAS"<<endl;
      break;
    }
    case 6:
    {
      cout<<"MARKET PLACE"<<endl;
      break;
    }
    case 7:
    {
      cout<<"BUS STAND"<<endl;
      break;
    }
    case 8:
    {
      cout<<"RELIANCE"<<endl;
      break;
    }
    case 9:
    {
      cout<<"CHILLIS"<<endl;
      break;
    }
    case 10:
    {
      cout<<"GORANTLA"<<endl;
      break;
    }
    case 11:
    {
      cout<<"SRM UNVERSITY"<<endl;
      break;
    }
    case 12:
    {
      cout<<"MANGALAGIRI"<<endl;
      break;
    }
    case 13:
    {
      cout<<"GORANTLA"<<endl;
      break;
    }
    case 14:
    {
      cout<<"CHILLIS"<<endl;
      break;
    }
    case 15:
    {
      cout<<"RELIANCE"<<endl;
      break;
    }
    case 16:
    {
      cout<<"BUS STAND"<<endl;
      break;
    }
    case 17:
    {
      cout<<"MARKET PLACE"<<endl;
      break;
    }
    case 18:
    {
      cout<<"SANKARAVILAS"<<endl;
      break;
    }
    case 19:
    {
      cout<<"KORITHAPADU"<<endl;
      break;
    }
    case 20:
    {
      cout<<"JKC BUS STOP"<<endl;
      break;
    }
    case 21:
    {
      cout<<"GUJJNAGUNDLA"<<endl;
      break;
    }
    case 22:
    {
      cout<<"HANUMAIAH COMPANY"<<endl;
      break;
    }
  
    }
    break;
  }
  case 2:
  { 
  cout<<"                       VIJAYAWADA                     \n";
  cout<<"                Time               "<<endl;
	cout<<"\t|  V1. 7.00AM              |"<<endl;
	cout<<"\t|  V2. 7.05AM              |"<<endl;
	cout<<"\t|  V3. 7.08AM              |"<<endl;
	cout<<"\t|  V4. 7.12AM              |"<<endl;
	cout<<"\t|  V5. 7.20AM              |"<<endl;
  cout<<"\t|  V6. 7.25AM              |"<<endl;
  cout<<"\t|  V7. 7.30AM              |"<<endl;
  cout<<"\t|  V8. 7.35AM              |"<<endl;
  cout<<"\t|  V9.7.40AM               |"<<endl;
  cout<<"\t|  V10.7.45AM              |"<<endl;
  cout<<"\t|  V11.8.30AM              |"<<endl;
  cout<<"\t|  V12.6.15PM              |"<<endl;
	cout<<"\t|  V13.6.45PM              |"<<endl;
	cout<<"\t|  V14.7.00PM              |"<<endl;
	cout<<"\t|  V15.7.08PM              |"<<endl;
	cout<<"\t|  V16.7.15PM              |"<<endl;
  cout<<"\t|  V17.7.20PM              |"<<endl;
  cout<<"\t|  V18.7.30PM              |"<<endl;
  cout<<"\t|  V19.7.35PM              |"<<endl;
  cout<<"\t|  V20.7.40PM              |"<<endl;
  cout<<"\t|  V21.7.45PM              |"<<endl;
  cout<<"\t|  V22.8.00PM              |"<<endl;
  cout<<"\n\t\t\tEnter the time :  ";
  cin>>b2choice;
  switch(b2choice)
  {
    case 1:
    {
      cout<<"SRM CITY OFFICE"<<endl;
      break;
    }
    case 2:
    {
      cout<<"GUNADALA"<<endl;
      break;
    }
    case 3:
    {
      cout<<"HCG CANCER HOSPITAL"<<endl;
      break;
    }
    case 4:
    {
      cout<<"BHANU NAGAR SIGNAL"<<endl;
      break;
    }
    case 5:
    {
      cout<<"FOOD JUNCTION"<<endl;
      break;
    }
    case 6:
    {
      cout<<"SITHARAMAPURAM"<<endl;
      break;
    }
    case 7:
    {
      cout<<"KHAZANA JEWELLERY"<<endl;
      break;
    }
    case 8:
    {
      cout<<"PVP MALL"<<endl;
      break;
    }
    case 9:
    {
      cout<<"BENZ CIRCLE"<<endl;
      break;
    }
    case 10:
    {
      cout<<"NRI HOSPITAL"<<endl;
      break;
    }
    case 11:
    {
      cout<<"MANGALAGIRI OLD BUSSTAND"<<endl;
      break;
    }
    case 12:
    {
      cout<<"MANGALAGIRI OLD BUSSTANd"<<endl;
      break;
    }
    case 13:
    {
      cout<<"NRI HOSPITAL"<<endl;
      break;
    }
    case 14:
    {
      cout<<"TADEPALLI DOWN"<<endl;
      break;
    }
    case 15:
    {
      cout<<"BENZ CIRCLE"<<endl;
      break;
    }
    case 16:
    {
      cout<<"PVP MALL"<<endl;
      break;
    }
    case 17:
    {
      cout<<"KHAZANA JEWELLERY"<<endl;
      break;
    }
    case 18:
    {
      cout<<"SITHARAMAPURAM SIGNAL"<<endl;
      break;
    }
    case 19:
    {
      cout<<"FOOD JUNCTION"<<endl;
      break;
    }
    case 20:
    {
      cout<<"BHANU NAGAR SIGNAL"<<endl;
      break;
    }
    case 21:
    {
      cout<<"GUNADALA"<<endl;
      break;
    }
    case 22:
    {
      cout<<"SRM CITY OFFICE"<<endl;
      break;
    }
  
    }
    break;
  }
  }
}
void vline(char ch){
  for (int i=80;i>0;i--)
  cout<<ch;
}
void a::install()
{
  cout<<"Enter bus no: ";
  cin>>bus[p].busn;
  cout<<"\nEnter Driver's name: ";
  cin>>bus[p].driver;
  cout<<"\nArrival time: ";
  cin>>bus[p].arrival;
  cout<<"\nDeparture: ";
  cin>>bus[p].depart;
  cout<<"\nFrom: \t\t\t";
  cin>>bus[p].from;
  cout<<"\nTo: \t\t\t";
  cin>>bus[p].to;
  bus[p].empty();
  p++;
}
void a::allotment()
{
  int seat;
  char number[5];
  top:
  cout<<"Bus no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {

      cout<<"\nThere are only 32 seats available in this bus.";

    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }

  }

void a::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}
void a::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  vline('*');
  cout<<"Bus no: \t"<<bus[n].busn
  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct bus no: ";
}
void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
         p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}
void a::avail()
{
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<"Bus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    vline('_');
  }
}
void booking()
{
	system("cls");
int w;
while(1)
{
    //system("cls");
  cout<<"\n\n\n\n\n";
  cout<<"|\t         1.Install           \t\t\t|\n"
  <<"|                2.Reservation     \t\t\t|\n"
  <<"|                3.Show             \t\t\t|\n"
  <<"|                4.Buses Available.  \t\t\t|\n"
  <<"|                5.Exit                \t\t\t|\n";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].install();
      break;
    case 2:  bus[p].allotment();
      break;
    case 3:  bus[0].show();
      break;
    case 4:  bus[0].avail();
      break;
    case 5:  exit(0);

  }
}
}







