#include <iostream>
#include <map> 
#include <string>
#include <vector>

using namespace std;

class Node {  
  public:
    string prod;
    Node *reag1;
    Node *reag2;

    Node(string _prod, string _reag1, string _reag2)
    {
        prod = _prod;
        //reag1 = Node();
    }
};

int main()
{
    vector<Node> root;
    int n;

    //cout << root.prod << "\n";
    return 0;

    cin >> n;
    while(n != 0){    
        string ignore;
        string reag1, reag2, produto;

        //root = new (n)Node("");
        
        cin >> reag1 >> ignore >> reag2 >> ignore >> produto;
        
        Node 
        
        cin >> n;
    }
    return 0;
}

/*
1
2H + O -> Water

5
A + B -> T1
C + D -> T2
E + F -> T3
T2 + T3 -> T4
T4 + T1 -> P

3
a + b -> ab
ab + c -> abc
abc + d -> abcd
0
*/
