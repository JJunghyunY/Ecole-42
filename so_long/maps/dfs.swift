import Foundation

var MAP =
"""
1111111111111
1C010000000C1
1000011111001
1P0011E0000C1
1111111111111
"""

var board = [[String]]()
for _ in 0..<5 {
	board.append(readLine()!.map{String($0)})
}
var checkBoard = board
var totalC = 3
var totalE = 1
var dX = [1, -1, 0, 0]
var dY = [0, 0, 1, -1]
var success = 0

for i in 0..<5 {
	for j in 0..<13 {
		if (board[i][j] == "P") {
			dfs(i, j)
		}
	}
}

func dfs(_ x: Int, _ y: Int) {
	if (checkBoard[x][y] == "1") { return }
	checkBoard[x][y] = "1"
	print("dfs >> ", x, y)
	if (board[x][y] == "1") {
		print("board 1 ", x, y);return }
	else if (board[x][y] == "E") {
		print("meet E >", board[x][y])
		totalE -= 1
	}
	else if (board[x][y] == "C") {
		print("meet C >", board[x][y])
		totalC -= 1
	}
	
	for i in 0...3 {
		if (x + dX[i] < 5 || y + dY[i] < 13) {
			dfs(x + dX[i], y + dY[i])
		}
	}
}

if totalC == 0 && totalE == 0 {print("success")}
else {print("fail")}

	// i = -1;
	// map = (char **)malloc(sizeof(char) * game->hei);
	// while (++i < game->hei)
	// {
	// 	map[i] = (char *)malloc(sizeof(char) * game->wid);
	// 	map[i] = &game->str[i * game->wid];
	// }
