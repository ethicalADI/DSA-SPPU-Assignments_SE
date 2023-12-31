
/*
BY:ADITYA KUMAR  
Topic: BINARY SEARCH TREE
*/
#include <bits/stdc++.h>
 
using namespace std ;

struct Node 
{
    int data ;
    struct Node *left, *right;
};

Node* newNode(int val)
{
    Node *temp = new Node;
    temp->left = temp->right = NULL;
    temp->data = val;
    return temp;
};

//=========== Displays ===========//

void inorder(Node*x)
{
        if(x!=NULL)
        {
            inorder(x->left);
            cout<<x->data;
            inorder(x->right);
        }
    }
    void preorder(Node*x){
        if(x!=NULL){
            cout<<x->data;
            preorder(x->left);
            preorder(x->right);
        }
    }
    void postorder(Node*x){
        if(x!=NULL){
            postorder(x->left);
            postorder(x->right);
            cout<<x->data;
        }
    }
    
 Node* Insert(Node* root , int data)
{
    if(!root)
    {
        Node* temp ;
        temp=newNode(data) ;
        return temp ;
    }
    if(data > root->data)
    {
        root->right = Insert(root->right , data) ;
    }
    else if(data < root->data)
    {
        root->left = Insert(root->left , data) ;
    }
    return root ;
}


//=========== Searching ===========//

int Search(Node* root, int data, int h)
{
    if(!root)
    {
        return 0 ;
    }
    if(data > root->data)
    {
        return Search(root->right , data , h + 1);
    }
    else if(data < root->data)
    {
        return Search(root->left , data , h + 1);
    }

     return h ;
    
}
//================= =================//
Node* Delete(Node* root , int data)
{
    Node* temp ;
    if(!root)
    {
        cout << "Element NOT FOUND\n" ;
        return NULL ;
    }
    else if(data > root->data)
    {
        root->right = Delete(root->right , data) ;
    }
    else if(data < root->data)
    {
        root->left = Delete(root->left , data);
    }
    
    else
    {
        if(root->left && root->right)
        {
            temp = Find_Min(root->right) ;
            root->data = temp->data ;
            root->right = Delete(root->right , temp->data) ;
        }
        else
        {
            temp = root ;
            if(!root->left)
            {
                root = root->right ;
            }
            else if(!root->right)
            {
                root = root->left;
            }
            free(temp);
        }
        return root ;
    }
}
Node* Find_Min(Node* root)
{
    if(!root)
    {
        return NULL ;
    }
    if(root->left)
    {
        return Find_Min(root->left) ;
    }
    else
    {
        return root ;
    }
}

Node* Find_Max(Node* root)
{
    if(!root)
    {
        return NULL ;
    }
    if(root->right)
    {
        return Find_Max(root->right) ;
    }
    else
    {
        return root ;
    }
}
void Display_LeafNodes(Node* root)
{
    if(!root->left && !root->right)
    {
        cout << root->data << " " ;
        return ;
    }
    if(root->left)
    {
        Display_LeafNodes(root->left);
    }
    if(root->right)
    {
        Display_LeafNodes(root->right);
    }
}

void Display_LevelOrder(Node* root)
{
	deque<Node*> s1 , s2 ;
	s1.push_front(root) ;
	int c = 0 ;
	while(s1.size())
	{
		Node* temp;
		temp = s1.back();
		s1.pop_back();
		if(temp->data)
		{
			cout << temp->data << " " ;
		    if(temp->left)
			{
				s2.push_front(temp->left);
			}
		    if(temp->right)
			{
				s2.push_front(temp->right);
			}
		}
		if(s1.size()==0)
		{
			s1 = s2 ;
			while(s2.size())
			{
				s2.pop_front() ;
			}
			cout << "\n" ;
		}
	}
}



void mirror_image(Node* root)
	{
		if(root!=NULL)
		{
			mirror_image(root->left);
			mirror_image(root->right);
			swap(root->left,root->right);
		}
		
	}
void copy(Node* one,Node*& two)
{
		if(one==NULL)
		{
			two=NULL;
		}
		else
		{
			two=new Node;
			two->data=one->data;
			copy(one->left,two->left);
			copy(one->right,two->right);
		}
	}

int height(Node* root)
{
		if(root==NULL)
		{
			return 0;
		}
		Node* P=root;
		queue<Node*> q;
		q.push(P);
		q.push(NULL);
		int Height=0;
		while(!q.empty())
		{
			P=q.front();
			q.pop();
			if(P==NULL)	
			Height++;
			if(P!=NULL)
			{
				if(P->left!=NULL)	q.push(P->left);
				if(P->right!=NULL)	q.push(P->right);
			}
			else if(!q.empty())
			{
				q.push(NULL);
			}		
		}
		return Height;
	}
	

//====================== MAIN =====================//
void menu( )
{
	cout << "\n\nChoose Your Operation:\n" ;
    cout << "1.Insert Nodes\n" ;
    cout << "2.Delete A Node\n" ;
    cout << "3.Display Tree. (INORDER TRAVERSAL)\n" ;
   
    cout << "4.Find Minimum Element.\n" ;
    cout << "5.Find Maximum Element.\n" ;
    cout << "6.Search An Element.\n" ;
    cout << "7.Display Tree Level Order.\n" ;
    cout << "8.Display All Leaf Nodes.\n" ;
    cout << "9.height\n" ;
    cout << "10.mirror image\n" ;
    cout<<"11.copy\n";
    cout<<"12.exit\n";
    cout << "Enter you choice: " ;
}
int main()
{
    Node *bst = NULL ;
    Node* root ;
    while(true)
	{
		menu() ;
	    int choice ;
	    cin >> choice ;
	    cout << "\n" ;
	    if(choice == 1)
	    {
	    	cout<<"Enter number element to be insert : ";
            int n ;
            cin >> n ; 
            cout << "Enter elements :\n" ;
            while(n -- )
            {
            	int input ;
            	cin >> input ;
                bst=Insert(bst , input) ;
            }
            
	    }
	    else if(choice == 2)
	    {
	    	cout << "Enter element to be deleted: " ;
            int input ;
            cin >> input ;
            bst=Delete(bst , input);
            cout << "ELEMENT DELETED. Remaining elements are: \n" ;
            inorder(bst) ;
	    }
	    else if(choice == 3)
	    {
	    	
	    	int t;
	    	cout<<"1.inorder \n 2.preorder\n 3. postorder\n"<<endl;
	    	cin>>t;
	    	if(t==1)
            {
            	cout << "Elements in tree are: \n" ;
            	inorder(bst);}
            else if(t==2)
            {cout << "Elements in tree are: \n" ;
            	preorder(bst);
            }
            else if(t==3)
            {cout << "Elements in tree are: \n" ;
            	postorder(bst);
            }
	    }
	    else if(choice == 4)
	    {
	    	root = Find_Min(bst) ;
            cout << "Minimum element is: " << root->data ;
	    }
	    else if(choice == 5)
	    {
	    	root = Find_Max(bst) ;
            cout << "Maximum element is: " << root->data ;
	    }
	    else if(choice == 6)
	    {
	    	cout << "Enter element to be searched: " ;
	    	int input ;
            cin >> input ;
           int  h = Search(bst , input , 0) ;
            if(h)
            {
                cout << "Element found" ;
            }
            else
            {
            	cout << "ELEMENT NOT FOUND" ;
            }
	    }
	    else if(choice == 7)
	    {
	    	cout << "Level order display of tree:\n" ;
            Display_LevelOrder(bst) ;
        }
	    else if(choice == 8)
	    {
	    	cout << "All leaf nodes of tree are: \n" ;
            Display_LeafNodes(bst) ;
	    }
	     else if(choice == 9)
	    {
	    	cout << "Height of tree are: \n" ;
            cout<<height(bst) ;
	    }
	    else if(choice == 10)
	    {   
	    	mirror_image(bst);
	    	
	    }
	    else if(choice == 11)
	    {   
	    	Node* copyy;
	    	copy(bst,copyy);
	    	inorder(copyy);
	    	
	    }
	    else if(choice == 12)
	    {
	    	cout << "Thank You!" ;
	    	break ;
	    }
	    else
	    {
	    	cout << "Invalid Choice. Try again." ;
	    }
	}
	return 0 ;
}

