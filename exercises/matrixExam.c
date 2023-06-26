//
// Created by danie on 26.06.2023.
//

int M[4][4] = {{-1, 0, -1, 0}, {-1, 0, -1, -1}, {-1,-1,-1,0},{-1,-1,-1-0}};

int maxLen(int m) {

    int max = 0;
    int helperMatrix[m][m];// init with 0

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            helperMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || j == 0) && M[i][j] < 0) {
                helperMatrix[i][j] = 1;
            } else {
                if (M[i][j] < 0) {
                    helperMatrix[i][j] =
                            (helperMatrix[i - 1][j] + helperMatrix[i][j - 1] + helperMatrix[i - 1][j - 1]) / 3 + 1;
                    if (helperMatrix[i][j] > max) max = helperMatrix[i][j];
                }
            }
        }
    }
    return max;
}

int main(){
    maxLen(4);
}