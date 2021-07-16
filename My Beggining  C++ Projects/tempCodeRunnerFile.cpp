                }
            }

            cout << "ROOM NOT FOUND! " << endl;
            cout << "Press any key to continue..." << endl;
            _getch();
            main();
        }
    }

    else if (u_input == 3)
    {
        string roomno, roomid, u_name;
        if (counter == 0)
        {
            cout << "THERE IS NO ROOMS TO BE BOOKED FIRST ADD THE ROOM " << endl;
            cout << "Press any key to continue..." << endl;
            _getch();
            main();
        }

        else
        {

            cout << "ENTER THE ROOMNO : " << endl;
            cin >> roomno;
            cout << "ENTER THE ROOMID : " << endl;
            cin >> roomid;
            for (int i = 0; i < counter; i++)
            {
                if (room[i].getRoomNo() == roomno && room[i].getRoomId() == roomid)
                {
                    cout << "ROOM FOUND! " << endl;
                    cout << "ENTER THE USER NAME OF THE ROOM " << endl;
                    cin >> u_name;
                    room[i].setName(u_name);
                    BookingIncrement(bookCounter);
                    cout << " ROOM BOOKED SUCCESFULLY " << endl;
                    cout << "PRESS ANY KEY TO CONTINUE..." << endl;
                    _getch();
                    main();
                }
            }

            cout << "ROOM NOT FOUND!" << endl;
            cout << "PRESS ANY KEY TO CONTINUE..." << endl;
            _getch();
            main();
        }
    }

    else if (u_input == 4)
    {
        string roomno, roomid, u_name;
        if (bookCounter == 0)
        {
            cout << "NO ROOMS IS BOOKED FIRST BOOK THE ROOM " << endl;
            cout << "Press any key to continue..." << endl;
            _getch();
            main();
        }

        else
        {

            cout << "ENTER THE ROOMNO : " << endl;
            cin >> roomno;
            cout << "ENTER THE ROOMID : " << endl;
            cin >> roomid;
            cout << "ENTER THE USER NAME : " << endl;
            cin >> u_name;
            for (int i = 0; i < bookCounter; i++)
            {
                for (int j = 0; i < counter; j++)
                {
                    if (room[i].getName() == u_name && room[i].getRoomNo() == roomno && room[i].getRoomId() == roomid)
                    {
                        cout << "ROOM FOUND!" << endl;
                        cout << "Press any key to continue..." << endl;
                        _getch();
                        main();
                    }

                    if (room[i].getName() != u_name && room[i].getRoomNo() != roomno && room[i].getRoomId() != roomid && room[j].getName() != u_name && room[j].getRoomNo() == roomno && room[j].getRoomId() == roomid)
                    {
                        cout << "ROOM IS THERE BUT THE ROOM IS NOT BOOKED ! " << endl;
                        cout << "Press any key to continue..." << endl;
                        _getch();
                        main();
                    }
                }
                cout << "ROOM IS NOT ADDED " << endl;
                main();
            }
        }
    }
    cout << "Press any key to continue.." << endl;
    _getch();
    main();
}