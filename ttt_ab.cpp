// ttt_ab.cpp
// Compile with: g++ -std=c++11 -o ttt_ab ttt_ab.cpp ttt.cpp

#include <iostream>
#include <algorithm>
#include <map>
#include <limits>
#include "ttt.h"

enum class PlayerType { Human, Computer };

int getMonteCarloEval(const State &board, Player player, int trials)
{
	vector<Move> moves = getMoves(board);

	int score = 0;

	State mcBoard = board;

	for (int i = 0; i < trials; ++i)
	{
		random_shuffle(moves.begin(), moves.end());

		if (getWinner(mcBoard) == Player::X)
		{
			if (board[i] == Player::X)
			{
				score++;
			}

			if (board[i] == Player::O)
			{
				score--;
			}
		}

		if (getWinner(mcBoard) == Player::O)
		{
			if (board[i] == Player::X)
			{
				score--;
			}

			if (board[i] == Player::O)
			{
				score++;
			}
		}
	}

	return score;
}

int eval(const State &board, const Player &player)
{
	vector<Move> moves = getMoves(board);

	int wins = 0;

	State mcBoard = board;

	for (int i = 0; i < 9; ++i)
	{
		random_shuffle(moves.begin(), moves.end());
		 
		for (const Move &m : moves)
		{
			mcBoard = doMove(mcBoard, m);
		}			
		
		if (getWinner(mcBoard) == player)
		{
			wins ++;
		}	

	}

	return wins - 200 / 2;
}

MoveEval alphaBeta(State &board, int ply, Player player, Player opponent, int alpha, int beta)
{
	if (ply == 0)
	{
		return make_pair(Move(), getMonteCarloEval(board, player,9));
	}		

	vector<Move> moves = getMoves(board);

	if (moves.size() == 0)
	{
		return make_pair(Move(), getMonteCarloEval(board, player,9));
	}		

	MoveEval best = make_pair(Move(), alpha);

	for (Move &move : moves)
	{
		doMove(board, move);
		MoveEval me = alphaBeta(board, ply - 1, opponent, player, -beta, -alpha);

		if (-me.second > alpha)
		{
			alpha = -me.second;
			best = make_pair(move, alpha);
		}

		if (alpha >= beta)
		{
			return best;
		}
			
	}

	return best;
}

Move alphaBeta(const State &b, int ply)
{
	State board(b);
	Player player = getCurrentPlayer(board);
	Player opponent = Player::None;

	if (player == Player::X)
	{
		opponent = Player::O;
	}

	else
	{
		opponent = Player::X;
	}
	
	return alphaBeta(board, ply, player, opponent, numeric_limits<int>::min() + 1, numeric_limits<int>::max()).first;
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
			cout << "+-+-+-+" << endl <<
				"|0|1|2|" << endl <<
				"+-+-+-+" << endl <<
				"|3|4|5|" << endl <<
				"+-+-+-+" << endl <<
				"|6|7|8|" << endl <<
				"+-+-+-+" << endl << endl;
			cout << "Enter a move ( ";
			for (Move m : moves) cout << m << " ";
			cout << "): ";
			Move m;
			cin >> m;
			board = doMove(board, m);
		}

		else 
		{
			board = doMove(board, alphaBeta(board, 5));
		}
		cout << board << endl;
		moves = getMoves(board);
	}

	return 0;
}