#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    // password for user access their car
    string password;
    // speed of car
    int speed;
    // user choice of primary menu
    string menu_choice;
    // user choice of sub menu
    string sub_menu_choice;
    // couting number of acceleration or deceleration
    int count;
    // remember user choice
    string memory;
} Data;

Data x;

bool checksub_menu_choice(char sub_menu_choice);

bool checkmenu_choice(char menu_choice);

void P_mode();

void N_mode();

void menu2();

void proccessMenu2();

void warning();

void login()
{
    cout << "NHAP MA SO CA NHAN " << endl;
    string checkPass = "12345678";
    getline(cin, x.password);
    while (checkPass.compare(x.password))
    {
        cout << "SAI MA SO CA NHAN" << endl;
        cout << "VUI LONG NHAP LAI MA SO CA NHAN" << endl;
        getline(cin, x.password);
    }
}

/**
 * Show primary menu for user
 * @return None
 */
void menu()
{
    cout << "XIN MOI LUA CHON" << endl;
    cout << "1. P" << endl;
    cout << "2. R" << endl;
    cout << "3. N" << endl;
    cout << "4. D" << endl;
    cout << "5. POWER OFF" << endl;
    cin >> x.menu_choice;
}

/**
 * Show sub menu for user
 * @return None
 */
void menu2()
{
    cout << "------- TOC DO HIEN TAI LA " << x.speed << "\n"
         << endl;
    if (x.menu_choice == "2" && x.speed >= 20)
    {
        cout << "TROI OI CHAY CHI GIU VAY" << endl;
    }
    else if (x.menu_choice == "4" && x.speed >= 60)
    {
        cout << "CHAY TU TU THOI" << endl;
    }
    cout << "MOI LUA CHON: " << endl;
    cout << "1. TANG TOC" << endl;
    cout << "2. GIAM TOC" << endl;
    cout << "3. PHANH" << endl;
    cout << "4. TRO VE MENU" << endl
         << "\t >> ";
    cin >> x.sub_menu_choice;
}

/**
 * Validate user's input of primary menu
 * @return Boolean
 */
bool checkmenu_choice(string menu_choice)
{
    return (menu_choice == "1" || menu_choice == "2" || menu_choice == "3" || menu_choice == "4" || menu_choice == "5");
}

/**
 * Validate user's input of sub menu
 * @return Boolean
 */
bool checksub_menu_choice(string sub_menu_choice)
{
    return (sub_menu_choice == "1" || sub_menu_choice == "2" || sub_menu_choice == "3" || sub_menu_choice == "4");
}

/**
 * Process function of primary menu
 * @return None
 * 
 */
void proccessMenu1()
{
    // show primary menu/
    menu();
    // validate user select
    while (!checkmenu_choice(x.menu_choice))
    {
        // clear terminal
        printf("\033c");
        // show menu again
        cout << "VUI LONG LUA CHON TU 1 DEN 5 THEO MENU" << endl
             << "XIN MOI LUA CHON" << endl
             << "1. P" << endl
             << "2. R" << endl
             << "3. N" << endl
             << "4. D" << endl
             << "5. POWER OFF" << endl;
        // get input
        cin >> x.menu_choice;
    }
    // in case car in Reverse mode -> user want to change to Drive mode
    if (x.memory == "2")
    {
        while (x.menu_choice == "4" && x.speed > 0)
        {
            printf("\033c");
            cout << "VAN TOC DANG CON, KHONG THE CHUYEN CHE DO!!!" << endl
                 //  << "VUI LONG CHUYEN VE 'P' HOAC 'N' HOAC GIAM VAN TOC" << endl
                 << "XIN MOI LUA CHON" << endl
                 << "1. P" << endl
                 << "2. R" << endl
                 << "3. N" << endl
                 << "4. D" << endl
                 << "5. POWER OFF" << endl;
            cin >> x.menu_choice;
        }
    }
    // in case car in Drive mode and user want to change to Reverse mode
    if (x.memory == "4")
    {
        while (x.menu_choice == "2" && x.speed > 0)
        {
            printf("\033c");
            cout << "VAN TOC DANG CON, KHONG THE CHUYEN CHE DO!!!" << endl
                 //  << "VUI LONG CHUYEN VE 'P' HOAC 'N' HOAC GIAM VAN TOC" << endl
                 << "XIN MOI LUA CHON" << endl
                 << "1. P" << endl
                 << "2. R" << endl
                 << "3. N" << endl
                 << "4. D" << endl
                 << "5. POWER OFF" << endl;
            cin >> x.menu_choice;
        }
    }

    // if (x.memory == "1")
    // {
    //     while (x.menu_choice == "4" && x.speed > 0)
    //     {
    //         printf("\033c");
    //         cout << "VAN TOC DANG CON, KHONG THE CHUYEN CHE DO!!!" << endl
    //              << "VUI LONG CHUYEN VE 'P' HOAC 'N' HOAC GIAM VAN TOC" << endl
    //              << "XIN MOI LUA CHON" << endl
    //              << "1. P" << endl
    //              << "2. R" << endl
    //              << "3. N" << endl
    //              << "4. D" << endl
    //              << "5. POWER OFF" << endl;
    //         cin >> x.menu_choice;
    //     }
    // }

    // clear terminal
    printf("\033c");
    // Parking mode
    if (x.menu_choice == "1")
    {
        x.menu_choice = "1";

        // change to P mode
        P_mode();
    }
    // Reversing mode
    else if (x.menu_choice == "2")
    {
        x.menu_choice = "2";

        x.count++;
        // x.speed = x.count;
        x.memory = "2";

        if (x.count == 1)
        {
            // default speed is 7km/h
            x.speed = 7;
            x.memory = "2";
        }
        else if (x.menu_choice == "2" && x.count == 1)
        {
            x.speed = 7;
            x.memory = "2";
        }else if (x.menu_choice == "2" && x.count == 1 || x.sub_menu_choice == "4"){
            x.speed = 7;
            x.memory = "2";
        }

        // else{
        //     x.speed = 7 * x.count;
        //     x.memory = "2";

        // }
        proccessMenu2();
    }
    // 0 gear
    else if (x.menu_choice == "3")
    {
        x.menu_choice = "3";

        // start reverse gear to N
        N_mode();
    }
    // Driving mode
    else if (x.menu_choice == "4")
    {
        x.menu_choice = "4";

        x.count++;
        // x.speed = x.count;
        x.memory = "4";
        if (x.count == 1)
        {
            // default speed is 7km/h
            x.speed = 7;
            x.memory = "4";
        }
        else if (x.count == 2)
        {
            x.speed = 7;
            x.memory = "4";
        }
        // else{
        //     x.speed = 7 * x.count;
        //     x.memory = "4";

        // }
        proccessMenu2();
    }
    // turn off engine
    else if (x.menu_choice == "5")
    {
        cout << "DA TAT HE THONG" << endl;
        cout << "CAM ON BAN DA SU DUNG" << endl;
        exit(0);
    }
}

/**
 * Processing option 2 - Reverse
 * @return None
 * 
 */
void proccessMenu2()
{
    // show sub menu after user choose
    menu2();
    while (!checksub_menu_choice(x.sub_menu_choice))
    {
        printf("\033c");
        cout << "VUI LONG LUA CHON TU 1 DEN 4 THEO MENU" << endl;
        menu2();
        cin >> x.sub_menu_choice;
    }
    printf("\033c");
    // driving mode
    if (x.sub_menu_choice == "1")
    {
        x.speed += 5;
    }
    // reverse mode
    else if (x.sub_menu_choice == "2")
    {
        if (x.speed >= 5)
        {
            x.speed -= 5;
        }
        else if (x.sub_menu_choice != "4")
        {
            x.speed = 0;
        }
        else if (x.sub_menu_choice == "4" && x.count == 1)
        {
            x.speed = 7;
        }
    }
    // reverse gear to 0
    else if (x.sub_menu_choice == "3")
    {
        // reset count = 0 - sync with number of accele or decele
        x.count = 0;
        x.speed = 0;
    }
    // change to primary menu
    else if (x.sub_menu_choice == "4")
    {
        proccessMenu1();
    }
    // validate input
    while (x.sub_menu_choice != "4")
    {
        // clear terminal
        printf("\033c");
        // show wrning for user
        warning();
        proccessMenu2();
    }
}

/**
 * Parking mode
 * @return None
 * 
 ***/

/**
 * chay -> tang toc -> P -> not 
 * ==> ko thuc hien dc thi ko luu lai memory
 * 
 * 
 * 
 * 
 */
void P_mode()
{

    while (x.speed > 0)
    {
        cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0 KM/H\n"
             << endl;
        proccessMenu1();
    }
    cout << "DA VE SO P" << endl;
    cout << "CHU Y SU DUNG PHANH DE DAM BAO AN TOAN" << endl;
    x.memory = "1";
    proccessMenu1();
}

/**
 * Gear 0 mode
 * Car's speed must be 0 if user want to reverse gear to 0
 * @return None
 * 
 */
void N_mode()
{
    // Varify speed of car is 0
    while (x.speed > 0)
    {
        cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0 KM/H" << endl;
        proccessMenu1();
    }

    cout << "DA VE SO N" << endl;
    cout << "CHU Y SU DUNG PHANH DE DAM BAO AN TOAN" << endl;
    x.memory = "3";
    x.speed = 0;
    proccessMenu1();
}

/**
 *Show warning notification for user
 @return None 
 */
void warning()
{
    char b(52);
    if (x.menu_choice == "2" && x.speed >= 20)
    {
        cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
    }
    else if (x.menu_choice == "4" && x.speed >= 60)
    {
        cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
    }
}

/**
 * Main function
 * @return 0
 */
int main()
{
    // access to car
    login();
    // clear terminal
    printf("\033c");
    // hello user
    cout << "XIN CHAO " << x.password << endl;
    // process user
    proccessMenu1();
    return 0;
}