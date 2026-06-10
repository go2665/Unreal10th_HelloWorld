#pragma once
#pragma once

struct TreeNode {
    int Key = 0;
    TreeNode* Left = nullptr;
    TreeNode* Right = nullptr;

    TreeNode(int key) : Key(key) {}
};

class BinarySearchTree {
public:
    // 생성자
    BinarySearchTree() = default;

    // 소멸자
    ~BinarySearchTree();

    // 키 삽입
    void Insert(int InKey);

    // 키 검색 - 찾은 노드 반환
    TreeNode* Search(int InKey);

    // 키 삭제
    void Delete(int InKey);

    // 중위 순회 출력 (정렬된 순서)
    void PrintInOrder() const;

    // 전위 순회 출력
    void PrintPreOrder() const;

    // 후위 순회 출력
    void PrintPostOrder() const;

    // 트리가 비어있는지 확인
    bool IsEmpty() const;

private:
    TreeNode* Root = nullptr;

    // 노드 삽입 (재귀)
    TreeNode* InsertNode(TreeNode* InNode, int InKey);

    // 노드 검색 (재귀) - 찾은 노드 반환
    TreeNode* SearchNode(TreeNode* InNode, int InKey);

    // 최소값 노드 찾기 (오른쪽 서브트리에서)
    TreeNode* FindMinNode(TreeNode* InNode);

    // 노드 삭제 (재귀)
    TreeNode* DeleteNode(TreeNode* InNode, int InKey);

    // 중위 순회 (재귀)
    void InOrderTraversal(const TreeNode* InNode) const;

    // 전위 순회 (재귀)
    void PreOrderTraversal(const TreeNode* InNode) const;

    // 후위 순회 (재귀)
    void PostOrderTraversal(const TreeNode* InNode) const;

    // 트리 삭제 (재귀)
    void DestroyTree(TreeNode* InNode);
};

