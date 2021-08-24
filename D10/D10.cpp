// D10.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class MyStr {
	// メンバ変数
	size_t m_size;      //文字数
	char* m_data;       //文字列
	size_t m_capacity;  //最大容量
public:
	// 定数
	static const size_t   npos = -1;
	// コンストラクタ
	MyStr();
	MyStr(const char*);
	MyStr(const MyStr&);
	// デストラクタ
	~MyStr() {
		delete[] m_data;
	}
	// 演算子
	MyStr& operator += (const char*);
	MyStr& operator += (const MyStr&);
	MyStr& operator = (const char* s);
	MyStr& operator = (const MyStr&);
	MyStr operator+(const MyStr& s2);
	MyStr operator*(const int n);
	char& operator[](const int n);
	// 各種メンバ関数

	void set(const char* s, size_t newlen);
	void print();
};

// コンストラクタ
MyStr::MyStr() {   //省略
	m_data = NULL;
	*this = "";
}
MyStr::MyStr(const char* c) {  //char* c
	m_data = NULL;
	*this = c;
}
MyStr::MyStr(const MyStr& s) {    //コピーコンストラクタ
	m_data = NULL;
	*this = s;
}
void MyStr::set(const char* s, size_t newlen) {
	char* old = m_data;
	m_size = newlen;
	if (!old || m_capacity < m_size) {
		if (!old) m_capacity = 16;
		while (m_capacity < m_size)
			m_capacity += m_capacity;
		m_data = new char[m_capacity + 1];
	}
	if (m_data != s) strcpy(m_data, s);
	if (old != m_data) delete[] old;
}
// 演算子
MyStr& MyStr::operator+=(const char* s) {
	int oldlen = m_size;
	set(m_data, m_size + strlen(s));
	strcpy(&m_data[oldlen], s);
	return *this;
}

MyStr& MyStr::operator+=(const MyStr& s) {
	int oldlen = m_size;
	set(m_data, m_size + s.m_size);

	strcpy(&m_data[oldlen], s.m_data);
	return *this;
}

MyStr& MyStr::operator=(const char* s) {
	set(s, strlen(s));
	return *this;
}

MyStr& MyStr::operator=(const MyStr& s) {
	set(s.m_data, s.m_size);
	return *this;
}
MyStr MyStr::operator+(const MyStr& s2) {
	MyStr ret = *this;
	ret += s2;
	return ret;
}
MyStr MyStr::operator*(const int n) {
	MyStr ret = *this;
	MyStr buf = *this;
	for (int i = 1; i < n; i++)
	{
		ret += buf;
	}
	return ret;
}
char& MyStr::operator[](const int n) {
	return m_data[n];
}
void MyStr::print() {
	std::cout << m_data << std::endl;
}
int main()
{
	int che;
	std::cin >> che;
	std::cout << che;

	MyStr str4 = "zap";//(4)
	str4.print();

	MyStr str5_1 = MyStr();
	MyStr str5_2("abc");
	MyStr str5_3(str4);
	str5_1.print();
	str5_2.print();
	str5_3.print();

	MyStr str6_1 = "konpeitou ";
	MyStr str6_2 = "umaibou ";
	MyStr str6_3 = "saikou";
	str6_1 += "oishii!!";
	str6_2 += str6_3;
	str6_1.print();
	str6_2.print();

	MyStr str7_1 = "koppe";
	MyStr str7_2 = "pan";
	MyStr str7_3 = str7_1 + str7_2;
	str7_3.print();

	MyStr str8_1 = "ba-ka ba-ka!!";
	MyStr str8_2 = str8_1 * 3;
	str8_2.print();

	MyStr str9 = "abcdefg";
	std::cout << str9[3] << std::endl;
	str9[3] = 'a';
	std::cout << str9[3] << std::endl;

}
