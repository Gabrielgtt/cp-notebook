ios::sync_with_stdio(false);
cin.tie(NULL);

vector <int> split(string a) {
    istringstream is( a );
    int n;
    vector<int> ve;
    while( is >> n ) {
        ve.emplace_back(n);
    }
    return ve;
}

