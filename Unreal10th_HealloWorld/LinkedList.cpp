#include <iostream>
#include "LinkedList.h"
#include "BattleShip.h"

LinkedList::~LinkedList()
{
    Clear();
}

void LinkedList::Add(int InData)
{
    // InData가 들어간 노드를 만든다
    ListNode* NewNode = new ListNode(InData);

    if (Head == nullptr)
    {
        // 처음 넣을 때
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        // 맨 마지막으로 이동해서 맨 마지막 노드의 Next를 새 노드로 지정한다.
        Tail->Next = NewNode;
        Tail = NewNode;
    }

    Size++;

    // 해드가 없는 경우. Tail과 Size에 대한 처리 필요
}

void LinkedList::InsertAt(int InData, int InPosition)
{
    if (InPosition > Size)
    {
        InPosition = Size;
    }
    if(InPosition == Size)
    { 
        Add(InData);    // 어차피 마지막에 추가할거면 Tail을 활용하는게 빠르다.
        return;
    }

    // InData가 들어간 노드를 만든다
    ListNode* NewNode = new ListNode(InData);
    if (InPosition == 0)
    {
        NewNode->Next = Head;
        Head = NewNode;
    }
    else
    {
        // 포지션까지 Head에서 시작해서 Next를 계속 타고 이동한다.
        ListNode* PrevNode = Head;
        ListNode* Current = Head;
        for (int i = 0; i < InPosition; i++)
        {
            PrevNode = Current;
            Current = Current->Next;
        }
        PrevNode->Next = NewNode;   // 포지션 위치에 있는 노드의 앞노드의 Next 주소를 새로 만든 노드로 설정
        NewNode->Next = Current;    // 새 노드의 다음 주소를 포지션 위치에 있는 노드의 주소로 설정
    }
    Size++;
}

void LinkedList::Remove(int InData)
{
    if (Head == nullptr)
        return;

    // InData를 가진 노드가 있는지 Head부터 찾는다.
    ListNode* NodeToDelete = nullptr;
    ListNode* PrevNode = nullptr;

    if (Head->Data == InData)
    {
        NodeToDelete = Head;
        Head = Head->Next;
        if (Head == nullptr)
        {
            Tail = nullptr;
        }
    }
    else
    {
        PrevNode = Head;
        while (PrevNode->Next != nullptr && PrevNode->Next->Data != InData)
        {
            // 찾는 데이터를 가진 노드의 앞노드 찾기
            PrevNode = PrevNode->Next;
        }

        if (PrevNode->Next != nullptr)
        {
            // 찾은 노드의 앞에 있는 노드의 Next를 찾은 노드의 Next에 저장된 주소로 변경한다.
            NodeToDelete = PrevNode->Next;
            PrevNode->Next = NodeToDelete->Next;
            if (NodeToDelete == Tail)
            {
                Tail = PrevNode;
            }
        }
    }

    if (NodeToDelete != nullptr)
    {
        // 찾은 노드를 delete
        delete NodeToDelete;
        NodeToDelete = nullptr;
        Size--;
    }
    else
    {
        printf("오류 : %d 값을 가진 노드가 없습니다.\n", InData);
    }
}

void LinkedList::RemoveAt(int InPosition)
{
    if (InPosition >= Size)
    {
        printf("오류 : %d 위치는 리스트의 범위를 벗어납니다.(현재 크기:%d)\n", InPosition, Size);
        return;     //위치가 없는 경우는 그냥 종료
    }

    ListNode* NodeToDelete = nullptr;
    if (InPosition == 0)
    {
        // 특수 처리(맨 앞이다)
        NodeToDelete = Head;
        Head = Head->Next;
        if (Head == nullptr)
        {
            Tail = nullptr;
        }
    }
    else
    {
        // 위치 찾기
        ListNode* PrevNode = Head;
        int TargetIndex = InPosition - 1;       // 지울 노드의 앞쪽노드(PrevNode)까지 가기 위해서
        for (int i = 0; i < TargetIndex; i++)
        {
            PrevNode = PrevNode->Next;
        }
        NodeToDelete = PrevNode->Next;
        PrevNode->Next = NodeToDelete->Next;    // 찾은 노드 앞 노드의 Next를 찾은 노드의 Next로 변경
        if (NodeToDelete == Tail)
        {
            //PrevNode->Next = nullptr;
            Tail = PrevNode;
            Tail->Next = nullptr;
        }
    }
    // 찾은 노드 delete
    delete NodeToDelete;
    NodeToDelete = nullptr;
    Size--; 
}

ListNode* LinkedList::Search(int InData) const
{
    // InData와 같은 값을 가지는 노드 찾기
    ListNode* Current = Head;
    while (Current != nullptr)
    {
        if (Current->Data == InData)
        {
            break;
        }
        Current = Current->Next;
    }
    return Current;
}

void LinkedList::Clear()
{
    // 동적할당이 된 노드를 모두 제거한다.
    while (Head)
    {
        RemoveAt(0);
    }
}

void LinkedList::PrintList() const
{
    // 리스트 Head부터 Tail까지 출력하는 함수
    if (Head == nullptr && Size == 0)
    {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    printf("리스트(크기:%d) : ", Size);
    ListNode* Current = Head;
    while (Current != nullptr)
    {
        printf("%d -> ", Current->Data);
        Current = Current->Next;
    }
    printf("nullptr\n");
}
