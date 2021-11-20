// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <Windows.h>
#define MAX_TF_S 4
#define TF_MIN 1
#define TF_MAX 13
using namespace std;
class s
{
	public:
		int a, b;
		void out()
		{
			cout << a << "/" << b << endl;
		}
		void f()
		{
			if (a == 0)
			{
				return;
			}
			int m = b, n = a;
			int m0 = m, n0 = n;
			while (m % n != 0)
			{
				int temp = m;
				m = n;
				n = temp % n;
			}
			a = n0 / n;
			b = m0 / n;
		}
		bool z()
		{
			if (double(a) / double(b) == a / b)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};
s operator+(s a, s b)
{
	s r;
	r.a = a.a * b.b + a.b * b.a;
	r.b = a.b * b.b;
	r.f();
	return r;
}
s operator-(s a, s b)
{
	s r;
	r.a = a.a * b.b - a.b * b.a;
	r.b = a.b * b.b;
	r.f();
	return r;
}
s operator*(s a, s b)
{
	s r;
	r.a = a.a * b.a;
	r.b = a.b * b.b;
	r.f();
	return r;
}
s operator/(s a, s b)
{
	s r;
	r.a = a.a * b.b;
	r.b = a.b * b.a;
	r.f();
	return r;
}
string operator+(string a, s b)
{
	stringstream su;
	string bb;
	if (b.z())
	{
		su << b.a / b.b;
	}
	else
	{
		su << "(" << b.a << "/" << b.b << ")";
	}
	su >> bb;
	return a + bb;
}
class tf
{
	private:
		s d[MAX_TF_S];
		int ss = 0;
		string answer[10000];
	public:
		void get()
		{
			for (int i = 0; i < MAX_TF_S; i++)
			{
				cin >> d[i].a;
				d[i].b = 1;
			}
		}
		void set(int* dd)
		{
			for (int i = 0; i < MAX_TF_S; i++)
			{
				d[i].a = dd[i];
				d[i].b = 1;
			}
		}
		void ran()
		{
			srand(time(0));
			for (int i = 0; i < MAX_TF_S; i++)
			{
				d[i].a = rand()% TF_MAX + TF_MIN;
				d[i].b = 1;
			}
			cout << "随机到的数字是：";
			for (int i = 0; i < MAX_TF_S; i++)
			{
				cout << d[i].a << " ";
			}
			cout << endl;
		}
		bool check(string ans)
		{
			for (int i = 0; i < ss; i++)
			{
				if (answer[i] == ans)
				{
					return false;
				}
			}
			return true;
		}
		void make(s* dd,int l,string ans)
		{
			if (l == 1)
			{
				if (dd[0].b * 24 == dd[0].a and ans.find("--") == -1 and ans.find("=-") == -1 and check(ans))
				{
					cout << ans << endl;
					answer[ss] = ans;
					ss++;
				}
				return;
			}
			for (int i = 0; i < l; i++)
			{
				for (int j = 0; j < l; j++)
				{
					if (i == j)
					{
						continue;
					}
					s sss[MAX_TF_S];
					int ssss = 0;
					for (int k = 0; k < l; k++)
					{
						if (k != i and k != j)
						{
							sss[ssss] = dd[k];
							ssss++;
						}
					}
					sss[ssss] = dd[i] - dd[j];
					make(sss, l - 1, ans + dd[i] + "-" + dd[j] + "=" + sss[ssss] + "\n");
					if (dd[j].a)
					{
						sss[ssss] = dd[i] / dd[j];
						make(sss, l - 1, ans + dd[i] + "/" + dd[j] + "=" + sss[ssss] + "\n");
					}
				}
			}
			for (int i = 0; i < l; i++)
			{
				for (int j = i+1; j < l; j++)
				{
					s sss[MAX_TF_S];
					int ssss = 0;
					for (int k = 0; k < l; k++)
					{
						if (k != i and k != j)
						{
							sss[ssss] = dd[k];
							ssss++;
						}
					}
					sss[ssss] = dd[i] + dd[j];
					make(sss, l - 1, ans + dd[i] + "+" + dd[j] + "=" + sss[ssss] + "\n");
					sss[ssss] = dd[i] * dd[j];
					make(sss, l - 1, ans + dd[i] + "*" + dd[j] + "=" + sss[ssss] + "\n");
				}
			}
		}
		void start()
		{
			make(d, MAX_TF_S, "");
			if (ss == 0)
			{
				cout << "无解！" << endl;
			}
		}
};
int main()
{
	while (true)
	{
		tf x;
		x.get();
		system("pause>nul");
		x.start();
		system("pause>nul");
		system("cls");
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
