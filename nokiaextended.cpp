#include <iostream>
#include <conio.h>
#include <thread>
#include <Windows.h>
#include <chrono>

#pragma comment(lib, "Winmm.lib")

using namespace std;

// Function declarations
void mainmenu();
void message();
void message1(const string& senderPhoneNumber);
void inbox();
int messagetimer();
void messagetimerThread();
void calltimerThread();

void call();
void calltimer(const string& callType);
void playsound();

// Global variables for thread termination
bool exitMessagetimerThread = false;
bool exitCalltimerThread = false;
bool callcheck = false;
string callcheckType;

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
            mainmenu();
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
            // Add support for different message types
            cout << "\nSelect Message Type:\n";
            cout << "1. Plain Text\n";
            cout << "2. Audio Message\n";
            cout << "3. Video Message\n";
            cout << "4. Multimedia Message\n";

            char messageTypeOption = _getch();
            switch (messageTypeOption)
            {
            case '1':
                message1("Plain Text");
                break;
            case '2':
                message1("Audio Message");
                break;
            case '3':
                message1("Video Message");
                break;
            case '4':
                message1("Multimedia Message");
                break;
            default:
                break;
            }
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
    cout << "   ______________________" << endl;
    cout << " //=========+++++========\\\\" << endl;
    cout << " ||        NOKIA         ||" << endl;
    cout << " ||        Calls         ||" << endl;
    cout << " ||                      ||" << endl;
    cout << " ||  Select Call Type:   ||" << endl;
    cout << " ||  [1] Audio Call      ||" << endl;
    cout << " ||  [2] Video Call      ||" << endl;
    cout << " ||  [3] Conference Call ||" << endl;
    cout << " \\\\____________________//" << endl;

    char option = _getch();
    if (option == '1')
    {
        callcheckType == "Audio";
        calltimerThread();
    }
    else if (option == '2')
    {
        callcheckType == "Video";
        calltimerThread();
    }
    else if (option == '3')
    {
        callcheckType == "Conference";
        calltimerThread();
    }
    else
    {
        cin.clear();
    }
}

void message1(const string& messageType)
{
    system("cls");
    cout << "  Enter receiver phone no : ";
    string phoneno;
    cin >> phoneno;

    cout << "  Type your " << messageType << " here : ";
    string messagesent;
    cin >> messagesent;
    system("cls");
    cout << "  " << messageType << " has been sent...";
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

void calltimer(const string& callType)
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
        if (callcheck == true)
        {
            return;
        }

        // Play different sounds based on the call type
        if (callcheck && callcheckType == "Audio")
        {
            Beep(1500, 200);
        }
        else if (callcheck && callcheckType == "Video")
        {
            // Play video call sound (replace with actual implementation)
            cout << "Playing video call sound..." << endl;
        }
        else if (callcheck && callcheckType == "Conference")
        {
            // Play conference call sound (replace with actual implementation)
            cout << "Playing conference call sound..." << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(200));
    }
}


void calltimerThread()
{
    while (!exitCalltimerThread)
    {
        calltimer(callcheckType);
    }
}
