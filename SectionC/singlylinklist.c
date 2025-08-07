#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node * next;
}typedef Node;


Node * make_list(){
    Node * head = (Node * )malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void Display(Node * head){
    Node * temp = head;

    while(temp!= NULL){
        printf("%d ",temp->data);
    temp = temp->next;
    }
    printf("\n");
}


Node *  insert_head(Node * head,int data){
    Node * ptr = make_list();
    ptr->data = data;
    ptr->next = head;
    head = ptr;

    printf("Inserting element %d at its head-> ",data);
    Display(head);

    return head;
}

Node *  insert_tail(Node * head,int data){
    Node * temp = make_list();
    temp->data = data;

    if(head == NULL){
        head = temp;
        return head;
    }
    Node * ptr;
    ptr = head;
    while(ptr->next !=NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;

    printf("Inserting element %d at its tail-> ",data);
    Display(head);

    return head;
}


Node * delete_on_index(Node * head, int pos){
    if(head == NULL) return head;


    if(pos == 1) {
        Node * temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node * prev = head;
    int cnt = 1;

    while(prev != NULL && cnt < pos - 1) {
        prev = prev->next;
        cnt++;
    }

    // Position is invalid
    if(prev == NULL || prev->next == NULL) {
        return head;
    }

    Node * to_delete = prev->next;
    prev->next = to_delete->next;
    free(to_delete);

    printf("Deleting element at %d position->   ",pos);
    Display(head);

    return head;
}



int main(){
    // initilization
    Node * sahil = make_list();
    Node * binod = make_list();
    Node * manish = make_list();
    Node * rikesh = make_list();
    Node * saban = make_list();
    Node * kanchan = make_list();


    // connection 
    sahil->next = binod;
    binod->next = manish;
    manish->next = rikesh;
    rikesh->next = saban;
    saban->next = kanchan;

    // value
    sahil->data = 5;
    manish->data = 6;
    binod->data = 10;
    rikesh->data = 12;
    saban->data = 25;
    kanchan->data = 11;


    printf("**Current list -> \t\t   ");
    Display(sahil);

    delete_on_index(sahil,3);

    sahil = insert_head(sahil,98);
    sahil = insert_tail(sahil,98);


    return 0;
}
