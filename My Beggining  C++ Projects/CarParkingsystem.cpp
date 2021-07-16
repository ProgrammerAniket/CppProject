#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Parking
{
    int choice;
    int i;
    float money = 0, count = 0;
    int r = 0;
    int b = 0;
    int c = 0;
    int v = 0;

public:
    void Menu(void)
    {
        while (1)
        {
            cout << "ENTER 1 FOR RICKSHAW : " << endl;
            cout << "ENTER 2 FOR BUS : " << endl;
            cout << "ENTER 3 FOR CAR : " << endl;
            cout << "ENTER 4 FOR VAN : " << endl;
            cout << "ENTER 5 TO VIEW THE RECORD : " << endl;
            cout << "ENTER 6 TO DELETE THE RECORD : " << endl;
            cin >> choice;
            if (choice == 1)
            {
                if (count <= 50)
                {
                    r++;
                    count = count + 1;
                    money = money + 100;
                }

                else if (count > 50)
                {
                    cout << "There is no space to park the car " << endl;
                }
            }
            else if (choice == 2)
            {
                if (count <= 50)
                {
                    b++;
                    count = count + 1;
                    money = money + 200;
                }

                else if (count > 50)
                {
                    cout << "There is no space to park the car " << endl;
                }
            }

            else if (choice == 3)
            {
                if (count < 50)
                {
                    c++;
                    count = count + 1;
                    money = money + 300;
                }

                else if (count > 50)
                {
                    cout << "There is no space to park the car " << endl;
                }
            }

            else if (choice == 4)
            {
                if (count <= 50)
                {
                    v++;
                    count = count + 1;
                    money = money + 400;
                }

                else if (count > 50)
                {
                    cout << "There is no space to park the car " << endl;
                }
            }

            else if (choice == 5)
            {
                if (count == 0)
                {
                    cout << "There is no vehicles to show " << endl;
                }

                else
                {
                    cout << "Total vehicles parked : " << count << endl;
                    cout << "Total amount of the vehicles are : " << money << endl;
                    cout << "Total Rickshaws Parked : " << r << endl;
                    cout << "Total Bus Parked : " << b << endl;
                    cout << "Total Car Parked : " << c << endl;
                    cout << "Total Van Parked : " << v << endl;
                }
            }

            else if (choice == 6)
            {
                count = 0;
                money = 0;
                r = 0;
                b = 0;
                c = 0;
                v = 0;
                cout << "Total vehicles parked : " << count << endl;
                cout << "Total amount of the vehicles are : " << money << endl;
                cout << "Total Rickshaws Parked : " << r << endl;
                cout << "Total Bus Parked : " << b << endl;
                cout << "Total Car Parked : " << c << endl;
                cout << "Total Van Parked : " << v << endl;
            }

            else
            {
                cout << "PLEASE ENTER A VALID INPUT " << endl;
            }
        }
    }
};

int main()
{
    Parking p1;
    p1.Menu();
    return 0;
}