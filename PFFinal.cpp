# include <iostream>
# include <fstream>
# include <conio.h>

using namespace std;

int main();


void wait(int v){
	for (int i = 0; i< (v*5000000); i++)
	{
		i++;
	}
}

void print(string val, int w)
{
	
	for (int i = 0; i < val.length() ; i++)
	{
		cout << val[i];
		wait(w);
	}
	
}


struct Teachers{
	string name;
	string subject, department;
	string email;
	string userName;
	string password;
	string contactno;
	string YoJoining;
}teacher_1, teacher_2, teacher_3;



struct Students{
	int id;
	string f_name, l_name;
    string father_name;
	string regNo;
	string address;
	string email;
	int contactNo;
	int cnic;
	float attendence[3];
	float no_present[3], t_attd[3];
	float opt_marks[3];
	int total_marks = 100;
}stds[15];



void get_student()
{

	ifstream file("students.txt");
	
	for(int i = 0; i<15; i++)
	{
		file >> stds[i].id >> stds[i].f_name >> stds[i].l_name >> stds[i].father_name >> stds[i].attendence[0] >> stds[i].attendence[1] >> stds[i].attendence[2] >> stds[i].no_present[1] >> stds[i].t_attd[1];	
	}
	file.close();

}



void put_students();



void get_result()
{
	ifstream obj("std_result.txt");
	for (int i = 0; i < 15; i++)
	{
		obj >> stds[i].opt_marks[0] >> stds[i].opt_marks[1] >> stds[i].opt_marks[2];
	}
	obj.close();
}



void put_teacher_data(Teachers *teacher1, Teachers *teacher2, Teachers *teacher3)
{
	teacher1->name = "Xyz";
	teacher1->department = "Computer Science";
	teacher1->subject = "Programming Fundamental";
	teacher1->contactno = "034652842421";
	teacher1->email = "xyz@nutech.edu.pk";
	teacher1->userName = "xyz@nutech"; 
	teacher1->password = "nutech@1234";
	teacher1->YoJoining = "26 Aug, 2018";
	
	teacher2->name = "Orp";
	teacher2->department = "Meachanical Enginerring";
	teacher2->subject = "Physics";
	teacher2->contactno = "03263256432";
	teacher2->email = "orp@nutech.edu.pk";
	teacher2->userName = "orp@nutech"; 
	teacher2->password = "orp.nutech@1235";
	teacher2->YoJoining = "24 March, 2020";
	
	teacher2->name = "Abc";
	teacher2->department = "Computer Science";
	teacher2->subject = "ICT";
	teacher2->contactno = "030570374332";
	teacher2->email = "abc@nutech.edu.pk";
	teacher2->userName = "abc@nutech"; 
	teacher2->password = "abc.nutech@1234";
	teacher2->YoJoining = "29 April, 2019";
	
}



int option(int lower, int upper)
{
	int option;
	while(1)
	{
		cout << "\nPlease Enter any number between " << lower << " to " << upper << ":  ";
		cin >> option;
		if ( option >= lower and option <= upper)
		{
			return option;
		}
		else{
			cout << "\nWrong Input\n\n";
		}
	}
}



void auth(string userName, string password)
{
	while(1)
	{
		string name, passw;
		print("\nPlease Enter Your User Name: ",4);
		cin >> name;
		print("Please Enter Your Password: ", 4);
		cin >> passw;
		
		if (name == userName and passw == password)
		{
			print ("\n\n................................................Login Succesful................................................\n\n",3);
			break;
		}
		else
		{
			print("\n\nWrong Username or Password \nPlease Try Again\n\n ",4);
		}
	}
	
}




void take_attendence()
{
	int date, month, absent=0, present = 0;
	string section, subject;
	cout << "Enter Class: ";
	cin >> section;
	cout << "Enter Subject ";
	cin >> subject;
	cout << "Enter date and month with spaces: ";
	cin >> date >> month;

	for(int i = 0; i < 15; i++)
	{
		char attd;
		cout << endl << stds[i].f_name << " " << stds[i].l_name << " ";
		
		attd = getche();
		
		if (attd == 'p')
		{
			present++;
			stds[i].no_present[1]++;
			stds[i].t_attd[1]++;
			
			stds[i].attendence[1] = (stds[i].no_present[1] / stds[i].t_attd[1]) * 100;
		}
		else if(attd == 'c')
		{
			cout << endl << stds[i].f_name << "'s attendence is " << stds[i].attendence[1] << "%" << endl;
			i--;
		}
		else if(attd == 'a')
		{
			absent++;
			stds[i].t_attd[1] ++;
			stds[i].attendence[1] =  (stds[i].no_present[1] / stds[i].t_attd[1]) * 100;
		}
		else
		{
			cout << endl << "\nWrong input please enter: p, c or a " << endl;
			i--;
		}					
	}
		 	
	
	cout << "\n\nToday: " << "2\tNo of Present:  " << present << endl;
	cout << "\t\tNo of Absent: " << absent << endl << endl;			
	
}




void update_attendence()
{
	
	
	while(1)
	{
		print("\nWhom do you wanna update:\n",4);
		cout << "Enter id no: ";
		int id;
		cin >> id;
		cout << "\nClass: ";
		string clas;
		cin >> clas;
		cout << "\n\nDo you want to update " << stds[id].f_name << " "<< stds[id].l_name << "'s attendence...? \n"; 
		cout << "Enter Y for Yes or N for No: ";
		char c;
		cin >> c;
		if (c == 'N' or c == 'n')
		{
			continue;
		}
		
		else if (c == 'Y' or c == 'y')
		{
			cout << "\nPlease Enter the amount of percentage you want to increment or decrement with +ve or -ve sign: ";
			float uttd;
			cin >> uttd;
			stds[id].attendence[1] += uttd;
			cout << "\n\n....................................Attendence Updated..................................." << endl << endl;
			
			cout << "Do you wanna exit? (Y/N): ";
			cin >> c;
			if (c=='Y' or c== 'y')
			{
				break;
			}
			else
			{
				continue;
			}

		}
	}
}




void attendence()
{
	cout << "What do you want: 1. Take 2. Update ";
	
	int opt = option(1,2);
	
	switch(opt)
	{
		case 1:
			take_attendence();
			break;
		case 2:
			update_attendence();
			break;
	}
}




void check_result()
{
	cout << "\nPlease Enter Id ";
	int id = option (0,14);
	cout << stds[id].f_name << " " << stds[id].l_name << " has got " << stds[id].opt_marks[1] << " out of " << stds[id].total_marks << endl; 
}




void update_result()
{
	cout << "\nPlease Enter Student Id: ";
	int id = option(0,14);
	cout << "\nPlease Enter New Mark: ";
	int new_mark;
	cin >> new_mark;
	stds[id].opt_marks[1] = new_mark;
	cout << "......................Result has Updated........................\n\n";
	ofstream obj("std_result.txt");
	
	for (int i = 0; i < 15; i++)
	{
		obj << stds[i].opt_marks[0] << " " << stds[i].opt_marks[1] << " " << stds[i].opt_marks[2] << endl;
	}

	obj.close();
}




void result()
{
	ifstream obj("std_result.txt");
	
	cout << "What do you want?: 1. Check  2. Update ";
	int opt = option(1,2);
	
	if (opt == 1)
	{
		check_result();		
	}
	else
	{
		update_result();
	}
}




void t_academic()
{
	cout << "\nYou have following option here: 1. Attendence  2. Result ";
	int option2 = option(1,2);
	switch (option2)
	{
		case 1:
			attendence();
			break;
		case 2:
			result();
			break;
//		case 3:
//			announce();
//		default:
//			cout << "Error Somewhere";

	}
}



void teacher_profile(string t_userName)
{
	
	if (t_userName == teacher_1.userName)
	{
		cout << "\n\n\t\t\t..........User Profile............\n\n";
		cout << "Name:             " << teacher_1.name << endl;
		cout << "Department:       " << teacher_1.department << endl;
		cout << "Subject:          " << teacher_1.subject << endl;
		cout << "Contact No:       " << teacher_1.contactno << endl;
		cout << "Email Address:    " << teacher_1.email << endl;
		cout << "Year of Joining:  " << teacher_1.YoJoining << endl;
	}
	
	else if (t_userName == teacher_2.userName)
	{
		cout << "\n\n\t\t\t..........User Profile............\n\n";
		cout << "Name:             " << teacher_2.name << endl;
		cout << "Department:       " << teacher_2.department << endl;
		cout << "Subject:          " << teacher_2.subject << endl;
		cout << "Contact No:       " << teacher_2.contactno << endl;
		cout << "Email Address:    " << teacher_2.email << endl;
		cout << "Year of Joining:  " << teacher_2.YoJoining << endl;
	}
	
	else if (t_userName == teacher_3.userName)
	{
		cout << "\n\n\t\t\t..........User Profile............\n\n";
		cout << "Name:             " << teacher_3.name << endl;
		cout << "Department:       " << teacher_3.department << endl;
		cout << "Subject:          " << teacher_3.subject << endl;
		cout << "Contact No:       " << teacher_3.contactno << endl;
		cout << "Email Address:    " << teacher_3.email << endl;
		cout << "Year of Joining:  " << teacher_3.YoJoining << endl;
	}
}




void UserAccount(Teachers *teacher)
{
	cout << "What do you want?  1. Change PassWord   2.  Logout: ";
	int opt = option(1,2);
	
	if (opt == 1)
	{
		string new_password;
		cout << "\nEnter your new password: ";
		cin >> new_password;
		teacher->password = new_password;
		cout << "\n\n...............................Password has changed successfully.................................\n\n";
		main();
		
	}
	
	else
	{
		cout << "\n\n...................................Logout Successful..........................................\n\n";
		main();
	}
}




void teacher()
{
	string userName, password;
	userName = teacher_1.userName;
	password = teacher_1.password;
	cout << "\n..................................................loginPage.....................................................\n";
	auth(userName, password);
	cout << "\nYou can open following:\n1. Personel Info\t 2. Academic\t 3. Account Setting\n";
	cout << "What do you want: ";
	int option1;
	option1 = option(1,3);
	
	switch (option1)
	{
		case 1:
			teacher_profile(userName);
			break;
		case 2:
			t_academic();
			break;
		case 3:
			UserAccount(&teacher_1);
			break;
	}
}



void std_profile(int s_id)
{
	cout << "\n\n..........................Profile..............................\n\n\n";
	cout << "Name:            " << stds[s_id].f_name << " " << stds[s_id].l_name << endl;
	cout << "Father Name:     " << stds[s_id].father_name << endl;
	cout << "Student ID:      " << stds[s_id].id << endl;
	
	cout << "\n.................................................................\n\n";
}



void std_academic(int s_id)
{
	cout << "1. Attendence   2.    Result";
	int opt = option(1,2);
	if (opt == 1)
	{
		cout << "\n\n....................Attendence Record.......................\n\n\n";
		cout << "  SUBJECT                       Percentege\n\n";
		cout << "  Calculus:\t                   " << stds[s_id].attendence[0] << "%" << endl;
		cout << "  Programming Fundamentals:\t   " << stds[s_id].attendence[1] << "%" << endl;
		cout << "  Computational Thinking:\t     "  << stds[s_id].attendence[2] << "%" << endl << endl;
	}
	
	else
	{
		cout << "\n\n......................Result Record.......................\n\n\n";
		cout << "  SUBJECT                      Total Marks      Marks Obtained      Class Average\n\n";
		cout << "  Calculus:\t                   " <<   stds[s_id].total_marks   <<  "\t\t\t"  <<   stds[s_id].opt_marks[0]   <<   "\t 60"   << endl;
		cout << "  Programming Fundamentals:\t   " <<   stds[s_id].total_marks   <<  "\t\t\t" <<  stds[s_id].opt_marks[1]   <<   "\t 67"   << endl;
		cout << "  Computational Thinking:\t   " <<   stds[s_id].total_marks   <<  "\t\t\t"  << stds[s_id].opt_marks[2]   <<   "\t 79"   << endl   <<  endl;
		
	}
}



void student()
{
	print("\n\n...............................................Login Page.................................................\n\n",4);
	cout << "Please Enter your id no: ";
	int id;
	cin >> id;
	auth(stds[id].f_name, stds[id].l_name); //
	cout << "\nWhat do you want? " << endl;
	print( "1.  Profile    2.  Academic  3.  logout\n\n", 4);
	int opt = option(1,3);
	
	switch(opt)
	{
		case 1:
			std_profile(id);
			break;
		case 2:
			std_academic(id);
			break;
		case 3:
			print("\n....................Logout Successful.....................\n\n",5);
			main();
			break;
	}
	
}

	
int main()
{
	put_teacher_data (&teacher_1, &teacher_2, &teacher_3);
	get_student();
	get_result();
	int opt;
	print("\n\n...............................................Welcome to UMS...............................................\n\n\n",4);
	print("Whom your are? 1. Student  2. Teacher 3. Admin:  ",5);
	opt = option(1,3);
	
	switch (opt)
	{
		case 1:
			student();
			break;
		case 2:
			teacher();
			break;
//		case 3:
//			admin ();
//			break;
		default:
			return 0;
	}
	put_students();
}



void put_students()
{

	ofstream file("students.txt");
	
	for(int i = 0; i<15; i++)
	{
		file << stds[i].id << "  " << stds[i].f_name << "  " << stds[i].l_name << "  " << stds[i].father_name << " " << stds[i].attendence[0] << " " << stds[i].attendence[1] << " " << stds[i].attendence[2] << " " << stds[i].no_present[1] << " " << stds[i].t_attd[1] << endl;		
	}
    file.close();
}

