#include <bits/stdc++.h>
using namespace std;

int n,m;
int graphmatrix[20][20];
vector <int> adj[100];
bool visited[100];
vector <int> path;
//Ma tran canh ke
void insertmatrix(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			cout << graphmatrix[i][j] << " ";
		cout << endl;		
	}
}
//Danh sach lan can
void edgelist(){
	for (int i=1;i<=n;i++){
		cout << i << ". ";
		for (int j=0;j<adj[i].size();j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}
}
//Duyet chieu sau
void DFS(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int i=0;i<adj[u].size();i++) {
        int v=adj[u][i];
        if (!visited[v]) 
        	DFS(v);
    }
}
//Duyet chieu rong
void BFS(int u) {
    queue <int> q;
    q.push(u);
    visited[u]=true;
    while (!q.empty()) {
        int v=q.front();
        q.pop();
        cout << v << " ";
        for (int i=0;i<adj[v].size();i++) {
                int k=adj[v][i];
                if (!visited[k]){
                	q.push(k);
                	visited[k]=true;
				} 
            }
        }
    }
//Tim moi duong di 
//backtracking DFS
void findallpath(int start,int finish) {
    if (start==finish){
    	for (int i=0;i<path.size();i++)
    		cout << path[i] << " ";
    	cout << endl;
	}
	else{
    for (int i=0;i<adj[start].size();i++) {
        int v=adj[start][i];
        if (!visited[v]) { 	
        	visited[v]=true;
        	path.push_back(v);
			findallpath(v,finish);
        	path.pop_back();	
			}	
    	}
	}
	visited[start]=false;
}

int main(){
	cout << "Nhap so dinh va so canh: " << endl;
	cin >> n >> m;
	memset(visited,false,sizeof(visited));
	//Nhap cac cap dinh
	cout << "Nhap cac cap dinh:" << endl;
	for (int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		graphmatrix[x][y]=1;
	}
	cout << "-------- Ma tran canh ke --------" << endl;
	insertmatrix();
	cout << "------- Danh sach lan can -------"<<endl;
	edgelist();
	cout << "-------- Duyet DFS --------" << endl;
	DFS(1);
	memset(visited,false,sizeof(visited));
	cout << endl;
	cout << "-------- Duyet BFS --------" << endl;
	BFS(1);
	cout << endl;
	
	cout << "-------Tim duong di-------" <<endl;
	int start,finish;
	cout << "Nhap diem dau va diem cuoi: ";
	cin >> start >> finish;
	memset(visited,false,sizeof(visited));
	path.push_back(start);
	findallpath(start,finish);	
}


