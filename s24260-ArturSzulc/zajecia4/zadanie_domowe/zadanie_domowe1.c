#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int number;
    struct Node *next;
} NodeType;

void show(NodeType *head);
int listSize(NodeType *head);
void pushFront(NodeType **head, int number);
void pushBack(NodeType **head, int number);
void popFront(NodeType **head);
void popBack(NodeType **head);

int main()
{
    NodeType *head;
    head = (NodeType *)malloc(sizeof(NodeType)); //zapisujemy adres nowego elementu head
    head = NULL; //ustawiamy go na null

    int option, number;

    while(1)
    {
        printf("\nAktualny stan listy: ");
        show(head);

        printf("\n\nWybierz z opcji co chcialbyc zrobić: \n");
        printf("1. Dodaj na poczatek listy.\n");
        printf("2. Dodaj na koniec listy.\n");
        printf("3. Usun z poczatku listy.\n");
        printf("4. Usun z konca listy.\n");
        printf("5. Wyswietl liczbe wierszy. \n");
        printf("0. Zakoncz program.\n");

        scanf("%i", &option);

        switch (option)
        {
            case 0:
		free(head);
                return 0;
            case 1:
                printf("Wpisz liczbe jaka chcesz dodac: ");
                scanf("%i", &number);
                pushFront(&head, number);
                break;
            case 2:
                printf("Wpisz liczbe jaka chcesz dodac: ");
                scanf("%i", &number);
                pushBack(&head, number);
                break;
            case 3:
                popFront(&head);
                break;
            case 4:
                popBack(&head);
                break;
            case 5:
                listSize(head);
                break;
            default:
                printf("Podaj wlasciwa opcje.");
                break;
        }
    }
}

void pushFront(NodeType **head, int number) {
    NodeType *current;  //nowy element liczby
    current = (NodeType *)malloc(sizeof(NodeType)); //adres nowego elementu

    current->number = number; //umieszczamy dane w elemencie
    current->next = (*head); // kolejnym elementem bedzie akualny head
    *head = current; // head ustawiamy na nasz stworzony element
}

void pushBack(NodeType **head, int number) {
    if (*head == NULL) { //jesli aktualnie nie ma elementów czyli head = null to instrukcja:
        *head = (NodeType *) malloc(sizeof(NodeType)); //zapisujemy adres nowego elementu head
        (*head)->number = number; //wartosc
        (*head)->next = NULL; // kolejnym bedzie null bo on jest ostatni
    } else {
        NodeType *current = *head; // tworzymy zmienna current która ma adres head

        while (current->next != NULL) { // przechodzimy do ostaniego elementu
            current = current->next;
        }

        current->next = (NodeType *) malloc(sizeof(NodeType)); //dodajemy jego pamiec
        current->next->number = number; // wartosc
        current->next->next = NULL; // ustawiamy next jako null;
    }
}

void show(NodeType *head)
{
    printf("\n");
    if(head == NULL) {
        printf("List is empty");
    } else {
        NodeType *current = head;

        do {
            printf("%i", current->number);
            printf("\n");
            current = current->next;
        } while (current != NULL);
    }
}

int listSize(NodeType *head)
{
    int counter = 0;
    if(head == NULL) {
        return counter;
    } else {
        NodeType *current=head;
        do {
            counter++;
            current = current->next;
        } while (current != NULL);
    }

    return counter;
}

void popFront(NodeType **head)
{
    NodeType * tmp = NULL; // tworzymy pusty element

    if (*head != NULL) { //sprawdzamy czy head nie jest puste
        tmp = (*head)->next; //zapisujemy nastepny element
        free(*head); //usuwamy head'a
        *head = tmp; //nowym headem bedzie ten który zapisalismy do zmiennej tymczasowej
    }
}

void popBack(NodeType **head)
{
    if((*head)->next == NULL) { // sprawdzamy czy nastepny element jest null
        *head = NULL; // jesli tak to ustawiamy head na null
    } else {
        NodeType *current = *head; //jesli nie to tworzymy zmianna pomocnicza która ma adres aktualnego heada 

        while (current->next->next != NULL) { //iterujemy do ostatniego elementu
            current = current->next; // zmienna tymczasowa to aktualnie ostatni element
        }

        free(current->next); // usuwamy go
        current->next = NULL; // ustawiamy na null
    }
}

