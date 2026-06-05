#include "LinkedList.h"

LinkedList::~LinkedList()
{
    Clear();
}

void LinkedList::Add(int InData)
{
    // InData가 들어간 노드를 만든다
    // 맨 마지막으로 이동해서 맨 마지막 노드의 Next를 새 노드로 지정한다.

    // 해드가 없는 경우. Tail과 Size에 대한 처리 필요
}

void LinkedList::InsertAt(int InData, int InPosition)
{
    // InData가 들어간 노드를 만든다
    // 포지션까지 Head에서 시작해서 Next를 계속 타고 이동한다.
    // 포지션 위치에 있는 노드의 Next 주소를 새로 만든 노드의 Next에 설정
    // 포지션 위치에 있는 노드의 Next 주소에 새로 만든 노드의 주소를 저장

    // InPosition이 Size보다 크거나 같을 때. InPosition이 0일 떄
}

void LinkedList::Remove(int InData)
{
    // InData를 가진 노드가 있는지 Head부터 찾는다.
    // 찾은 노드의 앞에 있는 노드의 Next를 찾은 노드의 Next에 저장된 주소로 변경한다.
    // 찾은 노드를 delete
    
    // 맨 앞과 뒤일 때 처리. 없는 경우에 대한 처리
}

void LinkedList::RemoveAt(int InPosition)
{
}

ListNode* LinkedList::Search(int InData) const
{
    return nullptr;
}

void LinkedList::Clear()
{
    // 동적할당이 된 노드를 모두 제거한다.
}

void LinkedList::PrintList() const
{
}
