#include<iostream>
#include"XDD.h"
#include<string>
#include <fstream>

using namespace std ;

void delay()
{
	cout<<"Loading" ;
	for(int k = 0 ; k < 5 ; k++){
	for(int i = 0 ; i < 10000 ; i++){
		for(int j = 0 ; j < 10000 ; j++){
	
		}
	
	}
	
		cout <<"." ;
	
	}
	
	system("CLS");

} 

class department ;
class Student {
	
	protected :
		
		string name , f_name, cnic , gender, address, city ;
		long long int num;
		int age;	
		int c;
	public :
		void Student_data() ;
		
		void info() ;
		string get_city() ;
	
};



class Academic_Institute
{
	protected :
		string name,city;
		bool scholarship,extracirc;
		int fee;
	
	public:
		virtual void set_v(){
			
			cout<<"\nNO VALUE ENTERED \n";
		}
		

};

class College_Student : public Student 
{	
	private :
		double percent;
		int extra_curricular;
		string d;

	public:
		College_Student(){
		}
		College_Student(string dep):Student(){
			d = dep;
			
		}
		void info() ;
		
		double getper() ;
		
		int get_extra();
	
		int compare(department obj[37] ) ;
		
		void fileit();
		
		void loadit();		
};

class University:public Academic_Institute 
{	protected:
		bool hostel;

	public:
	

};

class department : public University{
	
	private :
	
		string name_dep;
		double req;
		
	public :
		void set_v(string n,double r,bool h,string nm,string c,bool sch,bool extr,int f) ;
		
		string getname () ;
		double getperc() ;
		
		
		void print(){
			
			cout<<"\n\n\nUniversity Name  : " << name << endl << "Department Name : " << name_dep << endl << "Per Semester Fee : " << fee << endl << "City : " << city;
			
		}
		int friend College_Student::compare(department obj[37]) ;
			
};




class Field 
{
	private :
	int sc,cmart;
	int eng,med;
	int cs,ee,ce;
	int cm,art;
	int den,mbs;
	int ba,eco,acc;
	int lang,cul;
	int ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8,ans9,ans10;
	public:
		Field() ;
		string ask_questions() ;
		
};

void College_Student::fileit() {
		ofstream file;
		file.open("cstudent.bin",ios::out|ios::binary);
		if(!file){
			cout<<"Error"<<endl;
		}
		else{			
			file.write((char*)this, sizeof(*this));
			file.close();
			fflush(stdin);
			}
		
}

void College_Student::loadit() {
	
	College_Student p;
	fstream file;
	
	file.open("cstudent.bin",ios::in);
	file.read((char*)&p, sizeof(p));
	
	cout<<"Name : ";
	cout<<p.name<<endl;
	
	cout<<"Age : ";
	cout<<p.age<<endl;
	
	cout<<"Phone number : ";
	cout<< p.num <<endl;
	
	cout<<"City : ";
	cout<<p.city<<endl;
	
	cout<<"Suggested Department : ";
	cout<<p.d<<endl;
	
	cout<<"\n\n\n\n"<<endl;
	 		
}


void Student::Student_data () {
	
			
			cout<<"Enter Name : ";
			fflush(stdin);
			getline(cin,name);
			cout<<"Enter Father Name : ";
			fflush(stdin);
			getline(cin,f_name);
			fflush(stdin);
			cout<<"Enter CNIC : ";
			cin>> cnic;
			fflush(stdin);
			cout<<"Enter Gender : ";
			cin>> gender;
			fflush(stdin);
			cout<<"Enter Address : ";
			cin>> address;
			fflush(stdin);
			cout<<"Enter City\n1. Lahore\t2. Karachi\t3. Islamabad\t4. Other\n";
			cin>>c;
			do{
			if(c == 1)
			{
				city = "LAHORE";
			}
			else if(c == 2)
			{
				city = "KARACHI";
			}
			else if(c == 3)
			{
				city = "ISLAMABAD";
			}
			else if(c == 4)
			{
				city = "OTHER";
			}
			}while(c <0 && c >5);
			
			cout<<"Enter Phone : ";
			cin>>num;
			cout<<"Enter Age : ";
			cin>>age;
}

void College_Student::info(){
			
	cout<<"Enter Percentage : ";
	cin>>percent;
			
	cout << "\nEnter Extra Curricular : 1. Yes 2. No\n\t";
	cin>> extra_curricular;
}

string Student::get_city(){
	
	return city ;
}

double College_Student::getper(){
	
	return percent ;
	
}

int College_Student::get_extra(){
			
	return extra_curricular ;
}

int College_Student::compare( department obj[37] ){
		int check =0 ;
		cout<<"The following are the Best Selected Universities for you in your City!\n"<<endl;
		for(int i = 0 ; i < 37 ; i++){
		
			if (obj[i].req <=  percent){
			
				if(obj[i].name_dep == d){
					
					if(obj[i].city == city){
						
						obj[i].print() ;
						check++;
				
					if(extra_curricular == obj[i].extracirc ){
					
					cout << "\nThis University contains Extra Curricular Activity!!!" << endl ;
					
				}
					
				else if(extra_curricular != obj[i].extracirc ){
					
					cout << "\nThis university does not contain Extra Curricular Activity but it matches the criteria." << endl ;
				}
				
				
				if(obj[i].scholarship == 1){
					
					cout << "This University gives scholarship " << endl ;
				}else{
					
					cout << "This University does not give scholarship " << endl ;
					
				}
				}
			}
	
		}
	}
		cout<<"\n\n\n\n\n\nFollowing Universities are not in your Selected City but match the criteria :\n";
		for(int i = 0 ; i < 37 ; i++){
		
		if (obj[i].req <=  percent){
			
				if(obj[i].name_dep == d){
					
					if(obj[i].city != city){
						
						obj[i].print() ;
						check++;
				
				if(extra_curricular == obj[i].extracirc ){
					
					cout << "\nThis University Contains Extra Curricular Activity!!!" << endl ;
					
				}
					
				else {
					cout << "\nThis University does not contain Extra Curricular Activity but it matches the Criteria " << endl ;
			}
			
			if(obj[i].scholarship == 1){
					
					cout << "This University gives scholarship " << endl ;
				}else{
					
					cout << "This University does not give scholarship " << endl ;
					
				}
			
				}
			}
				
			}
	
		}	
		
	if(check == 0){
		system("CLS");
		cout<<"\n\n\nSorry!! No Universities found for your Criteria....";
	}
	return 1;
}

		

void department::set_v(string n,double r,bool h,string nm,string c,bool sch,bool extr,int f)  
{
	name_dep = n;
	req = r;
	hostel = h ;
	name = nm;
	city = c;
	scholarship = sch;
	extracirc = extr;
	fee = f;			
		
}


string department::getname(){
	
	return name_dep ;
}

double department::getperc(){
	
	return req ;
	
}

Field::Field()
{
	sc = 0 ;
	cmart = 0 ; 
	eng = 0 ; 
	med = 0 ; 
	cs = 0 ;
	ee = 0 ; 
	ce = 0 ;
}

string Field::ask_questions(){
	
	do{
	cout<<"\nIf given the chance to volunteer as an Assistant to :"<<endl;
	cout<<"1. Principle\n2. Accounts office\n3. Lab Organiser\n4. Math teacher"<<endl;
		cin>>ans1 ;
		system("CLS");
		delay();
		
	}while(ans1 != 1 && ans1 != 2 && ans1 != 3 && ans1 != 4) ;
		if(ans1==1){
			cmart++;
		}	
		if(ans1==2){
			cmart++;
		}
		if(ans1==3){
			sc++;
		}if(ans1==1){
			sc++;
			cmart++;
		}
		
	do{
	cout<<"Would you rather go on a school trip to :"<<endl;
	cout<<"1. Planetarium\n2. Textile Mill\n3. Bank\n4. Zoo"<<endl;
		cin>>ans2;
		system("CLS");
		delay();
			
	}	while(ans2 != 1 && ans2 != 2 && ans2 != 3 && ans2 != 4) ;
		if(ans2==1){
			sc++;
		}	
		if(ans2==2){
			sc++;
			cmart = cmart + 2;
		}
		if(ans2==3){
			cmart++;
		}
		if(ans2==4){
			sc++;
		}
		
	do{
	cout<<"If you could have an interview with a famous person who would it be :"<<endl ;
	cout<<"1. Mark Zuckerburg\n2. Elon Musk\n3. Jeff Bezos\n4. Peter Jonas"<<endl;
		cin>>ans3;
		system("CLS");
		delay();	
		
	}	while(ans3 != 1 && ans3 != 2 && ans3 != 3 && ans3 != 4) ;
		if(ans3==1){
			sc++;
		}	
		if(ans3==2){
			sc++;
		}
		if(ans3==3){
			cmart++;
		}
		if(ans3==4){
			cmart++;
		}
		if(sc>cmart){
			
			do{
			cout<<"You're done doing homework and have free time. What do you do : "<<endl;
			cout<<"1. Reach out to a friend to see how their doing\n2. Study some more\n3. Play a computer game\n4. Edit a video"<<endl;
				cin>>ans4;
				system("CLS");
				delay();
				
			} while(ans4 != 1 && ans4 != 2 && ans4 != 3 && ans4 != 4) ;
				if(ans4==1){
					med++;
				}	
				if(ans4==2){
					med++;
				}
				if(ans4==3){
					eng++;
				}
				if(ans4==4){
					eng++;
				}
			do{
			cout<<"You are Brilliant and Charming, Of course, but your favorite teacher would also describe you as: "<<endl;
			cout<<"1. Analytical \n2. Compassionate \n3. Creative \n4. Calm Headed"<<endl;
				cin>>ans5;
				system("CLS");
				delay();	
				
			}	while(ans5 != 1 && ans5 != 2 && ans5 != 3 && ans5 != 4) ;		
				if(ans5==1){
					eng++;
				}	
				if(ans5==2){
					med++;
				}
				if(ans5==3){
					eng++;
				}
				if(ans5==4){
					med++;
				}
			do{
			cout<<"You have been handed instruction a a Recipy :"<<endl;
			cout<<"1. Follow as Carefully as Possible\n2. Add your own ingredients"<<endl;
				cin>>ans6;
				system("CLS");
				delay();	
				
			}	while(ans6 != 1 && ans6 != 2 ) ;
				if(ans6==1){
					med++;
				}	
				if(ans6==2){
					eng++;
				}
				if(eng>med){
					do{
					cout<<"What film would you watch in the Cinema : "<<endl;
					cout<<"1. Anonymous\n2. Prison break\n3. 3 Idiots\n4. The Martian "<<endl;
						cin>>ans7;
						system("CLS");
						delay();
							
					}	while(ans7 != 1 && ans7 != 2 && ans7 != 3 && ans7 != 4) ;
						if(ans7==1){
							cs++;
						}	
						if(ans7==2){
							ce++;
						}
						if(ans7==3){
							ee++;
						}
						if(ans7==4){
							ee++;
						}
						
					do{
					cout<<"What game would you play in your free time : "<<endl;
					cout<<"1. Cut the Rope\n2. Watch Dods\n3. Minecraft\n4. Fallout"<<endl;
						cin>>ans8;
						system("CLS");	
						delay();
						
					}	while(ans8 != 1 && ans8 != 2 && ans8 != 3 && ans8 != 4) ;
						if(ans8==1){
							ce++;
						}	
						if(ans8==2){
							cs++;
						}
						if(ans8==3){
							ee++;
						}
						if(ans8==4){
							ce++;
						}
						
					do{
					cout<<"Would you rather work : "<<endl;
					cout<<"1. Remotly\n2. In an Office \n3. In a Field \n4. Factory"<<endl;
						cin>>ans9;
						system("CLS");	
						delay();
						
					}	while(ans9 != 1 && ans9 != 2 && ans9 != 3 && ans9 != 4) ;
						if(ans9==1){
							cs++;
						}	
						if(ans9==2){
							cs++;
						}
						if(ans9==3){
							ee++;
							ce++ ;
						}
						if(ans9==4){
							ee++;
						}
							if(cs>ee){
								if(cs>ce){
										
								return "BSCS";
									}
										
								if(cs<ce){

								return "BSCE";
								}
							}
							
							if(ce>ee){
								if(ce>cs){
								
								return "BSCE";
										}
								if(ce<cs){

							
								return "BSCS";
								}

								}
							if(ee>cs){
								if(ee>ce){
								return "BSEE";
										}
									
								if(ee<ce){
								return "BSCE";
									}
						
								}
					}
				if(med>eng){
					
					do{
					cout<<"Would you like to work under a superior until you can get thier Recognition?"<<endl;
					cout<<"1. Yes\n2. No\n3. If Neccesary"<<endl;
						cin>>ans7;
						system("CLS");	
						delay();
						
					}	while(ans7 != 1 && ans7 != 2 && ans7 != 3 ) ;
						if(ans7==1){
							mbs++;
						}	
						if(ans7==2){
							den++;
						}
						if(ans7==3){
							den++;
						}
						
					do{
					cout<<"You're paniking about an assignment you forgot to do and have only an hour left what do you do?";
					cout<<"\n1. Ask a freind \n2. Calmly try to do as much as you can\n3. Make an excuss \n4. Copy from the Internet"<<endl;
						cin>>ans8;
						system("CLS");	
						delay();
						
					}	while(ans8 != 1 && ans8 != 2 && ans8 != 3 && ans8 != 4) ;
						if(ans8==1){
							mbs++;
						}	
						if(ans8==2){
							den++;
						}
						if(ans8==3){
							den++;
						}
						if(ans8==4){
							mbs++;
						}
						
					do{
					cout<<"Are you planning on saving for Future Investment by doing part time Job?";
					cout<<"\n1. Yes \n2. No \n3.Saving without part time Job \n4. Not Saving"<<endl;
						cin>>ans9;
						system("CLS");	
						delay();
						
					}	while(ans9 != 1 && ans9 != 2 && ans9 != 3 && ans9 != 4) ;
						if(ans9==1){
							den++;
						}	
						if(ans9==2){
							mbs++;
						}
						if(ans9==3){
							mbs++;
						}
						if(ans9==4){
							mbs++;
						}
						if(den>mbs){
							return "BDS";
						}
						if(mbs>den){
							return "MBBS";
						}
				}
		}
		else if(cmart>sc){
			
			do{
			cout<<"Do you want to work with Staff and Organisational related matters?";
			cout<<"\n1. Yes \n2. No"<<endl;
				cin>>ans4;
				system("CLS");	
				delay();
				
			}while(ans4 != 1 && ans4 != 2 ) ;
				if(ans4==1){
					cm++;
				}	
				if(ans4==2){
					art++;
				}
				
			do{
			cout<<"A friend asks your help in studying for a test. Do you : ";
			cout<<"\n1. Help him yourself \n2. Refer him to a freind \n3. Refer him to a coaching \n4. Dont help him"<<endl;
				cin>>ans5;
				system("CLS");	
				delay();
				
			}	while(ans5 != 1 && ans5 != 2 && ans5 != 3 && ans5 != 4) ;		
				if(ans5==1){
					art++;
				}	
				if(ans5==2){
					cm++;
				}
				if(ans5==3){
					cm++;
				}
				if(ans5==4){
					cm++;
				}
			
			do{
			cout<<"You are boarding a plane and must choose only one magazine to accompany the trip, You are more likely to choose : ";
			cout<<"\n1. Peoples Tribune \n2. The Wired \n3. The Economist \n4.Times"<<endl;
				cin>>ans6;
				system("CLS");	
				delay();
				
			}	while(ans6 != 1 && ans6 != 2 && ans6 != 3 && ans6 != 4) ;
				if(ans6==1){
					art;
				}	
				if(ans6==2){
					cm++;
				}
				if(ans6==3){
					cm++;
				}
				if(ans6==4){
					art++;
				}
				if(cm>art){
					
					do{
					cout<<"What is your favourite movie out of these : ";
					cout<<"\n1. Boiler Room \n2. Margin Call \n3. The Big Short \n4. American Psycho"<<endl;
						cin>>ans7;
						system("CLS");	
						delay();
						
					}	while(ans7 != 1 && ans7 != 2 && ans7 != 3 && ans7 != 4) ;
						if(ans7==1){
							ba++;
						}	
						if(ans7==2){
							eco++;
						}
						if(ans7==3){
							acc++;
						}
						if(ans7==4){
							ba++;
						}
						
					do{
					cout<<"You are stuck on a Math Problem do you : ";
					cout<<"\n1. Ask a friend \n2. Watch a Youtube Video \n3. Try to solve it again until you get it right \n4. Skip the question"<<endl;
						cin>>ans8;
						system("CLS");	
						delay();
						
					}	while(ans8 != 1 && ans8 != 2 && ans8 != 3 && ans8 != 4) ;
						if(ans8==1){
							ba++;
						}	
						if(ans8==2){
							eco++;
						}
						if(ans8==3){
							acc++;
						}
						if(ans8==4){
							ba++;
						}
						
					do{
					cout<<"You need some quick money in summer holidays. You have the option to : ";
					cout<<"\n1.Open a lemonade stand \n2.Work in a shoe shop \n3.Sell products online \n4. work in a call center"<<endl;
						cin>>ans9;
						system("CLS");	
						delay();
						
					}	while(ans9 != 1 && ans9 != 2 && ans9 != 3 && ans9 != 4) ;
						if(ans9==1){
							ba++;
						}	
						if(ans9==2){
							eco++;
						}
						if(ans9==3){
							eco++;
							acc++ ;
						}
						if(ans9==4){
							ba++;
						}
							if(ba>acc){
								if(ba>eco){
										
								return "BBA";
									}
										
								if(ba<eco){

								return "ECONOMICS";
								}
							}
							
							if(acc>eco){
								if(acc>ba){
								
								return "ACCOUNTING";
										}
								if(acc<ba){

							
								return "BBA";
								}

								}
							if(eco>ba){
								if(eco>acc){
								return "ECONOMICS";
										}
									
								if(eco<acc){
								return "ACCOUNTING";
									}
						
								}
			
				}
				if(art>cm){
					
					do{
					cout<<"You have some Spare Cash do you : ";
					cout<<"\n1. Donate to EDHI \n2. Donate to your Favourite Streamer \n3. Use it to Donate Food near your Home \n4. Donate it to your Favourite Author"<<endl;
						cin>>ans7;
						system("CLS");	
						delay();
						
					}	while(ans7 != 1 && ans7 != 2 && ans7 != 3 && ans7 != 4) ;
						if(ans7==1){
							cul++;
						}	
						if(ans7==2){
							lang++;
						}
						if(ans7==3){
							cul++;
						}
						if(ans7==4){
							lang++;
						}
						
					do{
					cout<<"You are invited to freshmen year party do you : ";
					cout<<"\n1. Take your friend \n2. Go Alone \n3. Don't Go \n4. Go late"<<endl;
						cin>>ans8;
						system("CLS");	
						delay();
						
					}	while(ans8 != 1 && ans8 != 2 && ans8 != 3 && ans8 != 4) ;
						if(ans8==1){
							cul++;
						}	
						if(ans8==2){
							cul++;
						}
						if(ans8==3){
							lang++;
						}
						if(ans8==4){
							lang++;
						}
						
					do{
					cout<<"If you could Travel would you : ";
					cout<<"\n1. Go on a charity mission to africa \n2. Go visit Europe \n3.Teach part time in China \n 4. Surfing in Australia"<<endl;
						cin>>ans9;
						system("CLS");	
						delay();
						
					}	while(ans9 != 1 && ans9 != 2 && ans9 != 3 && ans9 != 4) ;
						if(ans9==1){
							cul++;
						}	
						if(ans9==2){
							lang++;
						}
						if(ans9==3){
							cul++;
						}
						if(ans9==4){
							lang++;
						}
						if(cul>lang){
							
							do{
							cout<<"Would you rather work : ";
							cout<<"\n1. Hands on in the outdoors \n2. Indoor in your comfort"<<endl;
								cin>>ans10;
								system("CLS");	
								delay();
								
							}	while(ans10 != 1 && ans10 != 2 ) ;
								if(ans10==1){
									return "HUMAN BEHAVIOUR";
								}	
								if(ans10==2){
									return "SOCIAL SCIENCES";
								}
						}		
						if(lang>cul){
							
							do{
								
							cout<<"Who is you're Favourite News Channel from these : ";
							cout<<"\n1.Geo News \n2. Samaa News \n3. BBC \n4. CNN"<<endl;
								cin>>ans10;
								system("CLS");	
								delay();
								
							}	while(ans10 != 1 && ans10 != 2 && ans10 != 3 && ans10 != 4) ;
								if(ans10==1){
									return "URDU-LIT";
								}
								if(ans10==2){
									return "URDU-LIT";
								}
								if(ans10==3){
									return "ENG-LIT";
								}
								if(ans10==4){
									return "ENG-LIT";
								}
						} 	
				}
			
		
		}
}



int main(){
	
	intro();
	delay();
	mid();
	delay();
	string city  ;
	double per ;
	int extra ; 
	string dprt ;
	department arr[37] ;
	
	arr[0].set_v("BSCS",80,1,"Nust","ISLAMABAD",1,1,90000);
	
	arr[1].set_v("BSEE",88,1,"Nust","ISLAMABAD",1,1,90000);
	
	arr[2].set_v("BSCE",85,1,"Nust","ISLAMABAD",1,1,90000);
	
	arr[3].set_v("BSCS",82,0,"NUCES FAST","KARACHI",0,0 ,130000 );	
	
	arr[4].set_v("BSEE",80,0,"NUCES FAST","KARACHI",0,0,130000);	
	
	arr[5].set_v("BDS",86,0,"DOW","KARACHI",1,0,70000);	
	
	arr[6].set_v("MBBS",89,0,"DOW","KARACHI",1,0,70000);	
	
	arr[7].set_v("ACCOUNTING",75,1,"IBA","KARACHI",0,1,300000);
	
	arr[8].set_v("ACCOUNTING",78,1,"LUMS","LAHORE",1,1,1200000);	
	
	arr[9].set_v("MBBS",85,1,"AGHA KHAN UNIVERISTY","KARACHI",0,1,1100000);	
	
	arr[10].set_v("BDS",81,1,"AGHA KHAN UNIVERSITY","KARACHI",0,1,1100000);	
	
	arr[11].set_v("BSCE",76,0,"HABIB UNIVERSITY","KARACHI",1,1,700000);	
	
	arr[12].set_v("BSEE",80,0,"HABIB UNIVERSITY","KARACHI",1,1,700000);	
	
	arr[13].set_v("BBA",88,1,"LUMS","LAHORE",1,1,1200000);	
	
	arr[14].set_v("ACCOUNTING",90,1,"LUMS","LAHORE",1,1,1200000);	
	
	arr[15].set_v("ECONOMICS",70,1,"IBA","KARACHI",1,1,350000);
	
	arr[16].set_v("BBA",75,1,"IBA","KARACHI",1,1,350000);
	
	arr[17].set_v("MBBS",80,1,"FATIMA ALI JINNAH UNIVERSITY","ISLAMABAD",0,0,500000);
		
	arr[18].set_v("BDS",78,1,"FATIMA ALI JINNAH UNIVERSITY","ISLAMABAD",0,0,450000);
	
	arr[19].set_v("MBBS",90,1,"KING EDWARD","LAHORE",1,1,2500000);
	
	arr[20].set_v("HUMAN BEHAVIOUR",60,0,"MAJU","KARACHI",0,0,33000);
	
	arr[21].set_v("SOCIAL SCIENCES",55,0,"MAJU","KARACHI",0,0,30000);
	
	arr[22].set_v("ENG-LIT",55,0,"FEDRAL URDU UNIVERSITY","ISLAMABAD",1,0,12000);
	
	arr[23].set_v("URDU-LIT",50,0,"IQRA","KARACHI",1,0,60000);
	
	arr[24].set_v("URDU-LIT",55,0,"FEDRAL URDU UNIVERSITY","ISLAMABAD",1,0,12000);
	
	arr[25].set_v("ENG-LIT",50,0,"IQRA","KARACHI",1,0,60000);
	
	arr[26].set_v("URDU-LIT",45,0,"NATIONAL COLLEGE OF ARTS","LAHORE",1,0,48000);  
	
	arr[27].set_v("ENG-LIT",45,0,"NATIONAL COLLEGE OF ARTS","LAHORE",1,0,48000); 
	
	arr[28].set_v("HUMAN BEHAVIOUR",45,0,"SCHOOL OF SOCIAL SCIENCE AND HUMANITIES","LAHORE",0,0,40000); 
	
	arr[29].set_v("SOCIAL SCIENCES",45,0,"SCHOOL OF SOCIAL SCIENCE AND HUMANITIES","LAHORE",0,0,40000);
	
	arr[30].set_v("HUMAN BEHAVIOUR",50,0,"NUML","ISLAMABAD",1,0,18000);
	
	arr[31].set_v("SOCIAL SCIENCES",50,0,"NUML","ISLAMABAD",1,0,18000);
	
	arr[32].set_v("BDS",90,1,"KING EDWARD","LAHORE",1,1,2500000);
	
	arr[33].set_v("ACCOUNTING",75,1,"ALAMA IQBAL OPEN UNIVERSITY","ISLAMABAD",1,1,70000);
	
	arr[34].set_v("ECONOMICS",65,1,"ALAMA IQBAL OPEN UNIVERSITY","ISLAMABAD",1,1,70000);
	
	arr[35].set_v("ACCOUNTING",60,0,"ABASYN UNIVERSITY","ISLAMABAD",1,0,40000);
	
	arr[36].set_v("BBA",50,0,"ABASYN UNIVERSITY","ISLAMABAD",1,0,40000);	
	
	
	Field obj1;
	dprt = obj1.ask_questions();
		system("CLS");
	College_Student s(dprt) ;
	s.Student_data() ;
	s.info() ;
		system("CLS");
	extra = s.compare(arr) ;
	int data;
	cout<<"\n\n\nDO YOU WANT TO SAVE YOUR DATA\n	1.Yes\n	2.No"<<endl;
	cin>>data;
		system("CLS");
	delay();
		system("CLS");
	if(data==1){
		s.fileit();
		cout<<"\nThe data we have saved is : \n"<<endl;
		s.loadit();
		system("pause");
	}
	end();

	return 0 ;
}


