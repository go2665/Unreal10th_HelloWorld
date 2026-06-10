#include "BST.h"
#include <cstdio>

// BinarySearchTree 소멸자
BinarySearchTree::~BinarySearchTree() 
{
    DestroyTree(Root);
}

// 키 삽입
void BinarySearchTree::Insert(int InKey) 
{
    Root = InsertNode(Root, InKey);
}

// 키 검색 - 찾은 노드 반환
TreeNode* BinarySearchTree::Search(int InKey) 
{
    return SearchNode(Root, InKey);
}

// 키 삭제
void BinarySearchTree::Delete(int InKey) 
{
    Root = DeleteNode(Root, InKey);
}

// 중위 순회 출력 (정렬된 순서)
void BinarySearchTree::PrintInOrder() const 
{
    printf("InOrder: ");
    InOrderTraversal(Root);
    printf("\n");
}

// 전위 순회 출력
void BinarySearchTree::PrintPreOrder() const 
{
    printf("PreOrder: ");
    PreOrderTraversal(Root);
    printf("\n");
}

// 후위 순회 출력
void BinarySearchTree::PrintPostOrder() const 
{
    printf("PostOrder: ");
    PostOrderTraversal(Root);
    printf("\n");
}

// 트리가 비어있는지 확인
bool BinarySearchTree::IsEmpty() const 
{
    return Root == nullptr;
}

// 노드 삽입 (재귀), node는 서브 루트임
TreeNode* BinarySearchTree::InsertNode(TreeNode* InNode, int InKey) 
{
    if (InNode == nullptr) 
    {
        // 입력받은 서브루트가 null이면 새로 노드를 만든다.
        //(리턴 받은 곳에서 할당함)
        return new TreeNode(InKey);
    }

    if (InKey < InNode->Key) 
    {
        // 입력하려는게 현재 노드보다 작으면
        // 왼쪽 서브트리에 추가 시도
        // 언젠가 빈곳에 도달하면 새로 생성될태니 생성된 것을 세팅
        // (중간에 거치는 노드에서 node->Left에 같은 값을 덮어쓰는게 조금 흠)
        InNode->Left = InsertNode(InNode->Left, InKey);
    }
    else if (InKey > InNode->Key) 
    {
        InNode->Right = InsertNode(InNode->Right, InKey);
    }
    // 중복된 키는 무시

    return InNode;
}

// 노드 검색 (재귀) - 찾은 노드 반환
TreeNode* BinarySearchTree::SearchNode(TreeNode* InNode, int InKey) 
{
    if (InNode == nullptr) 
    {
        return nullptr;
    }

    if (InKey == InNode->Key) 
    {
        return InNode;
    }
    else if (InKey < InNode->Key) 
    {
        return SearchNode(InNode->Left, InKey);
    }
    else 
    {
        return SearchNode(InNode->Right, InKey);
    }
}

// 최소값 노드 찾기 (오른쪽 서브트리에서). 삭제에서 사용.
TreeNode* BinarySearchTree::FindMinNode(TreeNode* InNode) 
{
    while (InNode && InNode->Left != nullptr) 
    {
        InNode = InNode->Left;
    }
    return InNode;
}

// 노드 삭제 (재귀), node는 서브 루트임
TreeNode* BinarySearchTree::DeleteNode(TreeNode* InNode, int InKey) 
{
    if (InNode == nullptr) 
    {
        return InNode;
    }

    if (InKey < InNode->Key) 
    {
        InNode->Left = DeleteNode(InNode->Left, InKey); // (깊이 3 이상으로 예시들것)
    }
    else if (InKey > InNode->Key) 
    {
        InNode->Right = DeleteNode(InNode->Right, InKey);
    }
    else 
    {
        // 삭제할 노드를 찾음
        if (InNode->Left == nullptr) 
        {
            TreeNode* temp = InNode->Right;
            delete InNode;
            return temp;
        }
        else if (InNode->Right == nullptr) 
        {
            TreeNode* temp = InNode->Left;
            delete InNode;
            return temp;
        }

        // 두 자식이 모두 있는 경우 - 오른쪽 서브트리의 최소값으로 대체
        TreeNode* temp = FindMinNode(InNode->Right);
        InNode->Key = temp->Key;
        InNode->Right = DeleteNode(InNode->Right, temp->Key);
    }
    return InNode;
}

// 중위 순회 (재귀)
void BinarySearchTree::InOrderTraversal(const TreeNode* InNode) const 
{
    if (InNode != nullptr) 
    {
        InOrderTraversal(InNode->Left);
        printf("%d ", InNode->Key);
        InOrderTraversal(InNode->Right);
    }
}

// 전위 순회 (재귀)
void BinarySearchTree::PreOrderTraversal(const TreeNode* InNode) const 
{
    if (InNode != nullptr) 
    {
        printf("%d ", InNode->Key);
        PreOrderTraversal(InNode->Left);
        PreOrderTraversal(InNode->Right);
    }
}

// 후위 순회 (재귀)
void BinarySearchTree::PostOrderTraversal(const TreeNode* InNode) const 
{
    if (InNode != nullptr) 
    {
        PostOrderTraversal(InNode->Left);
        PostOrderTraversal(InNode->Right);
        printf("%d ", InNode->Key);
    }
}

// 트리 삭제 (재귀)
void BinarySearchTree::DestroyTree(TreeNode* InNode) 
{
    if (InNode != nullptr) 
    {
        DestroyTree(InNode->Left);
        DestroyTree(InNode->Right);
        delete InNode;
    }
}