/*
BY:ADITYA KUMAR  
Topic: EXPRESSION TREE
*/

#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
     struct node*right,*left;
};
class exptree{
public:
     node* exptrepost(string s)
     {
        node*top,*t1,*t2,*t3;
        stack<node*> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<='z' && s[i]>='a'  )
            {
                top=new node();
                top->left=NULL;
                top->right=NULL;
                top->data=s[i];
                st.push(top);
            }
            else{
                t1=st.top();
                st.pop();
                t2=st.top();
                st.pop();
                top=new node();
               top->data=s[i];
               top->left=t2;
               top->right=t1;
               st.push(top);
            }
        }
        t3=st.top();
        return t3;
    }
    node*exptrepre(string s){
        reverse(s.begin(),s.end());
        node*top,*t1,*t2,*t3;
        stack<node*> st1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z'){
                top=new node();
                top->data=s[i];
                top->left=NULL;
                top->right=NULL;
                st1.push(top);
            }
            else{
                
                t1=st1.top();
                st1.pop();
                t2=st1.top();
                st1.pop();
                top=new node();
                top->data=s[i];
                top->left=t1;
                top->right=t2;
                st1.push(top);
            }
        }
    
        t3=st1.top();
        return t3;
    }
    void inoder(node*x){
        if(x!=NULL){
            inoder(x->left);
            cout<<x->data;
            inoder(x->right);
        }
    }
    void preoder(node*x){
        if(x!=NULL){
            cout<<x->data;
            preoder(x->left);
            preoder(x->right);
        }
    }
    void post(node*x){
        if(x!=NULL){
            post(x->left);
            post(x->right);
            cout<<x->data;
        }
    }
    void inoder_nr(node*x){
        stack<node*> s;
        node*temp=x;
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        while(!s.empty())
        {
            node*t=new node();
            t=s.top();
            s.pop();
            cout<<t->data;
            t=t->right;
            while(t!=NULL)
            {
                s.push(t);
                t=t->left;
            }

        }
    }
    void preoder_nr(node*x){
        stack<node*> s;
        node*temp=x;
        while(temp!=NULL){
            cout<<temp->data;
            s.push(temp);
            temp=temp->left;
        }
        while(!s.empty()){
            node*t=new node();
            t=s.top();
            s.pop();
            t=t->right;
            while(t!=NULL){
                cout<<t->data;
                s.push(t);
                t=t->left;
            }
        }
    }
    void postoder_nr(node*x){
     node *temp = x;
    stack<pair<node*,int>> s;
    while(temp!=NULL)
    {
        s.push({temp,0});
        temp = temp->left;
    }
    while(!s.empty())
    {
        temp = s.top().first;
        int check=s.top().second;
        s.pop(); 
        if(check==0)
        {
            s.push({temp,1});
            temp = temp->right;
            while(temp!=NULL)
            {
                s.push({temp,0});
                temp = temp->left;
            }
        }
        else
        {
        	cout <<" "<< temp->data; 
        }       
    }     
    }

void menu()
{cout<<"1.POSTFIX EXPREESION TREE\n";
cout<<"2.PREFIX EXPREESION TREE\n";
cout<<"3.inorder (recursion)\n";
cout<<"4.inorder(non-recursion)\n";
cout<<"5.preorder(recursion)\n";
cout<<"6.preorder(non-recusion)\n";
cout<<"7.postorder(recursion)\n";
cout<<"8.postorder(non-recurion)\n";
cout<<"9.exit\n";
}
};
int main(){
   
    node * root;
    exptree e;
    while(true)
    { e.menu();
     int choice;
     cin>>choice;
     cout<<endl;
    if(choice==1)
    {       string s;
            cout<<"ENTER THE POSTFIX EXPRESSION"<<endl;
            cin>>s;
           root= e.exptrepost(s);
     }
             else if(choice==2)
    {       string s;
            cout<<"ENTER THE PreFIX EXPRESSION"<<endl;
            cin>>s;
           root= e.exptrepre(s);
     }
             else if(choice==3)
       {     e.inoder(root);
       }
             else if(choice==4)
    {      e.inoder_nr(root);
     }
             else if(choice==5)
    {       e.preoder(root);
     }
       else  if(choice==6)
    {       e.preoder_nr(root);
     }
             else if(choice==7)
    {       e.post(root);
     }
             else if(choice==8)
    {     e.postoder_nr(root);
     }
           else   if(choice==9)
    {       cout<<"thank you"<<endl;
     }
     else
	    {
	    	cout << "Invalid Choice. Try again." ;
	    }
  }
            
}          
            
