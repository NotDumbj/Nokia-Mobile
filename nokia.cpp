#include<iostream>
#include<conio.h>
#include<thread>
#include<Windows.h>
#include<chrono>

#pragma comment(lib, "Winmm.lib")

using namespace std;

// Function declarations
void mainmenu();
void message();
void message1();
void inbox();
void messagetimerThread();
void calltimerThread();
void call();
void calltimer();
int messagetimer();
void playsound();

// Global variables for thread termination
bool exitMessagetimerThread = false;
bool exitCalltimerThread = false;
bool callcheck = false;

int main()
{
    thread timerThread1(messagetimerThread);
    thread timerThread2(calltimerThread);

    // Main menu
    mainmenu();

    // Set termination flags
    exitMessagetimerThread = true;
    exitCalltimerThread = true;

    // Wait for threads to finish
    timerThread1.join();
    timerThread2.join();

    return 0;
}

void mainmenu()
{
    system("cls");
    cout << "   _________________" << endl;
    cout << " //=================\\\\" << endl;
    cout << " ||      NOKIA      ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " || > Message ( 1 ) ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " || > Call    ( 2 ) ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " ||-----------------||" << endl;
    cout << " || [1]   [2]   [3] ||" << endl;
    cout << " || [4]   [5]   [6] ||" << endl;
    cout << " || [7]   [8]   [9] ||" << endl;
    cout << " || [0]   [✓]   [x] ||" << endl;
    cout << " \\\\_________________//" << endl;

    while (true)
    {
        char option = _getch();
        if (option == '1')
        {
            message();
            break;
        }
        else if (option == '2')
        {
            call();
            break;
        }
        else
        {
            cin.clear();
            if (_kbhit)
            {
                _getch();
            }
        }
    }
}

void message()
{
    system("cls");
    cout << "   _________________" << endl;
    cout << " //=================\\\\" << endl;
    cout << " ||      NOKIA      ||" << endl;
    cout << " ||    Messages     ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " ||  >  Send  ( 1 ) ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " ||  >  Inbox ( 2 ) ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " ||-----------------||" << endl;
    cout << " || [1]   [2]   [3] ||" << endl;
    cout << " || [4]   [5]   [6] ||" << endl;
    cout << " || [7]   [8]   [9] ||" << endl;
    cout << " || [0]   [✓]   [x] ||" << endl;
    cout << " \\\\_________________//" << endl;

    while (true)
    {
        char option2 = _getch();
        if (option2 == '1')
        {
            message1();
            mainmenu();
            break;
        }
        else if (option2 == '2')
        {
            system("cls");
            inbox();
            mainmenu();
            break;
        }
    }
}

void call()
{
    system("cls");
    cout << "   _________________" << endl;
    cout << " //=================\\\\" << endl;
    cout << " ||      NOKIA      ||" << endl;
    cout << " ||      Calls      ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " ||  Enter Phone :  ||" << endl;
    cout << " ||   (11-digit)    ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " ||                 ||" << endl;
    cout << " ||-----------------||" << endl;
    cout << " || [1]   [2]   [3] ||" << endl;
    cout << " || [4]   [5]   [6] ||" << endl;
    cout << " || [7]   [8]   [9] ||" << endl;
    cout << " || [0]   [✓]   [x] ||" << endl;
    cout << " \\\\_________________//" << endl;

    char phonecall[11];  // Increased size to account for null-terminator
    for (int i = 0; i < 11; i++)
    {
        phonecall[i] = _getch();
        cout << "*";  // Display '*' for each digit entered
    }
    

    system("cls");
    cout << "Calling " << phonecall << " ....";
    this_thread::sleep_for(chrono::seconds(3));
    system("cls");
    cout << "Call not received.....\n\n";
    system("pause");
    mainmenu();
}

void message1()
{
    system("cls");
    cout << "  Enter receiver phone no : ";
    string phoneno;
    cin >> phoneno;

     

    cout << "  Type your message here : ";
    string messagesent;
    cin >> messagesent;
    system("cls");
    cout << "  Message has been sent...";
    _getch();
}

void inbox()
{
    int check = messagetimer();
    if (check == 0)
    {
        cout << "  Your Inbox is empty, check again later.";
    }
    if (check == 1)
    {
        cout << "  Old AC Deal : Sale!!! AC Sale your AC, Window AC, Split AC, Cabinet AC...";
    }
    if (check == 2)
    {
        cout << "  Rafay : Jldi Basement AAA....";
    }
    cout << "\n\n  ";
    system("pause");
}

void messagetimerThread()
{
    while (!exitMessagetimerThread)
    {
        int check = messagetimer();
        // playsound();  // Commented this out to handle sound in calltimerThread
    }
}

void calltimerThread()
{
    while (!exitCalltimerThread)
    {
        calltimer();
        calltimer();
    }
}

int messagetimer()
{
    int n = 0;
    if (n == 0)
    {
        n++;
        return 0;
    }
    Beep(1500, 200);
    this_thread::sleep_for(chrono::seconds(25));
    system("cls");
    cout << "  You received a message...\n";
    

    if (n == 1)
    {
        n++;
        return 1;
    }
    else if (n == 2)
    {
        return 2;
    }
}

void calltimer()
{
    int counter = 0;

    if (counter == 0)
    {
        this_thread::sleep_for(chrono::seconds(20));
        system("cls");
        cout << "   _________________\n";
        cout << " //=================\\\\\n";
        cout << " ||      NOKIA      ||\n";
        cout << " ||                 ||\n";
        cout << " ||                 ||\n";
        cout << " ||    Call From    ||\n";
        cout << " ||    Armaghan G   ||\n";
        cout << " ||                 ||\n";
        cout << " ||  (A)       (D)  ||\n";
        cout << " ||-----------------||\n";
        cout << " || [1]   [2]   [3] ||\n";
        cout << " || [4]   [5]   [6] ||\n";
        cout << " || [7]   [8]   [9] ||\n";
        cout << " || [0]   [✓]   [x] ||\n";
        cout << " \\\\_________________//\n";
    }

    if (counter == 1)
    {
        this_thread::sleep_for(chrono::seconds(20));
        system("cls");
        cout << "   _________________\n";
        cout << " //=================\\\\\n";
        cout << " ||      NOKIA      ||\n";
        cout << " ||                 ||\n";
        cout << " ||                 ||\n";
        cout << " ||    Call From    ||\n";
        cout << " ||    Rafay Bhai   ||\n";
        cout << " ||                 ||\n";
        cout << " ||  (A)       (D)  ||\n";
        cout << " ||-----------------||\n";
        cout << " || [1]   [2]   [3] ||\n";
        cout << " || [4]   [5]   [6] ||\n";
        cout << " || [7]   [8]   [9] ||\n";
        cout << " || [0]   [✓]   [x] ||\n";
        cout << " \\\\_________________//\n";
    }
    thread timerThread(playsound);
    while (true)
    {
        char callchoice;
        cin >> callchoice;
        if (callchoice == 'A' || callchoice == 'a')
        {
            system("cls");
            callcheck = true;

            cout << "   _________________\n";
            cout << " //=================\\\\\n";
            cout << " ||      NOKIA      ||\n";
            cout << " ||                 ||\n";
            cout << " ||                 ||\n";
            cout << " ||     Network     ||\n";
            cout << " ||      Issue      ||\n";
            cout << " ||       ...       ||\n";
            cout << " ||                 ||\n";
            cout << " ||-----------------||\n";
            cout << " || [1]   [2]   [3] ||\n";
            cout << " || [4]   [5]   [6] ||\n";
            cout << " || [7]   [8]   [9] ||\n";
            cout << " || [0]   [✓]   [x] ||\n";
            cout << " \\\\_________________//\n";
            Sleep(1500);
            mainmenu();
        }
        else if (callchoice == 'd' || callchoice == 'D')
        {
            system("cls");
            callcheck = true;

            cout << "   _________________\n";
            cout << " //=================\\\\\n";
            cout << " ||      NOKIA      ||\n";
            cout << " ||                 ||\n";
            cout << " ||                 ||\n";
            cout << " ||       Call      ||\n";
            cout << " ||     Declined    ||\n";
            cout << " ||       ...       ||\n";
            cout << " ||                 ||\n";
            cout << " ||-----------------||\n";
            cout << " || [1]   [2]   [3] ||\n";
            cout << " || [4]   [5]   [6] ||\n";
            cout << " || [7]   [8]   [9] ||\n";
            cout << " || [0]   [✓]   [x] ||\n";
            cout << " \\\\_________________//\n";
            Sleep(1500);
            mainmenu();
        }
        else
        {
            cin.clear();
        }
    }
    counter++;
    timerThread.join();
}

void playsound()
{
    while (true)
    {
        Beep(1500, 200);
        this_thread::sleep_for(chrono::milliseconds(200));
        if (callcheck == true)
        {
            return;
        }
    }

}
