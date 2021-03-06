#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "move.h"

#define WHITE 0
#define BLACK 1

#define MAX_GAME_PLY 1024 // max length of game
#define MAX_TOTAL_MOVES 4096 // max moves available in a position

typedef unsigned long long U64;

typedef struct 
{
    char white_castle_k;
    char white_castle_q;
    char black_castle_k;
    char black_castle_q;
    char en_passant_loc;
    char fifty_move_rule;
} RECORD_t;

typedef struct
{
    MOVE_t movelist[MAX_TOTAL_MOVES];
    RECORD_t history[MAX_GAME_PLY];

    U64 white_pawns;
    U64 white_knights;
    U64 white_bishops;
    U64 white_rooks;
    U64 white_queens;
    U64 white_king;

    U64 black_pawns;
    U64 black_knights;
    U64 black_bishops;
    U64 black_rooks;
    U64 black_queens;
    U64 black_king;

    U64 white_pieces;
    U64 black_pieces;
    U64 all_pieces;

    // history[end_of_search] is the deepest we've gone, the furthest search
    // deptch achieved is end_of_search - move_number.
    int move_number;   // indexes to history
    int end_of_search; // indexes to history

    char white_castle_k;
    char white_castle_q;
    char black_castle_k;
    char black_castle_q;

    char white_to_move;
    char fifty_move_rule;
    char en_passant_loc;
} BOARD_t;

RECORD_t* new_record(BOARD_t*);
BOARD_t* new_empty_board(void);
BOARD_t* new_board(char[]);
void print_bitboard(U64);
void print_board(BOARD_t*);
char alg_loc_to_int(char, char);
void update_special_bitboards(BOARD_t*);
void make_move(BOARD_t*, MOVE_t);
void unmake_move(BOARD_t*, MOVE_t);
void unmake_capture(BOARD_t*, U64, char);
void unmake_white_promotion(BOARD_t*, U64, char);
void unmake_black_promotion(BOARD_t*, U64, char);

#endif