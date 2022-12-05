#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef struct _S_NODE
{
	int x, y;
	int step;
} Node;

int Size = 0;
bool flag[310][310] = {0};

int step[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1},
{2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void initial(){
    for(int i=0;i<310;++i){
        for(int j=0;j<310;++j){
            flag[i][j] = 0;
        }
    }
}

bool CheckValid(const Node& node)
{
	if (node.x >= 0 && node.x < Size
		&& node.y >= 0 && node.y < Size
		&& !flag[node.x][node.y])
	{
		return true;
	}
	return false;
}

int BFS(const Node& s, const Node& e)
{
	queue<Node> q;
	q.push(s);
	//memset(flag, 0, sizeof(flag));
	//flag[310][310] = {0};
	initial();

	while (!q.empty())
	{
		Node tmp = q.front();
		q.pop();
		if (tmp.x == e.x && tmp.y == e.y)
		{
			return tmp.step;
		}

		for (int i = 0; i < 8; ++i)
		{
			Node node = tmp;
			node.x += step[i][0];
			node.y += step[i][1];
			++node.step;
			if (CheckValid(node))
			{
				q.push(node);
				flag[node.x][node.y] = 1;
			}
		}
	}
	return 0;
}

int main(int argc, char **argv)
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n;
	scanf ("%d", &n);
	while (n--)
	{
		scanf ("%d", &Size);
		Node start, End;
		scanf ("%d %d", &start.x, &start.y);
		scanf ("%d %d", &End.x, &End.y);
		start.step = End.step = 0;
		printf ("%d\n", BFS(start, End));
	}

	return 0;
}
