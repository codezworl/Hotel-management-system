#include<iostream>
#include<ctime>
#include<string>
#include<windows.h>
#include<fstream>
#include <sstream>
using namespace std;

class Hotel {
private:
	int id, days, phone; 
	string date;
	double price;
	string name, roomtype;
	Hotel* next;

public:
	Hotel* head = NULL;

	

	void verfication() {
		system("COLOR 80");
		int choice;
		system("cls");

		cout << "\t\t\t\t  \n\n\n\n\n\n\t\t\t\t\t Welcom to online Booking system" << endl;
		cout << "\t\t\t\t\t            Verify " << endl;
		cout << "\t\t\t\t\t----------TO continue----------" << endl;

	start:
		srand(time(0));
		setcolor(240);
		int r = rand();
		cout << " CAPTCHA CODE IS = " << r << endl;
		setcolor(15);
		cout << "\n\t\t\tENTER CAPTCHA TO LOGIN IN =";
		cin >> choice;

		if (choice == r) {
			setcolor(0x0C);
			cout << "\n\t\t\tLogin successfully " << endl;
			setcolor(15);
		}
		else {

			cout << "\n\t\t\tWrong PassWord .Enter Correct Pass " << endl;

			goto start;
		}


		cout << "\n\n\n";
		cout << "\t\t\t Loading : ";
		char y = 221;
		for (int a = 0; a < 30; a++) {
			cout << y;
			Sleep(100);

		}
		menu();
	

	}
	string setcolor(unsigned short color) {
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, color);
		return "";
	}



	void menu() {

		system("COLOR 60");
		int choice;

		system("cls");

		cout << "\t\t\t-------------------------------------------" << endl;
		cout << "\t\t\t-----WELCOME TO BOOKING PORTAL-----" << endl;
		cout << "\t\t\t-------------------------------------------" << endl;
		cout << "\n\t\t\t 1.ENTER TO SELECT ROOM  " << endl;
		cout << "\n\t\t\t 2.ENTER TO PRINT BILL " << endl;
		cout << "\n\t\t\t 3.ENTER TO SEARCH ROOM " << endl;
		cout << "\n\t\t\t 4.SHOW ROOM RECORDS " << endl;
		cout << "\n\t\t\t 5.safe data " << endl;
		cout << "\n\t\t\t 6.Administration " << endl;
		cout << "\n\t\t\t 7.Exit " << endl;

	Again:

		cout << "\n\t\t\t****************************";
		cout << "\n\t\t\tEnter Your choice :";
		cin >> choice;
		switch (choice) {

		case 1:
			insert();

			break;
		case 2:
			BILL();
			break;  
		case 3:
			search_room();

			break;
		case 4:
			showRoom_recrds();
			break;

		case 5:
			savefile();
			break;
		case 6:
		    admin();
			break;	
        case 7:
		exit(0);
		default:
			cout << "Invalid option " << endl;
			Sleep(5);
         menu();

		}



	}
	


	void admin() {
		

		//system("cls");
		string pass = "";
		cout << "\n\n\n\n\n\n\n\t\t\t\t\tEnter Password: ";
		cin >> pass;
		if (pass == " pass") {
			cout << "\n\n\t\t\t\t\tAccess Granted \n";
		}
		if (pass!="pass")
		{
			cout << "\n\n\t\t\t\t\tAccess Aborted...Press Any Key To Try Again\n";
			//system("CLS");
			//Sleep(3);
			admin();
		}
			
		

		system("cls");
		system("COLOR 60");
		int choice;

	

		cout << "\t\t\t-------------------------------------------" << endl;
		cout << "\t\t\t-----WELCOME TO ADMIN PORTAL-----" << endl;
		cout << "\t\t\t-------------------------------------------" << endl;
		cout << "\n\t\t\t 1.ENTER TO UPDATE ROOM " << endl;
		cout << "\n\t\t\t 2.ENTER TO DELETE ROOM  " << endl;
		cout << "\n\t\t\t 3.SHOW ROOM RECORDS " << endl;
		cout << "\n\t\t\t 4.GO BACK " << endl;
		cout << "\n\t\t\t 5.EXIT " << endl;

	Again:

		cout << "\n\t\t\t****************************";
		cout << "\n\t\t\tEnter Your choice :";
		cin >> choice;
		switch (choice) {

		case 1:
			update_room();

			break;
		case 2:
			delete_Room();

			break;
		case 3:
			showRoom_recrds();
	
			break;
		case 4:
			menu();

			break;
		case 5:
			exit(0);
		default:
			cout << "Enter correct option " << endl;
		Sleep(2);
         menu();

		}
	}



	void insert() {
		system("cls");
		cout << "\n\t__________Hotel  Managment System__________" << endl;
		Hotel* temp = new Hotel;

		cout << "\nEnter Your id : ";
		cin >> temp->id;
		cout << "\nEnter Customer Name : ";
		cin.get();
		getline(cin, temp->name);
		cout << "\nEnter Allocated Date : ";
		cin.get();
		getline(cin, temp->date);
		cout<<"\nEnter Your Phone Number : ";
		cin>>temp->phone;
		cout << "\nEnter Room Type ( Single || Double || Twin ) : ";
		cin >> temp->roomtype;
		cout<<"\nHow Many Days You Want To stay : ";
		cin>>temp->days;									

		if (head == NULL) {
			head = temp;
		}
		else {
			Hotel* ptr = head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = temp;
		}
		cout << "\n\n\t\t New Room Inserted " << endl;

	p:
		char E = 0;
		cout << "\b " << "\n\t\tPRESS Y TO CHECK PRICE = ";
		cin >> E;
		if (E == 'y' || E == 'Y') {
			check_price();
		}
		else {
			cout << "Enter Correct KEY";

			goto p;
		}
	}

	void check_price() {
		system("cls");

		if (head == NULL) {
			cout << "Linked list is Empty " << endl;
		}
		else {
			Hotel* ptr = head;
			
				if (ptr->days == 1) {
					ptr->price = 4000;
					cout << "\n\n\t\t\tYour Stay Days is " << ptr->days << endl;
					cout << "\n\n\t\t\tFOR 1 DAY STAY YOUR PRICE IS  " << ptr->price << endl;
					
				}
				if (ptr->days == 2) {
					ptr->price = 6000;
					cout << "\n\n\t\t\tYour Stay Days is " << ptr->days << endl;
					cout << "\n\t\t\tFOR 2 DAY STAY YOUR PRICE IS  " << ptr->price << endl;
				}
				if (ptr->days == 3) {
					ptr->price = 8500;
					cout << "\n\n\t\t\tYour Stay Days is " << ptr->days << endl;
					cout << "\n\t\t\tFOR 3 DAY STAY YOUR PRICE IS  " << ptr->price << endl;
				}
				if (ptr->days == 4) {
					ptr->price = 10000;
					cout << "\n\n\t\t\tYour Stay Days is " << ptr->days << endl;
					cout << "\n\t\t\tFOR 4 DAY STAY YOUR PRICE IS  " << ptr->price << endl;
				}
				if (ptr->days == 5) {
					ptr->price = 15500;
					cout << "\n\n\t\t\tYour Stay Days is " << ptr->days << endl;
					cout << "\n\t\t\tFOR 5 DAY STAY YOUR PRICE IS  " << ptr->price << endl;

					
				}
			
				
		}
	p:
		char E = 0;
		cout << "\b " << "\n\n\tPRESS Y TO GO BACK = ";
		cin >> E;
		if (E == 'y' || E == 'Y') {
			menu();
		}
		else {
			cout << "Enter Correct KEY";

			goto p;
		}
	}


	void search_room() {

		system("cls");
		int t_id;

		if (head == NULL) {
			cout << "Linked list is Empty " << endl;
		}
		else {
			cout << "\n\nEnter YOUR ID TO SEARCH ROOM " << endl;
			cin >> t_id;
			Hotel* ptr = head;
			while (ptr != NULL) {
				if (t_id == ptr->id) {
					cout << "\n\nCustomer ID IS " << ptr->id << endl;
					cout << "\n\nCustomer Name " << ptr->name << endl;
					cout << "\n\nCustomer Phone " << ptr->phone << endl;
					cout << "\n\nRoom Allocated Date " << ptr->date << endl;
					cout << "\n\nRoom Type " << ptr->roomtype << endl;
					cout << "\n\nDAYS STAY " << ptr->days << endl;
					cout << "\n\nTOTAL PRICE " << ptr->price << endl;
				}
				ptr = ptr->next;

			}
		p:
			char E = 0;
			cout << "\b " << "\n\t\tPRESS Y TO GO BACK = ";
			cin >> E;
			if (E == 'y' || E == 'Y') {
				menu();
			}
			else {
				cout << "Enter Correct KEY";

				goto p;
			}


		}
	}
	

	void showRoom_recrds() {
		system("cls");
		Hotel* ptr = head;
		while (ptr != NULL)
		{
			cout << "\n\t\t\tCustomer ID :" << ptr->id << endl;
			cout << "\n\t\t\tCustomer Name :" << ptr->name << endl;
			cout << "\n\t\t\tCustomer Phone :" << ptr->phone << endl;
			cout << "\n\t\t\tAllocated Date :" << ptr->date << endl;
			cout << "\n\t\t\tRoom Type :" << ptr->roomtype << endl;
			cout << "\n\t\t\tDAYS STAY :" << ptr->days << endl;
			cout << "\n\n\t\tTOTAL PRICE " << ptr->price << endl;
			cout << "------------------------------------------------------------" << endl;
			ptr = ptr->next;
		}
	p:
		char E = 0;
		cout << "\b " << "\n\t\tPRESS Y TO GO BACK = ";
		cin >> E;
		if (E == 'y' || E == 'Y') {
			menu();
		}
		else {
			cout << "Enter Correct KEY";

			goto p;
		}

	}
	

	int savefile(void)
	{ 
	 Hotel* save =head;
        int fs = 0;
        fstream fout("save.txt",ios::out);

        if (!fout.is_open())  // failed to open file
        {
            cout << "Could not open the file " << "save.txt" << endl;
            return 0;
			
        }
        fout << " ID\tName\tDate\tdate\tphone\tRoomtype\tdays\tprice\n\n";

        while ( save != NULL )
        {
            fout << save->id << "\t" << save->name << "\t" << save->date<<"\t"<<save->phone<<"\t"<<save->roomtype<<"\t"<<save->days<<"\t"<<save->price<< endl;
            save = save->next;
            fs = 1;
        }
        fout.close();
        if (fs == 0)
        {
            cout << "Empty database !! \n";
           return 0;
        }
        else
        {
            cout << "Done \n";
           // return 1;
        }
	p:
		char E = 0;
		cout << "\b " << "\n\t\tPRESS Y TO GO BACK = ";
		cin >> E;
		if (E == 'y' || E == 'Y') {
			menu();
		}
		else {
			cout << "Enter Correct KEY";

			goto p;
		}

	}
	
	void BILL() {
		system("cls");
		ifstream fin("save.txt");
		if (!fin.is_open()) {
			cout << "Could not open the file " <<"save.txt" << endl;
			return;
		}
		int id;
		cout << "Enter the ID of the room you want to generate bill for: ";
		cin >> id;
		string data;
		bool found = false;
		while (getline(fin, data)) {
			stringstream ss(data);
			int roomId;
			ss >> roomId;
			if (roomId == id) {
				found = true;
				cout << data << endl;

			}
		}
		if (!found) {
			cout << "No room found with ID " << id << endl;
		}
		fin.close();

		char E = 0;
		cout << "\n\t\tPRESS Y TO GO BACK = ";
		cin >> E;
		if (E == 'y' || E == 'Y') {
			menu();
		}
	}
	void update_room() {
		system("cls");
		if (head == NULL) {
			cout << "Linked list is Empty " << endl;
		}
		else {
			int t_id;
			cout << "\n\nEnter Room ID TO UPDATE: ";
			cin >> t_id;

			Hotel* ptr = head;
			while (ptr != NULL) {
				if (t_id == ptr->id) {
					cout << "\nEnter YOUR ID: ";
					cin >> ptr->id;
					cout << "\nEnter Customer Name: ";
					cin.get();
					getline(cin, ptr->name);
					cout << "\nEnter Allocated Date: ";
					getline(cin, ptr->date);
					cout << "Enter Your Phone Number :" << endl;
					cin >> ptr->phone;
					cout << "\nEnter Room Type (Single || Double || Twin): ";
					cin >> ptr->roomtype;
					cout << "How Many Days You Want To stay: ";
					cin >> ptr->days;

					cout << "Record Update Successfully " << endl;
					break;
				}
				ptr = ptr->next;
			}
		}

		char E = 0;
		cout << "\n\t\tPRESS Y TO GO BACK = ";
		cin >> E;
		if (E == 'y' || E == 'Y') {
			admin();
		}
	}
	
void delete_Room() {
		system("cls");
		int t_id;

	if (head == NULL) {
    cout << "Linked list is Empty " << endl;
      } 
else {
    cout << "\n\nEnter Room ID TO DELETE " << endl;
    cin >> t_id;
    Hotel* pre = head;
    Hotel* ptr = head;
    while (ptr != NULL) {
        if (t_id == ptr->id) {
            if (ptr == head) {
                head = ptr->next;
            } else {
                pre->next = ptr->next;
            }
            delete ptr;
            cout << "Data is Deleted Successfully " << endl;
            break;
        }
        pre = ptr;
        ptr = ptr->next;
    }
}
		
	p:
		char E = 0;
		cout << "\b " << "\n\t\tPRESS Y TO GO BACK = ";
		cin >> E;
		if (E == 'y' || E == 'Y') {
			admin();
		}
		else {
			cout << "Enter Correct KEY";

			goto p;
		}
	}






};
int main() {
	Hotel h;
	h.verfication();
}








