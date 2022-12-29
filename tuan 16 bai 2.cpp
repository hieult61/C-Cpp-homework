#include <iostream>
using namespace std;

int n=0;

template <class T>
struct Node{
	T data;
	Node *left;
	Node *right;
	
	Node (T x,Node *l,Node *r){
		data=x;
		left=l;
		right=r;
	}
}; 

template <class T>
class BSTree{
	public:
		//Ham tao
		BSTree(){
			initBTree();
		};
		//Ham huy
		~BSTree(){
			makeEmpty(tree);
		};
		//Khoi tao cay rong
		void initBTree(){
			tree = NULL;
		};
		//Bo sung x tro thanh cha cua nut P
		void insertParents(T x,Node<T> *p){
			insertParents(x,tree,p);
		}
		//Bo sung x tro thanh nut con trai cua nut P
		void insertLeftChild(T x,Node<T> *p){
			insertLeftChild(x,tree,p);
		}
		//Bo sung x tro thanh nut con phai cua nut P
		void insertRightChild(T x,Node<T> *p){
			insertRightChild(x,tree,p);
		}
		//Xoa nut hien tai tro boi p
		void deleteCurrentNode(Node<T> *p){
			deleteCurrentNode(tree,p);
		}
		//Xoa nut con trai cua p
		void deleteLeftNode(Node<T> *p){
			deleteLeftNode(tree,p);		
		}
		//Xoa nut con phai tro boi p
		void deleteRightNode(Node<T> *p){
			deleteRightNode(tree,p);
		}
		//Tim node co gia tri x
		Node<T> *search(T x){
			int m=0;
			search(x,tree,m);
		}
		//Kich thuoc cay
		int getsize(){
			return n;
		}
		void show(){
			show (tree);	
		}
	private:
		Node<T> *tree;
		//lam rong
		void makeEmpty(Node<T> *&t){
			if (t==NULL)
				return;
			else{
				makeEmpty(t->left);
				makeEmpty(t->right);
			}	
			delete t;
			t=NULL;
		}
		//Tim nut co gia tri x
		Node<T> *search(T x, Node<T> *t,int &i){
			if (t->data==x)
				return t;
			i++;
			if (i>n)
				return NULL;
			search (x, t->left,i);
			search (x, t->right,i);
			}
		//Tim cha cua nut co gia tri x
		Node<T> *searchParent(T x, Node<T> *t,int &i){
			if (t->left->data==x||t->right->data==x)
				return t;
			i++;
			if (i>n)
				return NULL;
			searchParent (x,t->left,i);
			searchParent (x,t->right,i);
			}
		//In gia tri cay	
		void show(Node<T> *t){
			if (t!=NULL){
				cout << t->data << endl;
				show(t->left);
				show(t->right);
			}
		}
		//Xoa nut con trai
		void deleteLeftNode(Node<T> *&t,Node<T> *p){
			int m=0;		
			Node<T> *k=search(p->data,t,m);
			Node<T> *z=k->left;
			if (k->left==NULL)
				return;
			else if (k->left->right==NULL)
				k->left=k->left->left;
			else if (k->left->left==NULL)
				k->left=k->left->right;
			else{
				k->left->right->left=k->left->left;
				k->left=k->left->right;	
			}
			delete z;
			n--;
			}
		//Xoa nut con phai
		void deleteRightNode(Node<T> *&t, Node<T> *p){
			int m=0;
			Node<T> *k=search(p->data,t,m);
			Node<T> *z=k->right;
			if (k->right==NULL)
				return;
			else if (k->right->right==NULL)
				k->right=k->right->left;
			else if (k->right->left==NULL)
				k->right=k->right->right;
			else{
				k->right->left->right=k->right->right;
				k->right=k->right->left;	
			}
			delete z;
			n--;
		}
		//Xoa nut hien tai
		void deleteCurrentNode(Node<T> *&t, Node<T> *p){
			int m=0;
			Node<T> *k = search(p->data,t,m);
			if (k==NULL)
				return;
			else{
				Node<T> *z=k;
				if (k->left==NULL)
					k=k->right;
				else if (k->right==NULL)
					k=k->left;
				//Thay the boi nut trai nhat cay con phai
				else {
					Node<T> *y=k->right;
					swapnode(z,y);
				}			
			delete z;
			}
			n--;
		}
		void swapnode(Node<T> *&x,Node<T> *&y){
			if (y->left==NULL)
				swapnode (x,y->left);
			else{
				x->data=y->data;
				x=y;
				y=y->right;
			}
		}
		//Bo sung nut cha
		void insertParents(T x, Node<T> *&t, Node<T> *p){
			if (t==NULL){
				cout << "Cay rong" << endl;
				return;
			}
			else{			
			if (p->data==t->data){
				p->left=t;
				t=p;
				n++;
			}
			else{
			int t=0;	
			Node<T> *q=searchParent(p->data,tree,t);
			if (q!=NULL){
				Node<T> *h=new Node<T> ( x,NULL,NULL);
				if (q->left->data==p->data){
					h->left=q->left;
					q->left=h;
				}
				else {
					h->right=q->right;
					q->right=h;
				}		
				n++;
				}
			}
		}
	}	//Bo sung nut con trai
		void insertLeftChild(T x, Node<T> *&t, Node<T> *p){
			if (t==NULL){
				t=p;
				n++;
				return;
			}
			else{
			int m=0;
			Node<T> *q=search(p->data,t,m);
			if (q!=NULL){		
				Node<T> *h=new Node<T> (x,NULL,NULL);
				h->left=q->left;
				q->left=h;	
				n++;
			}
		}
	}
		//Bo sung nut con phai
		void insertRightChild(T x, Node<T> *&t, Node<T> *p){
			if (t==NULL){
				t=p;
				n++;
				return;
			}
			else{
			
			int m=0;
			Node<T> *q=search(p->data,tree,m);
			if (q!=NULL){		
				Node<T> *h=new Node<T> (x,NULL,NULL);
				h->right=q->right;
				q->right=h;	
				n++;
			}
		}
	}
}; 

int main(){
	BSTree <int>t;
	Node <int>*p=new Node<int>(35,NULL,NULL);
	t.insertParents(30,p);
	t.show();
	t.insertLeftChild(30,p);
	t.insertLeftChild(39,p);
	t.insertRightChild(40,p);
	t.show();
//	t.deleteCurrentNode(p);	
//	Node <int>*pt=new Node<int>(39,NULL,NULL);
//	t.insertLeftChild(50,pt);
//	t.insertRightChild(60,pt);
//	t.show();
//	
//	cout << "\nXoa nut 39" << endl;
//	t.deleteCurrentNode(pt);
//	t.show();
}
