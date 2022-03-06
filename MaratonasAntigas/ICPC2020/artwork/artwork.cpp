// https://maratona.ime.usp.br/primfase19/provas/competicao/maratona_en.pdf

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

vector<vector<bool>> matrix;
int m, n, k;

bool is_possible(int x, int y)
{
	if(x < 0 || x >= m || y < 0 || y >= n) return false;
	if(matrix[x][y] == false) return false;
	if(x == m - 1 && y == n - 1) return true;
	
	matrix[x][y] = false;

	return is_possible(x - 1, y) || is_possible(x + 1, y) || 
			is_possible(x, y - 1) || is_possible(x, y + 1);
}

ull dist(int x1, int y1, int x2, int y2)
{
	ull difx = x1 - x2;
	ull dify = y1 - y2;

	return difx * difx + dify * dify;
}

int main()
{
	cin >> m >> n >> k;

	for (int i = 0; i < m; i++)
	{
		vector<bool> line;
		for (int j = 0; j < n; j++)
		{
			//cout << "linha " << i << "; coluna " << j << endl;
			line.push_back(true); // default
		}

		matrix.push_back(line);
	}
	

	for (int i = 0; i < k; i++)
	{
		int x, y, s;
		cin >> x >> y >> s;

		ull d_s = s * s;

		int s_row = max(0, x - s), e_row = min(m - 1, x + s);
		int s_col = max(0, y - s), e_col = min(n - 1, y + s);

		// cout << "row: " << s_row << ", " << e_row << endl;
		// cout << "col: " << s_col << ", " << e_col << endl;

		for (int j = s_row; j <= e_row; j++)
		{
			for (int k_i = s_col; k_i <= e_col; k_i++)
			{
				//cout << "linha " << j << "; coluna " << k_i << endl;
				if(dist(j, k_i, x, y) < d_s) matrix[j][k_i] = false;
			}			
		}
		
	}


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << (is_possible(0, 0) ? "S" : "N") << endl;
	

	return 0;
}