#include <cstdio>
#include <vector>

using namespace std;

double dfs(int f, int c, vector<vector<int> > &map){
    int path = 0;
    double length = 0.0;
    for(int i = 0; i < map[c].size(); ++i){
        if(f == map[c][i]) continue;
        ++path;
        length += dfs(c, map[c][i], map);
    }
    if(!path) return 0.0;
    return (length + path) / path;
}

int main(int argc, char* argv[]){
    int n,u,v;
    scanf("%d", &n);
    vector<vector<int> > map(n);
    while(n-- > 1){
        scanf("%d%d", &u,&v);
        map[u-1].push_back(v-1);
        map[v-1].push_back(u-1);
    }
    printf("%.7lf\n", dfs(0, 0, map));
    return 0;
}
