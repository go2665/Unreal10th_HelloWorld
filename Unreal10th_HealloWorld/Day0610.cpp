#include "Day0610.h"
#include "BitFlag.h"
#include "BST.h"

void Day0610::TestMain()
{
	//TestTemplateClass();
    TestTree();
}

void Day0610::TestTemplateClass()
{
	TestEnumClass Test1 = TestEnumClass::Up;
	TestEnumClass Test2 = TestEnumClass::Down;
	TestEnumClass Test3 = Test1 | Test2;
	//TestEnumClass Test4 = Test1 & Test2;

	Calculator Calc;

	auto Sum = Calc.Add(10, 2.5);

	//auto Div = Calc.Divide(5, 0);
	int i = 0;
}

void Day0610::TestTree()
{
    BinarySearchTree bst;

    // 데이터 삽입
    printf("=== BST 삽입 ===\n");
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        bst.Insert(values[i]);
        printf("%d 삽입\n", values[i]);
    }

    // 순회 출력
    printf("\n=== 순회 결과 ===\n");
    bst.PrintInOrder();
    bst.PrintPreOrder();
    bst.PrintPostOrder();

    // 검색
    printf("\n=== 검색 ===\n");
    int searchKeys[] = { 40, 25, 80, 100 };
    int searchSize = sizeof(searchKeys) / sizeof(searchKeys[0]);

    for (int i = 0; i < searchSize; i++) {
        TreeNode* found = bst.Search(searchKeys[i]);
        if (found != nullptr) {
            printf("%d: 찾음 (노드 주소: %p)\n", searchKeys[i], found);
        }
        else {
            printf("%d: 없음\n", searchKeys[i]);
        }
    }

    // 삭제
    printf("\n=== 삭제 ===\n");
    int deleteKeys[] = { 20, 30, 50 };
    int deleteSize = sizeof(deleteKeys) / sizeof(deleteKeys[0]);

    for (int i = 0; i < deleteSize; i++) {
        printf("%d 삭제\n", deleteKeys[i]);
        bst.Delete(deleteKeys[i]);
        bst.PrintInOrder();
    }
}

