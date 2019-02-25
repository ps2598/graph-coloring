#include<iostream>
#include<map>
#include<list>
#include<iterator>
#include<string.h>
using namespace std;
map<char,int> node;
int no_of_node;
list<char > edge[100];
int color=0;
void input(){
	int n;
	char data;
	cout<<"enter the no of nodes"<<endl;
	cin>>no_of_node;
	for(int i=0;i<no_of_node;i++){
		cout<<"enter the no adj of"<<char(i+65)<<endl;
		cin>>n;
		cout<<"enter the adj of"<<char(i+65)<<endl;
		for(int j=0;j<n;j++){
			cin>>data;
			edge[i].push_back(data);
		}
	}
}
void coloring(){
	for(int i=0;i<no_of_node;i++){
	node.insert(pair<char,int>(char(i+65),1));
	}
	list<char >::iterator itr;
	map<char,int>::iterator map_itr,map_itr2;
	for(int i=1;i<no_of_node;i++)
	for(itr=edge[i].begin();itr!=edge[i].end();++itr){
	
		
			map_itr=node.find(char(i+65));
			map_itr2=node.find(*itr);
			if(map_itr->second==map_itr2->second){
				map_itr->second=map_itr->second+1;
				if(color<map_itr->second)
				color=map_itr->second;
			}
		
	}
}

void display(){
	cout<<"Minimum no of colors";
	cout<<color<<endl;
	map <char,int>:: iterator itr;
	for(itr=node.begin();itr!=node.end();++itr){
		cout<<itr->first<<"\t"<<itr->second<<endl;
	}
}
int main(){
input();
coloring();	
display();
return 0;	
}
