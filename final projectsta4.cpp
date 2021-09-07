#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int a[10][10],m,o,m1,o1,d,e,s,count1;
void display2();

struct node
{
    int data;
    int data1;
    struct node *next;
};
struct node *top=NULL;
void push(int m2,int n2)
{
    struct node *curr;

    curr=(struct node*)malloc(sizeof(struct node));
    curr->data=m2;
    curr->data1=n2;
    curr->next=top;
    top=curr;

}

void pop(){
  struct node *temp;
    temp=top;
    top=temp->next;
    free(temp);
}

void take(){
    int i,j;
    cout<<"Enter size of array :"<<endl;
    cin>>s;
    display2();
    cout<<"Enter path "<<endl;
     for(int i=0;i<s*s;i++)
    {
        cin>>i>>j;
         if(i==-1||j==-1){
            break;}
            if(i<s&&j<s)
        a[i][j]=1;
        else
        {
            cout<<"Cannot take "<<endl;
            i--;
            }

    }
    cout<<"Enter Source"<<endl;
    cin>>m>>o;
    cout<<"Enter Destination :"<<endl;
    cin>>d>>e;
   // a[d][e]=20;
}

void copy_()
{
    if(top!=NULL){
        m=top->data;
        o=top->data1;
    }
    if(top==NULL){
        m=s;
        o=s;
    }
}

void move_()
{
   // i=m;j=o;
    if(m<s&&o<s){
        if(m==d&&o==e){
            cout<<"Rat can go"<<endl;
            a[m][o]=20;
            cout<<"Here 20 is Destination "<<endl;
            count1=8;
        }

        else{
            if (a[m][o]==1){
                a[m][o]=2;
                push(m,o);
                m=m;
                o=o;
                move_();
            }

            else if(a[m][o+1]==1||a[m][o+1]==20){
                if(o<s-1){
                    o=o+1;
                    m=m;
                }
                move_();
               // copy_();
            }

            else if(a[m+1][o]==1||a[m+1][o]==20){
                   // push(m+1,o);
                if(m<s-1){
                    m=m+1;o=o;
                }
                move_();

            }

            else if(a[m][o-1]==1||a[m][o-1]==20){
                o=o-1;
                m=m;
                move_();
            //    copy_();
            }

            else if(a[m-1][o]==1||a[m-1][o]==20){
                o=o;
                m=m-1;
                move_();
              //  copy_();
            }

            else if(a[m+1][o+1]==1){
                o=o+1;
                m=m+1;
                move_();
             //   copy_();
            }

            else if(a[m+1][o-1]==1){

                o=o-1;
                m=m+1;
                move_();
              //  copy_();
            }

            else if(a[m-1][o-1]==1){

                o=o-1;
                m=m-1;
                move_();
               // copy_();
            }

            else if(a[m-1][o+1]==1){

                o=o+1;
                m=m-1;
                move_();
                //copy_();
            }

            else{
                a[m][o]=3;
                pop();
                copy_();
                move_();
            }
        }
    }
}
/*void display()
{
    struct node *temp;
    temp=top;

    while(temp!=NULL){
        printf("%d ",temp->data);
        printf("%d ",temp->data1);
        cout<<endl;
        temp=temp->next;
    }
}*/

void display2(){
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){

    take();
    if(a[m][o]==1){
        move_();
    }
    else
        cout<<"Source is not on the path...!!!"<<endl;
   // display();
   if(count1!=8){
       cout<<"Rat Cannot go...!!!"<<endl;
       a[d][e]=20;
       cout<<"Here 20 is destination "<<endl;
      // a[d][e]=20;
   }
    display2();
    return 0;
}


