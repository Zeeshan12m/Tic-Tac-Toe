
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
char arr[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
string name1, name2;
string password1, password2;
int row, col;
char ch = 'X';
bool draw = false;
void registerplayer1();
void registerplayer2();
bool login1();
bool login2();
void display();
void ToCheck();
bool check_Who_wins();
bool is_draw();
void updateWinCount(const string& filename);
void displayWinCount(const string& filename, const string& playerName);

int main()
{
	int choice = 0;
	cout << "\t\t\tWelcome To Tic Tac Toe Game\n" << endl;
	cout << "Player1 :" << endl;
	cout << "1. To Register\n2. To Login" << endl;
	cin >> choice;
	if (choice == 1)
	{
		registerplayer1();
	}
	else if (choice == 2)
	{
		if (!login1())
		{
			cout << "Login failed for player1. Please try again.\n";
			return 1;
		}
		displayWinCount("userdata1.txt", name1);
	}
	else
	{
		cout << "Invalid Choice!!" << endl;
		return 1;
	}
	cout << "\nPlayer2 :" << endl;
	cout << "1. To Register\n2. To Login" << endl;
	cin >> choice;
	if (choice == 1)
	{
		registerplayer2();
	}
	else if (choice == 2)
	{
		if (!login2())
		{
			cout << "Login failed for player2. Please try again.\n";
			return 1;
		}
		displayWinCount("userdata2.txt", name2);
	}
	else
	{
		cout << "Invalid Choice!!" << endl;
		return 1;
	}
	cout << "\n\nNew Game Starts :" << endl;
	while (!check_Who_wins() && !is_draw())
	{
		display();
		ToCheck();
		system("cls");
	}
	if (!draw)
	{
		if (ch == 'O')
		{
			cout << name1 << " Wins" << endl;
			updateWinCount("userdata1.txt");
		}
		else if (ch == 'X')
		{
			cout << name2 << " Wins" << endl;
			updateWinCount("userdata2.txt");
		}
	}
	else
	{
		cout << "It's a Draw" << endl;
	}
}

void registerplayer1()
{
	bool isUsernameUnique = false;
	while (!isUsernameUnique) {
		ifstream fin("userdata1.txt");
		cout << "Enter The Name of Player 1 :";
		cin >> name1;
		string storedUsername, storedPassword;
		int winCount;
		isUsernameUnique = true;
		while (fin >> storedUsername >> storedPassword >> winCount)
		{
			if (storedUsername == name1) {
				cout << "Username already exists for " << name1 << ". Please try another one.\n";
				isUsernameUnique = false;
				break;
			}
		}
		fin.close();
	}
	cout << "Enter The Password of player 1 : ";
	cin >> password1;
	ofstream fout("userdata1.txt", ios::app);
	if (fout.is_open()) {
		fout << name1 << " " << password1 << " 0" << endl;
		fout.close();
		cout << "Registration successful!\n";
	}
	else {
		cout << "Unable to open file for writing.\n";
	}
}

void registerplayer2()
{
	bool isUsernameUnique = false;
	while (!isUsernameUnique) {
		ifstream fin("userdata2.txt");
		cout << "Enter The Name of Player 2 :";
		cin >> name2;
		string storedUsername, storedPassword;
		int winCount;
		isUsernameUnique = true;
		while (fin >> storedUsername >> storedPassword >> winCount)
		{
			if (storedUsername == name2) {
				cout << "Username already exists for " << name2 << ". Please try another one.\n";
				isUsernameUnique = false;
				break;
			}
		}
		fin.close();
	}
	cout << "Enter The Password of player 2 : ";
	cin >> password2;
	ofstream fout("userdata2.txt", ios::app);
	if (fout.is_open()) {
		fout << name2 << " " << password2 << " 0" << endl;
		fout.close();
		cout << "Registration successful!\n";
	}
	else {
		cout << "Unable to open file for writing.\n";
	}
}

bool login1()
{
		cout << "Login\n";
		cout << "Enter Name of player 1 : ";
		cin >> name1;
		cout << "Enter password of player 1 : ";
		cin >> password1;
		ifstream fin("userdata1.txt");
		if (fin.is_open())
		{
			string storedUsername, storedPassword;
			int winCount;
			while (fin >> storedUsername >> storedPassword >> winCount) {
				if (storedUsername == name1 && storedPassword == password1) {
					cout << "Login successful!\n";
					fin.close();
					return true;
				}
			}
			fin.close();
			cout << "Incorrect username or password for " << name1 << ".\n";
		}
		else {
			cout << "Unable to open file for reading.\n";
		}
	return false;
}

bool login2()
{
	cout << "Login\n";
	cout << "Enter Name of player 2 : ";
	cin >> name2;
	cout << "Enter password of player 2 : ";
	cin >> password2;
	ifstream fin("userdata2.txt");
	if (fin.is_open())
	{
		string storedUsername, storedPassword;
		int winCount;
		while (fin >> storedUsername >> storedPassword >> winCount) {
			if (storedUsername == name2 && storedPassword == password2) {
				cout << "Login successful!\n";
				fin.close();
				return true;
			}
		}
		fin.close();
		cout << "Incorrect username or password for " << name2 << ".\n";
	}
	else {
		cout << "Unable to open file for reading.\n";
	}
	return false;
}

void display()
{
	cout << "\t|\t|" << endl;
	cout << "   " << arr[0][0] << "    |   " << arr[0][1] << "   |   " << arr[0][2] << endl;
	cout << "\t|\t|" << endl;
	cout << "  ______|_______|______" << endl;
	cout << "\t|\t|" << endl;
	cout << "   " << arr[1][0] << "    |   " << arr[1][1] << "   |   " << arr[1][2] << endl;
	cout << "\t|\t|" << endl;
	cout << "  ______|_______|______" << endl;
	cout << "\t|\t|" << endl;
	cout << "   " << arr[2][0] << "    |   " << arr[2][1] << "   |   " << arr[2][2] << endl;
	cout << "\t|\t|" << endl;
	cout << "******************************" << endl;
}

void ToCheck()
{
	int digit;
	if (ch == 'X')
	{
		cout << name1 << " Please Enter The Number where you to place [X]: ";
		cin >> digit;
	}
	if (ch == 'O')
	{
		cout << name2 << " Please Enter The Number where you to place [O]: ";
		cin >> digit;
	}
	switch (digit) {
	case 1: row = 0, col = 0; break;
	case 2: row = 0, col = 1; break;
	case 3: row = 0, col = 2; break;
	case 4: row = 1, col = 0; break;
	case 5: row = 1, col = 1; break;
	case 6: row = 1, col = 2; break;
	case 7: row = 2, col = 0; break;
	case 8: row = 2, col = 1; break;
	case 9: row = 2, col = 2; break;
	}
	if (digit < 1 || digit > 9 )
	{
		cout << "Please Enter Number Between 1 To 9 !!!" << endl;
	}
	if (ch == 'X' && arr[row][col] != 'X' && arr[row][col] != 'O')
	{
		arr[row][col] = 'X';
		ch = 'O';
	}
	else if (ch == 'O' && arr[row][col] != 'X' && arr[row][col] != 'O')
	{
		arr[row][col] = 'O';
		ch = 'X';
	}
	else
	{
		cout << "There is no empty space !!" << endl;
		ToCheck();
	}
	display();
}

bool check_Who_wins()
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && (arr[i][0] == 'X' || arr[i][0] == 'O'))
		{
			return true;
		}
		if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && (arr[0][i] == 'X' || arr[0][i] == 'O'))
		{
			return true;
		}
	}
	if ((arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && (arr[0][0] == 'X' || arr[0][0] == 'O')) || (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && (arr[0][2] == 'X' || arr[0][2] == 'O')))
	{
		return true;
	}
	return false;
}

bool is_draw()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] != 'X' && arr[i][j] != 'O')
			{
				return false;
			}
		}
	}
	draw = true;
	return true;
}
void updateWinCount(const string& filename)
{
	ifstream fin(filename);
	ofstream temp("temp.txt");
	if (fin.is_open() && temp.is_open())
	{
		string storedUsername, storedPassword;
		int winCount;
		while (fin >> storedUsername >> storedPassword >> winCount)
		{
			if (storedUsername == name1 || storedUsername == name2)
			{
				winCount++;
			}
			temp << storedUsername << " " << storedPassword << " " << winCount << endl;
		}
		fin.close();
		temp.close();
		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
	}
	else
	{
		cout << "Unable to open file for updating win count.\n";
	}
}

void displayWinCount(const string& filename, const string& playerName)
{
	ifstream fin(filename);
	if (fin.is_open())
	{
		string storedUsername, storedPassword;
		int winCount;
		while (fin >> storedUsername >> storedPassword >> winCount)
		{
			if (storedUsername == playerName)
			{
				cout << playerName << " has won " << winCount << " times." << endl;
				break;
			}
		}
		fin.close();
	}
	else
	{
		cout << "Unable to open file for reading win count.\n";
	}
}
