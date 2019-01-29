// ttt_mc.cpp
// Compile with: g++ -std=c++11 -o ttt_mc ttt_mc.cpp ttt.cpp
#include "ttt.h"
#include <iostream>
#include <algorithm>
#include <map>
/*
using namespace std;

array<int, 9> scores = { 0,0,0,0,0,0,0,0,0 };

enum class PlayerType { Human, Computer };

void mcUpdateScores(array<int, 9> &subscores, State &trialboard, Player &winner)
{
	for (int i = 0; i < 9; i++)
	{
		if (winner == Player::X)
		{
			if (trialboard[i] == Player::X)
			{
				subscores[i]++;
			}

			if (trialboard[i] == Player::O)
			{
				subscores[i]--;
			}
		}

		if (winner == Player::O)
		{
			if (trialboard[i] == Player::X)
			{
				subscores[i]--;
			}

			if (trialboard[i] == Player::O)
			{
				subscores[i]++;
			}
		}
	}
	
	for (int i = 0; i < 9; i++)
	{
		scores[i] = scores[i] + subscores[i];
	}
}

State mcTrial(const State &board)
{
	State trialboard = board;
	array<int, 9> subscores = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	Player winner;

	vector<Move> moves = getMoves(trialboard);

	while (moves.size() != 0)
	{
		trialboard = doMove(trialboard, moves[(rand() % moves.size())]);
		moves = getMoves(trialboard);
	}

	winner = getWinner(trialboard);

	mcUpdateScores(subscores, trialboard, winner);

	return board;
}

Move getBestMove(State &board)
{
	int highest = -100;
	int index = -1;

	for (int i = 0; i < 9; i++)
	{
		if (scores[i] > highest && board[i] == Player::None)
		{
			highest = scores[i];
			index = i;
		}
	}

	return index;
}

Move mcMove(State &board)
{
	scores = { 0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 20000; i++)
	{
		board = mcTrial(board);
	}

	return getBestMove(board);
}

int main()
{
	srand(time(0));

	map<Player, PlayerType> playerType;
	playerType[Player::X] = PlayerType::Human;
	playerType[Player::O] = PlayerType::Computer;

	State board =
	{
		Player::None, Player::None, Player::None,
		Player::None, Player::None, Player::None,
		Player::None, Player::None, Player::None
	};
	cout << board << endl;

	vector<Move> moves = getMoves(board);
	while (moves.size() > 0)
	{
		if (playerType[getCurrentPlayer(board)] == PlayerType::Human)
		{
			cout <<
				"+-+-+-+" << endl <<
				"|0|1|2|" << endl <<
				"+-+-+-+" << endl <<
				"|3|4|5|" << endl <<
				"+-+-+-+" << endl <<
				"|6|7|8|" << endl <<
				"+-+-+-+" << endl <<
				endl;
			cout << "Enter a move ( ";
			for (Move m : moves) cout << m << " ";
			cout << "): ";
			Move m;
			cin >> m;
			board = doMove(board, m);
		}

		else
		{
			board = doMove(board, mcMove(board));
		}
		cout << board << endl;
		moves = getMoves(board);
	}

	return 0;
}
*/