#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

float us;//���� ������

struct article//��������� ������
{
	string describe;//����
	float price_ua;//���� � �������
	float price_us;//���� � �������
	int amount;//������� �� �����
	string type;//���
	string mark;//�����
};

void enter_data(article *arr,int size)//������� ��� �������� �����
{
	for (int i = 0; i < size; ++i)
	{
		cout << "\t\t����� �" << i + 1 << endl;
		cout << "��� ������:";
		cin >> arr[i].type;//������� ���� ��� ������ �������� � �����
		cout << "����� ������:";
		cin >> arr[i].mark;
		cout << "ʳ������ �� �����:";
		cin >> arr[i].amount;
		cout << "����(��������������):";
		cin >> arr[i].describe;
		cout << "ֳ�� � �.�.:";
		cin >> arr[i].price_us;
		arr[i].price_ua = arr[i].price_us * us;
	}
}

void show_info(article*arr, int size)//������� ��� ��������� ����������
{
	//�������� �����
	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t��� ������\t|\t����� ������\t|\tʳ������ �� �����\t|\tֳ�� � �.�.\t|\tֳ�� � �������\t|" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; ++i)//�� ����� ������� ���� �����
	{
		cout << "|\t" << arr[i].type << "\t\t";
		cout << "|\t" << arr[i].mark << "\t\t";
		cout << "|\t\t" << arr[i].amount << "\t\t";
		cout << "|\t" << arr[i].price_us << "\t\t";
		cout << "|\t\t" << arr[i].price_ua << "\t\t|" << endl;
		cout << "����:\n" << arr[i].describe;
		cout << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

article* del_note(article* arr, int &size)//��������� �������� � ������
{
	article a;//��������� ����� 
	cout << "������ ���� ��� �����, ���� ������� ��������:" << endl;
	cout << "��� ������:";
	cin >> a.type;//�������� ����������, ��� ����� ���� ��� �������� � ������
	cout << "����� ������:";
	cin >> a.mark;
	int n = 0;//������� ����� ������ � �����
	for (int i = 0; i < size; ++i)
		if (a.type == arr[i].type && a.mark == arr[i].mark)//��������� ������� ������, �� ��� ��������
			++n;
	if (n == 0)//���� ����� ������ �� ��������
	{
		cout << "����� �� ��������" << endl;//�������� �������� �����������
		return arr;//� ��������� ����� ��� ���
	}
	article* new_ = new article[size - n];//���� � � ��� ������, �� �������
	for (int i = 0,j=0; i < size; ++i)
		if (a.type != arr[i].type && a.mark != arr[i].mark)//���������� ����� ��� ���������� ����� ���� �� ������� ��������
		{
			new_[j] = arr[i];
			++j;
		}

	size -= n;
	arr = new article[size];//������� ����� ��������� ������
	for (int i = 0; i < size; ++i)
		arr[i] = new_[i];//�� ���������� ��� ����� ������, �� �� ������� ���� ��������
	delete[]new_;//��������� ���'�� �-�� ����������� ������
	cout << "����� ��������" << endl;
	return arr;//���������� ������������� ������
}

void sort_by_type(article* arr, int size)//���������� �� �����
{
	for (int i = 1; i < size; i++)//������� �� �������� �� � �� � ������� ���������
	{
		for (int j = 0; j < size - i; j++)
		{
			if (arr[j].type > arr[j + 1].type)
				swap(arr[j], arr[j + 1]);
		}
	}
}

void sort_by_price(article* arr, int size)//���������� �� �����
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)//������� � ������� �������� ������� ���������
		{
			if (arr[j].price_ua < arr[j+ 1].price_ua)
				swap(arr[j], arr[j + 1]);
		}
	}
}

void find_discribe(article* arr, int size, string mark)//����� ����� ����'����� �� ������� ������
{
	for (int i = 0; i < size; ++i)//����������� �� ��� �������
	{
		if (arr[i].mark == mark&& arr[i].type=="����'����")//���� ������� ����� ��� ����'���� � ���� ����� ������� �� �������
		{
			cout << "��������������:" << endl;
			cout << arr[i].describe << endl;//�� �������� ��������������
			return;//� �������� ������
		}
	}
	cout << "����� �� ��������" << endl;
}

void find_printers(article* arr, int size, int price)//����� ��������, ���� ���� �� �������� ������ ����
{
	//�������� ����� ��� �������
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t����� ������\t|\tʳ������ �� �����\t|\tֳ�� � �.�.\t|\tֳ�� � �������\t|" << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	int n = 0;//������� �������� ������
	for (int i = 0; i < size; ++i)//����������� �� ��� �������
	{
		if (arr[i].price_ua <= price && arr[i].type == "�������")//���� ��������� �� ������� � ���� ���� �� �������� ������
		{
			++n;
			cout << "|\t" << arr[i].mark << "\t\t";//�� �������� ���������� ��� �������
			cout << "|\t\t" << arr[i].amount << "\t\t";
			cout << "|\t" << arr[i].price_us << "\t\t";
			cout << "|\t\t" << arr[i].price_ua << "\t\t|" << endl;
			cout << "����:\n" << arr[i].describe;
			cout << endl;
			cout << "----------------------------------------------------------------------------------------------------" << endl;
		}
	}
	if(n==0)//���� ����� ������ ����, �� �������� �������� �����������
		cout << "����� �� ��������" << endl;
}

void find_5count(article* arr, int size)//����� ������, ���� ���������� ����� 5 �� �����
{
	//�������� �����
	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t��� ������\t|\t����� ������\t|\tʳ������ �� �����\t|\tֳ�� � �.�.\t|\tֳ�� � �������\t|" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
	int n = 0;//������ �������� ������
	for (int i = 0; i < size; ++i)//����������� �� ��� �������
	{
		if (arr[i].amount <5)//���� ��������� ������ �� ����� ����� 5, �� �������� ���������� ��� �����
		{
			++n;
			cout << "|\t" << arr[i].type << "\t\t";
			cout << "|\t" << arr[i].mark << "\t\t";
			cout << "|\t\t" << arr[i].amount << "\t\t";
			cout << "|\t" << arr[i].price_us << "\t\t";
			cout << "|\t\t" << arr[i].price_ua << "\t\t|" << endl;
			cout << "����:\n" << arr[i].describe;
			cout << endl;
			cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
	}
	if (n == 0)//���� ����� ������ �� ��������, �� �������� �������� �����������
		cout << "����� �� ��������" << endl;
}

void corect_price(article* arr, int size)//������������ ����
{
	for (int i = 0; i < size; ++i)//����������� �� ��� �������
		arr[i].price_ua = us * arr[i].price_us;//�� ������������ ���� � �������
}

void print_information_by_types(article*arr, int size)//���� ���������� �� ������
{
	int n = 0;//������� ����� ���� ������ � ��� �����
	string* a = new string[size];//����� ����� ������ ������
	for (int i = 0; i < size; ++i)//���������� ����� � ������ ������
		a[i] = arr[i].type;
	for (int i = 0; i < size; ++i)//������� � ���������� ������ ������� ������, ������� ���� ����
	{
		for (int j = i+1; j < size; j++)
		{
			if (a[i] == a[j])
				a[j] = "";
		}
	}
	for (int i = 0; i < size; ++i)//������� ������� ����, �� ���������� �����
		if (a[i] != "")
			++n;
	string* a_new = new string[n];//��������� �����, � ����� ������ �������� ���� ������, ��� �������
	for(int i=0,j=0;i<size;++i)
		if (a[i] != "")//�� ��� �� �������
		{
			a_new[j] = a[i];//�� ���������� ���� ��� ����� ���������� ������
			++j;
		}
	delete[]a;//������� ���'���
	for (int i = 0; i < n; ++i)//����������� �� ��� ����� ������
	{
		cout <<"\t\t\t\t"<< a_new[i] << endl;//�������� ��� 
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "|\t����� ������\t|\tʳ������ �� �����\t|\tֳ�� � �.�.\t|\tֳ�� � �������\t|" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		for (int j = 0; j < size; ++j)//����������� �� ������ ������
		{
			if (arr[j].type == a_new[i])//���� ��� ������ ������� �� ����� ���� ���� �������� �� �����
			{
				cout << "|\t" << arr[j].mark << "\t\t";
				cout << "|\t\t" << arr[j].amount << "\t\t";//�� �������� ����������
				cout << "|\t" << arr[j].price_us << "\t\t";
				cout << "|\t\t" << arr[j].price_ua << "\t\t|" << endl;
				cout << "����:\n" << arr[j].describe;
				cout << endl;
				cout << "-------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
	}	
	delete[]a_new;//��������� ���'���
}

int main()
{
	SetConsoleCP(1251);//���� ��������� ��� ������ � ���������
	SetConsoleOutputCP(1251);
	int k = -1;
	int size=0;//������� ������ � ��� �����
	article* arr=0;//�����(���� �����) ��� ���������� ����������
	do
	{
		cout << "���� ������:";
		cin >> us;//�������� ����� ������
	} while (us <= 0);//�������� �� ������������ �������� �����
	
	while (k != 0)//���� ����� ���� �� ��������� ������
	{
		system("cls");//�������� ������
		cout << "������� ���� �� ������:" << endl;//������� ������� �����, � ���� ������ ���������
		if (size==0)
			cout << "\t1-������ ����" << endl;
		cout << "\t2-����������� �� ����" << endl;
		cout << "\t3-������ ����� �����" << endl;
		cout << "\t4-�������� �����" << endl;
		cout << "\t5-��������� �� ����� ������" << endl;
		cout << "\t6-��������� �� ����� ������" << endl;
		cout << "\t7-����� �������������� ����'����� ������ �����" << endl;
		cout << "\t8-������� ���������� ��� �������� �������� �� ������ ����" << endl;
		cout << "\t9-������ ���� �� ����� ����� 5 ����" << endl;
		cout << "\t10-���������� ���� ������" << endl;
		cout << "\t11-����������, ������������ �� �����" << endl;
		cout << "\t0-��������� ������" << endl;
		cin >> k;
		switch (k)//�������� �� �������� ������ ����������� �������� 䳿
		{
		case 1://�������� �����
			if (size == 0)//������ ���� ������ ���� ���� ����� ������
			{
				cout << "ʳ������ ������: ";
				cin >> size;//������� ������� ������
				arr = new article[size];//�������� ���'��� �� �����
				enter_data(arr, size);//��������� ������� ��� ��������� �����
			}
			system("pause");//�������� ���������� �� ������
			break;
		case 2://���� �����
			if (size == 0)//���� ������ ����, �������� �������� �����������
				cout << "���� ����� �����."<<endl;
			else
				show_info(arr, size);//������ �������� �� ������ � ���� �����
			system("pause");
			break;
		case 3://��������� ������
		{
			article* prev = new article[size];//��������� ���������� ����� ��� ���������� �����
			for (int i = 0; i < size; ++i)
				prev[i] = arr[i];//���������� ���� ���������� � ������� ���� �����
			++size;
			arr = new article[size];//�������� ����� ��� ������� ���� �����
			for (int i = 0; i < size-1; ++i)//�������� � ������� ���� ����� ������ �� ��� ���� ������ � ���
				arr[i] = prev[i];
			cout << "\t\t������ ���� ��� �����" << endl;
			cout << "��� ������:";
			cin >> arr[size-1].type;//� ������� ���� ��� ������ ������
			cout << "����� ������:";
			cin >> arr[size - 1].mark;
			cout << "ʳ������ �� �����:";
			cin >> arr[size - 1].amount;
			cout << "����(��������������):";
			cin >> arr[size - 1].describe;
			cout << "ֳ�� � �.�.:";
			cin >> arr[size - 1].price_us;
			arr[size - 1].price_ua = arr[size - 1].price_us * us;//����������� ���� � ������� � ���� � �������
			delete[]prev;//��������� ���'��� � ����������� ������
			system("pause");
			break;
		}
		case 4://��������� ������
			arr=del_note(arr, size);//������ ������� ��� ��������� ������
			system("pause");
			break;
		case 5://���������� �� �����
			sort_by_type(arr, size);//������ ������� ��� ���������� ������ �� �����
			cout << "������ ����������� �� �����" << endl;
			system("pause");
			break;
		case 6://���������� �� �����
			sort_by_price(arr, size);//������ ������� ��� ���������� ������ �� �����
			cout << "������ ����������� �� �����" << endl;
			system("pause");
			break;
		case 7://����� ����� ����'����� �� ������� ������
		{
			string mark;
			cout << "������ ����� ��� ������ ����'�����: ";
			cin >> mark;//�������� �����
			find_discribe(arr, size, mark);//������ ������� ��� ������
			system("pause");
			break;
		}
		case 8://����� �������� �� �����
		{
			float price;
			cout << "������ ���� � ������� ��� ������ ��������: ";
			cin >> price;//�������� ����
			find_printers(arr, size, price);//������ ������� ��� ������ ��������
			system("pause");
			break;
		}
		case 9://����� ������, ������� ���� �� �������� 5
			find_5count(arr, size);//������ �������� �������
			system("pause");
			break;
		case 10://����������� ����
			cout << "����� ���� ������: ";
			cin >> us;//�������� ����� ������
			corect_price(arr, size);//������ ������� ��� ����������� ����
			cout << "ֳ�� �����������" << endl;
			system("pause");
			break;
		case 11://���� ���������� �� ������
			print_information_by_types(arr, size);//������ �������� ����������
			system("pause");
			break;
		}
	}
	delete[]arr;//������� ���� �����
	system("pause");
	return 0;
}