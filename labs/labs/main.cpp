﻿// lab11_2
/* Написать программу, в которой описана иерархия классов: 
функция от одной переменной (SIN(X), COS(X), TG(X)). 
Базовый класс должен иметь методы получения значения функции 
для данного значения переменной вводимой пользователем с экрана, 
а также создания экземпляра класса, представляющего собой производную текущего экземпляра.
*/
#include <iostream> // содержит функции ввода вывода cin, cout
#include<windows.h> //содержит функции SetConsoleCP(), SetConsoleOutputCP()
#include<math.h>
#define PI  3.141592653589793238462643383279 // число пи
using namespace std;

class X // описываем базовый класс
{
public: 
	X() // конструктор
	{}
	~X() // деструктор
	{}
	
	virtual float sin_x() // виртуальный метод sin_x()
	{
		return 0;
	};  
	virtual float cos_x() // виртуальный метод cos_x()
	{
		return 0;
	};  
	virtual float tan_x() // виртуальный метод tan_x()
	{
		return 0;
	};  
	
	void set_x(float x1) // метод записи значения в переменную x 
	{
	x=x1;
	}
	float get_x() // метод получения значения из переменной x 
	{
		return x;
	}

private:
	float x; // переменная не доступна вне класса X
};

class sin_X : public X // описываем производный от класса X класс sin_X 
{
public:
	float sin_x() // метод возращающий значение синуса от числа х
	{
		int temp=get_x();
		if(temp==180||temp==360) //если углы равны 180 или 360 градусов возращаем 0 
		{
			return 0;
		}
		else
		{
			return sin((get_x() * PI)/180); // вычисляем значение синуса
		}	
	
	}

};
class cos_X : public X
{
public:
	float cos_x() // метод возращающий значение косинуса от числа х
	{
		float temp= get_x();
		if(temp==90||temp==270) //если углы равны 90 или 270 градусов возращаем 0 
		{
			return 0;
		}
		else
		{ 
			return cos((get_x() * PI)/180);  // вычисляем значение косинуса
		}	
	}
};
class tan_X : public X, public sin_X,  public cos_X // описываем производный от классов X, sin_X,cos_X класс tan_X 
{
public:
	float tan_x() // метод возращающий значение тангенса от числа х
	{
		float temp = cos_X::cos_x();
		if(temp==0) //проверяем значение косинуса равно 0 или нет 
		{
			cout<<"Значение тангенса неопределено"<<endl;
			return 0;
		}
		else
		{
			return sin_X::sin_x()/temp;
		
		}	
	}
};
void main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	/* Для правильного отображения русских символов в консоли нужно выбрать 
	в свойствах консоли шрифт Lucida Console */
	//X * X_ptr=new X();
	sin_X * sin_X_ptr=new sin_X(); // создаем оъект класса sin_X
	cos_X * cos_X_ptr=new cos_X(); // создаем оъект класса cos_X
	tan_X * tan_X_ptr=new tan_X(); // создаем оъект класса tan_X
	cout<<"Введите значение х в градусах от 0 до 360:";
	float x_in;
	cin>>x_in; // вводим значение числа х в градусах
	
	sin_X_ptr->set_x(x_in); // передаем значение числа объекту класса sin_X находящемуся по адресу sin_X_ptr
	cout<<"sin("<<x_in<<")="<<sin_X_ptr->sin_x()<<endl;
	
	cos_X_ptr->set_x(x_in);
	cout<<"cos("<<x_in<<")="<<cos_X_ptr->cos_x()<<endl;
		
	tan_X_ptr->sin_X::set_x(x_in);
	tan_X_ptr->cos_X::set_x(x_in);
	if(x_in==90||x_in==270)
	{
		cout<<"Значение тангенса неопределено"<<endl;
	}
	else
	{
		cout<<"tan("<<x_in<<")="<<tan_X_ptr->tan_x()<<endl;
	}
	
	system("pause"); // команда задержки  экрана
}

