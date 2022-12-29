#include <iostream>
#include <cstring>
using namespace std;

int n=1;

struct Node{
	int sbd;
	string hoTen;
	Node *left;
	Node *right;
	
	Node (int s, string h, Node *l, Node *r){
		sbd=s;
		hoTen=h;
		left=l;
		right=r;
	}
};

struct sinhvien{
	int sbd;
	string hoTen;
};
sinhvien data[100];

class BSTree{
	public:
		//Ham tao
		BSTree(){
			root = NULL;
		}
		//Ham huy
		~BSTree(){
			makeEmpty();
		}
		//Kiem tra cay rong
		bool isEmpty(){
			if (root == NULL)
				return true;
			else return false;
		}
		//Xoa het cac nut
		void makeEmpty(){
			makeEmpty(root);
		}
		//Chen sinh vien moi
		void insert(int sbd, string hoTen){
			insert (sbd, hoTen, root);
		}
		//Tim sinh vien theo sbd
		Node *search(int sbd){
			search (sbd,root);
		}
		//Duyet truoc
		void preorder(){
			NLR(root);
		}
		//Duyet giua
		void indorder(){
			LNR(root);
		}
		//Duyet sau
		void postorder(){
			LRN(root);
		}
		
	private:
		Node *root;
		//Xoa rong cay de quy
		void makeEmpty(Node *&t){
			if (t==NULL)
				return;
			else{
				makeEmpty(t->left);
				makeEmpty(t->right);
			}	
			delete t;
			t=NULL;
		}
		//Chen sinh vien moi de quy
		void insert(int sbd, string hoTen, Node *&t){
			if (t == NULL){
				Node *p=new Node(sbd,hoTen,NULL,NULL);
				t = p;
				data[n].sbd=sbd;
				data[n].hoTen=hoTen;
				n++;
			}	
			else{
				if (t->sbd > sbd)
					insert (sbd, hoTen, t->left);
				else if (t->sbd < sbd)
					insert (sbd, hoTen, t->right);
			}	
		}
		//Tim kiem sinh vien de quy
		Node *search(int sbd, Node *t){
			if (t == NULL)
				return NULL;
			else{
				if (t->sbd > sbd)
					search (sbd, t->left);
				else if (t->sbd < sbd)
					search (sbd, t->right);
				else return t;
				}
		}
		void NLR(Node *t){
			if (t!=NULL){
				cout << "Ten: "<<t->hoTen<<" SBD"<<t->sbd<<endl;
				NLR(t->left);
				NLR(t->right);
			}
		}
		void LNR(Node *t){
			if (t!=NULL){
				LNR(t->left);
				cout << "Ten: "<<t->hoTen<<" SBD"<<t->sbd<<endl;
				LNR(t->right);
			}
		}
		void LRN(Node *t){
			if (t!=NULL){
				LRN(t->left);
				LRN(t->right);
				cout << "Ten: "<<t->hoTen<<" SBD"<<t->sbd<<endl;
			}
		}
};

//Heapsort
	void push (int i,int n,sinhvien data[]){
		sinhvien k=data[i]; //goc
		int j=2*i;	//nut trai
		while (j<=n){
			if ((j < n)&&(data[j].sbd < data[j+1].sbd))
				j++;
			if (k.sbd > data[j].sbd){
				data[j/2]=k;
				return;  
			}
			data[j/2]=data[j];
			j*=2;
		}
			data[j/2]=k;
			return;
	}
	
	void heapsort(sinhvien a[],int n){
		for (int i=n/2;i>=1;i--)
			push(i,n,a);
		for (int i=n-1;i>=1;i--){
			sinhvien temp=a[1];
			a[1]=a[i+1];
			a[i+1]=temp;
			push (1,i,a);
		}
	}
	
int main(){
	BSTree bst;
	//Chen sinh vien moi
	bst.insert(5,"Tuan");
	bst.insert(6,"Lan");
	bst.insert(3,"Cong");
	bst.insert(8,"Huong");
	bst.insert(7,"Binh");
	bst.insert(4,"Hai");
	bst.insert(2,"Son");
	//Tim sinh vien co sbd
	Node *n1=bst.search(4);
	Node *n2=bst.search(9); 
	//Ket qua tim kiem
	if (n1!=NULL)
		cout << "Sinh vien sbd 4 la " << n1->hoTen << endl;
	if (n2==NULL)
		cout << "Khong tim thay sinh vien sbd 9" << endl;		
	//lam rong cay
	bst.makeEmpty();
	if (bst.isEmpty())
		cout << "Cay da bi xoa rong" << endl;
	//Sap xep theo sbd
	cout << "------------Danh sach ban dau------------" << endl;
	for (int i=1;i<=n-1;i++)
		cout << i << ". Ten: " << data[i].hoTen << " SBD: " << data[i].sbd << endl;	
	cout << "---------Heapsort---------" << endl;
	heapsort(data,n-1);
	for (int i=1;i<=n-1;i++)
		cout << i << ". Ten: " << data[i].hoTen << " SBD: " << data[i].sbd << endl;	
	return 0;
}
