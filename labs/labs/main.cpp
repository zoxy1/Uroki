﻿// lab9_2
/* Для получения места в общежитии формируется список студентов, который включает ФИО студента, 
группу, средний балл, доход на члена семьи. Общежитие в первую очередь предоставляется тем, 
у кого доход на члена семьи меньше двух минимальных зарплат, затем остальным в порядке уменьшения
среднего балла. Вывести список очередности предоставления мест в общежитии.
*/

#include <iostream> // содержит функции ввода вывода cin, cout
#include<windows.h> //содержит функции SetConsoleCP(), SetConsoleOutputCP()
#include <iomanip> //необходима для setw() задание ширины поля вывода данных 
using namespace std;
struct struct_student // описываем структуру struct_student включающую: 
{
	char FIO[60]; //фамилия имя отчество
	int group;	  //группа
	float bal;    //средний бал
	int income; //доход на члена семьи
};

void main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	/* Для правильного отображения русских символов в консоли нужно выбрать 
	в свойствах консоли шрифт Lucida Console */
int incom2=12000; // устанавливаем две минимальные зарплаты
int stud[10]; 
int stud_count=0;
// Инициализируем массив с ФИО студентов
char name[10][60]={"Петин Иван Дмитриевич","Халеев Иван Сергеевич","Худякова Антонина Павловна",
	"Шариков Борис Николаевич",	"Данилин Виктор Иванович","Шакурова Разина Шакуровна",
	"Кузнецова Марина Александровна","Чистякова Тамара Васильевна","Гаврилова Мария Григорьевна","Нефёдова Евдокия Ивановна "}; 
int groups[10]={120,121,122,123,124,125,126,127,128,129}; //  массив с номером группы студентов
float bals[10]={4.5, 5, 3.2, 4.3, 4.9, 2.8, 3.9, 4 ,3.5, 3.3}; // массив со средним балом студентов
int incomes[10]={10000,15000,7000,20000,4000,25000,8000,15000,9500,1400}; // массив с доходом на члена семьи студентов
struct_student student[10]; //инициализируем массив структур типа struct_student
for(int i=0;i<10;i++) 
{
strcpy(student[i].FIO,name[i]); // копируем ФИО в структуры
student[i].group=groups[i]; // копируем группы в структуры
student[i].bal=bals[i]; //копируем баллы в структуры
student[i].income=incomes[i]; // копируем доход на члена семьи
}
cout<<"Общежитие в первую очередь предоставляется студентам,"<<endl;
cout<<"у которых доход на члена семьи меньше двух минимальных зарплат ("<<incom2<<") рублей:"<<endl<<endl;

for(int i=0;i<10;i++)
{
	if(student[i].income<incom2) // проверяем если доход на члена семьи меньше чем incom2, то выполняем следующее
	{
		cout<<"Доход:"<<setw(5)<<left<<student[i].income<<" ";
		cout<<student[i].FIO<<endl; //выводим ФИО студента
		stud[i]=1; // относим студента к первой очереди
	}
	else
	{
		stud[i]=2; // относим студента ко второй очереди
		stud_count++; // считаем сколько студентов попало во вторую очередь
	}
}
struct_student *stud2 = new struct_student[stud_count]; // создаем массив структур типа struct_student размером второй очереди
int k=0;
for(int i=0;i<10;i++)
	{
		if(stud[i]==2) //если студент попал во вторую очередь копируем его данные в stud2 
		{
			strcpy(stud2[k].FIO,student[i].FIO);
			stud2[k].bal=student[i].bal;
			stud2[k].group=student[i].group;
			stud2[k].income=student[i].income;
			k++;
		}

	}
//для сортировки используем метод пузырька
char temp1[60]; 
for (int i = 0; i < stud_count; i++) // начинаем с конца до нулевого элемента, затем с конца до первого и т д
    {
        for (int j = stud_count - 1; j > i; j--) //начинаем с послднего элемента
		{
           	if (stud2[j].bal > stud2[j - 1].bal) // если последний элемент больше предыдущего, то меняем их местами
            {
				swap (stud2[j].bal, stud2[j - 1].bal);  // меняем местами среднее значения балла  
                swap (stud2[j].group, stud2[j - 1].group); // меняем местами номера групп
				swap (stud2[j].income, stud2[j - 1].income); // меняем местами доходы
				//меняем местами ФИО студентов 
				strcpy(temp1,stud2[j].FIO);				
				strcpy(stud2[j].FIO,stud2[j-1].FIO);
				strcpy(stud2[j-1].FIO,temp1);
			}
        }
    }
cout<<endl<<"Остальным в порядке уменьшения среднего балла"<<endl;
for(int i=0;i<stud_count;i++)//Выводим в порядке уменьшения среднего бала ФИО студентов второй очереди
{
	cout<<"Средний бал:"<<setw(4)<<left<<stud2[i].bal<<" ";
	cout<<stud2[i].FIO<<endl;
}
delete stud2; // освобождаем память выделенную под структуру stud2
system("pause"); // команда задержки  экрана
}

