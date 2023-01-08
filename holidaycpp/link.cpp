#include<iostream>
#define Max 20
using namespace std;
typedef struct{
    int ex;
    int c;
}polyarray[Max];
struct polynode{
    int ex;
    int c;
    polynode* next;
};
class poly{
	private:
        polynode* head;
    public:
        poly();
        ~poly();
        void createpoly(polyarray a,int n);
        void displaypoly();
        void polysort();
        void polyadd(poly B);
};
void poly::createpoly(polyarray a,int n){
    polynode *p,*r;r=head;
    for(int i=0;i<n;i++){
        p=new polynode;
        p->c=a[i].c;
        p->ex=a[i].ex;
        r->next=p;r=p;
    }
//必须创建两个指针，一个用来创建new polynode，一个用来指向已创建的位置（定位），否则创建指针时会位置丢失
}

void poly::displaypoly(){
    polynode* p;
    if(head==NULL || head->next==NULL){
        return;
    }
    if(head != NULL && head->next != NULL){
    p=head->next;
    while(p != NULL){
        cout<<p->c<<"x^"<<p->ex;
        p=p->next;
        }        
    }
}

void poly::polyadd(poly B){
    polynode *pa,*pb,*qa,*qb;//由于是单循环列表，pa用于储存当前polynode，qa用于定位上一个
    pa=head->next;pb=B.head->next;
    qa=head;qb=B.head;
    while(pa!=NULL && pb!=NULL){
        if(pa->ex<pb->ex){
            pa=pa->next;qa=qa->next;
        }
        if(pa->ex==pb->ex){
            pa->c+=pb->c;
            if(pa->c==0){
                qa->next=pa->next;delete pa;pa=qa->next;
            }
        }       
        if(pa->ex>pb->ex){
            qb->next=pb->next;
            qa->next=pb;pb->next=pa;
        }
    qa=qa->next;pa=pa->next;qb=qb->next;pb=pb->next;
    }
}

void poly::polysort(){
    polynode *p,*r,*q;
    p->head->next;
    
}
int main(){
    cout<<"hello world"<<endl;
    return 0;
}
