#include <iostream>
#include <time.h>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
#include <locale>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
	void Print()
	{
		cout << " day  " << day << endl;
		cout << " month  " << month << endl;
		cout << " year  " << year << endl;

	}

	void FillRandom(int max = 2004, int min = 1960)
	{
		day = rand() % 31;
		month = rand() % 12 + 1;
		year = min + (rand() % (max - min));
	}

};

struct Student
{
	string FirstName;
	string LastName;

	Date data;

	int marks[10];
	bool vidminuk;
	bool privelegia;

	void RandomMarks()
	{
		for (int i = 0; i < 10; i++)
		{
			marks[i] = 1 + rand() % 12;
		}
	}

	void RandomVidminnuk()
	{
		for (int i = 0; i < 10; i++)
		{
			marks[i] = 10 + rand() % (12 - 10);
		}
	}

	void RandomPrivelegia()
	{
		privelegia = rand() % 2;

	}
	void Fill()
	{
		string sn[15] = { "Bondarenko", "Melnik", "Shevchenko", "Tkachenko", "Kovalenko", "Bojko", "Kucher", "Savchuk", "Robota", "Gamera", "Krektun", "Kovalenko", "Karaush", "Ostapchuk", "Medun"  };
		string n[15] = { "Oleksij", "Oleksandr", "Maksim", "Boris", "Yurij", "Vladislav", "Ostap", "Anton", "Taras", "Yana", "Oksana", "Natasha", "Alisa", "Katya", "Nazar" };
		int c, b;
		int vidm = 0;
		vidm = rand() % 10;
		c = rand() % 5;
		b = rand() % 5;
		FirstName = n[b];
		LastName = sn[c];

		data.FillRandom();
		if (vidm == 0)
		{
			RandomVidminnuk();
			vidminuk = true;
		}
		else
		{
			RandomMarks();
			vidminuk = false;

		}
		RandomPrivelegia();
	}
	void PrintStudent()
	{

		cout << " FirstName : " << FirstName << endl;
		cout << " LastName : " << LastName << endl;
		cout << " Marks : ";
		for (int i = 0; i < 10; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;

		if (privelegia)
		{

			cout << " Privelegia : +";
		}
		else
		{
			cout << " Privelegia : -";
		}
		cout << endl;

		if (vidminuk)
		{
			cout << " Excellent : +";
		}
		else
		{
			cout << " Excellent : -";
		}
		cout << endl;
		data.Print();
	}
};

struct Teacher
{
	string FirstName;
	string LastName;

	Date data;

	void Fill()
	{
		string sn[6] = { "Nechiporchuk", "Melnik", "Shevchenko", "Tkachenko", "Kovalenko", "Bojko" };
		string n[6] = { "Maksim", "Anton", "Maksim", "Boris", "Taras", "Vladislav" };
		int c, b;
		c = rand() % 6;
		b = rand() % 6;
		FirstName = n[b];
		LastName = sn[c];

		data.FillRandom();
	}

	void PrintTeacher()
	{
		cout << " Teacher FirstName : " << FirstName << endl;
		cout << " Teacher LastName : " << LastName << endl;

		data.Print();
	}


};

struct Group
{
	Teacher teacher;

	Student* students = new Student[5];

	string Name;

	void Fill(string name)

	{
		Name = name;
		teacher.Fill();

		for (int i = 0; i < 5; i++)
		{
			students[i].Fill();
		}
	}
	void PrintGroup()
	{
		cout << "\t\t\t ***Group Name***  " << endl;
		cout << " \t\t\t     " << Name << endl;
		cout << "\t\t\t ***Teacher***  " << endl;
		teacher.PrintTeacher();
		cout << "\t\t\t ***Students***  " << endl;
		for (int i = 0; i < 5; i++)
		{
			students[i].PrintStudent();
			cout << "--------------------------------------------------\n";
		}

	}
};

void Excellent(Group* groups)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (groups[i].students[j].vidminuk)
			{
				cout << "\t\t\t***Excellent***" << endl;
				cout << "\t\t\t ***Group Name***  " << endl;
				cout << " \t\t\t     " << groups[i].Name << endl;
				groups[i].students[j].PrintStudent();
				cout << "--------------------------------------------------\n";
			}
		}

	}
}

void Print_Best_Teacher(Group* groups)
{
	float avg1 = 0;
	float avg2 = 0;
	float avg3 = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for ( int k = 0; k < 10; k++)
			{
				if (i == 0)
				{
					avg1 += groups[i].students[j].marks[k];
				}
				if (i == 1)
				{
					avg2 += groups[i].students[j].marks[k];
				}
				if (i == 2)
				{
					avg3 += groups[i].students[j].marks[k];
				}
			}
		}
	}

	if (avg1 > avg2 && avg1 > avg3)
	{
		groups[0].teacher.PrintTeacher();
	}
	if (avg2 > avg1 && avg2 > avg3)
	{
		groups[1].teacher.PrintTeacher();
	}
	if (avg3 > avg1 && avg3 > avg2)
	{
		groups[2].teacher.PrintTeacher();
	}
}

void Class_Worst_Perf(Group* groups)
{
	float sum = 0;
	float rating[3];

	for (int i = 0; i < 3; i++)
	{
		sum = 0;

		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				sum += groups[i].students[j].marks[k];
			}
		}
		rating[i] = sum / 50;
	}
	float min = rating[0];
	for (int i = 0; i < 3; i++)
	{
		if (rating[i] < min)
		{
			min = rating[i];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (rating[i] == min)
		{
			cout << "The Lowest Academic Perfomance\t" << min << endl;
			cout << "Group name \n";
			cout << groups[i].Name << endl;

		}
	}


}

void Birthday(Group* groups)
{
	Student* arr1 = new Student[15];
	for (int i = 0, s=0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++, s++)
		{
			arr1[s] = groups[i].students[j];
			groups[i].students[j].PrintStudent();
			cout << "--------------------------------------------------\n";
		}
	}
	cout << endl;

	cout << "***Who born in one day:***" << endl;

	int x = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = i + 1; j < 15; j++)
		{
			if (arr1[i].data.day == arr1[j].data.day && arr1[i].data.month == arr1[j].data.month && arr1[i].data.year == arr1[j].data.year)
			{
				arr1[i].PrintStudent();
				cout << "--------------------------------------------------\n";
				arr1[i].PrintStudent();
				cout << "--------------------------------------------------\n";

				x++;
			}
		}
	}
	if (x == 0)
	{
		cout << "No one bird in one day" << endl;
	}

}

void OldestStudent(Group* groups)
{
	int indexI = 0;
    int	indexJ = 0;
	int day = groups[0].students[0].data.day;
	int month = groups[0].students[0].data.month;
	int year = groups[0].students[0].data.year;
	int res = 0; int res2 = 0;
	res = (30 - day) + ((12 - month) * 30) + (2020 - year) * 365;
	cout << "\t\t\t****OldestStudent****" << endl;
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			day = groups[i].students[j].data.day;
			month = groups[i].students[j].data.month;
			year = groups[i].students[j].data.year;
			res2 = (30 - day) + ((12 - month) * 30) + (2020 - year) * 365;

			if (res < res2)
			{
				res = res2;
				indexI = i;
				indexJ = j;
			}
		}
	}
	cout << "The oldest student is: " << endl;
	cout << endl;
	groups[indexI].students[indexJ].PrintStudent();
}

void Hig_Academ_Perf_Student(Group* groups)
{
	float sum = 0;
	float rating_student[3][5];

	cout << "\t\t\t***Students who haveaverage rating abov 8.5:***" << endl;
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum = 0;
			for (int k = 0; k < 10; k++)
			{
				sum += groups[i].students[j].marks[k];
			}
			rating_student[i][j] = sum / 10;
		}

	}
	short bal = 8.5;
	int count = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (rating_student[i][j] >= bal)
			{
				count++;
			}
		}
	}
	cout << "Number of students with an average rating abov 8.5:  " << count << endl;
}

void Hig_Privilege(Group* groups)
{
	int count[3]{ 0,0,0 };
	int max = 0;

	cout << "\t\t\t***Group with highest privilege:***" << endl;
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (groups[i].students[j].privelegia == 1)
			{
				count[i]++;
			}
		}				
	}
	for (int i = 0; i < 3; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
		}
	}
	cout << "Group with the most privileged students: " << endl;
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		if (count[i] == max)
		{
			cout << groups[i].Name << endl;
		}
	}
}



void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Size_Console(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { 0, 0, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}

int Menu(string menu_items[], int SIZE) {
	int key = 0;
	int code;
	do {
		//system("cls");
		key = (key + SIZE) % SIZE;
		for (int i = 0; i < SIZE; i++)
		{
			SetPos(20, 10 + i);
			if (key == i)
			{

				cout << " "; SetColor(6); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
			}
			else
			{
				cout << " "; cout << menu_items[i]; cout << " " << endl;
			}

		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int Menu2(Group* groups)
{
	Size_Console(65, 45);

	string menu[] = { "1.Ecxelents student","2.Teacher of Highest academic perfomance group",
		"3.Group with lowest academic perfomance","4.Find students who were born on the same day",
		"5.Find the oldest student", "6.The number of students who have an average score above 8.5",
		"7.Groups with the most privileges", "8.Exit" };

	int m = Menu(menu, size(menu));

	if (m == 0)
	{
		Excellent(groups);
	}
	if (m == 1)
	{
		Print_Best_Teacher(groups);
	}
	if (m == 2)
	{
		Class_Worst_Perf(groups);

	}
	if (m == 3)
	{
		Birthday(groups);

	}
	if (m == 4)
	{
		OldestStudent(groups);

	}
	if (m == 5)
	{
		Hig_Academ_Perf_Student(groups);
	}
	if (m == 6)
	{
		Hig_Privilege(groups);

	}
	system("pause");
	system("CLS");
	return m;






}


void main()
{

	srand(time(0));
	Group groups[3];
	string names[3] = { "BV021","BV022","1711" };
	for (int i = 0; i < 3; i++)
	{

		groups[i].Fill(names[i]);
		//groups[i].PrintGroup();

	}		

	while (Menu2(groups) != 7)
	{

	}






	/*Excellent(groups);*/
	/*Print_Best_Teacher(groups);*/
	/*Class_Worst_Perf(groups);*/
	/*Birthday(groups);*/
	/*OldestStudent(groups);*/
	/*Hig_Academ_Perf_Student(groups);*/
	/*Hig_Privilege(groups);*/


	//Student student[15];
	//for (int i = 0; i < 6; i++)
	//{
	//	student[i].Fill(); student[i].Print();
	//}

	//Teacher teacher[6];
	//for (int i = 0; i < 6; i++)
	//{
	//	teacher[i].Fill(); teacher[i].Print();
	//}
	system("pause");
}