// lab4_1
#include <iostream> // �������� ������� ����� ������ cin, cout
#include<windows.h> //�������� ������� SetConsoleCP(), SetConsoleOutputCP()
using namespace std;

void Vivod(int elementCount, int *Array) //������� ������ �� ������� ������� � �������� ����������� ���������
{
for(int k=0;k<elementCount;k++) // ������� ����������� ������ 
	{
		cout <<k<<" : "<<Array[k]<<endl;
	}	
}
int a[10]; //�������������� ������ ���� int
int main()
{
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	/* ��� ����������� ����������� ������� �������� � ������� ����� ������� 
	� ��������� ������� ����� Lucida Console */
	
	int *p; // �������������� ���������
	int i=3;// ���������� i ����������� �������� 3
	p=a; // ��������� p ����������� ����� ������� �������� ������� 
	for(int j=0;j<10;j++){
		*(p+j)=j+1; //��������� ������ � ������� ��������� �������  1 2 3 4 5 6 7 8 9 10 
	}
	cout <<"������� ������:"<<endl;
	Vivod(10,p); 
	p=p+4; // ���������� ��������� �� ����� �������
	cout <<"���������� ��������� �� ����� �������(p+=4)"<<endl;
	cout <<"�������� ��������� ����������(*p) �� ������: "<<p<<" �����:"<<*p<<endl; 
	// ������� �������� ���������� � ������� ���������� �� ������ p
	cout <<"��������� �� "<<i<<"-� ���������� ����� ���������(p+"<<i<<"):"<<(p+i)<<endl;
	cout <<"��������� �� "<<i<<"-� ���������� ����� ���������(p-"<<i<<"):"<<(p-i)<<endl;
	cout <<"�������� "<<i<<"-� ���������� ����� ���������(*(p+"<<i<<")):"<<*(p+i)<<endl;
	cout <<"�������� "<<i<<"-� ���������� ����� ���������(p["<<i<<"]):"<<p[i]<<endl;
	cout <<"�������� ��������� p:"<<p<<endl;
	p++; 
	cout <<"����������� ��������� �� ��������� ����������(p++),�������� ���������:"<<p<<endl;
	p--;
	cout <<"����������� ��������� �� ���������� ����������(p--),�������� ���������:"<<p<<endl;
	p++;
	cout <<"����������� ��������� �� ��������� ����������(p++),�������� ����������:"<<*p<<endl;
	p--;
	cout <<"����������� ��������� �� ���������� ����������(p--),�������� ����������:"<<*p<<endl;
	p+=i;
	cout <<"����������� ��������� �� "<<i<<" ���������� ������(p+="<<i<<"),\n�������� ����������:"<<*p<<endl;
	p-=i;
	cout<<"����������� ��������� �� "<<i<<" ���������� �����(p-="<<i<<"), \n�������� ����������:"<<*p<<endl;
	cout<<"�������� �������� ��������� ���������� � ����������� ��������� \n� ���������(*�++;), �������� ����������:"<<*p++<<endl;
	cout <<"�������� ���������� �� ������ �:"<<*p<<endl;
	cout<<"����������� ��������� � ����������, �������������� ���������, \n� �������� �� ��������(*(--�)), �������� ����������:"<<*(--p)<<endl;
	cout <<"�������� ��������� �:"<<p<<endl;
	p=p+i;
	cout<<"��������� �� ��������� ������ ����� �� ��������� ����������(p+"<<i<<"), \n�������� ���������:"<<p<<endl;

	system("pause"); //  ������� �������� ������
	return 0;
}

