#include <iostream>

using namespace std;

class List
{
public:
	List();
	~List();
    void CreateList(int Size);                          //создание списка заполненного рандомными числами
    void PrintList();                                   //вывод списка на дисплей
    void *GetHead() { return this->head; };             //получение начало списка
    void AddToEnd(int value);                           //1.добавление в конец списка
    void AddToBegining(int value);                      //2.добавление в начало списка
    void DelLast();                                     //3.удаление последнего элемента
    void DelFirst();                                    //4.удаление первого элемента
    void AddByIndex(int index, int value);              //5.добавление элемента по индексу (перед элементом по индексу) 
    int GetByIndex(int index);                          //6.получение элемента по индексу
    void DelByIndex(int index);                         //7.удаление элемента по индексу 
    int GetSize() { return Size; };                     //8.получение размера списка
    void DelAll();                                      //9.удаление всех элементов списка
    void RewriteNode(int index, int value);             //10.замена элемента по индексу на передаваемый элемент
    bool IsEmpty() { return !Size; };                   //11.проверка на пустоту списка (1 пуст, 0 нет)
    void ReverseList();                                 //12.меняет порядок элементов списка на обратный
    void InsertListFromIndex(List *SecList, int index); //13.вставка другого списка начиная с индекса
    void InsertListToEnd(List* SecList);                //14.вставка другого списка в конец
    void InsertListToBegining(List* SecList);           //15.вставка другого списка в начало
    bool IsListIn(List* Seclist);                       //16.проверка на содержание другого списка в списке, можно сделать целочисленного типа
    int FindFirstIn(List* Seclist);                     //17.поиск первого вхождения другого списка в список
    int FindLastIn(List* Seclist);                      //18.поиск последнего вхождения другого списка в список
    void SwitchByIndex(int index_a, int index_b);       //19.обмен двух элементов по индексам

private:
    struct Node 
    {
        int data;
        Node* next;

        Node(int data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }

    };
    
    Node* head;
    int Size = 0;
};

List::List()
{
    Size = 0;
    head = nullptr;
}

List::~List()
{

}

void List::CreateList(int Size)
{
    this->Size = Size;
    head = new Node(rand() % 5);
    
    Node* curr = this->head;

    for (int i = 0; i < (Size-1); i++)
    {        
        curr->next = new Node(rand() % 5);
        curr = curr->next;
    }
    
}

void List::PrintList() 
{
    Node* curr = this->head;
    for (int i = 0; i < Size; i++)
    {
        cout << i << ". " << curr->data << endl;
        curr = curr->next;
    }
    cout << endl;
}

void List::AddToEnd(int value)
{
    if (head == nullptr)
    {
        head = new Node(value);
    }
    else
    {
        Node* curr = this->head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new Node(value);
    }
    
    Size++;
}

void List::AddToBegining(int value)
{
    if (head == nullptr)
    {
        head = new Node(value);
    }
    else
    {
        Node* curr = new Node(value);
        curr->next = head;
        head = curr;
    }

    Size++;
}

void List::DelLast()
{
    if (head == nullptr)
    {
        cout << "Ошибка удаления, список пустой.";
    }
    else if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        Size--;
    }
    else
    {
        Node* curr = this->head;
        while (curr->next->next != nullptr)
        {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
        Size--;
    }
    
}

void List::DelFirst()
{
    if (head == nullptr)
    {
        cout << "Ошибка удаления, список пустой.";
    }
    else if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        Size--;
    }
    else
    {
        Node* curr = this->head;
        head = head->next;
        delete curr;
        curr = nullptr;
        Size--;
    }
}

void List::AddByIndex(int index, int value)
{
    Node* temp = this->head;
    Node* curr = this->head;

    for (int i = 0; i < (index - 1); i++)
    {
        curr = curr->next;
        temp = temp->next;
    }
    temp = temp->next;
    curr->next = new Node(value);
    curr = curr->next;
    curr->next = temp;

    Size++;
}

int List::GetByIndex(int index)
{
    Node* curr = this->head;
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    return curr->data;
}

void List::DelByIndex(int index)
{
    Node* curr = this->head;

    for (int i = 0; i < (index - 1); i++)
    {
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;

    Size--;
}

void List::DelAll()
{
    while (Size)
    {
        DelFirst();
    }
}

void List::RewriteNode(int index, int value)
{
    Node* curr = this->head;
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    curr->data = value;

}

void List::ReverseList()
{    
    if (head == nullptr) return;
    Node* prev = nullptr;
    Node* current = this->head;
    Node * next;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void List::InsertListFromIndex(List* SecList, int index)
{
    Node* curr = this->head;

    for (int i = 0; i < (index - 1); i++)
    {
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = SecList->head;

    while (curr->next) 
    {
        curr = curr->next;
    }

    curr->next = temp;
    
    Size += SecList->GetSize();
}

void List::InsertListToEnd(List* SecList)
{
    Node* curr = this->head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = SecList->head;

    Size += SecList->GetSize();
}

void List::InsertListToBegining(List* SecList)
{
    Node* curr = SecList->head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = this->head;
    this->head = SecList->head;

    Size += SecList->GetSize();
}

bool List::IsListIn(List* Seclist)
{
    if (Size < Seclist->GetSize()) { return 0; }

    Node* base = this->head;
    Node* curr = this->head;
    Node* cmpr = Seclist->head;

    do
    {
        if (curr->data == cmpr->data)
        {
            curr = curr->next;
            cmpr = cmpr->next;
        }
        else
        {
            cmpr = Seclist->head;
            curr = base->next;
            base = base->next;

        }
    } while ((cmpr && curr));
    
    return !(cmpr);

}

int List::FindFirstIn(List* Seclist)
{
    if (Size < Seclist->GetSize()) { return 0; }

    Node* base = this->head;
    Node* curr = this->head;
    Node* cmpr = Seclist->head;
    int index = 0;

    do
    {
        if (curr->data == cmpr->data)
        {
            curr = curr->next;
            cmpr = cmpr->next;
        }
        else
        {
            cmpr = Seclist->head;
            curr = base->next;
            base = base->next;
            index++;
        }
    } while ((cmpr && curr));

    if (curr)
    {
        return index;
    }
    else
    {
        return -1;
    }

}

int List::FindLastIn(List* Seclist)
{
    if (Size < Seclist->GetSize()) { return 0; }

    Node* base = this->head;
    Node* curr = this->head;
    Node* cmpr = Seclist->head;
    int index = 0;
    int buf =-1;
        
    do
    {
        
        if (!cmpr)
        {
            buf = index;
            cmpr = Seclist->head;
            curr = base->next;
            base = base->next;
            index++;
        }
        else if (curr->data == cmpr->data)
        {
            curr = curr->next;
            cmpr = cmpr->next;
        }

        else
        {
            cmpr = Seclist->head;
            curr = base->next;
            base = base->next;
            index++;
        }
        
    } while (curr);

    return buf;


}

void List::SwitchByIndex(int index_a, int index_b)
{
    if (index_a == index_b) { return; }
    Node* currA = this->head;
    Node* currB = this->head;

    for (int i = 0; i < index_a; i++)
    {
        currA = currA->next;
    }

    for (int i = 0; i < index_b; i++)
    {
        currB = currB->next;
    }
    
    int buf = currA->data;
    currA->data = currB->data;
    currB->data = buf;

}


void main() 
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    
    int index, n;
    char c;
    List MyList;
    List NewList;

    do
    {
        system("cls");

        if (MyList.GetHead() != nullptr)
        {
            cout << "Ваш список:" << endl;
            MyList.PrintList();
        }
        
        cout << "\nВыберите действие:" << endl
            << "0 - Заполнить список псевдослучайными числами" << endl
            << "1 - Добавление в конец списка" << endl
            << "2 - Добавление в начало списка" << endl
            << "3 - Удаление последнего элемента" << endl
            << "4 - Удаление первого элемента" << endl
            << "5 - Добавление элемента по индексу" << endl
            << "6 - Получение элемента по индексу" << endl
            << "7 - Удаление элемнета по индексу" << endl
            << "8 - Получение размера списка" << endl
            << "9 - Удаление всех элементов списка" << endl
            << "10 - Замена элемента по индексу на передаваемый элемент" << endl
            << "11 - Проверка на пустоту списка" << endl
            << "12 - Замена порядка элементов в списке на обратный" << endl
            << "13 - Вставка другого списка в список, начиная с индекса" << endl
            << "14 - Вставка другого списка в конец" << endl
            << "15 - Вставка другого списка в начало" << endl
            << "16 - Проверка на содержание другого списка в списке" << endl
            << "17 - Поиск первого вхождения другого списка в список" << endl
            << "18 - Поиск послдеднего вхождения списка по индексам" << endl
            << "19 - Обмен двух элемнетов списка по индексам" << endl
            << "20 - Выйти из редактора" << endl
            << "> ";
        int menu;

        do
        {
            cin >> menu;
            switch (menu)
            {
                case 0:
                {
                    cout << "Введите кличество элементов списка > ";
                    cin >> n;
                    MyList.CreateList(n);
                    break;
                }

                case 1:
                {
                    cout << "Введите значение элемента > ";
                    cin >> n;
                    MyList.AddToEnd(n);
                    break;
                }

                case 2:
                {
                    cout << "Введите значение элемента > ";
                    cin >> n;
                    MyList.AddToBegining(n);
                    break;
                }

                case 3:
                {
                    MyList.DelLast();
                    break;
                }

                case 4:
                {
                    MyList.DelFirst();
                    break;
                }

                case 5:
                {
                    cout << "Введите значение элемента > ";
                    cin >> n;
                    cout << "Введите индекс > ";
                    cin >> index;
                    MyList.AddByIndex(index,n);
                    break;
                }

                case 6:
                {
                    cout << "Введите индекс > ";
                    cin >> index;
                    cout << MyList.GetByIndex(index) << endl;                    
                    break;
                }

                case 7:
                {
                    cout << "Введите индекс > ";
                    cin >> index;
                    MyList.DelByIndex(index);
                    break;
                }

                case 8:
                {
                    cout << "Размер списка: " << MyList.GetSize() << endl;
                    break;
                }

                case 9:
                {
                    MyList.DelAll();
                    break;
                }

                case 10:
                {
                    cout << "Введите значение элемента > ";
                    cin >> n;
                    cout << "Введите индекс > ";
                    cin >> index;
                    MyList.RewriteNode(index, n);
                    break;
                }

                case 11:
                {
                    if (MyList.IsEmpty())
                    {
                        cout << "Cписок пустой" << endl;
                        
                    }
                    else
                    {
                        cout << "Cписок не пустой" << endl;
                    }

                    break;
                }

                case 12:
                {
                    MyList.ReverseList();
                    break;
                }

                case 13:
                {
                    cout << "Введите кличество элементов нового списка > ";
                    cin >> n;
                    NewList.CreateList(n);
                    cout << "Ваш второй список:" << endl;
                    NewList.PrintList();
                    cout << "Введите индекс > ";
                    cin >> index;
                    MyList.InsertListFromIndex(&NewList, index);
                    break;
                }

                case 14:
                {
                    cout << "Введите кличество элементов нового списка > ";
                    cin >> n;
                    NewList.CreateList(n);
                    cout << "Ваш второй список:" << endl;
                    NewList.PrintList();
                    MyList.InsertListToEnd(&NewList);
                    break;
                }

                case 15:
                {
                    cout << "Введите кличество элементов нового списка > ";
                    cin >> n;
                    NewList.CreateList(n);
                    cout << "Ваш второй список:" << endl;
                    NewList.PrintList();
                    MyList.InsertListToBegining(&NewList);
                    break;
                }

                case 16:
                {
                    cout << "Введите кличество элементов нового списка > ";
                    cin >> n;
                    NewList.CreateList(n);
                    cout << "Ваш второй список:" << endl;
                    NewList.PrintList();
                    
                    if (MyList.IsListIn(&NewList))
                    {
                        cout << "Второй список содержится в первом списке" << endl;
                    }
                    else
                    {
                        cout << "Второй список не найден в первом списке" << endl;
                    }
                    break;
                }

                case 17:
                {
                    cout << "Введите кличество элементов нового списка > ";
                    cin >> n;
                    NewList.CreateList(n);
                    cout << "Ваш второй список:" << endl;
                    NewList.PrintList();

                    cout << "Первое вхождение второго списка в первый по индексу - " << MyList.FindFirstIn(&NewList) << endl;

                    break;
                }

                case 18:
                {
                    cout << "Введите кличество элементов нового списка > ";
                    cin >> n;
                    NewList.CreateList(n);
                    cout << "Ваш второй список:" << endl;
                    NewList.PrintList();

                    cout << "Последнее вхождение второго списка в первый по индексу - " << MyList.FindLastIn(&NewList) << endl;

                    break;
                }

                case 19:
                {
                    cout << "Введите первый индекс > ";
                    cin >> index;
                    cout << "Введите второй индекс > ";
                    cin >> n;

                    MyList.SwitchByIndex(index, n);

                    break;
                }

                case 20:

                    break;

                default:
                    cout << "Такого пункта нет. Выберите один из представленных выше\n> ";
                    break;
            }

        } while (menu < 0 || menu > 20);

        
        cout << "Продолжить работу? y/n -->";
        cin >> c;
    } while (c == 'y' || c == 'Y');


    cout << endl << endl;
    system("pause");
}
