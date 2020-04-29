//头文件部分
#include<iostream>  //cin,cout
#include<cstdio>    //fopen_s,fprint,
#include<cstdlib>   //system,rand,srand,RAND_MAX
#include<ctime>     //time
#include<windows.h> //Speep
#include<cstring>   //string
using namespace std;

//定义初始化参数
char Arithmetic_brackets[4] = { '(',' ',')',' ' };  //包含的括号的数组
char Arithmetic_operators[4] = { '+','-','*','/' }; //包含的运算符
const int Arithmetic_brackets_nums = 4; // 括号数量
int Arithmetic_nums;  //设置题目的数量
int Arithmetic_operation;   //设置运算符
int Arithmetic_maxnumber;  //设置最大的数值
string  Arithmetic_isdecimal; //设置是否有小数
string Arithmetic_isbracket; //设置是否有括号
string Arithmetic_isfile; // 设置是否输出到文件



//定义随机生成的三个整数
int i_nums1;
int i_nums2;
int i_nums3;

//定义随机生成的三个小数
float f_nums1;
float f_nums2;
float f_nums3;

//定义选择的运算符
char c_nums;


//设置题目数量
void initfun1()
{
	system(" echo."); //相当于产生一行空行。
	cout << "第一步：请设置题目数量<1-100>: " << endl;
	cin >> Arithmetic_nums;
	while (Arithmetic_nums > 100 || Arithmetic_nums < 1)
	{
		cout << "您输入的题目数量不符合要求，请重新输入：" << endl;
		cin >> Arithmetic_nums;
	}
}

//设置运算符符
void initfun2()
{
	system(" echo.");
	cout << "请选择运算符：加法运算请输入0，减法运算请输入1，乘法运算请输入2，除法运算请输入3" << endl;
	cin >> Arithmetic_operation;
	if (Arithmetic_operation == 0 || Arithmetic_operation == 1 || Arithmetic_operation == 2 || Arithmetic_operation == 3)
	{
		c_nums = Arithmetic_operators[Arithmetic_operation];
	}
	while (Arithmetic_operation != 0 && Arithmetic_operation != 1 && Arithmetic_operation != 2 && Arithmetic_operation != 3)
	{
		cout << "您输入的运算符不符合要求，请重新输入: " << endl;
		cin >> Arithmetic_operation;
		c_nums = Arithmetic_operators[Arithmetic_operation];
	}
}

//设置最大值
void initfun3()
{
	system(" echo.");
	cout << "第二步：请设置最大数值<1-1000>: " << endl;
	cin >> Arithmetic_maxnumber;
	while (Arithmetic_maxnumber > 1000 || Arithmetic_maxnumber < 1)
	{
		cout << "您输入的最大数值不符合要求，请重新输入:  "<<endl;
		cin >> Arithmetic_maxnumber;
	}
}

//设置是否有小数
void initfun4()
{
	system(" echo.");
	cout << "请选择是否有小数<y/n>(是则输入字符y,否则输入字符n): " << endl;
	cin >> Arithmetic_isdecimal;
	while (Arithmetic_isdecimal != "y" && Arithmetic_isdecimal != "n")
	{
		cout << "您输入的字符不符合要求，请重新输入: " << endl;
		cin >> Arithmetic_isdecimal;
	}
}

//设置是否有括号
void initfun5()
{
	system(" echo.");
	cout << "请选择是否有括号<y/n>(是则输入字符y,否则数去字符n): " << endl;
	cin >> Arithmetic_isbracket;
	while (Arithmetic_isbracket != "y" && Arithmetic_isbracket != "n")
	{
		cout << "您输入的字符不符合要求，请重新输入: " << endl;
		cin >> Arithmetic_isbracket;
	}
}

//设置是否输出到文件
void initfun6()
{
	system(" echo.");
	cout << "请选择是否输出的文件<y/n>(是则输入字符y,否则输入字符n): " << endl;
	cin >> Arithmetic_isfile;
	while (Arithmetic_isfile != "y" && Arithmetic_isfile != "n")
	{
		cout << "您输入的字符不符合要求，请重新输入: " << endl;
		cin >> Arithmetic_isfile;
	}
}

//初始化用户设置函数
void init_set()
{
	initfun1();
	initfun2();
	initfun3();
	initfun4();
	initfun5();
	initfun6();
}

//随机生成运算数据
void init_calculation_data()
{
	//随机生成五个整数
	i_nums1 = rand() % Arithmetic_maxnumber + 1;
	i_nums2 = rand() % Arithmetic_maxnumber + 1;
	i_nums3 = rand() % Arithmetic_maxnumber + 1;

	//随机生成五个小数
	f_nums1 = (float)rand() / RAND_MAX * Arithmetic_maxnumber + 1;
	f_nums2 = (float)rand() / RAND_MAX * Arithmetic_maxnumber + 1;
	f_nums3 = (float)rand() / RAND_MAX * Arithmetic_maxnumber + 1;
}

//输出到屏幕
void Arithmetic_Output_Screen()
{
	cout << "以下是生成的小学四则运算题目：" << endl;
	srand(time(0));
	for (int i = 1; i <= Arithmetic_nums; i++)
	{
		init_calculation_data();
		if (Arithmetic_isdecimal == "y")
		{
			if (Arithmetic_isbracket == "y")
			{
				printf("< %d >:  ( %.2f %c %.2f ) %c %.2f = \n", i, f_nums1, c_nums,f_nums2, c_nums,f_nums3);
			}
			else if (Arithmetic_isbracket == "n")
			{
				printf("< %d >:   %.2f %c %.2f %c %.2f = \n", i, f_nums1, c_nums, f_nums2, c_nums, f_nums3);
			}
		}
		else if (Arithmetic_isdecimal == "n")
		{
			if (Arithmetic_isbracket == "y")
			{
				printf("< %d >:  ( %d %c %d ) %c %d = \n", i, i_nums1, c_nums, i_nums2, c_nums, i_nums3);
			}
			else if (Arithmetic_isbracket == "n")
			{
				printf("< %d >:  %d %c %d %c %d = \n", i, i_nums1, c_nums, i_nums2, c_nums, i_nums3);
			}
		}
	}
	cout << "小学四则运算题目生成完毕。" << endl;
}

//输出到文件
void Arithmetic_Output_File()
{
	
	FILE* fp;
	errno_t err= fopen_s(&fp,"F:\\task4.txt", "a+");
	if (err)
	{
		cout << "打开文件失败,无法输出到文件" << endl;
		exit(-1);
	}
	fprintf(fp, "以下是生成的小学四则运算题目：\n");
	srand(time(0));
	for (int i = 1; i <= Arithmetic_nums; i++)
	{
		init_calculation_data();
		if (Arithmetic_isdecimal == "y")
		{
			if (Arithmetic_isbracket == "y")
			{
				fprintf(fp, "< %d >:  ( %.2f %c %.2f ) %c %.2f = \n", i, f_nums1, c_nums, f_nums2, c_nums, f_nums3);
			}
			else if (Arithmetic_isbracket == "n")
			{
				fprintf(fp, "< %d >:  %.2f %c %.2f %c %.2f = \n", i, f_nums1, c_nums, f_nums2, c_nums, f_nums3);
			}
		}
		else if (Arithmetic_isdecimal == "n")
		{
			if (Arithmetic_isbracket == "y")
			{
				fprintf(fp,"< %d >:  ( %d %c %d ) %c %d = \n", i, i_nums1, c_nums, i_nums2, c_nums, i_nums3);
			}
			else if (Arithmetic_isbracket == "n")
			{
				fprintf(fp, "< %d >:  %d %c %d %c %d = \n", i, i_nums1, c_nums, i_nums2, c_nums, i_nums3);
			}
		}
	}
	cout << "题目已经输出到文件，可以到F:\\task4.txt查看。" << endl;
}



int main()
{
	char ch;//是否退出程序
	while (true)
	{
		init_set();
		if (Arithmetic_isfile == "y")
		{
			Arithmetic_Output_File();
		}
		else if (Arithmetic_isfile == "n")
		{
			Arithmetic_Output_Screen();
		}
		system(" echo.");
		system(" echo.");
		cout << "是否继续生成小学生四则运算题?<y/n>(是则输入字符y,否则输入字符n): ";
		cin >> ch;
		while (ch != 'y' && ch != 'n')
		{
			cout << "您输入的字符不符合要求，请重新输入: " << endl;
			cin >> ch;
		}
		if (ch == 'y')
		{
			system("cls");
		}
		else
			break;
	}
	cout << "小学生四则运算程序已经退出！谢谢您的使用。" << endl;
	return 0;
}