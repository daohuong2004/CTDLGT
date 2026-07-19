#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1005;

vector<int> child[MAX];
bool hasParent[MAX];

//================ Height =================
int height(int u)
{
    if (child[u].size() == 0)
        return 0;

    int h = 0;

    for (int v : child[u])
    {
        h = max(h, height(v));
    }

    return h + 1;
}

//================ Preorder =================
void preorder(int u)
{
    cout << u << " ";

    for (int v : child[u])
        preorder(v);
}

//================ Postorder =================
void postorder(int u)
{
    for (int v : child[u])
        postorder(v);

    cout << u << " ";
}

//================ Check Binary =================
bool isBinary(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (child[i].size() > 2)
            return false;
    }

    return true;
}

//================ Inorder =================
void inorder(int u)
{
    if (child[u].size() >= 1)
        inorder(child[u][0]);

    cout << u << " ";

    if (child[u].size() == 2)
        inorder(child[u][1]);
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        child[u].push_back(v);
        hasParent[v] = true;
    }

    // Tìm gốc
    int root;

    for (int i = 1; i <= N; i++)
    {
        if (!hasParent[i])
        {
            root = i;
            break;
        }
    }

    // Height
    cout << height(root) << endl;

    // Preorder
    preorder(root);
    cout << endl;

    // Postorder
    postorder(root);
    cout << endl;

    // Inorder
    if (isBinary(N))
    {
        inorder(root);
        cout << endl;
    }
    else
    {
        cout << "NOT BINARY TREE";
    }

    return 0;
}