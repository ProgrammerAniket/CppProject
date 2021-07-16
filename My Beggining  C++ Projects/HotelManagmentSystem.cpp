//Header Files
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

//Global vraibles and functions.
void manageRooms();
int main();

class Customer
{
public:
    char name[100];
    char address[100];
    char phone[100];
    char from_date[100];
    char to_date[100];
    double advancePayment;
};

//Class Room
class Room
{
public:
    //Varibales of Room Class
    int roomno;
    int roomid;
    int status;
    //Functions of Room Class
    class Customer cust;
    void addRoom(int rno);
    void searchRoom(int rno);
    int backToMain();
    void displayRoom(Room);
};

Room rooms[100]; //Object of the Room class stores 100 elemnent.
int count = 0;   // Varibale which stores the count.

//Defining the function of the class Room
void Room ::addRoom(int rno)
{
    rooms[count].roomno = rno;
    cout << "Enter the room id " << endl;
    cin >> rooms[count].roomid;
    cout << "Room added succesfully! " << endl;
    count++;
    cout << "this is count no " << count << endl;
    rooms[count].status = 0;
    cout << "Press any key to continue.." << endl;
    _getch();
    manageRooms();
}

void Room ::searchRoom(int rno)
{
    int i, found = 0;

    for (i = 0; i < count; i++)
    {
        if (rooms[i].roomno == rno)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {
        if (status == 0)
        {
            cout << "ROOM IS NOT BOOKED " << endl;
            displayRoom(rooms[i]);
            cout << "Press any key to continue.." << endl;
            _getch();
            manageRooms();
        }

        else if (status == 1)
        {
            cout << "ROOM IS BOOKED " << endl;
            displayRoom(rooms[i]);
            cout << "Press any key to continue.." << endl;
            _getch();
            manageRooms();
        }
    }

    else
    {
        cout << "Room not found " << endl;
        cout << "Press any key to continue.." << endl;
        _getch();
        manageRooms();
    }
}

int Room ::backToMain()
{
    main();
}

void Room ::displayRoom(Room tempRoom)
{
    cout << "\n\t\t ROOM DETAILS : " << endl;
    cout << "Room id " << tempRoom.roomid << endl;
    cout << "Room no " << tempRoom.roomno << endl;
}

//Defining the Global function
void manageRooms()
{
    system("CLS");
    int ch, rno;
    cout << "\t\t\t[1] Add a room " << endl;
    cout << "\t\t\t[2] Search a room " << endl;
    cout << "\t\t\t[3] Back to main" << endl;
    cin >> ch;

    //Switch case to check the input and the cases
    switch (ch)
    {
    case 1:
        cout << "Enter the room no " << endl;
        cin >> rno;
        rooms->addRoom(rno);
        break;

    case 2:

        if (count == 0)
        {
            cout << "There is no room added " << endl;
            cout << "Press any key to continue.." << endl;
            _getch();
            manageRooms();
        }

        else
        {
            cout << "Enter the room no " << endl;
            cin >> rno;
            rooms->searchRoom(rno);
        }
        break;

    case 3:
        rooms->backToMain();
        break;

    default:
        cout << "Please enter a valid input " << endl;
        break;
    }
}

//Creating a hotel managment class.
class HotelManagment : public Room
{
public:
    void checkIn();
    void getAvailableRooms();
};

void HotelManagment ::checkIn()
{
    int rno, i, found = 0;

    cout << "Enter the room number : " << endl;
    cin >> rno;

    for (i = 0; i < count; i++)
    {
        if (rooms[i].roomno == rno)
        {
            found = 1;
            break;
        }
    }

    if (found == 1)
    {

        if (rooms[i].status == 0)
        {
            cout << "Enter the name of the customer " << endl;
            cin >> cust.name;
            cout << "Enter the address of the customer " << endl;
            cin >> cust.address;
            cout << "Enter the phone number of the customer " << endl;
            cin >> cust.phone;
            cout << "Enter the from date " << endl;
            cin >> cust.from_date;
            cout << "Enter the to date " << endl;
            cin >> cust.to_date;
            cout << "Enter the advance paymnent " << endl;
            cin >> cust.advancePayment;
            rooms[i].status = 1;
            cout << "Room Booked Succesfully " << endl;
            cout << "Press any key to continue.." << endl;
            _getch();
            main();
        }

        if (rooms[i].status == 1)
        {
            cout << "Room is already booked " << endl;
            cout << "Press any key to continue.." << endl;
            _getch();
            main();
        }
    }

    else
    {
        cout << "Room not found " << endl;
        cout << "Press any key to continue.." << endl;
        _getch();
        main();
    }
}



int main()
{
    class HotelManagment htl;
    system("CLS");
    int ch;
    cout << "\t\t\t[1] Manage Room " << endl;
    cout << "\t\t\t[2] Check_IN " << endl;
    cout << "\t\t\t[3] Get available rooms " << endl;
    cout << "\t\t\tENTER THE CHOICE HERE " << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        manageRooms();
        break;

    case 2:

        if (count == 0)
        {
            cout << "First add the rooms there are no rooms in the hotel " << endl;
            cout << "Press any key to continue.." << endl;
            _getch();
            main();
        }

        else
        {
            htl.checkIn();
        }

        case 3:

        if (count == 0)
        {
            cout << "First add the rooms there are no rooms in the hotel " << endl;
            cout << "Press any key to continue.." << endl;
            _getch();
            main();
        }

        else
        {
            htl;
        }

    default:
        break;
    }
}