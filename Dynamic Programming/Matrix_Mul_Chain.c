#include <stdio.h>
#define MAX 100

void matrix_chain_order(int p[], int n, int m[][MAX], int s[][MAX]) {
    int i, j, k, l, q;

    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n-l+1; i++) {
            j = i + l - 1;
            m[i][j] = 99999999;

            for (k = i; k <= j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
void print_parenthesis(int s[][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_parenthesis(s, i, s[i][j]);
        print_parenthesis(s, s[i][j]+1, j);
        printf(")");
    }
}
int main() {
    int n, i, j;
    int p[MAX], m[MAX][MAX], s[MAX][MAX];

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    printf("Enter the number of rows of matrices: ");
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    matrix_chain_order(p, n, m, s);
    printf("Minimum number of multiplications required: %d\n", m[1][n]);
    printf("The Parenthesization is: ");
    print_parenthesis(s, 1, n);
    return 0;
}