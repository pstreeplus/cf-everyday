#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

#define MAXN 3e5 + 10

using namespace std;

struct Flight{
    int cost;
    int minute;

    Flight(int c, int m): cost(c), minute(m) {}

    bool operator < (const Flight &b) const {
        if(cost == b.cost){
            return b.minute < minute;
        }
        return cost < b.cost;
    }

};

priority_queue<Flight> q;

int main(){
    int n,k,c;
    scanf("%d%d", &n, &k);
    long long cost = 0;
    vector<pair<int, int> > ans;
    int minute = 1;
    while(n--){
        scanf("%d", &c);
        Flight flight(c, minute);
        q.push(flight);
        if(minute > k){
            Flight flight = q.top();
            q.pop();
            cost + = (long long)(minute - flight.minute) * flight.cost;
            ans.push_back(make_pair(flight.minute, minute));
        }
        ++minute;
    }
    while(!q.empty()){
        Flight flight = q.top();
        q.pop();
        cost += (long long)(minute - flight.minute) * flight.cost;
        ans.push_back(make_pair(flight.minute, minute));
        ++minute;
    }
    sort(ans.begin(), ans.end());
    printf("%lld\n", cost);
    for(int i = 0; i < ans.size(); ++i){
        printf("%d ", ans[i].second);
    }
    puts("");
    return 0;
}
