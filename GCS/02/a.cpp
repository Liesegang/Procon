#include<bits/stdc++.h>
using namespace std;

vector<int> dfs(int N, vector<vector<int> > myedges){
    vector<int> parent(N);
    for(int i = 0; i < parent.size(); i++) parent[i] = -1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < myedges[i].size(); j++){
            if(myedges[i][j] != parent[i]){
                parent[myedges[i][j]] = i;
            }
        }
    }
    return parent;
}

vector<int> solve (int N, vector<int> values, vector<vector<int> > edges) {
    // Write your code here
    vector<vector<int> > myedges(N, vector<int>());
    for(int i = 0; i < edges.size(); i++){
        myedges[edges[i][0] - 1].push_back(edges[i][1] - 1);
        myedges[edges[i][1] - 1].push_back(edges[i][0] - 1);
    }

    vector<int> parent(N);
    parent = dfs(N, myedges);

    for(int i = 0; i < parent.size(); i++){
        printf("%d, %d\n", i, parent[i]);
    }

    vector<int> ret;
    return ret;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> values(N);
        for(int i_values = 0; i_values < N; i_values++)
        {
        	cin >> values[i_values];
        }
        vector<vector<int> > edges(N-1, vector<int>(2));
        for (int i_edges = 0; i_edges < N-1; i_edges++)
        {
        	for(int j_edges = 0; j_edges < 2; j_edges++)
        	{
        		cin >> edges[i_edges][j_edges];
        	}
        }

        vector<int> out_;
        out_ = solve(N, values, edges);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}