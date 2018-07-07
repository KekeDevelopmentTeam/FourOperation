// FourOperation.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"stdlib.h"
#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<time.h>
#include<sys/timeb.h>
#include<fstream>
using namespace std;
int languageNum,num_i=4;
string str="";
int random(double start, double end)
{
	return (int)(start + (end - start)*rand() / (RAND_MAX + 1.0));
}   //���������

int gcd(int a, int b)       //���庯��gcd ���� 
{
	if (a%b == 0)
		return b;         
	else
		return gcd(b, a%b);     
}////�����Լ��
void strout1(int fenzi, int fenmu)   //���ݷ��ӷ�ĸ������������ʽ��
{
	int f = 1 + random(0, 50);
	if (f < 25) {
		if (num_i > 2)
		{
			num_i--;
			int x = 1;
			int y = 1 + random(fenmu, fenmu+3);
			strout1(x, y);
			int sum1 = fenzi*y - x * fenmu;
			int sum2 = fenmu*y;
			int gcd1 = gcd(sum2, sum1);
			x = sum1 / gcd1; y = sum2 / gcd1;
			str = to_string(x) + "/" + to_string(y) + "+"+str;
		}
		else
		{
			int x = 1;
			int y = 1 + random(fenmu, fenmu +3);
			int sum1 = fenzi*y - x * fenmu;
			int sum2 = fenmu*y;
			int gcd1 = gcd(sum2, sum1);
			int x1 = sum1 / gcd1; int y1 = sum2 / gcd1;
			str =str+ to_string(x) + "/" + to_string(y) + "+"+to_string(x1) + "/" + to_string(y1);
		}
	}
	else if (f >= 25 && f < 50) {
		if (num_i > 2)
		{
			num_i--;
			int x = random(1, 10);
			int y = 1 + random(1, 15);
			strout1(x,y);
			int sum1 = fenzi*y + x*fenmu;
			int sum2 = fenmu*y;
			int gcd1 = gcd(sum2, sum1);
			int x1 = sum1 / gcd1; 
			int y1= sum2 / gcd1;
			str = to_string(x1) + "/" + to_string(y1) + "-" + str ;
		}
		else
		{
			int x = random(1, 10);
			int y = 1 + random(1, 15);
			int sum1 = fenzi*y + x*fenmu;
			int sum2 = fenmu*y;
			int gcd1 = gcd(sum2, sum1);
			int x1 = sum1 / gcd1; 
			int y1 = sum2 / gcd1;
			str = str+to_string(x1) + "/" + to_string(y1) + "-"+to_string(x) + "/" + to_string(y);
		}

	}
	
}    //����
void strout(int ans)           //������������������������ʽ
{
	int f = 1 + random(0,100);
	if (f < 25) {// +
		if (num_i > 2) {
			num_i--;
			int x = random(1,ans); 
			strout(x);
			int y = ans - x;
			if(y>=0)
			str = to_string(y) + "+" + str;

		}
		else {
			int x =  random(1, ans);
			int y = ans - x;
			if(y>=0)
			str = str + to_string(y) + "+" + to_string(x);
		}
	}
	if (f >= 25 && f < 50) {// -
		if (num_i > 2) {
			num_i--;
			int x = random(1, ans);
			strout(x);
			int y = ans + x;
			str = to_string(y) + "-" + "(" + str + ")";

		}
		else {
			int x = random(1, ans);
			int y = ans + x;
			str = str + to_string(y) + "-" + to_string(x);
		}
	}
	if (f >= 50 && f < 75) {// *
		if (num_i > 2) {
			num_i--;
			int x = 0;
			for (int i = (int)sqrt(ans); i > 0; i++) {
				if (ans%i == 0) {
					x = i;
					break;
				}
			}
			int y = ans / x; 
			strout(x);
			str = to_string(y) + "*" + "(" + str + ")";

		}
		else {
			int x = 0;
			for (int i = (int)sqrt(ans); i > 0; i++) {
				if (ans%i == 0) {
					x = i;
					break;
				}
			}
			int y = ans / x;
			str = str + to_string(y) + "*" + to_string(x);
		}
	}
	if (f >= 75) {// /
		if (num_i > 2) {
			num_i--;
			int x = 1 + random(0,10); 
			strout(x);
			int y = ans * x;
			str = to_string(y) + "��" + "(" + str + ")";

		}
		else {
			int x = 1 + random(0, 10);
			int y = ans * x;
			str = str + to_string(y) + "��" + to_string(x);
		}
	}
	//str += "=";
	
}  
 
void run2()                                  //���з�������
{
	int n, i;
	int trueCount = 0, errCount = 0,ansCount=1,exeCount=1;
	ofstream fout("FracAnswers.txt");
	ofstream fout1("FracExercises.txt");
	num_i = 2;
	cout << "����������ʽ������";
	cin >> n;
	i = n;
	while (n--)
	{
		int fenzi,fenmu,gcd1;
		string get,ans;
		//int num1, num2, a;
		//char signal;
		struct timeb timeSeed;
		ftime(&timeSeed);
		srand(timeSeed.time * 1000 + timeSeed.millitm);
		fenzi = random(1,5);
		fenmu = random(2, 10);
		gcd1 = gcd(fenzi, fenmu);
		fenzi = fenzi / gcd1; fenmu = fenmu / gcd1;
		strout1(fenzi,fenmu);
		cout << str << endl;
		fout1 << ansCount++ << "." << str << endl;
		str = "";
		if (fenzi%fenmu == 0) ans = fenzi / fenmu;
		else ans = to_string(fenzi) + "/" + to_string(fenmu);
		cin >> get;
		fout << exeCount++ << "." << ans << endl;
		if (get == ans) trueCount++;
		else errCount++;
		cout << "������ˣ�" << i - n << "����" << "   ��ȷ��" << trueCount << "��" << "   ����" << errCount << "��" << endl << endl;;
	
		num_i = 2;
	}
	}
	
void run()                     //������������
{
	int n,i;
	int trueCount=0, errCount = 0,ansCount=1,exeCount=1;
	ofstream fout("IntAnswers.txt");
	ofstream fout1("IntExercises.txt");
	cout << "����������ʽ������";
	cin >> n;
	i = n;
	while (n--)
	{
		int get,ans;
		//int num1, num2, a;
		//char signal;
		struct timeb timeSeed;
		ftime(&timeSeed);
		srand(timeSeed.time * 1000 + timeSeed.millitm);
		ans = random(1,50);
		fout << ansCount++ << "." << ans << endl;
		strout(ans);
		cout << str << endl;
		fout1<< exeCount++<<"."<<str << endl;
		str = "";
		num_i = 4;
		cin >> get;
		if (get == ans) trueCount++;
		else errCount++;
		cout << "������ˣ�" << i - n << "����" << "   ��ȷ��" << trueCount << "��" << "   ����" << errCount << "��" << endl;
		
	}
}                  
void mainUI()
{
	int choose;
	if (languageNum == 1)
	{
		cout << "                                       *****************���˵�*********************" << endl;
		cout << "                                                     1.��������                       " << endl;
		cout << "                                                     2.���������                       " << endl;
		cout << "                                                     2.��������                           " << endl;
		cout << "                                                     3.�˳�                            " << endl << endl << endl;
		cout << "                          ������ѡ��";
	}
	cin >> choose;
	if (choose == 1)
	{
		system("cls");
		run();
	}
	if (choose == 2)
	{
		system("cls");
		run2();
	}
	if (choose == 3) exit(0);
}

int main()
{
	languageNum = 1;
	mainUI();
    return 0;
}

