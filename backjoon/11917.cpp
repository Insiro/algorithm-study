#include <iostream>
using namespace std;
typedef struct structe
{
    int data;
    struct structe *next;
} st;
#define size sizeof(st)
st *head;
st *temp;
int main()
{
    head = (st *)malloc(size);
    head->next = NULL;
    int mount, count = 0, data, t = 0;
    cin >> mount;
    for (int i = 0; i < mount; i++)
    {
        cin >> data;
        t = 0;
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            if (data != temp->data)
                continue;
            t = 1;
            break;
        }
        if (t == 0)
        {
            temp->next = (st *)malloc(size);
            temp->next->data = data;
            temp->next->next = NULL;
            count++;
        }
    }
    cin >> t;
    for (int i = mount + 1; i < t; i++)
    {
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            if (count == temp->data)
            {
                i = t;
                break;
            }
        }
        if (count != temp->data)
        {
            temp->next = (st *)malloc(size);
            temp = temp->next;
            temp->data = count;
            temp->next = NULL;
            count++;
        }
    }
    cout << count;
}