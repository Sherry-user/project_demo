// 判断唯一可译码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;
#pragma warning(disable:4996)
char c[100][50];//保存码字
char f[300][50];//保存尾随后缀
int N, sum = 0;//分别为码字的个数和尾随后缀个数
int flag;//判断是否为唯一可译码
void patterson(char c[], char d[])//检测尾随后缀
{
	int i, j, k;
	for (i = 0;; i++)
	{
		if (c[i] == '\0' && d[i] == '\0')//两字符串长度相同
			break;
		if (c[i] == '\0')//d比c长，将d的尾随后缀放入到f中
		{
			for (j = i; d[j] != '\0'; j++)
				f[sum][j - i] = d[j];
			f[sum][j - i] = '\0';
			for (k = 0; k < sum; k++)
			{
				if (strcmp(f[sum], f[k]) == 0)//查看当前生成的尾随后缀在f集合中是否存在
				{
					sum--;
					break;
				}
			}
			sum++;
			break;
		}
		if (d[i] == '\0')//c比d长，将c的尾随后缀放入f中
		{
			for (j = i; c[j] != '\0'; j++)
				f[sum][j - i] = c[j];
			f[sum][j - i] = '\0';
			for (k = 0; k < sum; k++)
			{
				if (strcmp(f[sum], f[k]) == 0)//查看当前生成的尾随后缀在f集合中是否存在
				{
					sum--;
					break;
				}
			}
			sum++;
			break;
		}
		if (c[i] != d[i])
			break;
	}
}
void main()
{
	int k = 0, N = 0, m = 0, a[50], z = 0;
	a[m] = N; m++;
	fstream file1;
	file1.open("out4.txt");
	FILE* file;
	file = fopen("in4.txt", "r+");//读取码字
	int num = fgetc(file) - 48;
	for (int n = 0; n < num; n++)
	{
		int i = 0, j;
		if (fgetc(file) == ' ')
			N += (fgetc(file) - 48);
		else
			N += (fgetc(file) - 48);
		a[m] = N; m++;
		fgetc(file);
		for (k; k < N; k++)
		{
			for (int q = 0;; q++)
			{
				char temp = fgetc(file);
				c[k][q] = temp;
				if (temp == ' ' || temp == '$')
				{
					c[k][q] = '\0';
					break;
				}
			}
		}
		flag = 0;
		for (i = a[z]; i < N - 1; i++)//判断码本身是否重复
			for (j = i + 1; j < N; j++)
			{
				if (strcmp(c[i], c[j]) == 0)
				{
					flag = 1; break;
				}
			}
		if (flag == 1)//如果码本身存在重复，即可断定其不是唯一可译码
		{
			for (int y = a[z]; y < N; y++)
				file1 << c[y] << ' ';
			file1 << "不是唯一可译码\n";
		}
		else {
			for (i = a[z]; i < N - 1; i++)//将原始码字生成的尾随后缀集合s[1]放入f中
			{
				for (j = i + 1; j < N; j++)
				{
					patterson(c[i], c[j]);
				}
			}
			for (i = 0;; i++)//根据原始码与s[i]生成s[i+1]也放入f[i]
			{
				int s = 0;
				for (j = a[z]; j < N; j++)//判断s[i+1]中的字符串是否与s[i]中一样，重复则不再添加
				{
					if (i == sum)
					{
						s = 1; break;
					}
					else
						patterson(f[i], c[j]);
				}
				if (s == 1)
					break;
			}
			for (i = 0; i < sum; i++)//判断尾随后缀与原始码字是否相同，相同则不是唯一可译码
			{
				for (j = a[z]; j < N; j++)
				{
					if (strcmp(f[i], c[j]) == 0)
					{
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1)
			{
				for (int y = a[z]; y < N; y++)
					file1 << c[y] << ' ';
				file1 << "不是唯一可译码\n";
			}
			else {
				for (int y = a[z]; y < N; y++)
					file1 << c[y] << ' ';
				file1 << "是唯一可译码\n";
			}
		}
		file1 << "尾随后缀集合为:";
		for (i = 0; i < sum; i++)
			file1 << f[i] << ' ';
		file1 << "\n";
		z++;
		sum = 0;
	}
}

