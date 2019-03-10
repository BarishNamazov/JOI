/*** Author: Barish Namazov (toonewbie) ***/
#include <bits/stdc++.h>

using namespace std;

char A[3005][3005];
int si[3005][3005], so[3005][3005];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            so[i][j] = so[i][j + 1] + (A[i][j] == 'O');
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; i--) {
            si[i][j] = si[i + 1][j] + (A[i][j] == 'I');
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i][j] == 'J') {
                res += 1LL * so[i][j] * si[i][j];
            }
        }
    }
    cout << res << endl;
    return 0;
}
