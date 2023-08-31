#include <iostream>
using namespace std;

struct ELemType {
	int value;
};
//������
typedef struct BiNode {
	ELemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//�������
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);

	}
}
void visit(BiTree T) {
	cout << T->data->value;
}
int main()
{
	char str[] = "Hello C++";

	cout << "Value of str is : " << str << endl;
}