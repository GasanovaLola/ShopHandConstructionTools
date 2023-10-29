#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

typedef struct Product
{
	string NameOfProduckt;
	string Manufacturer;
	int VendorCode;
	int Price;
	struct Product* sled;
} Prod;

static int Size = NULL;

struct Product* create_add_Prod(void);
void add(Prod** first_add);
void update(Prod** first_cr);
void del(Prod** first_cr);
void prosm_Prod(Prod* first_pr);
void all_Prod_infa(Prod* first_infa);
void zvit(Prod* first_infa);
void to_file_Prod(Prod* first_tf);
bool from_file_Prod(Prod** first);

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Prod* first = NULL;

	from_file_Prod(&first);

	int temp;

	const string admin_login = "admin", admin_password = "admin";
	string login, password;

	cout << " Увійти до системи як:\n";
	cout << "  - 1. адміністратор\n";
	cout << "--------------------------------------";
	cout << "  - 2. звичайний користувач\n";

	cin >> temp;

	if (temp == 1)
	{
		cout << "Введіть логін: ";
		cin >> login;

		cout << "Введіть логінроль: ";
		cin >> password;

		if (login == admin_login && password == admin_password)
		{
			cout << "Ви увійшли до системи як адміністратор.\n";
			system("pause");

			while (true)
			{
				system("cls");
				int num = 0;
				cout << " МАГАЗИН РУЧНИХ БУДІВЕЛЬНИХ ІНСТРУМЕНТІВ:";
				cout << "	1) Додати товар до бази";
				cout << "	2) Від редагувати конкретний товар";
				cout << "	3) Видалити конкретний товар із бази";
				cout << "	4) Отримати список всіх товарів";
				cout << "	5) Отримати всю інформацію про товари";
				cout << "	6) Вивести звіт за заданими критеріями";
				cout << "	7) Записати дані у файл";
				cout << "	0) Вихід\n";

				cout << endl << "Ваш вибір: ";
				cin >> num;

				if (num == 1)
				{
					add(&first);
				}
				else if (num == 2)
				{
					update(&first);
				}
				else if (num == 3)
				{
					del(&first);
				}
				else if (num == 4)
				{
					prosm_Prod(first);
				}
				else if (num == 5)
				{
					all_Prod_infa(first);
				}
				else if (num == 6)
				{
					zvit(first);
				}
				else if (num == 7)
				{
					to_file_Prod(first);
				}
				else if (num == 0)
				{
					break;
				}
				else
				{
					cout << "Програма приймає лише конкретний номер пункту меню від 1 до 6. Щоб вийти з програми, натисніть 0." << endl;
				}
			}
		}
		else
		{
			cout << "Пароль чи логін не правильні." << endl;
		}
	}
	else if (temp == 2)
	{
		while (true)
		{
			system("cls");
			int num = 0;
			cout << " МАГАЗИН РУЧНИХ БУДІВЕЛЬНИХ ІНСТРУМЕНТІВ:";
			cout << "	1) Отримати список всіх товарів";
			cout << "	2) Отримати всю інформацію про товари";
			cout << "	3) Вивести звіт за заданими критеріями";
			cout << "	4) Записати дані у файл";
			cout << "	0) Вихід\n";

			cout << endl << "Ваш вибір: ";

			cin >> num;

			if (num == 1)
			{
				prosm_Prod(first);
			}
			else if (num == 2)
			{
				all_Prod_infa(first);
			}
			else if (num == 3)
			{
				zvit(first);
			}
			else if (num == 4)
			{
				to_file_Prod(first);
			}
			else if (num == 0)
			{
				break;
			}
			else
			{
				cout << "Програма приймає лише конкретний номер пункту меню від 1 до 6. Щоб вийти з програми, натисніть 0." << endl;
			}
		}
	}

	return(0);
}

void zvit(Prod* first_infa)
{
	if (first_infa == NULL)
	{
		system("cls");
		cout << "Список порожній!" << endl;
		system("pause");
	}
	else
	{
		int num, count = 0, price_check1, price_check2;
		string manufacturer_check;

		cout << " Введіть номери пунктів, за якими хочете поставити умову виведення звіту"; 
		cout << "	1. За виробником товару";      
		cout << "	2.За ціною товару";      
		cout << "	3.За виробником і ціною товару \n";
		
		
		cout << "Ваш вибір : "; 
		cin >> num;

		if (num == 1)
		{
			cout << "Введіть найменування виробника товару за яким хочете отримати звіт : ";
			cin >> manufacturer_check;


			while (first_infa != NULL)
			{
				if (first_infa->Manufacturer == manufacturer_check)
				{
					cout << "Найменування товару : " << first_infa->NameOfProduckt << endl;
					cout << "Виробник товару : " << first_infa->Manufacturer << endl;
					cout << "Артикул товару : " << first_infa->VendorCode << endl;
					cout << "Ціна товару : " << first_infa->Price << endl;

					cout << endl;

					count++;
				}
				first_infa = first_infa->sled;
			}
			system("pause");


			if (count == 0)
			{
				cout << "У списку немає жодного товару цього виробника.\n";

				system("pause");
			}
		}
		else if (num == 2)
		{
			num = 0;

			cout << "Оберіть варіант виведення звіту за фіксованою ціною :";
			cout << "	1. від ... до ...";
			cout << "	2. конкретна ціна\n";
			
			cout << "Ваш вибір : "; 
			cin >> num;

			if (num == 1)
			{
				cout << "Від : ";
				cin >> price_check1;
				cout << "До : ";
				cin >> price_check2;


				while (first_infa != NULL)
				{
					if (first_infa->Price >= price_check1 && first_infa->Price <= price_check2)
					{
						cout << "Найменування товару : " << first_infa->NameOfProduckt << endl;
						cout << "Виробник товару : " << first_infa->Manufacturer << endl;
						cout << "Артикул товару : " << first_infa->VendorCode << endl;
						cout << "Ціна товару : " << first_infa->Price << endl;

						cout << endl;

						count++;
					}
					first_infa = first_infa->sled;
				}
				system("pause");

				if (count == 0)
				{
					cout << "Жодний товар не потрапив під вашу умову.";

					system("pause");
				}
			}
			else if (num == 2)
			{
				cout << "Введіть вартість виробника товару за якою хочете отримати звіт : ";
				cin >> price_check1;


				while (first_infa != NULL)
				{
					if (first_infa->Price == price_check1)
					{
						cout << "Найменування товару : " << first_infa->NameOfProduckt << endl;
						cout << "Виробник товару : " << first_infa->Manufacturer << endl;
						cout << "Артикул товару : " << first_infa->VendorCode << endl;
						cout << "Ціна товару : " << first_infa->Price << endl;

						cout << endl;

						count++;
					}
					first_infa = first_infa->sled;
				}
				system("pause");


				if (count == 0)
				{
					cout << "Жодний товар не потрапив під вашу умову.";

					system("pause");
				}
			}
		}
		else if (num == 3)
		{
			cout << "Введіть найменування виробника товару за яким хочете отримати звіт: ";
			cin >> manufacturer_check;

			num = 0;

			cout << " Оберіть варіант виведення звіту за фіксованою ціною :";
			cout << "	1. від ... до ..."; 
			cout << "	2.конкретна ціна\n";
			
			
			cout << "Ваш вибір : "; 
			cin >> num;

			if (num == 1)
			{
				cout << "Від : ";
				cin >> price_check1;
				cout << "До : ";
				cin >> price_check2;

				
				while (first_infa != NULL)
				{
					if (first_infa->Price >= price_check1 && first_infa->Price <= price_check2 && first_infa->Manufacturer == manufacturer_check)
					{
						cout << "Найменування товару : " << first_infa->NameOfProduckt << endl;
						cout << "Виробник товару : " << first_infa->Manufacturer << endl;
						cout << "Артикул товару : " << first_infa->VendorCode << endl;
						cout << "Ціна товару : " << first_infa->Price << endl;

						cout << endl;

						count++;
					}
					first_infa = first_infa->sled;
				}
				system("pause");
				

				if (count == 0)
				{
					cout << "Жодний товар не потрапив під вашу умову.";

					system("pause");
				}
			}
			else if (num == 2)
			{
				cout << "Введіть вартість виробника товару за якою хочете отримати звіт : ";
				cout << "Ваш вибір : ";
				cin >> price_check1;

				
				while (first_infa != NULL)
				{
					if (first_infa->Price == price_check1 && first_infa->Manufacturer == manufacturer_check)
					{
						cout << "Найменування товару : " << first_infa->NameOfProduckt << endl;
						cout << "Виробник товару : " << first_infa->Manufacturer << endl;
						cout << "Артикул товару : " << first_infa->VendorCode << endl;
						cout << "Ціна товару : " << first_infa->Price << endl;

						cout << endl;

						count++;
					}
					first_infa = first_infa->sled;
				}
				system("pause");
				

				if (count == 0)
				{
					cout << "Жодний товар не потрапив під вашу умову.";

					system("pause");
				}
			}
		}
		else
		{
			cout << "Функція приймає лише конкретний номер пункту меню від 1 до 3.";
			system("pause");
		}
	}
}

bool from_file_Prod(Prod** first)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream fileObj;
	fileObj.open("List.txt");

	if (!fileObj)
	{
		cout << "Файл не відкривався. Виникла помилка.";
		return false;
	}

	string temp;

	while (getline(fileObj, temp))
	{
		if (*first == NULL)
		{
			*first = new Prod;

			getline(fileObj, (*first)->NameOfProduckt);
			getline(fileObj, (*first)->Manufacturer);
			fileObj >> (*first)->VendorCode;
			fileObj >> (*first)->Price;
			fileObj.get();

			(*first)->sled = NULL;
		}
		else
		{
			while ((*first)->sled != NULL)
			{
				first = &((*first)->sled);
			}

			(*first)->sled = new Prod;

			getline(fileObj, (*first)->sled->NameOfProduckt);
			getline(fileObj, (*first)->sled->Manufacturer);
			fileObj >> (*first)->sled->VendorCode;
			fileObj >> (*first)->sled->Price;
			fileObj.get();

			(*first)->sled->sled = NULL;
		}
	}

	fileObj.close();
	return true;
}

struct Product* create_add_Prod(void) 
{
	struct Product* temp_str = new struct Product;

	cout << "Введіть найменування товару : ";
	(cin >> temp_str->NameOfProduckt).get();
	cout << "Введіть виробника товару : ";
	getline(cin, temp_str->Manufacturer);
	cout << "Введіть артикул товару : ";
	cin >> temp_str->VendorCode;
	cout << "Введіть ціну товару : ";
	cin >> temp_str->Price;
	temp_str->sled = NULL;
	fflush(stdin);
	return (temp_str);
}

void del(Prod** first_cr)
{
	if (first_cr == NULL)
	{
		system("cls");
		cout << "Списка немає!!!";
		system("pause");
	}
	else
	{
		struct Product temp_del = *(create_add_Prod());
		struct Product* kop_first = *first_cr;
		bool sw = true;
		struct Product** prev = first_cr;
		while (kop_first != NULL)
		{
			if (kop_first->NameOfProduckt == temp_del.NameOfProduckt && kop_first->Manufacturer == temp_del.Manufacturer && kop_first->VendorCode == temp_del.VendorCode && kop_first->Price == temp_del.Price)
			{
				system("cls");
				cout << "Елемент знайден!!";
				system("pause");
				if (sw == true)
				{
					kop_first = (*first_cr)->sled;
					delete* first_cr;
					*first_cr = kop_first;
					Size--;
				}
				else
				{
					system("cls");
					cout << "Знайдено елемент який не є першим!!";
					system("pause");
					*prev = kop_first->sled;
					delete kop_first;
					Size--;
				}
				sw = false;
				system("cls");
				cout << "Елемент успішно видален!!!";
				system("pause");
				return;
			}
			else
			{
				prev = &(kop_first->sled);
				kop_first = kop_first->sled;
				sw = false;
			}
		}
		system("cls");
		cout << "У списку елемент не знайдено!!";
		system("pause");
	}
}

void update(Prod** first_cr)
{
	if (first_cr == NULL)
	{
		system("cls");
		cout << "Списка немає!!!";
		system("pause");
	}
	else
	{
		cout << "Введіть дані товару, який хочете змінити" << endl;

		struct Product temp_up = *(create_add_Prod());
		struct Product* kop_first = *first_cr;
		bool sw = true;
		struct Product** prev = first_cr;
		while (kop_first != NULL)
		{
			if (kop_first->NameOfProduckt == temp_up.NameOfProduckt && kop_first->Manufacturer == temp_up.Manufacturer && kop_first->VendorCode == temp_up.VendorCode && kop_first->Price == temp_up.Price)
			{
				system("cls");

				cout << "Введіть дані для редагування" << endl;

				cout << "Введіть найменування товару : ";
				(cin >> temp_up.NameOfProduckt).get();
				cout << "Введіть виробника товару : ";
				getline(cin, temp_up.Manufacturer);
				cout << "Введіть артикул товару : ";
				cin >> temp_up.VendorCode;
				cout << "Введіть ціну товару : ";
				cin >> temp_up.Price;

				if (kop_first->NameOfProduckt == temp_up.NameOfProduckt && kop_first->Manufacturer == temp_up.Manufacturer && kop_first->VendorCode == temp_up.VendorCode && kop_first->Price == temp_up.Price)
				{
					cout << "Ви не змінили жодного параметра продукту!" << endl;
				}
				else {
					kop_first->NameOfProduckt = temp_up.NameOfProduckt;
					kop_first->Manufacturer = temp_up.Manufacturer;
					kop_first->VendorCode = temp_up.VendorCode;
					kop_first->Price = temp_up.Price;
				}
				system("pause");
				return;
			}
		}
		system("cls");
		cout << "У списку елемент не знайдено!!";
		system("pause");
	}
}

void add(Prod** first_add)
{
	if (*first_add == NULL)
	{
		*first_add = new Prod;

		cout << "Введіть найменування товару : ";
		(cin >> (*first_add)->NameOfProduckt).get();
		cout << "Введіть виробника товару : ";
		getline(cin, (*first_add)->Manufacturer);
		cout << "Введіть артикул товару : ";
		cin >> (*first_add)->VendorCode;
		cout << "Введіть ціну товару : ";
		cin >> (*first_add)->Price;

		(*first_add)->sled = NULL;
	}

	else
	{
		while ((*first_add)->sled != NULL)
		{
			first_add = &((*first_add)->sled);
		}

		(*first_add)->sled = new Prod;

		cout << "Введіть найменування товару : ";
		(cin >> (*first_add)->sled->NameOfProduckt).get();
		cout << "Введіть виробника товару : ";
		getline(cin, (*first_add)->sled->Manufacturer);
		cout << "Введіть артикул товару : ";
		cin >> (*first_add)->sled->VendorCode;
		cout << "Введіть ціну товару : ";
		cin >> (*first_add)->sled->Price;
		(*first_add)->sled->sled = NULL;
	}
	system("pause");
}

void prosm_Prod(Prod* first_pr)
{
	if (first_pr == NULL)
	{
		system("cls");
		cout << "Список порожній!" << endl;
		system("pause");
	}
	else
	{
		cout << "\nСПИСОК ТОВАРІВ: " << endl;
		while (first_pr != NULL)
		{
			cout << "	-" << first_pr->NameOfProduckt << " ";
			cout << first_pr->Manufacturer << endl;
			first_pr = first_pr->sled;
		}
		system("pause");
	}
}

void to_file_Prod(Prod* first_tf)
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (first_tf == NULL)
	{
		system("cls");
		cout << "Список порожній!" << endl;
		system("pause");
	}
	else
	{
		ofstream out;

		out.open("List.txt");

		if (!out.is_open())
		{
			system("cls");
			cout << "Файл не відкрився!" << endl;
			system("pause");
		}
		else
		{
			while (first_tf != NULL)
			{
				out << "- Товар:\n";
				out << first_tf->NameOfProduckt << endl;
				out << first_tf->Manufacturer << endl;
				out << first_tf->VendorCode << endl;
				out << first_tf->Price << endl;
				first_tf = first_tf->sled;
			}
			system("cls");
			cout << "Список у файлі!" << endl;
			system("pause");
			out.close();
		}
	}
}

void all_Prod_infa(Prod* first_infa)
{
	if (first_infa == NULL)
	{
		system("cls");
		cout << "Список порожній!" << endl;
		system("pause");
	}
	else
	{
		while (first_infa != NULL)
		{
			cout << "Найменування товару : " << first_infa->NameOfProduckt << endl;
			cout << "Виробник товару : " << first_infa->Manufacturer << endl;
			cout << "Артикул товару : " << first_infa->VendorCode << endl;
			cout << "Ціна товару : " << first_infa->Price << endl;
			first_infa = first_infa->sled;

			cout << endl;
		}

		system("pause");
	}
}
