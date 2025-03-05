#include <iostream>
#include <functional>
#include <cstdlib>
#include <ctime>

namespace lst {
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    // basic functions

    void push_back(Node* sent, int data){
        Node* α = new Node;
        α->data = data;
        α->prev = sent->prev;
        α->next = sent;
        sent->prev->next = α;
        sent->prev = α;
    }

    void push_front(Node* sent, int data){
        Node* α = new Node;
        α->data = data;
        α->prev = sent;
        α->next = sent->next;
        α->next->prev = α;
        sent->next = α;
    }

    void list_remove_element(Node* sent, int index){
        Node* α = sent->next;
        int β = 0;
        while (α != sent){
            if (β != index){++β; α = α->next;}
            else {
                α->prev->next = α->next;
                α->next->prev = α->prev;
                delete α;
                break;
            }
        }
    }

    void list_clear(Node* sent){
        Node* α = sent->next;
        while (α != sent){
            Node* β = α;
            α = α->next;
            delete β;
        }
    }

    void print_list(Node* sent){
        Node* α = sent->next;
        while(α != sent){
            std::cout << α->data << ' ';
            α = α->next;
        }
        std::cout << std::endl;
    }

    //custom functions

    bool IsPrime(int α){
        for (int i=2; i*i<=α; i++){
            if (α%i == 0) return false;
        }
        return α>1;
    }

    void list_delete_mults15(Node* sent){
        Node* α = sent->next;
        while (α != sent){
            if (α->data %15 == 0){
                Node* β = α;
                α->next->prev = α->prev;
                α->prev->next = α->next;
                α = α->next;
                delete β;
            }
            else {α = α->next;}
        }
    }

    void dub_prime_numbers(Node* sent){
        Node* α = sent->next;
        while (α != sent){
            if (IsPrime(α->data)){
                Node* β = new Node;
                β->data = α->data;
                β->next = α->next;
                α->next = β;
                α = β->next;
            }
            else {α = α->next;}
        }
    }

    int get_first_digit(int α){
        while (α >= 10){
            α /= 10;
        }
        return α;
    }

    //merge sort
    
    Node* merge(Node* alpha, Node* beta, std::function<bool(Node* x, Node* y)> func){
        Node* α = alpha->next;
        Node* β = beta->next;
        
        while (α != alpha && β != beta){
            if (func(α, β)){
                α = α->next;
            } 
            else {
                α->prev->next = β;
                β->prev = α->prev;
                α->prev = β;
                β = β->next;
                α->prev->next = α;
            }
        }

        if (β != beta) {
            alpha->prev->next = β; 
            β->prev = alpha->prev; 
            beta->prev->next = alpha; 
            alpha->prev = beta->prev;
        }
        
        delete beta;
        return alpha;
    }

    Node* MergeSort(Node* sent, std::function<bool(Node* x, Node* y)> func = [](Node* x, Node* y){return x->data < y->data;}){
        if (sent->next->next == sent) return sent;

        Node* middle = sent->next;
        Node* last = sent->next;
        while (last->next != sent && last->next->next != sent){
            middle = middle->next;
            last = last->next->next;
        }

        Node* sent2 = new Node;
        sent2->next = middle->next;
        sent2->prev = sent->prev;
        sent2->next->prev = sent2;       
        middle->next = sent;
        sent->prev->next = sent2;        
        sent->prev = middle;

        return merge(MergeSort(sent, func), MergeSort(sent2, func), func);
    }
}

using namespace lst;

int main(){
    Node* list = new Node;
    list->prev = list;
    list->next = list;

    const int N = 7;
    srand(time(0)); for (int i=0; i<N; i++){ push_back(list, rand()); };;
    print_list(list);

    // sort if not sorted
    int direction = 0;
    for (Node* i=list->next; i->next!=list; i = i->next){
        if (i->data == i->next->data) {continue;}
        else if (direction == 0) {direction = (i->data < i->next->data) ? 1 : -1; continue;}
        else if (i->data < i->next->data && direction == -1) {direction = 7; break;} // if true - not sorted
        else if (i->data > i->next->data && direction == 1) {direction = 7; break;}
    }
    std::cout << direction << std::endl;
    if (direction != 7) {list_delete_mults15(list); dub_prime_numbers(list);}
    if (direction == 7) list = MergeSort(list, [](Node* x, Node* y){return get_first_digit(x->data) >= get_first_digit(y->data);});
    print_list(list);

    list_clear(list);
    delete list;
    return 0;
}