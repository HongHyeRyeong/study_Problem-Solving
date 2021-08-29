#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct Trie {    
    Trie* go[26]; // 현재 노드에서 해당 문자를 받으면 가는 노드    
    Trie* fail; // 현재 노드에서 해당 문자의 go 목적지가 없을 때 가는 노드
    bool output; // 현재 노드에 도달하면 찾는 문자열 집합 있는지 판단

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

        // 맨 앞 문자는 제외하고 전달한다.
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
        // 트라이에 S의 원소들을 모두 집어넣는다.
        root->insert(str);
    }

    // 트라이 노드를 방문하며 fail 함수를 만든다.
    queue<Trie*> q;
    root->fail = root;
    q.push(root);
    while (!q.empty()) {
        Trie* current = q.front();
        q.pop();

        // 26개의 input 각각에 대해 처리한다.
        for (int i = 0; i < 26; i++) {
            Trie* next = current->go[i];
            if (!next)
                continue;

            // 루트의 fail은 루트다.
            if (current == root)
                next->fail = root;
            else {
                Trie* dest = current->fail;

                // fail을 참조할 가장 가까운 조상을 찾아간다.
                while (dest != root && !dest->go[i])
                    dest = dest->fail;

                // fail(px) = go(fail(p), x)
                if (dest->go[i])
                    dest = dest->go[i];

                next->fail = dest;
            }

            // fail(x) = y일 때, output(y) ⊂ output(x)
            if (next->fail->output)
                next->output = true;

            // 큐에 다음 노드 push
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

            // 현재 노드에서 갈 수 없으면 fail을 계속 따라감
            while (current != root && !current->go[next])
                current = current->fail;

            // go 함수가 존재하면 이동. 루트면 이게 false일 수도 있다
            if (current->go[next])
                current = current->go[next];

            // 현재 노드에 output이 있으면 찾은 것이다.
            if (current->output) {
                result = true;
                break;
            }
        }

        cout << (result ? "YES" : "NO") << endl;
    }
}