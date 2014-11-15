class Solution {
public:
	void solve(vector<vector<char>> &board) {
	    if (board.empty())
	        return;
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool> > visited(m, vector<bool>(n, false));

		vector<pair<int,int> > circles;

		// scan four sides
		deque<pair<int, int> > q;
		int x,y,i;
		pair<int, int> cor;

		// top
		for (i = 0; i < n; ++i) {
			if (board[0][i] == 'X' || visited[0][i])
				continue;
			q.push_back(pair<int,int>(0,i));
			while(!q.empty()) {
				cor = q.front();
				circles.push_back(cor);
				x = cor.first;
				y = cor.second;

				if (x > 1) {
					if (board[x-1][y] == 'O' && !visited[x-1][y]) {
						q.push_back(pair<int,int>(x-1,y));
						visited[x-1][y] = true;
					}
				}

				if (y > 1) {
					if (board[x][y-1] == 'O' && !visited[x][y-1]) {
						q.push_back(pair<int,int>(x,y-1));
						visited[x][y-1] = true;
					}
				}

				if (x < m-1) {
					if (board[x+1][y] == 'O' && !visited[x+1][y]) {
						q.push_back(pair<int,int>(x+1,y));
						visited[x+1][y] = true;
					}
				}

				if (y < n-1) {
					if (board[x][y+1] == 'O' && !visited[x][y+1]) {
						q.push_back(pair<int,int>(x,y+1));
						visited[x][y+1] = true;
					}
				}

				q.pop_front();

			}
		}

		// bottom
		for (i = 0; i < n; ++i) {
			if (board[m-1][i] == 'X' || visited[m-1][i])
				continue;
			q.push_back(pair<int,int>(m-1,i));
			while(!q.empty()) {
				cor = q.front();
				circles.push_back(cor);
				x = cor.first;
				y = cor.second;

				if (x > 1) {
					if (board[x-1][y] == 'O' && !visited[x-1][y]) {
						q.push_back(pair<int,int>(x-1,y));
						visited[x-1][y] = true;
					}
				}

				if (y > 1) {
					if (board[x][y-1] == 'O' && !visited[x][y-1]) {
						q.push_back(pair<int,int>(x,y-1));
						visited[x][y-1] = true;
					}
				}

				if (x < m-1) {
					if (board[x+1][y] == 'O' && !visited[x+1][y]) {
						q.push_back(pair<int,int>(x+1,y));
						visited[x+1][y] = true;
					}
				}

				if (y < n-1) {
					if (board[x][y+1] == 'O' && !visited[x][y+1]) {
						q.push_back(pair<int,int>(x,y+1));
						visited[x][y+1] = true;
					}
				}

				q.pop_front();

			}
		}

		// left
		for (i = 0; i < m; ++i) {
			if (board[i][0] == 'X' || visited[i][0])
				continue;
			q.push_back(pair<int,int>(i,0));
			while(!q.empty()) {
				cor = q.front();
				circles.push_back(cor);
				x = cor.first;
				y = cor.second;

				if (x > 1) {
					if (board[x-1][y] == 'O' && !visited[x-1][y]) {
						q.push_back(pair<int,int>(x-1,y));
						visited[x-1][y] = true;
					}
				}

				if (y > 1) {
					if (board[x][y-1] == 'O' && !visited[x][y-1]) {
						q.push_back(pair<int,int>(x,y-1));
						visited[x][y-1] = true;
					}
				}

				if (x < m-1) {
					if (board[x+1][y] == 'O' && !visited[x+1][y]) {
						q.push_back(pair<int,int>(x+1,y));
						visited[x+1][y] = true;
					}
				}

				if (y < n-1) {
					if (board[x][y+1] == 'O' && !visited[x][y+1]) {
						q.push_back(pair<int,int>(x,y+1));
						visited[x][y+1] = true;
					}
				}

				q.pop_front();

			}
		}

		// right

		for (i = 0; i < m; ++i) {
			if (board[i][n-1] == 'X' || visited[i][n-1])
				continue;
			q.push_back(pair<int,int>(i,n-1));
			while(!q.empty()) {
				cor = q.front();
				circles.push_back(cor);
				x = cor.first;
				y = cor.second;

				if (x > 1) {
					if (board[x-1][y] == 'O' && !visited[x-1][y]) {
						q.push_back(pair<int,int>(x-1,y));
						visited[x-1][y] = true;
					}
				}

				if (y > 1) {
					if (board[x][y-1] == 'O' && !visited[x][y-1]) {
						q.push_back(pair<int,int>(x,y-1));
						visited[x][y-1] = true;
					}
				}

				if (x < m-1) {
					if (board[x+1][y] == 'O' && !visited[x+1][y]) {
						q.push_back(pair<int,int>(x+1,y));
						visited[x+1][y] = true;
					}
				}

				if (y < n-1) {
					if (board[x][y+1] == 'O' && !visited[x][y+1]) {
						q.push_back(pair<int,int>(x,y+1));
						visited[x][y+1] = true;
					}
				}

				q.pop_front();

			}
		}
		board = (vector<vector<char> >(m, vector<char>(n,'X')));
		while (!circles.empty()) {
			cor = circles.back();
			board[cor.first][cor.second] = 'O';
			circles.pop_back();
		}

	}
};