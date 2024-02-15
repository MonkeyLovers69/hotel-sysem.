#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <filesystem>
#include <windows.h>

using namespace std;
void setColor(unsigned int color) {
	std::cout << "\x1b[" << color << "m";
}
class MyClass1
{
public:
	void room_add() {
		fstream hotel("count.txt");
		string description, nomer, room_status = "empty"; string price, countOfGuests;
		int number, viborOperation;
		cout << "give room a description:\n";
		cin.ignore();
		getline(cin, description);
		cout << "room priece:";
		getline(cin, price);
		cout << "how many guests it can fit: ";
		cin >> countOfGuests;
		getline(hotel, nomer);
		hotel.close();
		fstream hotel2("count.txt");
		number = stoi(nomer);
		number += 1;
		hotel2 << to_string(number);
		ofstream newNumber("000" + to_string(number) + ".txt");
		newNumber << number << endl << "room descripton:" << description << endl << "amount of guests to fit:" << countOfGuests << endl << "price:" << price << endl << room_status;
		cout << "succesfully added!" << endl;
		newNumber.close();
		hotel2.close();
	}
};	
class room_deleting {
public: void roomdelete() {
	string deleting_room;
	cout << "enter number of room you want to delete: ";
	cin >> deleting_room;
	string filepath = "000" + deleting_room + ".txt";
	remove(filepath.c_str());
	cout << "room deleted succesfully! (can't be undone).\n";
}
};
class room_reserve
{
public:
	void roomreserving() {
		string	room_to_reserve;
		cout << "enter what room you want to reserve: "; 
		cin >> room_to_reserve;
		string room_reserv("000" + room_to_reserve + ".txt");
		deleteSubstring(room_reserv, "empty");
		cout << "Room reserved successfully";
	}
	void deleteSubstring(std::string fullFilePath, std::string substringToDelete) {
		std::ifstream fileIn(fullFilePath);
		std::stringstream buffer;
		buffer << fileIn.rdbuf();
		std::string content = buffer.str();
		fileIn.close();

		size_t pos = content.find(substringToDelete);
		while (pos != std::string::npos) {
			content.replace(pos, substringToDelete.length(), "Reserved");
			pos = content.find(substringToDelete, pos);
		}

		std::ofstream fileOut(fullFilePath);
		fileOut << content;
		fileOut.close();
	}
};
class infocout
{
public:
	void informationcout() {
		cout << "type room number you want to find information of: ";
		string roomFilePos;
		cin >> roomFilePos;
		string roomFilePosition = "000"+ roomFilePos+ ".txt";
		fstream nomerRoom(roomFilePosition);
		while (!nomerRoom.eof())
		{
			string roominfo;
			getline(nomerRoom,roominfo);
			cout << roominfo<<endl;
		}
	}

};
class populate
{
public:
	void deleteSubstring(std::string fullFilePath, std::string substringToDelete, std::string TextToPaste) {
		std::ifstream fileIn(fullFilePath);
		std::stringstream buffer;
		buffer << fileIn.rdbuf();
		std::string content = buffer.str();
		fileIn.close();

		size_t pos = content.find(substringToDelete);
		while (pos != std::string::npos) {
			content.replace(pos, substringToDelete.length(), TextToPaste);
			pos = content.find(substringToDelete, pos);

			std::ofstream fileOut(fullFilePath);
			fileOut << content;
			fileOut.close();
		}
	}
	void Populate() {
		string    guest_name;
		cout << "enter guest name: ";
		cin >> guest_name;
		string room;
		cout << "enter room: ";
		cin >> room;
		string  guest_file = guest_name + " guest_information.txt";
		ofstream guest(guest_file, ios_base::app);
		guest << endl << "hotel room: " << room << endl;
		deleteSubstring("000" + room + ".txt", "empty", "reserved by:" + guest_name);
		guest.close();
	}
};
class guestinfocout
{
public:
	void informationcout() {
		cout << "type guest name you want to find information of: ";
		string guestFilePos;
		cin >> guestFilePos; 
		string guestFilePosition = guestFilePos + " guest_information.txt";
		fstream guestinfo(guestFilePosition);
		while (!guestinfo.eof())
		{
			string guestinformation;
			getline(guestinfo,guestinformation );
			cout << guestinformation << endl;
		}
	}

};
class report {
public:
	void owner_report() {
		string myname;
		cin >> myname;
		string date;
		ofstream report_file(myname+ "_report" + ".txt");
		string report_info;
		getline(cin, report_info);
		time_t now;
		time(&now);
		tm ltm;
		localtime_s(&ltm, &now);
		int month = 1 + ltm.tm_mon;
		int day = ltm.tm_mday;
		string days = to_string(day);
		string months = to_string(month);
		report_file <<"date: " << month<< "." << days << endl << report_info << endl;
	}

};
class billsa
{
public:
	void bills() {
		string room_number;
		string empty_variable;
		int time_spent;
		cout << "enter room: ";
		cin >> room_number;
		cout << "time spent: ";
		string stringianprice;
		cin >> time_spent;
		string strprice;
		fstream room_file("000" + room_number + ".txt");
		while (!room_file.eof())
		{
			getline(room_file, empty_variable);
			if (empty_variable.find("price") != -1){
				strprice = empty_variable.erase(0, 6);
				cout << strprice;
				 int price = stoi(strprice);
				stringianprice = to_string(price * time_spent);
			}
		}
		cout << endl << "total: " << stringianprice << endl;
	}
};
class charges
{
public:
	void charging_bills() {
		string room_number;
		string empty_variable;
		int time_spent;
		cout << "enter room: ";
		cin >> room_number;
		cout << "time spent: ";
		string stringianprice;
		cin >> time_spent;
		string strprice;
		fstream room_file("000" + room_number + ".txt");
		while (!room_file.eof())
		{
			getline(room_file, empty_variable);
			if (empty_variable.find("price") != -1) {
				strprice = empty_variable.erase(0, 6);
				cout << strprice;
				int price = stoi(strprice);
				stringianprice = to_string(price * time_spent);
			}
		}
		cout << endl << "total: " << stringianprice << endl;
		room_file << "charged: " << stringianprice<< endl;
	}
};
class guest_reg
{
public:

	void guest_registration() {
		string guest_age; string guest_gender; string guest_passport; string guest_name;
		cout << "enter guest name: ";
		cin >> guest_name;
		cout << "Enter guest age: ";
		cin >> guest_age;
		cout << "enter guest gender: ";
		cin >> guest_gender;
		cout << "enter guest passport: ";
		cin >> guest_passport;
		ofstream guest_regist(guest_name + " guest_information.txt");
		guest_regist << guest_name << endl << guest_age << endl << guest_gender << endl << guest_passport;
		guest_regist.close();
		cout << "Information recorded successfully!" << endl;
	}
};
class move_out1
{
public:
	void deleteSubstring(std::string fullFilePath, std::string substringToDelete) {
		std::ifstream fileIn(fullFilePath);
		std::stringstream buffer;
		buffer << fileIn.rdbuf();
		std::string content = buffer.str();
		fileIn.close();
		size_t pos = content.find(substringToDelete);
		while (pos != std::string::npos) {
			content.replace(pos, substringToDelete.length(), "Reserved by:");
			pos = content.find(substringToDelete, pos + 1);
		}

		std::ofstream fileOut(fullFilePath);
		fileOut << content;
		fileOut.close();
	}

	void moving() {
		std::string guest_name;
		std::string room;
		std::cout << "enter room: ";
		std::cin >> room;
		std::string room_file = "000" + room + ".txt";
		std::string guest_file = guest_name + " guest_information.txt";
		std::string deleting_guest;
		std::cout << "enter guest you want to delete: ";
		std::cin >> deleting_guest;
		std::string filepath = deleting_guest + " guest_information.txt";
		deleteSubstring(room_file, "Reserved by:" + guest_name );
		remove(filepath.c_str());
		std::cout << "guest deleted successfully! (can't be undone).\n";
	}
};
class checklist
{
public:
	void reservation_check() {
		for (int room_num = 0; room_num < 9999; room_num++)
		{
			string num = to_string(room_num);
			fstream file_to_read("000"+ num + ".txt");
			string num_komnata_reserved = "000" + to_string(room_num);
			if (file_to_read) {
				while (!file_to_read.eof())
				{
					string gigga_nigga;
					getline(file_to_read, gigga_nigga);
					if (gigga_nigga.find("reserved by:") != -1)
					{
						cout << "reserved: " << num_komnata_reserved << endl;
					}
					if (gigga_nigga.find("empty") != -1)
					{
						cout << "unreserved: " << num_komnata_reserved << endl;
					}
				}
			}
		}
	}
};
class GUEST_REGIST
{
public:
	void guest_registing() {
		string guest_name;
		string guest_password;
		cout << "regist guest user: ";
		cin >> guest_name;
		cout << "enter guest password: ";
		cin >> guest_password;
		ofstream guest_regist_file(guest_name + ".txt");
		guest_regist_file << "guest name: " << guest_name << endl << "guest password: " << guest_password << endl;
	}

};
class guest_account_login {
public:
	bool guest_login_acc(string login, string password) {


		fstream guest_acc_file(login + ".txt");
		if (!guest_acc_file) {
			cout << "Account not found. Please register.\n";
			return false;
		}

		string stored_login;
		string stored_password;

		while (!guest_acc_file.eof()) {

			getline(guest_acc_file, stored_login);
			if (stored_login.find(login) != -1)
			{
				guest_acc_file.close();
				fstream guest_acc_file(login + ".txt");
				while (!guest_acc_file.eof()) {
					getline(guest_acc_file, stored_password);

					if (stored_password.find(password) != -1) {
						cout << "Logged in successfully!\n";

						return true;
						guest_acc_file.close();
					}
				}
			}


		}


		cout << "Login failed. Try again.\n";
		return false;
		guest_acc_file.close();
	}
};
class room_ordering
{
public:
	void room_order() { 
		string room_num_to_order;
		cout << "enter number of room you want to pre-order: ";
		cin >> room_num_to_order;
		ofstream room_to_order("room 000" + room_num_to_order + " order request.txt");
		string ordering_guest_name;
		string ordering_date;
		cout<< endl << "who orders room?: ";
		cin >> ordering_guest_name;
		cout <<endl<< "date of request and for how long will ordering last?:";
		cin >> ordering_date;
		room_to_order << "order request by: " << ordering_guest_name << endl << "for: " << ordering_date;
	}
};
class payment {
public:
	void pay(){
		string choice;
		cout << "choose way of payment:" << endl << "type 1 if you want to pay via cash:" << endl << "type 2 if you want to use Mastercard: " << endl << "type 3 if you want to pay via visa: ";
		if (choice == "1")
		{
			charges chargeP{};
			chargeP.charging_bills();
			cout << "go to reseption and pay via cash";
		}
		if (choice == "2") {
			string card_number;
			string date;
			string cardholder;
			cout << "enter your card number:";
			cin >> card_number;
			cout << endl << "enter date of expiration:";
			cin >> date;
			cout << endl << "enter cardholders name";
			cin >> cardholder;
			cout << "card_number:" << card_number << endl << "date of expitation:" << date << endl << "cardholder:" << cardholder;
		}
		if (choice == "3")
		{
			string card_number;
			string date;
			string cardholder;
			cout << "enter your card number:";
			cin >> card_number;
			cout << endl << "enter date of expiration:";
			cin >> date;
			cout << endl << "enter cardholders name";
			cin >> cardholder;
			cout << "card_number:" << card_number << endl << "date of expitation:" << date << endl << "cardholder:" << cardholder;
		}
	}
};
class guest_ordering
{
public:
	void guest_zakaz(string login) {
		string choice;
		int money_add_to_total = 0;
		string added_money = to_string(money_add_to_total);
		cout << "what would you like to order?";
		cout << endl << "type 1 if you want to order banana cocktail\ntype 2 if you want to order beef\ntype 3 if you want to order fried rice\ntype 4 if you want to order fried eggs: ";
		cin >> choice;
		if (choice == "1") {
			fstream acc_order(login + ".txt" ,ios_base::app);
			money_add_to_total+3;
			acc_order << "for ordering banana cocktail we add 3$ to your total "<< added_money <<endl;
		}
		if (choice == "2") {
			fstream acc_order(login + " bill.txt", ios_base::app);
			money_add_to_total +20 ; 
			acc_order << "for ordering beef we add 20$ to your total " << added_money << endl;
		}
		if (choice == "3") {
			fstream acc_order(login + ".txt", ios_base::app);
			money_add_to_total +4 ; 
			acc_order << "for ordering fried rice we add 4$ to your total " << added_money << endl;
		}
		if (choice == "4") {
			fstream acc_order(login + ".txt", ios_base::app);
			money_add_to_total +  2; 
			acc_order << "for ordering fried eggs we add 2$ to your total " << added_money << endl;
		}
	}
};
class redacting {
public:
	void rewriting() {
		string line_1;
		string line_2;
		string line_3;
		string line_4;
		cout << "type room you want to rewrite: ";
		cin >> line_1;
		system("cls");
		fstream rewriting_file("000" + line_1 + ".txt");
		cout << "enter room info: ";
		cin >> line_2;
		cout << "enter how many guests it can fit: ";
		cin >> line_3;
		cout << "how much does it cost a night: ";
		cin >> line_4;
		rewriting_file << "room information: " << line_2 << endl << "how many guests it can fit: " << line_3<<endl<<"price: "<< line_4<<endl;
		system("cls");
	}
};
int main()
{
	setColor(33);
	move_out1 moving{};
	populate populating{};
	report reporting{};
	billsa bill_check{};
	charges charge{};
	room_deleting room_del{};
	MyClass1 roomAdd{};
	room_reserve roomthatreserved{};
	guest_reg guest_information{};
	infocout informationvivod{};
	guestinfocout guest_info{};
	checklist checkreservation{};
	GUEST_REGIST guest_registration{};
	guest_account_login login_guest{};
	room_ordering room_order_request{};
	payment payment_ways{};
	guest_ordering orders{};
	redacting redo{};
	
	cout << "Hello its hotel *** , you want to login as admin or guest. \nTo login as admin type -'1', \nTo login as guest type -'0' ";
	int viborOperation;
	cin >> viborOperation;
	if (viborOperation == 1) {

		string admin_true_login;
		string login;
		ifstream admin_login("admin_login.txt");
		string password, login_password;
		ifstream passwordFile("admin_password.txt");
		while (!admin_login.eof() && !passwordFile.eof())
		{
			string line_1 = "login: ";
			getline(admin_login, admin_true_login);
			cout << line_1;
			cin >> login;
			string line_2 = "password: ";
			getline(passwordFile, password);
			cout << line_2;
			cin >> login_password;
		}
		if (admin_true_login == login and password == login_password) {
			int rep = 1;
			int choice;
			system("cls");
			while (rep == 1) {
				cout << "type 1 if you want to add a new room. \ntype 2 if you want to delete room(CAN'T BE UNDONE)\ntype 3 if you want to add guest info \ntype 4 if you want to reserve room \ntype 5 if you want to see room information\ntype 6 if you want to see guest information \ntype 7 if you want to take make a payment\ntype 8 if you want to make a report file\ntype 9 to populate room\ntype 0 if you want to move guest out\ntype 10 if you want to find free and reserved room\ntype 11 if you want to regist a new guest\ntype 12 if you want to redact certain room: ";
				cin >> choice;
				switch (choice) {
				case 1:
					system("cls");
					roomAdd.room_add();
					break;
				case 2:system("cls");
					room_del.roomdelete();
					break;
				case 3:system("cls");
					guest_information.guest_registration();
					break;
				case 4:system("cls");
					roomthatreserved.roomreserving();
					break;
				case 5:system("cls");
					informationvivod.informationcout();
					break; 
				case 6:system("cls");
					guest_info.informationcout();
					break; 
				case 7:system("cls");
					charge.charging_bills();
					break;
				case 8:system("cls");
					reporting.owner_report();
					break;
				case 9:system("cls");
					populating.Populate();
					break;
				case 0:system("cls");
					moving.moving();
					break;
				case 10:system("cls");
					checkreservation.reservation_check();
					break;
				case 11:system("cls");
					guest_registration.guest_registing();
					break;
				case 12:system("cls");
					redo.rewriting();
					break;
				default:
					break;
				}
			}
		}

	}
	else if (viborOperation == 0) {
		
		int choiceanotha;
		string login;
		string password;
		cout << "Enter login: ";
		cin >> login;
		cout << "Enter password: ";
		cin >> password;
		bool checking = login_guest.guest_login_acc(login, password);
		if (checking == true) {
			cout << "what you want to do? type 1 if you want to pre-order a room\nor type 2 if you want to check chagre for room\ntpye 3 if you want to pay your bills\ntype 4 if you want to order something: ";
			cin >> choiceanotha;
			switch (choiceanotha)
			{
			case 1:system("cls");
				room_order_request.room_order();
				break;
			case 2:system("cls");
				bill_check.bills();
				break;
			case 3:system("cls");
				payment_ways.pay();
				break;
			case 4:system("cls");
				orders.guest_zakaz(login);
			default:
				break;
			}
		}
	}
	}