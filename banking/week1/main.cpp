#include <iostream>

using namespace std;

typedef struct
{
    int id;
    int balance;
    char name[10];
} Account;

void core(void);
void showMenus(void);
void openAccount(void);
void deposit(void);
void withdraw(void);
void showAccounts(void);

Account accounts[100];
int num = 0;

int main()
{
    core();
    return 0;
}

void core(void)
{
    int menu = 0;

    while (true)
    {
        showMenus();
        cin >> menu;
        switch (menu)
        {
        case 1:
            openAccount();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            showAccounts();
            break;
        case 5:
            return;
            break;
        default:
            cout << "올바른 메뉴를 선택하여 주십시오." << endl;
            break;
        }
    }
}

void showMenus(void)
{
    cout << endl
         << "[ 메뉴 ]" << endl;
    cout << "1. 신규 계좌 개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌 전체 확인" << endl;
    cout << "5. 종료" << endl;
    cout << "선택 >> ";
}

void openAccount(void)
{
    int id;
    char name[10];

    cout << endl;
    cout << "[ 신규 계좌 개설 ]" << endl;
    cout << "- 계좌번호 : ";
    cin >> id;
    cout << "- 고객성명 : ";
    cin >> name;
    cout << endl;

    accounts[num].id = id;
    accounts[num].balance = 0;
    strcpy(accounts[num].name, name);

    cout << endl
         << "알림) 계좌계설이 완료되었습니다." << endl;

    num++;
}

void deposit(void)
{
    int id;
    int balance;

    cout << endl;
    cout << "[ 입금 ]" << endl
         << endl;

    cout << "- 계좌번호 : ";
    cin >> id;
    cout << "- 입금금액 : ";
    cin >> balance;

    for (int i = 0; i < num; i++)
    {
        if (accounts[i].id == id)
        {
            accounts[i].balance += balance;
            cout << endl
                 << "알림) 입금이 완료되었습니다." << endl;
            return;
        }
    }
    cout << endl
         << "에러) 올바른 계좌 정보를 찾지 못하였습니다." << endl;
}

void withdraw(void)
{
    int id;
    int balance;

    cout << endl;
    cout << "[ 출금 ]" << endl
         << endl;

    cout << "- 계좌번호 : ";
    cin >> id;
    cout << "- 출금금액 : ";
    cin >> balance;

    for (int i = 0; i < num; i++)
    {
        if (accounts[i].id == id)
        {
            if (accounts[i].balance >= balance)
            {
                accounts[i].balance -= balance;
                cout << endl
                     << "알림) 출금이 완료되었습니다." << endl;
            }
            else
            {
                cout << endl
                     << "에러) 잔액이 부족합니다." << endl;
            }
            return;
        }
    }
    cout << endl
         << "에러) 올바른 계좌 정보를 찾지 못하였습니다." << endl;
}

void showAccounts(void)
{
    cout << endl;
    cout << "[ 계좌 리스트 ]" << endl
         << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "- 계좌번호 : " << accounts[i].id << endl;
        cout << "- 고객성명 : " << accounts[i].name << endl;
        cout << "- 잔액 : " << accounts[i].balance << endl;
        cout << endl;
    }
}