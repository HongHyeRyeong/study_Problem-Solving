#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct Trie {    
    Trie* go[26]; // ���� ��忡�� �ش� ���ڸ� ������ ���� ���    
    Trie* fail; // ���� ��忡�� �ش� ������ go �������� ���� �� ���� ���
    bool output; // ���� ��忡 �����ϸ� ã�� ���ڿ� ���� �ִ��� �Ǵ�

    Trie() 
    {
        fill(go, go + 26, nullptr);
        output = false;
    }

    ~Trie() 
    {
        for (int i = 0; i < 26; i++)
            if (go[i])
                delete go[i];
    }

    void insert(string key)
    {
        if (key == "\0") {
            output = true;
            return;
        }

        int next = key[0] - 'a';
        if (!go[next])
            go[next] = new Trie;

        // �� �� ���ڴ� �����ϰ� �����Ѵ�.
        go[next]->insert(key.substr(1, key.size() - 1));
    }
};

int main()
{
    int N, M;
    string str;
    Trie* root = new Trie;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        // Ʈ���̿� S�� ���ҵ��� ��� ����ִ´�.
        root->insert(str);
    }

    // Ʈ���� ��带 �湮�ϸ� fail �Լ��� �����.
    queue<Trie*> q;
    root->fail = root;
    q.push(root);
    while (!q.empty()) {
        Trie* current = q.front();
        q.pop();

        // 26���� input ������ ���� ó���Ѵ�.
        for (int i = 0; i < 26; i++) {
            Trie* next = current->go[i];
            if (!next)
                continue;

            // ��Ʈ�� fail�� ��Ʈ��.
            if (current == root)
                next->fail = root;
            else {
                Trie* dest = current->fail;

                // fail�� ������ ���� ����� ������ ã�ư���.
                while (dest != root && !dest->go[i])
                    dest = dest->fail;

                // fail(px) = go(fail(p), x)
                if (dest->go[i])
                    dest = dest->go[i];

                next->fail = dest;
            }

            // fail(x) = y�� ��, output(y) �� output(x)
            if (next->fail->output)
                next->output = true;

            // ť�� ���� ��� push
            q.push(next);
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> str;

        Trie* current = root;
        bool result = false;
        for (int j = 0; str[j]; j++) {
            int next = str[j] - 'a';

            // ���� ��忡�� �� �� ������ fail�� ��� ����
            while (current != root && !current->go[next])
                current = current->fail;

            // go �Լ��� �����ϸ� �̵�. ��Ʈ�� �̰� false�� ���� �ִ�
            if (current->go[next])
                current = current->go[next];

            // ���� ��忡 output�� ������ ã�� ���̴�.
            if (current->output) {
                result = true;
                break;
            }
        }

        cout << (result ? "YES" : "NO") << endl;
    }
}