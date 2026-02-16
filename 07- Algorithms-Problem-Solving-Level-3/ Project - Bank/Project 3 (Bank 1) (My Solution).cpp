#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;
const string FileName = "Clients.txt";
struct stClient{
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double AccountBalance;
	bool Mark=false;
};
enum enMainMenueOptions
{
	ShowClient=1, AddingClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5,Exit=6
};
void PrintHeaderScreen(string S1) {
	cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
	cout << "\n\t" << S1 << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
}
void MainMenue(enMainMenueOptions );
string ReadAccountNumber() {
	string AccountNumber;
	cout << "\nPlease enter Account Number?    ";
	getline(cin>>ws, AccountNumber);
	return AccountNumber;
}
enMainMenueOptions ReadUserInput() {
	short UserInput = 0;
	do
	{
		cout << "Choose what do you want to do?  [1 to 6]?  ";
		cin >> UserInput;
	} while (UserInput < 1 || UserInput > 6);
	return (enMainMenueOptions)UserInput;
}
vector<string>SplitString(string S1, string Seperator = "#//#") {
	vector<string>Vwords;
	string Word;
	short Position = 0;
	while ((Position=S1.find(Seperator))!=string::npos) {
		Word = S1.substr(0, Position);
		if (Word!=""){
			Vwords.push_back(Word);
		}
		S1.erase(0,Position+ Seperator.length());
	}
	if (S1!=""){
		Vwords.push_back(S1);
	}
	return Vwords;
}
string ConvertRecordToLine(stClient Client, string Seperator = "#//#") {
	string S1;
	S1 += Client.AccountNumber + Seperator;
	S1 += Client.PinCode + Seperator;
	S1 += Client.Name + Seperator;
	S1 += Client.PhoneNumber + Seperator;
	S1 += to_string( Client.AccountBalance) ;
	return S1;
}
stClient ConvertLineToRecord(string Line,string Seperator="#//#") {
	stClient Client;
	vector<string>Vwords = SplitString(Line);
	Client.AccountNumber = Vwords[0];
	Client.PinCode = Vwords[1];
	Client.Name = Vwords[2];
	Client.PhoneNumber = Vwords[3];
	Client.AccountBalance =stod(Vwords[4]);
	return Client;
}
void SaveNewClientInFile(string FileName, stClient Client) {
	fstream Myfile;
	string Line = ConvertRecordToLine(Client);
	Myfile.open(FileName,ios::app);
	if (Myfile.is_open())
	{
		Myfile << Line << endl;
		Myfile.close();
	}
}
vector<stClient> LoadDataClientsFromFile(string FileName) {
	vector<stClient>Vclients;
	fstream Myfile;
	string Line;
	Myfile.open(FileName,ios::in);
	if (Myfile.is_open()){
		while (getline(Myfile, Line)) {
			Vclients.push_back(ConvertLineToRecord(Line));
		}
		Myfile.close();
	}
	return Vclients;
}
void ShowMainMenue() {
	system("cls");
	cout << "===============================================\n";
	cout << "\t\t Main Menue Screen\n";
	cout << "===============================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "===============================================\n";
	MainMenue(ReadUserInput());
}
void PrintClient(stClient &Client) {
	cout << "| " << left << setw(17) << Client.AccountNumber;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(35) << Client.Name;
	cout << "| " << left << setw(10) << Client.PhoneNumber;
	cout << "| " << left << setw(10) << Client.AccountBalance<<endl;
}
void ShowClientsListScreen(string FileName) {
	vector<stClient> Vclients = LoadDataClientsFromFile(FileName);
	cout << "\n\t\t\t\t Client List (" << Vclients.size() << ") Client(s).";
	cout << "\n_______________________________________________________________________";
	cout << "_________________________\n\n";
	cout << "| " << left << setw(17) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(35) << "Client Name";
	cout << "| " << left << setw(10) << "Phone";
	cout << "| " << left << setw(10) << "Balance";
	cout << "\n_______________________________________________________________________";
	cout << "_________________________\n\n";
	if (Vclients.size()==0)
		cout << "\t\t\t\tNo Clients Available In The System!";
	else {
		for (stClient& Client : Vclients) {
			PrintClient(Client);
		}
	}
	 cout << "\n_______________________________________________________________________";
	 cout << "_________________________\n\n";
}
bool IsClientExist(string AccountNumber) {
	vector<stClient>VClients = LoadDataClientsFromFile(FileName);
	for (stClient& C : VClients){
		if (C.AccountNumber== AccountNumber){
			return true;
		}
	}
	return false;
}
bool FindDataClient(string AccountNumber, stClient &Client) {
	vector<stClient>VClients = LoadDataClientsFromFile(FileName);
	for (stClient& C : VClients){
		if (C.AccountNumber== AccountNumber){
			Client = C;
			return true;
		}
	}
	return false;
}
void PrintClientCard(stClient Client) {
	cout << "\nThe following are the client details:\n";
	cout << "________________________________________\n";
	cout << "Account Number  : "<< Client.AccountNumber<<endl;
	cout << "Pin Code        : "<< Client.PinCode<<endl;
	cout << "Name            : "<< Client.Name<<endl;
	cout << "Phone Number    : "<< Client.PhoneNumber<<endl;
	cout << "Account Balance : "<< Client.AccountBalance<<endl;
	cout << "________________________________________\n";

}
bool MarkClientTodelete(string AccountNumbers, vector<stClient>&Vclients) {
	for (stClient& C : Vclients){
		if (C.AccountNumber== AccountNumbers){
			C.Mark = true;
			return true;
		}
	}
	return false;
}
void SaveClientsInFile(string FileName,vector<stClient> Vclients) {
	fstream Myfile;
	Myfile.open(FileName,ios::out);
	if(Myfile.is_open()) {
		for (stClient& C : Vclients){
			if (C.Mark==false)
			{
				Myfile << ConvertRecordToLine(C) << endl;
			}
		}
		Myfile.close();
	}
}
stClient UpdateDataClient(string AccountNumber){
	stClient Client;
	Client.AccountNumber = AccountNumber;
	cout << "Enter Pin Code?  ";
	getline(cin>>ws, Client.PinCode);
	cout << "Enter Name?  ";
	getline(cin, Client.Name);
	cout << "Enter Phone?  ";
	getline(cin, Client.PhoneNumber);
	cout << "Enter Account Balance?  ";
	cin >> Client.AccountBalance;
	return Client;
}
stClient AddClient() {
	stClient Client;
	cout << "Adding New Client:\n";
	cout << "Enter Account Number?   ";
	getline(cin>>ws, Client.AccountNumber);
	while (IsClientExist(Client.AccountNumber)) {
		cout << "\nClient With ["<< Client.AccountNumber <<"] Already exists ,Enter another Account Number?  ";
		getline(cin >> ws, Client.AccountNumber);
	}
	cout << "Enter Pin Code?  ";
	getline(cin, Client.PinCode);
	cout << "Enter Name?  ";
	getline(cin, Client.Name);
	cout << "Enter Phone?  ";
	getline(cin, Client.PhoneNumber);
	cout << "Enter Account Balance?  ";
	cin >> Client.AccountBalance;
	return Client;
}
void AddNewClientScreen() {
	char Answer = 'y';
	do
	{
		system("cls");
		PrintHeaderScreen("Add New Clients Screen");
		stClient CLient = AddClient();
		SaveNewClientInFile(FileName,CLient);
		cout << "\nClient Added SuccessFully,do you want to add more clients? Y/N?  ";
		cin >> Answer;
	} while (tolower(Answer)=='y');
}
void DeleteClientScreen() {
	stClient Client;
	char answer = 'y';
	PrintHeaderScreen("Delete Client Screen");
	string AccountNumber = ReadAccountNumber();
	if (FindDataClient(AccountNumber, Client)){
		PrintClientCard(Client);
		cout << "\nAre you sure you want delete this client? y/n?   \n";
		cin >> answer;
		if (tolower(answer)=='y') {
			vector<stClient>Vclients = LoadDataClientsFromFile(FileName);
			MarkClientTodelete(AccountNumber, Vclients);
			SaveClientsInFile(FileName,Vclients);
			cout << "\nClient Deleted Successfully.\n";
		}
	}
	else
	{
		cout << "Account Number " << AccountNumber << " is not find\n";
	}
}
void FindClientScreen() {
	stClient Client;
	PrintHeaderScreen("Find Client Screen");
	string AccountNumber = ReadAccountNumber();
	if (FindDataClient(AccountNumber, Client)){
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient With Account Number [" << AccountNumber << "] is not found!\n";
	}

}
void UpdateClientScreen() {
	stClient Client;
	char answer = 'y';
	PrintHeaderScreen("Update Client Info Screen");
	string AccountNumber = ReadAccountNumber();
	if (FindDataClient(AccountNumber, Client)) {
		PrintClientCard(Client);
		cout << "\nAre you sure you want update this client? y/n?   \n";
		cin >> answer;
		if (tolower(answer) == 'y') {
			vector<stClient>Vclients = LoadDataClientsFromFile(FileName);
			for (stClient& C : Vclients){
				if (C.AccountNumber==AccountNumber){
					C = UpdateDataClient(AccountNumber);
					break;
				}
			}
			SaveClientsInFile(FileName, Vclients);
			cout << "\nClient Updated Successfully.\n";
		}
	}
	else
	{
		cout << "Account Number " << AccountNumber << " is not find\n";
	}

}
void ExitScreen() {
	PrintHeaderScreen("Program Ends :-)");
}
void MainMenue(enMainMenueOptions MainMenueOptions) {

	switch (MainMenueOptions) {
	case enMainMenueOptions::AddingClient:
		system("cls");
		AddNewClientScreen();
		system("pause");
		ShowMainMenue();
		break;
	case enMainMenueOptions::DeleteClient:
		system("cls");
		DeleteClientScreen();
		system("pause");
		ShowMainMenue();
		break;
	case enMainMenueOptions::FindClient:
		system("cls");
		FindClientScreen();
		system("pause");
		ShowMainMenue();
		break;
	case enMainMenueOptions::UpdateClient:
		system("cls");
		UpdateClientScreen();
		system("pause");
		ShowMainMenue();
		break;
	case enMainMenueOptions::Exit:
		system("cls");
		ExitScreen();
		system("pause");
		return ;
		break;
	case enMainMenueOptions::ShowClient:
		system("cls");
		ShowClientsListScreen(FileName);
		system("pause");
		ShowMainMenue();
		break;
	}
}
int main() {
	ShowMainMenue();
	return 0;
}
