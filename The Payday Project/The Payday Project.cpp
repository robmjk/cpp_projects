// The Payday Project
// Sign up and login system
// Heister must input multiple types of information during sign up
// These details will save to the user credentials and can then be viewed by anyone that is also registered
// Information about heister to include: 
// Name (Username), Unique Password (This will not be shown), Height (cm and feet), Profession (Heister, Mastermind), Description (Experience), Skills (List of skills: Expert technician, driver, etc.), Date of signing
// A way to display list of all heisters that are registered
// A way to create a loading phase after successful login
// Classes involved: Heisters, Contractors, User, Registration, Login

#include <iostream>
#include <string> // for extra use of strings
#include <iomanip> // for table
#include <thread> // blocks execution the program for loading phase
#include <chrono> // pausing the program for loading phase

using namespace std;

// user class
class User
{
public:
	string username;
	string password;
	User() : username(""), password("") {}  // default constructor
	User(const string& name, const string& pwd) : username(name), password(pwd) {} // constructor initializing user with username and password
};

const int MAX_USERS = 3; // max users
User users[MAX_USERS]; // array storing users (users in database already)
int numUsers = 0; // registered users

// user registration
class Registration
{
public:
	// user signing
	bool signUp(const string& username, const string& password)
	{
		// check if username exists
		for (int u = 0; u < numUsers; ++u)
		{
			if (users[u].username == username)
			{
				cout << "User already exists in Project Day" << endl;
				return false;
			}
		}
		// user does not exist, user added to array
		if (numUsers < MAX_USERS)
		{
			users[numUsers] = User(username, password);
			++numUsers;
			cout << "User: " << username << ", you have successfully signed with the Payday Project" << endl;
			cout << "-------------------------------------------------------------------" << endl;
			cout << "" << endl;
			cout << "Please sign in below to view Payday Project records" << endl;
			return true;
		}
		// max user limit
		else
		{
			cout << "User limit reached" << endl;
			return false;
		}
	}
};

// user login 
class Login
{
public:
	// method to authenticate a user based on username and password
	static User* authenticate(const string& username, const string& password)
	{
		for (int u = 0; u < numUsers; ++u)
		{
			if (users[u].username == username && users[u].password == password)
				return &users[u];
		}
		return nullptr;
	}
};

class Heisters
{
private:
	string nameHeister;
	string roleHeister;
	string affiliationsHeister;
	string rangedHeister;
	string meleeHeister;
	string nationalityHeister;
	string languagesHeister;
	string ageHeister;
	string dobHeister;
	string hairColourHeister;
	string eyeColourHeister;
	string buildHeister;
	string heightHeister;
	string ethnicityHeister;
	string skillsHeister;

public:
	// constructor to initialize all string variables based on a heisters' information
	Heisters(const string& nameHeister, const string& roleHeister, const string& affiliationsHeister, const string& rangedHeister, const string& meleeHeister,
		const string& nationalityHeister, const string& languagesHeister, const string& ageHeister, const string& dob,
		const string& hairColourHeister, const string& eyeColourHeister, const string& buildHeister, const string& heightHeister, const string& ethnicityHeister, const string& skillsHeister)
		: nameHeister(nameHeister), roleHeister(roleHeister), affiliationsHeister(affiliationsHeister), rangedHeister(rangedHeister), meleeHeister(meleeHeister), nationalityHeister(nationalityHeister), languagesHeister(languagesHeister), ageHeister(ageHeister), dobHeister(dobHeister),
		hairColourHeister(hairColourHeister), eyeColourHeister(eyeColourHeister), buildHeister(buildHeister), heightHeister(heightHeister), ethnicityHeister(ethnicityHeister), skillsHeister(skillsHeister) {}

	// method to get name as a formatted string
	string getHeisterName() const { return "Name: " + nameHeister; }
	// method to get career information as a formatted string
	string getHeisterCareerInformation() const { return "Role: " + roleHeister + "Affiliations: " + affiliationsHeister; }
	// method to get signature weapons as a formatted string
	string getHeisterSignatureWeapons() const { return "Ranged: " + rangedHeister + "Melee: " + meleeHeister; }
	// method to get biographical information as a formatted string
	string getHeisterBiographicalInformation() const { return "Nationality: " + nationalityHeister + "Languages: " + languagesHeister + "Age: " + ageHeister + "Date of Birth: " + dobHeister; }
	// method to get physical description as a formatted string
	string getHeisterPhysicalDescription() const { return "Hair Colour: " + hairColourHeister + "Eye Colour: " + eyeColourHeister + "Build: " + buildHeister + "Height: " + heightHeister + "Ethnicity: " + ethnicityHeister; }
	// method to get skills as a formatted string
	string getHeisterSkillset() const { return "Skills: " + skillsHeister; }
};

class Contractors
{
private:
	string nameContractor;
	string roleContractor;
	string nationalityContractor;
	string languagesContractor;
	string ageContractor;

public:
	// constructor to initialize all string variables based on a contractors' information
	Contractors(const string& nameContractor, const string& roleContractor, const string& nationalityContractor, const string& languagesContractor, const string& ageContractor)
		: nameContractor(nameContractor), roleContractor(roleContractor), nationalityContractor(nationalityContractor), languagesContractor(languagesContractor), ageContractor(ageContractor) {}

	// method to get name as a formatted string
	string getContractorName() const { return nameContractor; }
	// method to get role as a formatted string
	string getContractorCareerInformation() const { return roleContractor; }
	// method to get nationality as a formatted string
	string getContractorBiographicalInformation() const { return "Nationality: " + nationalityContractor + "Languages: " + languagesContractor + "Age: " + ageContractor; }
	// method to get age as a formatted string
	string getContractorAge() const { return ageContractor; }
};

int main()
{
	Registration registration;

	// user signing up
	registration.signUp("Kribz1k", "123456");

	// asking user for details
	string username, password;
	cout << "User: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	// user logging in
	User* loggedInUser = Login::authenticate(username, password);

	// user logged
	if (loggedInUser) {
		cout << "Welcome to the crew, " << loggedInUser->username << endl;
		cout << "----------------------------" << endl;
	}
	// user not found/failed
	else
	{
		cout << "Unregistered user, IP logged" << endl;
	}

	// loading message
	cout << "Loading records of Project Payday's Heister's and Contractor's...";
	cout << "\n" << endl;
	cout << "\n" << endl;

	// 3 second delay
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));

	const int numHeisters = 1; // number of heisters
	Heisters* heisters[numHeisters]; // declares an array called heisters that can hold numHeisters pointers to Heisters objects

	heisters[0] = new Heisters("Kribz1k ", "Mastermind - ", "Mozzarella Mafia ", "USR - ", "Golden Knife ", "Australian - ", "English & German - ", "22 - ", "02/05/2001 ", "Brown - ", "Green - ", "Medium Muscle Build - ", "183cm / 6ft - ", "Caucasian ", "Hacker + Sniper + Hand-to-hand Combat ");
	// heisters[1] = new Heisters("Spunkii ")
	// Heisters[2] = new Heisters("Nayf ")

	for (int i = 0; i < numHeisters; ++i) {
		cout << "HEISTER'S" << endl;
		cout << "---------" << endl;
		cout << "\n" << endl;
		cout << "Heister's Name" << endl;
		cout << "--------------" << endl;
		cout << heisters[i]->getHeisterName() << endl;
		cout << "=============" << endl;
		cout << "Career Information" << endl;
		cout << "------------------" << endl;
		cout << heisters[i]->getHeisterCareerInformation() << endl;
		cout << "=================================================" << endl;
		cout << "Signature Weapons" << endl;
		cout << "-----------------" << endl;
		cout << heisters[i]->getHeisterSignatureWeapons() << endl;
		cout << "=================================" << endl;
		cout << "Biographical Information" << endl;
		cout << "------------------------" << endl;
		cout << heisters[i]->getHeisterBiographicalInformation() << endl;
		cout << "===========================================================================================" << endl;
		cout << "Physical Description" << endl;
		cout << "--------------------" << endl;
		cout << heisters[i]->getHeisterPhysicalDescription() << endl;
		cout << "================================================================================================================" << endl;
		cout << "Skillset" << endl;
		cout << "--------" << endl;
		cout << heisters[i]->getHeisterSkillset() << endl;
		cout << "=============================================" << endl;
		delete heisters[i]; // deleting dynamically allocated objects
	}

	const int numContractors = 1; // number of contractors
	Contractors* contractors[numContractors];

	contractors[0] = new Contractors("Capo Steve ", "Sicilian Conflict Veteran / Smuggler / Black Market Weapon Launderer ", "Italian ", "English, Italian, Arabic ", "Unknown ");

	for (int i = 0; i < numContractors; ++i) {
		cout << "\n" << endl;
		cout << "\n" << endl;
		cout << "\n" << endl;
		cout << "CONTRACTOR'S" << endl;
		cout << "------------" << endl;
		cout << "\n" << endl;
		cout << "Contractor's Name" << endl;
		cout << "-----------------" << endl;
		cout << contractors[i]->getContractorName() << endl;
		cout << "==========" << endl;
		cout << "Career Information" << endl;
		cout << "------------------" << endl;
		cout << contractors[i]->getContractorCareerInformation() << endl;
		cout << "====================================================================" << endl;
		cout << "Biographical Information" << endl;
		cout << "------------------------" << endl;
		cout << contractors[i]->getContractorBiographicalInformation() << endl;
		cout << "=====================================================================" << endl;
		delete contractors[i]; // deleting dynamically allocated objects
	}

	return 0;
}