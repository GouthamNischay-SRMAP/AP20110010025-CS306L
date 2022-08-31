#include<bits/stdc++.h>
using namespace std;

struct node
{
	string datatype,name,value;
	node*left;
	node*right;
};
node*root=NULL;

node*new_node(string datatype,string name,string value)
{
	node*temp=new node;
	temp->datatype=datatype;
	temp->name=name;
	temp->value=value;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insert(string datatype,string name,string value)
{
	if(root==NULL)
		root=new_node(datatype,name,value);
	else
	{
		node*temp=root;
		node*current=new node;
		
		while(temp!=NULL)
		{
			current=temp;
			if(name>temp->name)
				temp=temp->right;
			else
				temp=temp->left;	
		}
		if(name>current->name)
			current->right=new_node(datatype,name,value);
		else
			current->left=new_node(datatype,name,value);
	}
}

node*search(node*root,string name)
{
	if(root==NULL)
		return NULL;
	else if(root->name==name)
		return root;
	else if(name>root->name)
		return search(root->right,name);
	else
		return search(root->left,name);
}

int main()
{
	insert("int","int1","10");
	insert("float","fnum","20.0");
	insert("double","dnum","30.0123");
	insert("char","char1","c");
	insert("string","str1","SRM University");
	
	node*temp=search(root,"str1");
	cout<<temp->datatype<<","<<temp->name<<","<<temp->value;
}