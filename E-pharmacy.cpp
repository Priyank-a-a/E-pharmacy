#include <iostream>
#include <map>
#include<fstream>
#include<ctime>
using namespace std;
int age,price,mobile_number,otp;
string med,problem,name;
void timee()
{
time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   cout << "Local date and time: " << dt << endl;

   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout <<"UTC date and time: "<< dt << endl;
   }

void receipt()
  {
      cout<<"********E-RECEIPT********"<<endl;
      cout<<"name: "<<name<<endl;
      cout<<"age: "<<age<<endl;
      cout<<"suffering from: "<<problem<<endl;
      cout<<"prescription: "<<med<<endl;
      cout<<"total price: "<<price<<endl;
  }

  	

int main()
{
    cout<<"**********WELCOME TO E-PHARMACY********** \n";
    timee();
  map<string, string> name_map;
         int n;

      int med_price=0;
  // put pairs into map
  string minor_cut,high_bp,headache,mild_fever,chickenpox,diarrhoea,fungal_infection,insomnia,malaria,anxiety;
  string Bacitracin,Caduet,Damiana,Ecotrin,Acyclovir,Attapulgite,Nystatin,ChloralHydrate,Quinine,Buspirone;
	name_map["minor_cut"]="Bacitracin";
	name_map["high_bp"]="Caduet";
	name_map["headache"]="Damiana";
	name_map["mild_fever"]="Ecotrin";
	name_map["chickenpox"]="Acyclovir";
	name_map["diarrhoea"]="Attapulgite";
	name_map["fungal_infection"]="Nystatin";
	name_map["insomnia"]="ChloralHydrate";
	name_map["malaria"]="Quinine";
	name_map["anxiety"]="Buspirone";
    //cout<<name_map[minor_cut]<<endl;
    int days;
    cout<<"enter your name: ";
    cin >> name;
    cout<<"enter your age: ";
    cin >> age;
    if(age<=15)
    {
        cout<<"You are not allowed to access e-pharmacy";
    }
    else
    {
    cout<<"Enter your mobile number linked with your Official ID: ";
  	cin>>mobile_number;
  	cout<<"An OTP has been sent to your mobile. Please enter to continue.";
  	cin>>otp;
    if(otp!=NULL)
	{
	    
    cout<<"enter the disease as told by doctor: ";
    cin >> problem;
    cout<<"enter the number of days you are suffering from the problem: ";
    cin>>days;
    map<string, string>::iterator p;
    // find value given key
    p = name_map.find(problem);
    if(p != name_map.end()) 
    cout << "your required medicine is:  " << p->second;
    else
    cout << "your problem is not in the list.\n";
    med=p->second;
     //billing
     if(med == "Bacitracin")
         med_price=58; //ointment
         else if(med=="Caduet")
         med_price=8.5;
         else if(med=="Damiana")
         med_price=12;
         else if(med=="Ecotrin") 
         med_price=10;
         else if(med=="Acyclovir")
         med_price=20;
         else if(med=="Attapulgite")
         med_price=38;
         else if(med=="Nystatin")
         med_price=40;
         else if(med=="ChloralHydrate")
         med_price=18;
         else if(med=="Quinine")
         med_price=12;
         else if(med=="Buspirone")
         med_price=12;
         else
         cout<<"no medicine! ";
   //dose
   if(days==1)
   {
    cout<<"\nyou have to take the tablet twice a day for straight two days.";
   }
   else if(days==2)
   {
       
   cout<<"\nyou have to take the tablet twice a day for straight three days.";
   }
   else
   {
   cout<<"\nyou have to take the tablet twice a day for straight two days and see the doctor again."<<endl;
   }
  price=days*med_price;
  cout<<endl<<"\nyour bill is of Rupees "<<price;
  string answer;
  cout<<endl<<"\nDo you want to generate the receipt? "<<endl;
  cin>>answer;
 if(answer=="yes" || answer=="Yes" || answer== "YES" )
  {
      receipt();
  }
  else
  {
  cout<<"thank you!"<<endl;
  }
  ofstream outfile;
   outfile.open("medFile.txt",fstream::app);
  cout << "****Writing patient's data to the file****" << endl;
// write inputted data into the file.
   outfile<<"****************"<<endl;
   outfile << "Name: "<<name << endl;
   outfile << "Age: "<<age << endl;
   cin.ignore();
   // again write inputted data into the file.
   outfile << "Problem: "<<problem << endl;
   outfile<< "Prescribed medicine: "<<med <<endl;
   outfile<<"*****************"<<endl;
// close the opened file.
   outfile.close();
   ifstream infile;
   string answer1;
   //opening the record--only for the pharmacy owner
   cout<<"********STAFF SECTION ONLY*********"<<endl;
   cout<<"Do you want to check the records?\n";
   cin>>answer1;
   if(answer1=="yes" || answer1=="YES" || answer1=="Yes")
   {
       string password,line;
       cout<<"Enter password: ";
       cin>>password;
       if(password=="checkRecords")
       {
   infile.open("medFile.txt",fstream::in); 
   while (infile) { 
  
        // Read a Line from File 
        getline(infile, line); 
  
        // Print line in Console 
        cout << line << endl; 
    } 


   // close the opened file.
   infile.close();
   }
       else
       {
           cout<<"WRONG PASSWORD";
       }
   }
   else
   cout<<"OK!";
  return 0;
}}}
