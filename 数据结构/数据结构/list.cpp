#include <iostream>
using namespace std;
class SqList {
private:
	static const int Maxsize = 100;
	int a[Maxsize];
	int Length;
public:
	//顺序表初始化
	SqList() {
		InitList();
	}
	void InitList() {
		Length = 0;
	};
	//表长
	int GetLength() {
		return Length;
	};
	//按值查找
	int LocateELem(int e) {
		for (int i = 0; i < Length; i++) {
			if (a[i] == e) {
				return i+1;
			}
		}
		cout << "无对应元素" << endl;
	}
	//按位查找
	int GetElem(int i) {
		return a[i - 1];
	}
	//插入操作
	bool ListInsert(int i, int e) {
		if (i<1 || i>Length + 1)
			return false;
		if (Length >= Maxsize)
			return false;
		for (int j = Length; j >= i; j--) {
			a[j] = a[j - 1];
		}
		a[i - 1] = e;
		Length++;
		return true;
		
	}
	//删除操作
	bool ListDelete(int i) {
		if (IsEmpty())
			return false;
		if (i<1 || i>Length)
			return false;
		for (int j = i; j <= Length; j++) {
			a[j - 1] = a[j];
		}
		Length--;
		return false;
	}
	//输出操作
	void PrintList() {
		if (IsEmpty()){
			cout << "栈为空" << endl;
		}
		for (int i = 0; i < Length; i++)
		{
			cout << a[i]<<" ";
		}
	}
	//判空
	bool IsEmpty() {
		if (Length == 0) { return true; }
		else { return false; }
		
	}
	//销毁
	void DestoryList() {
		delete[]a;
	}
};
void SqListTest() {
	SqList s;
	s.ListInsert(1, 1);
	s.ListInsert(1, 3);
	s.ListInsert(2, 6);
	s.ListDelete(2);
	cout << s.GetLength()<<endl;
	s.PrintList();
}
class LinkList {

};
typedef struct {
	char data[100];
	int top;
}SqStack;

int main()
{
	cout<<isValid("(]");
}

