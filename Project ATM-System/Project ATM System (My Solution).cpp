#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
void ShowMainMenueAtmScreen();
void GoBackToMainMenue();
//Struct AND Enum
struct stClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string PhoneNumber;
	double Balance=0;
};
enum enMainMenueAtm {
	eQuiqWithdraw = 1, eNoramlWithdraw = 2, eDeposit = 3, eCheckBalance = 4, eLogout = 5
};
enum enQuickWithdraw{
	T20=1, T50 , T100,  T200,T400,T600,T800,T1000,Exit
};
//GlobalVar
const string ClientsFile = "Clients.txt";
stClient CurrentClient;
//Helping Funct
double ReadPositiveAmount() {
	double Amount = 0;
	do{
		cout << "Enter a positive Deposit Amount?   ";
		cin >> Amount;
	} while (Amount<=0);
	return Amount;
}
int ReadAmount() {
	int Amount = 0;
	do{
		cout << "\nEnter an amount multiple of 5's ?  ";
		cin >> Amount;
	} while (Amount%5!=0);
	return Amount;
}
short ReadClientChoice() {
	short Choice;
	cout << "Choose what do you want to do? [1 to 5]?  ";
	cin >> Choice;
	return Choice;
}
short ReadWithdrawChoice() {
	short Choice = 0;
	cout << "Choose what to withdraw from[1] to [8] ?";
	cin >> Choice;
	return Choice;
}
vector<string>SplitString(string S1,string Delim="#//#") {
vector<string>Vstring;
string Word;
short Pos = 0;
while ((Pos = S1.find(Delim)) != string::npos) {
	Word = S1.substr(0, Pos);
	if (Word != "") {
		Vstring.push_back(Word);
	}
	S1.erase(0, Pos + Delim.length());
}
if (S1 != "") {
	Vstring.push_back(S1);
}
return Vstring;
}
stClient ConvertLineToRecord(string Line) {
	vector<string>Vwords = SplitString(Line);
	stClient Client;
	Client.AccountNumber = Vwords[0];
	Client.PinCode = Vwords[1];
	Client.Name = Vwords[2];
	Client.PhoneNumber = Vwords[3];
	Client.Balance = stod(Vwords[4]);
	return Client;
}
string ConvertRecordToLine(stClient Client) {
	string Line;
	Line += Client.AccountNumber + "#//#";
	Line += Client.PinCode + "#//#";
	Line += Client.Name + "#//#";
	Line += Client.PhoneNumber + "#//#";
	Line +=to_string(Client.Balance);
	return Line;
}
vector<stClient> LoadDataClientFromFile(string File) {
	vector<stClient> VClients;
	fstream MyFile;
	MyFile.open(File, ios::in);
	string Line;
	if (MyFile.is_open()) {
		while (getline(MyFile, Line)) {
			VClients.push_back(ConvertLineToRecord(Line));
		}
	}
	return VClients;
}
void SaveDataClientsInFile(string File, vector<stClient>VClients) {
	fstream Myfile;
	Myfile.open(File,ios::out);
	if (Myfile.is_open()){
		for (stClient& C : VClients){
			Myfile << ConvertRecordToLine(C) << endl;
		}
		Myfile.close();
	}
}
//Login
bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client) {
	vector<stClient>Vclients = LoadDataClientFromFile(ClientsFile);
	for (stClient& C : Vclients) {
		if ((C.AccountNumber == AccountNumber) && (C.PinCode == PinCode))
		{
			Client = C;
			return true;
		}
	}
	return false;
}
bool LoadDataLogin(string AccountNumber, string PinCode) {
	if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient)) {
		return true;
	}
	return false;
}
void Login() {
	bool LoginFailed = false;
	string AccountNumber;
	string PinCode;
	do
	{
		system("cls");
		cout << "\n___________________________________________\n";
		cout << "\t\tLogin Screen\n";
		cout << "___________________________________________\n";
		if (LoginFailed) {
			cout << "Invalid Account Number/PinCode!\n";
		}
		cout << "Enter Account Number?   ";
		getline(cin>>ws, AccountNumber);
		cout << "Enter Pin?   ";
		getline(cin, PinCode);
		LoginFailed = !LoadDataLogin(AccountNumber, PinCode);
	} while (LoginFailed);
	ShowMainMenueAtmScreen();
}
//Check Balance
double GetBalance() {
	vector<stClient>VClients = LoadDataClientFromFile(ClientsFile);
	for (stClient& C : VClients){
		if (C.AccountNumber== CurrentClient.AccountNumber) {
			return C.Balance;
		}
	}
	return 0;
}
void CheckBalanceScreen() {
	cout << "=======================================\n";
	cout << "\tCheck Balance Screen";
	cout << "\n=======================================\n";
	cout << "Your Balance is "<< GetBalance();
}
//Deposit_Amount
void DepositAmount(vector<stClient>&VcLients,double Amount) {
	for (stClient& C : VcLients){
		if (C.AccountNumber==CurrentClient.AccountNumber){
			C.Balance += Amount;
		}
	}
}
//Normal Withdraw
bool ShowWithdrawScreen() {
	cout << "============================================\n";
	cout << "\tNormal Withdraw Screen\n";
	cout << "============================================\n";
	vector<stClient>Vclients = LoadDataClientFromFile(ClientsFile);
	char Answer = 'y';
	int Amount = ReadAmount();
	if (Amount > CurrentClient.Balance) {
		cout << "\nThe amount exceeds your balance, make another choice.";
		return false;
	}
	else {
		cout << "\n\nAre you sure you want perform this transction? y/n ? ";
		cin >> Answer;
		if (tolower(Answer) == 'y') {
			DepositAmount(Vclients, Amount * -1);
		}
		SaveDataClientsInFile(ClientsFile, Vclients);
		cout << "\n\nDone Successfully. New balance is: " << GetBalance();
		return true;
	}

}
//Quick Withdraw
double GetAmount(enQuickWithdraw QuickWithdraw) {
	switch (QuickWithdraw) {
	case enQuickWithdraw::T20:
		return 20;
	case enQuickWithdraw::T50:
		return 50;
	case enQuickWithdraw::T100:
		return 100;
	case enQuickWithdraw::T200:
		return 200;
	case enQuickWithdraw::T400:
		return 400;
	case enQuickWithdraw::T600:
		return 600;
	case enQuickWithdraw::T800:
		return 800;
	case enQuickWithdraw::T1000:
		return 1000;
	}
}
bool ScreenQuickWithdraw(enQuickWithdraw QuickWithdraw) {
	vector<stClient>Vclients=LoadDataClientFromFile(ClientsFile);
	char Answer = 'y';
	double Amount=GetAmount(QuickWithdraw);
	if (Amount>CurrentClient.Balance){
		cout << "\nThe amount exceeds your balance, make another choice.";
		return false;
	}
	else{
		cout << "\n\nAre you sure you want perform this transction? y/n ? ";
		cin >> Answer;
		if (tolower(Answer)== 'y'){
			DepositAmount(Vclients, Amount*-1);
		}
		SaveDataClientsInFile(ClientsFile, Vclients);
		cout << "\n\nDone Successfully. New balance is: " << GetBalance();
		return true;
	}
	
}
void PreformeQuickWithDrawMenue(enQuickWithdraw QuickWithdraw) {
	switch (QuickWithdraw) {
	case enQuickWithdraw::T20:
		ScreenQuickWithdraw(QuickWithdraw);
		GoBackToMainMenue();
		break;
	case enQuickWithdraw::T50:
		ScreenQuickWithdraw(QuickWithdraw);
		GoBackToMainMenue();
		break;
	case enQuickWithdraw::T100:
		ScreenQuickWithdraw(QuickWithdraw);
		GoBackToMainMenue();
		break;
	case enQuickWithdraw::T200:
		ScreenQuickWithdraw(QuickWithdraw);
		GoBackToMainMenue();
		break;
	case enQuickWithdraw::T400:
		ScreenQuickWithdraw(QuickWithdraw);
		GoBackToMainMenue();
		break;
	case enQuickWithdraw::T600:
		ScreenQuickWithdraw(QuickWithdraw);
		GoBackToMainMenue();
		break;
	case enQuickWithdraw::T800:
		ScreenQuickWithdraw(QuickWithdraw);
		GoBackToMainMenue();
		break;
	case enQuickWithdraw::T1000:
		ScreenQuickWithdraw(QuickWithdraw);
		GoBackToMainMenue();
		break;
	case enQuickWithdraw::Exit:
		ShowMainMenueAtmScreen();
	}
}
void ShowQuickWithDrawMenue() {
	cout << "===============================================\n";
	cout << "\t\tQuick Withdraw\n";
	cout << "===============================================\n";
	cout << "\t[1] 20";
	cout << "\t\t[2] 50\n";
	cout << "\t[3] 100";
	cout << "\t\t[4] 200\n";
	cout << "\t[5] 400";
	cout << "\t\t[6] 600\n";
	cout << "\t[7] 800";
	cout << "\t\t[8] 1000\n";
	cout << "\t[9] Exit\n";
	cout << "===============================================\n";
	cout << "Your Balance is " << CurrentClient.Balance<<endl;
	PreformeQuickWithDrawMenue((enQuickWithdraw)ReadWithdrawChoice());
}
//Deposit
bool ShowDepositScreen() {
	cout << "============================================\n";
	cout << "\tDeposit Screen\n";
	cout << "============================================\n";
	vector<stClient>Vclients = LoadDataClientFromFile(ClientsFile);
	char Answer = 'y';
	double Amount = ReadPositiveAmount();
	cout << "\n\nAre you sure you want perform this transction? y/n ? ";
	cin >> Answer;
	if (tolower(Answer) == 'y') {
		DepositAmount(Vclients, Amount);
		SaveDataClientsInFile(ClientsFile, Vclients);
		cout << "\n\nDone Successfully. New balance is: " << GetBalance();
		return true;
	}
	else
	{
		return false;
	}

}
//GoBackToMainMenue
void GoBackToMainMenue() {
	cout << "\n\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenueAtmScreen();
}
//MainMenue
void preformeMainMenue(enMainMenueAtm MainMenueAtm) {
	switch (MainMenueAtm) {
	case enMainMenueAtm::eQuiqWithdraw:
		system("cls");
		ShowQuickWithDrawMenue();
		GoBackToMainMenue();
		break;
	case enMainMenueAtm::eNoramlWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueAtm::eCheckBalance:
		system("cls");
		CheckBalanceScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueAtm::eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueAtm::eLogout:
		system("cls");
		Login();
		break;
	}
}
void ShowMainMenueAtmScreen() {
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tATM Main Menue Screen";
	cout << "\n===========================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "===========================================\n";
	preformeMainMenue((enMainMenueAtm)ReadClientChoice());
}
int main() {
	Login();
	return 0;
}
