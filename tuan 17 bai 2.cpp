#include <bits/stdc++.h>
using namespace std;
 
int board[100][100];
int n,toadox1,toadoy1,toadox2,toadoy2;
 
int xmove[8]={-2,-2,-1,-1,1,1,2,2};
int ymove[8]={-1,1,-2,2,-2,2,-1,1};

struct knight{
    int x,y,count;
    knight(int a, int b, int t){
        x=a; 
		y=b; 
		count=t;
    }
};

bool validmove(int a,int b){
	if (1<=a && a<=n && 1<=b && b<=n)
		return true;
	return false;
}
//BFS
void knighttour(int tdx1,int tdy1,int tdx2,int tdy2,int board[][100],bool &check){
	queue <knight> q;
	q.push(knight(tdx1,tdy1,0));
    board[tdx1][tdy1]=1;
    while (!q.empty())
    {
        knight t = q.front();
        q.pop();
        for (int k=0; k<8; k++)
        {
            int tdx = xmove[k]+t.x;
            int tdy = ymove[k]+t.y;
            if (validmove(tdx,tdy) && board[tdx][tdy]==0)
            {
                q.push(knight(tdx,tdy,t.count+1));
                board[tdx][tdy]=1;
                if (tdx==tdx2 && tdy==tdy2)
                {
                	check=true;
                    cout << "Quang duong ngan nhat la: " << t.count+1;
                }
            }
        }
    }
}

int main()
{
    bool check=false;
    cout << "Nhap kich thuoc ban co: " << endl;
    cin >> n;
    cout << "Nhap toa do bat dau: " << endl;
    cin >> toadox1 >> toadoy1;
    cout << "Nhap toa do ket thuc: " << endl;
    cin >> toadox2 >> toadoy2;
    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            board[i][j]=0;
 	knighttour(toadox1,toadoy1,toadox2,toadoy2,board,check);
    
    if (!check)
    	cout << "Khong tim thay duong di";
}
