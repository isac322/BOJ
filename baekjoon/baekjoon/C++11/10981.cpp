#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;
 
struct ICPC
{
    string univ;
    string name;
    int score;
    int penalty;
};
 
 
class mycomp //비교
{
public:
    bool operator()(ICPC *d1, ICPC *d2) const
    {
        if (d1->score < d2->score) return true; //스코어값 비교
        else if (d1->score == d2->score && d1->penalty > d2->penalty) return true;
        //스코어값이 같을경우 패널티값이 작은경우를 선정
        else return false;
    }
};
 
int N, K;
priority_queue <ICPC*, vector<ICPC*>, mycomp> pq; //우선순위큐
set <string> s; //중복확인을 위한 셋
set <string>::iterator it; //셋위치 변수
 
int main(void)
{
    cin >> N >> K;
    ICPC *team;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        team = new ICPC;
        cin >> team->univ;
        cin >> team->name;
        cin >> team->score;
        cin >> team->penalty;
        pq.push(team);
    }
    while(cnt != K)
    {
        it = s.find(pq.top()->univ);
        if (it == s.end())
        {
            cout << pq.top()->name << '\n';
            s.insert(pq.top()->univ);
            cnt++;
        }
        pq.pop();
    }
}