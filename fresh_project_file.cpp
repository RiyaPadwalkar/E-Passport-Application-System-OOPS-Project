#include<iostream>
#include<conio.h>
#include<iomanip>
#include<vector>
#include<fstream>
#include<random>
#include<string>
#include<cstdlib>
using namespace std;

bool y;
const int size = 100;
string name, address, s_name, f_name, m_name, whitespaces, dob, contact_no, adhar_nno, adhar_new, new_name;

class details
{
public:
	virtual void show()
	{
		cout.width(20);
		cout << "\nEnter details for Person " << endl;
	}
	void ddetails()
	{
		int size = 100;
		ofstream outFile("info", ios::app);
		cout << "\nEnter Applicant Name(FirstName_MiddleName_Surname): ";
		cin >> name;
		outFile << name << endl;
		cout << "Enter Address(H.no_fulladdress): ";
		cin >> address;
		outFile << address << endl;
		cout << "Enter Date Of Birth(DD-MM-YYYY): ";
		cin >> dob;
		outFile << dob << endl;
		cout << "Enter Contact no: ";
		cin >> contact_no;
		outFile << contact_no << endl;
		cout << "Enter Adhar no(AAAA-BBBB-CCCC): ";
		cin >> adhar_nno;
		outFile << adhar_nno << endl;
		cout << "Enter Father's Name(FirstName_Surname): ";
		cin >> f_name;
		outFile << f_name << endl;
		cout << "Enter Mother's Name(FirstName_Surname): ";
		cin >> m_name;
		outFile << m_name << endl;
		cout << "Enter Spouse's Name(if not Enter NULL): ";
		cin >> s_name;
		outFile << s_name << endl;
		outFile << "\n";
		outFile.close();
	}
};

class renewal :virtual public details
{
protected:
	string validity, issue, cissue, cvalidity;
	int ccount, size = 20;
public:
	void proof_of_passport()
	{
		cout << "Enter Issue Date(DD-MM-YYYY): ";
		cin >> issue;
		cout << "Enter your Passport Validity Date(DD-MM-YYYY): ";
		cin >> validity;
	}

	int modify()
	{
		int c, choice;
		cout << "\nAny details to be modify?";
		cout << "\n1.Yes\n2.No\n";
		cin >> c;
		if (c == 1)
		{
			while (1)
			{
				cout << "Enter Your Choice:";
				cout << "\n1.Name\n2.Address\n3.contact no\n4.exit\n";
				cin >> choice;

				switch (choice)
				{
				case 1:
				{
					/* cin >> name; */
						cout << "Enter correct Name(FirstName_MiddleName_Surname): ";
					cin >> name;
					break;
				}
				case 2:
				{
					cout << "Enter correct Address(H.no_fulladdress): ";
					cin >> address;
					break;
				}
				case 3:
				{
					cout << "Enter correct Contact no: ";
					cin >> contact_no;
					break;
				}
				case 4:return 0;
				default:cout << "Wrong Choice";
					break;
				}
			}

		}

	}

	friend void display();

};

template<typename T>
T generateId()
{
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<T>distribution(1000, 9999);
	return distribution(gen);
}
class New_Registration :virtual public details
{
protected:
	int count = 0;

public:
	void genetrator()
	{
		int Id = generateId<int>();
		cout << "\nId genertaed: " << Id << endl;
	}
	void operator ++()
	{
		++count;
		cout << "\nNumber of Registration: " << count;
	}

	friend void display();
	friend void AL_display();
};

void display()
{
	cout << "Applicant Name: " << name;
	cout << "\nAddress: " << address;
	cout << "\nDate Of Birth: " << dob;
	cout << "\nContact no: " << contact_no;
	cout << "\nAdhar no: " << adhar_nno;
	cout << "\nFather's Name: " << f_name;
	cout << "\nMother's Name: " << m_name;
	cout << "\nSpouse's Name: " << s_name;
}

void AL_display()
{
	cout << "Applicant Name: " << name;
	cout << "\nAddress: " << address;
	cout << "\nDate Of Birth: " << dob;
	cout << "\nContact no: " << contact_no;
	cout << "\nAdhar no: " << adhar_nno;
	cout << "\nFather's Name: " << f_name;
	cout << "\nMother's Name: " << m_name;
	cout << "\nSpouse's Name: " << s_name;
}

class appointment :public New_Registration
{
protected:string name_;
		 string date_;
		 string time_;


public:
	void show()
	{
		cout.width(20);
		cout << "\nAppointment Details:\n";
	}
	void setappointment(const string& name, const string& date, const string& time)
	{
		date_ = date;
		time_ = time;
		name_ = name;
	}
	void displayAppointment()
	{
		string nname, ddate, ttime;

		cout << "Enter your name to view booked apppointment slot:";
		cin >> name;
		ifstream infile("Appointment");
		while (infile >> nname >> ddate >> ttime)
		{
			if (nname == name)
			{
				cout.width(20);
				cout << "Name: ";
				cout.width(20);
				cout << name << endl;
				cout.width(20);
				cout << "Date: ";
				cout.width(20);
				cout << ddate << "\n";
				cout.width(20);
				cout << "Time: ";
				cout.width(20);
				cout << ttime << "\n\n";
			}
		}
		infile.close();
		cout << "Appointed Slot Booked." << endl;

	}

	void modify()
	{
		int  n, m;
		ifstream inFile("Appointment");
		string line;
		if (!inFile)
		{
			cerr << "Error opening file." << endl;
			return;
		}

		cout << "\nModify Appointment?(1.No/2.Yes)";
		cin >> m;
		if (m == 2)
		{
			cout << "Enter your adhar name to search: ";
			cin >> name;
			while (inFile >> new_name >> date_ >> time_)
			{
				cout << "\n\nModify Your Appiontment" << endl;
				cout.width(20);
				cout << "Name: ";
				cout.width(20);
				cout << name << endl;
				cout.width(20);
				cout << "Date: ";
				cout.width(20);
				cout << date_ << "\n";
				cout.width(20);
				cout << "Time: ";
				cout.width(20);
				cout << time_ << "\n\n";
				if (new_name == name)
				{
					cout << "\nEnter Your Choice to add date and time (1:No/2:Yes)): ";
					cin >> n;
					try
					{
						if (n == 2)
						{
							cout << "Enter Date: ";
							cin >> date_;
							cout << "Enter Time: ";
							cin >> time_;
							cout << "Previously Booked Appointment Is Cancelled\n";
							cout << "NEW APPOINTMENT SLOT BOOKED\n";
							cout.width(20);
							cout << "Name: ";
							cout.width(20);
							cout << name << endl;
							cout.width(20);
							cout << "Date: ";
							cout.width(20);
							cout << date_ << "\n";
							cout.width(20);
							cout << "Time: ";
							cout.width(20);
							cout << time_ << "\n\n";
						}
						else
							throw n;
					}
					catch (int n)
					{
						cout << "\nProceed furthur";
					}
				}
			}
		}


	}

};

class police_verification :public appointment
{
public:
	char whitespaces[10];
	int size = 30;
	void verify()
	{

		cout << "Police verification in progress..." << endl;
		_getch();
		cout << "\nPolice verification completed.\n" << endl;
		_getch();
	}
};

class payment :public New_Registration, public renewal
{
protected:
	string paymentMethod;
public:

	payment() {
		cout << "Payment in process......\n";

	}
	~payment()
	{
		cout << "payment successful\n";
		cout << "Thank You\n\n";


	}

};
int main()
{

	{
		details* ptr;
		payment person[5];
		system("cls");
		police_verification v[30];
		int vcount = 0;
		int size = 50;
		char whitespaces, ch;
		int pcount = 0, a, nn, ig;
	start:

		cout << "\t\t\t-------------------------------------------\n";
		cout << "\t\t\t----------PASSPORT MANAGEMENT SYSTEM---------------\n";
		cout << "\t\t\t----------WELCOME TO THE LOGIN PAGE---------------\n";
		cout << "\t\t\t---------       MENU       -------------\n";
		details D;
		ptr = &D;
		ptr->show();

		person[pcount].ddetails();
		cout << endl;
		while (1)
		{
			cout << "\nMENU\n";
			cout << "1.New Registration\n2.Renewal\n3.Appointment\n4.PoliCe Verificarion\n5.Payment\n6.Logout\n";
			cout << "Enter YOur Choice\n";
			cin >> a;
			switch (a)
			{
			case 1:
			{
				++person[pcount];
				cout << "\nDETAILS OF PERSON" << endl;
				vcount + 1;
				ofstream outFile("registration_data", ios::app);

				outFile.close();
				ifstream inFile("registration_data");

				if (!inFile)
				{
					cerr << "Error opening file." << endl;
					return 0;
				}

				bool found = false;
				cout << "Enter your adhar_no to check whether already registered or newly registered(AAAA-BBBB-CCCC) : ";
				cin >> adhar_nno;

				while (inFile >> name >> address >> dob >> contact_no >> adhar_new >> f_name >> m_name >> s_name)
				{
					if (adhar_new == adhar_nno)
					{
						cout << "Already Registred\n";
						ofstream outFile("registration_data", ios::app);
						outFile << name << endl;
						outFile << address << endl;
						outFile << dob << endl;
						outFile << contact_no << endl;
						outFile << adhar_nno << endl;
						outFile << f_name << endl;
						outFile << m_name << endl;
						outFile << s_name << endl;
						outFile << "\n";

						outFile.close();
						AL_display();
						v[vcount].modify();
						found = true;
						break;
					}


				}
				if (!found)
				{

					cout << "Newly Registered\n";
					ifstream inFile("info");
					{
						while (inFile >> name >> address >> dob >> contact_no >> adhar_new >> f_name >> m_name >> s_name)
							if (adhar_nno == adhar_new)
								display();
					}
					ofstream outFile("registration_data", ios::app);
					outFile << name << endl;
					outFile << address << endl;
					outFile << dob << endl;
					outFile << contact_no << endl;
					outFile << adhar_nno << endl;
					outFile << f_name << endl;
					outFile << m_name << endl;
					outFile << s_name << endl;
					outFile << "\n";
					outFile.open("registration_data", ios::app);

					outFile.close();
					New_Registration neww;
					neww.genetrator();
				}

				inFile._Seekbeg();
				inFile.close();
				break;
			}
			case 2:
			{
				person[pcount].proof_of_passport();
				person[pcount].modify();
				display();
				cin.get(whitespaces);
				cout << whitespaces;
				break;
			}
			case 3:
			{
				string name, date, time;

				cin.get(whitespaces);
				cout << whitespaces;
				ofstream outfile("Appointment", ios::app);
				cout << "Enter your name again(FirstName_MiddleName_Surname): ";
				getline(cin, name);
				outfile << name << endl;
				cout << "Enter date(excluding Sunday): ";
				getline(cin, date);
				outfile << date << endl;
				cout << "Enter time(9:00AM-5:00PM): ";
				getline(cin, time);
				outfile << time << endl << endl;
				outfile._Seekbeg();
				outfile.close();
				v[vcount].setappointment(name, date, time);

				appointment A;
				ptr = &A;
				ptr->show();

				v[vcount].displayAppointment();

				break;
			}
			case 4:
			{
				v[vcount].verify();


				break;
			}
			case 5:
			{

				string paymentMethod;
				cout << "Enter Payment Method (credit_card, debit_card, gpay): ";
				cin >> paymentMethod;

				cout << "Payment for (1.New_registration/2.Renewal) : ";
				cin >> nn;

				if (nn == 1)
				{
					payment person[1];

					cout << "Payment Details\n";
					while (pcount <= 5)
					{
						// Base registration fee and late fee
						double baseFee = 1000.0;
						double lateFee = 50.0;

						bool late;
						int days, latedays;
						double totalFee;

						cout << left << setw(20) << " " << left << setw(20) << "baseFee" << "lateFee" << endl;
						cout << left << setw(20) << " " << left << setw(2) << "Rs" << setw(3) << baseFee;
						cout << setw(15) << " ";
						cout << left << setw(2) << "Rs" << setw(3) << lateFee;

						cout << endl;
						cout << "Payment to be done on online registration day(0.No/1.Yes):";
						cin >> late;
						if (late == 1)
						{
							cout << left << setw(40) << "Payment Done For New Registration   = " << baseFee << endl;
						}

						else
						{
							cout << "No of days passed since the new registration is done(Enter from 1-10 ) : ";
							cin >> latedays;

							// Display table header
							cout << left << setw(20) << " " << left << setw(20) << "Days Past Deadline" << "Total Fee" << endl;

							// Loop through days past deadline and calculate fees
							for (days = 1; days <= latedays; ++days) {
								totalFee = baseFee + (days * lateFee);

							}
							// Display days past deadline and corresponding fee
							cout << left << setw(20) << " " << left << setw(20) << days - 1 << "Rs" << totalFee << endl;
						}
						break;
					}
				}

				if (nn == 2)
				{
					payment person[1];

					cout << "Payment Details\n";
					while (pcount <= 5)
					{
						// Base renewal fee and late fee
						double baserFee = 1000.0;
						double laterFee = 50.0;

						bool rlate;
						int rdays, rlatedays;
						double rtotalFee;

						cout << left << setw(20) << " " << left << setw(25) << "Base_Reenewal_Fee" << "LateFee" << endl;
						cout << left << setw(20) << " " << left << setw(2) << "Rs" << setw(3) << baserFee;
						cout << setw(19) << " ";
						cout << left << setw(2) << "Rs" << setw(3) << laterFee;

						cout << endl;
						cout << "Payment to be done on date given by the passport manamgement(0.No/1.Yes):";
						cin >> rlate;
						if (rlate == 1)
						{
							cout << left << setw(40) << "Payment Done For Renewal   = " << baserFee << endl;
						}

						else
						{
							cout << "No of days passed since the date for renewal of passport was given(Enter from 1-10 ) : ";
							cin >> rlatedays;

							// Display table header
							cout << left << setw(20) << " " << left << setw(20) << "Days Past Deadline" << "Total Fee" << endl;

							// Loop through days past deadline and calculate fees
							for (rdays = 1; rdays <= rlatedays; ++rdays) {
								rtotalFee = baserFee + (rdays * laterFee);

							}
							// Display days past deadline and corresponding fee
							cout << left << setw(20) << " " << left << setw(20) << rdays - 1 << "Rs" << rtotalFee << endl;
						}
						break;
					}
				}

				break;
			}

			case 6:
			{   int yy;
			system("cls");
			cout << "Apply For A New Passport(1.No/2.Yes) : ";
			cin >> yy;

			if (yy == 2)
			{
				goto start;//return 0;//return to main function
			}

			if (yy == 1)
			{
				int xx;
				cout << "\nCheck Already Registered Details(1.No/2.Yes) : ";
				cin >> xx;

				if (xx == 2)
				{
					ifstream inFile("registration_data");
					if (!inFile)
					{
						cerr << "Error opening file." << endl;
						return 0;
					}

					bool found = false;

					cout << "Enter your adhar_no to check whether already registered or newly registered(AAAA-BBBB-CCCC) : ";
					cin >> adhar_nno;
					while (inFile >> name >> address >> dob >> contact_no >> adhar_new >> f_name >> m_name >> s_name)
					{

						if (adhar_new == adhar_nno)
						{
							cout << "Already Registred\n";;
							AL_display();
							v[vcount].modify();
							found = true;
							break;
						}
					}

					if (!found)
					{

						cout << "Newly Registered\n";
						display();
						New_Registration neww;
						neww.genetrator();
					}

					inFile._Seekbeg();
					inFile.close();

				}

				if (xx == 1)
				{
					cout << "\nLogout Successfully";
					exit(0);
				}
			}
			break;
			}
			default:
			{
				cout << "Wrong Choice";
				break;
			}
			}
		}


	}

	return 0;
}