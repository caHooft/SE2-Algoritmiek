// ttt.h

#ifndef TTT_H
#define TTT_H
#include <algorithm>
#include <map>
#include <limits>
#include <tuple>
#include <array>
#include <vector>
#include <ctime>
#include <random>
#include <iterator>
#include <iostream>

using namespace std;

enum class Player { X, O, None };
using Move = int;
using State = array<Player,9>;
using MoveEval = pair<Move, int>;

// used to get a random element from a container
template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) 
{
    uniform_int_distribution<> dis(0, distance(start, end) - 1);
    advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) 
{
    static random_device rd;
    static mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

ostream &operator<<(ostream &os, const State &state);
ostream &operator<<(ostream &os, const Player &player);

Player getCurrentPlayer(const State &state);
State doMove(const State &state, const Move &m);
Player getWinner(const State &state);
vector<Move> getMoves(const State &state);

#endif // TTT_H