/*
BY:ADITYA KUMAR  
Topic: INFIX,POSTFIX,PREFIX
*/

#include<bits/stdc++.h>
using namespace std;

int prior(char x)
{
	if(x=='*'){return 4;}
	else if(x=='/'){return 3;}
	else if(x=='+'){return 2;}
    else if(x=='-'){return 1;}
	else{return 0;}
}
struct node{
    char data;
    struct node *next;
};
class stack{
        public:
        node *top;
        stack()
        {
            top=NULL;
        }
    node create(int x)
    {
        node *p;
        p=new node;
        p->data=x;
        p->next=NULL;
        return *p;
    }
    void push(char x)
    {
        node *newnode;
        newnode=new node;
        *newnode=create(x);
        if(top==NULL)
        {
            top=newnode;
            return;
        }
        newnode->next=top;
        top=newnode;
        return;
    }
    char pop(){
        if(top==NULL){
            cout<<"Stack is empty\n";
            return 1;
        }
        node *temp;
        temp=top;   
        top=top->next;
        return temp->data;
    }
    void display()
    {
        node *temp;
        temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    bool empty(){
    	return top==NULL;
    }
    char topElement(){
    	return top->data;
    }

};
int evalution(int a,int b,char x)
{
    if(x=='*'){return b*a;}
    else if(x=='/'){return b/a;}
    else if(x=='+'){return b+a;}
    else{return b-a;}
}
string infix_to_postfix(string infix){
    stack s;
    int j=0;
    char x,y;
    string res;
    char postfix[infix.length()];
    for(int i=0;i<infix.length();i++)
    {
        x=infix[i];
        if(isalnum(x))
        {
            postfix[j]=x;
            j++;
        }
        else if(x=='(')
        {
            s.push(x);
        }
        else if(x==')')
        {
            y=s.pop();
            while(y!='(')
            {
            	postfix[j]=y;
            	j++;
                y=s.pop();
            }
        }
        else
        {
        	while(!s.empty() && prior(x)<prior(s.topElement()))
        	{
        		y=s.pop();
        		postfix[j]=y;
        		j++;
        	}
        	s.push(x);
        }

    }
    while(! s.empty())
    {
        y = s.pop();
        postfix[j]=y;
        j++;
    }
    for(int i=0;i<j;i++)
    {
    	res+=postfix[i];
    }
    return res;
}
string infix_to_prefix(string infix)
{
    char prefix[infix.length()];
    string res;
    for(int i=0;i<infix.length();i++)
    {
        if(infix[infix.length()-i-1]=='(')
        {res+=')';}
        else if(infix[infix.length()-i-1]==')')
        {res+='(';}
        else
        {res+=infix[infix.length()-i-1];}
    }
    string z=infix_to_postfix(res);
    reverse(z.begin(),z.end());
    return z;
}
int postfix_evalution(string postfix){
    stack s;
    char x,q;
    int a,b;
    for(int i=0;i<postfix.length();i++)
    {
        x=postfix[i];
        if(isalnum(x))
        {
            cout<<"Enter the value of "<<x<<": ";
            cin>>q;
            s.push(q);
        }
        else
        {
            a=s.pop()-'0'; 
            b=s.pop()-'0';
            if(a==0 && x=='/')
            {
                cout<<"Error"<<endl;
                return 0;
            }
            int z=evalution(a,b,x);
            s.push(z+'0');
        }
    }
    int r=s.pop()-'0';
    return r;
}
int prefix_evalution(string prefix){
    reverse(prefix.begin(),prefix.end());
    stack s;
    char x,q;
    int a,b;
    for(int i=0;i<prefix.length();i++){
        x=prefix[i];
        if(isalnum(x))
        {
            cout<<"Enter the value of "<<x<<": ";
            cin>>q;
            s.push(q);
        }
        else
        {
            a=s.pop()-'0';
            b=s.pop()-'0';
            if(b==0  && x=='/')
            {
                cout<<"Error"<<endl<<endl;
                return 0;
            }
            int z=evalution(b,a,x);
            s.push(z+'0');
        }
    }
    int r=s.pop()-'0';
    return r;

}

void menu()
{
	       cout<<"Choose the action you want to perform\n";
           cout<<"1. Infix to Postfix\n";
           cout<<"2. Infix to Prefix\n";
           cout<<"3. Evaluation of Postfix\n";
           cout<<"4. Evaluation of Prefix\n\n";
           cout<<"5.Exit\n";
            
}
int main(){
    stack s;
    int ans;
    string infix;
  
    while(true)
    { menu();
     int choice;
     cin>>choice;
     cout<<endl;
    
    if(choice==1)
    {
            cout<<"Enter the infix value: ";
            cin>>infix;
            cout<<"Postfix expression is: ";
            cout<<infix_to_postfix(infix)<<endl<<endl;
        }
        
       else if(choice==2)
            {cout<<"Enter the infix value: ";
            cin>>infix;
            cout<<"Prefix expression is: ";
            cout<<infix_to_prefix(infix)<<endl<<endl;
            }
        
        else if(choice==3)
           { cout<<"Enter the postfix value: ";
            cin>>infix;
            ans=postfix_evalution(infix);
            if(ans!=0)
             {
                cout<<"Value of expression is: ";
                cout<<ans<<endl;
             }
            }
            
        else if(choice==4)
           { cout<<"Enter the prefix value: ";
            cin>>infix;
            ans=prefix_evalution(infix);
            if(ans!=0)
            {
                cout<<"Value of expression is: ";
                cout<<ans<<endl;
            }
           }
        
        
           else if(choice == 5)
	    {
	    	cout << "Thank You!" ;
	    	
	    }
	    else
	    {
	    	cout << "Invalid Choice. Try again." ;
	    }
        
    }

}
