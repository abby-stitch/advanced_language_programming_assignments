/* 1850917 电信 梁诗瑶 */
#pragma once

/*源程序文件的公用声明部分及其它所需内容*/
#define M 8
#define N 10
#define START_MAX 3
#define TIME 50

/* 90-b2-tools */
void input_int(const char* prompt, const int min, const int max, int& val);
void input_coordinate(const int row, const int col, int& row_pos, int& col_pos, int matrix[][N]);
void input_End();
char input_is_merge(const int row_pos, const int col_pos);
void wait_for_enter(const char* prompt);
void reset(const int row, const int col, int arr[][N]);

/* 90-b2-base */
void generate_matrix(const int row, const int col, int matrix[][N]);
void print_matrix(int mode, const char* prompt, const int row, const int col, int str[][N]);
void print_matrix_color(const char* prompt, const int row, const int col, int matrix[][N], int pos[][N]);
int is_adjacent_same(const int row, const int col, const int row_pos, const int col_pos, int matrix[][N]);
void seek_same_val_nonrecursive(const int row, const int col, int row_pos, int col_pos, int matrix[][N], int pos[][N]);
void seek_same_val_recursive(const int row, const int col, int row_pos, int col_pos, int matrix[][N], int pos[][N]);
void merge(const int row, const int col, const int row_pos, const int col_pos, int matrix[][N], int pos[][N], int& point, int goal, int& max, int mode = 0);
void drop_down(const int row, const int col, const int row_pos, const int col_pos, int matrix[][N], int pos[][N], int mode = 0);
void fill_new_val(const int row, const int col, int matrix[][N], int pos[][N], const int max, int mode = 0);
int is_array_adjacent_same(const int row, const int col, int matrix[][N]);

/* 90-b2-console */
void show_outer_frame(int x_pos, int y_pos, const int row, const int col, int mode);
void show_cube(const int x, const int y, int val, int mode = 0);
void show_sel_cube(const int x, const int y, int val, int mode = 0);
void show_arr_cube(int x_pos, int y_pos, const int row, const int col, int matrix[][N], int mode);
void move_by_arrow(const int x_pos, const int y_pos, int& row_pos, int& col_pos, const int row, const int col, int matrix[][N], int pos[][N], int mode = 0);
void show_arr(int x_pos, int y_pos, const int row, const int col, int matrix[][N], int pos[][N], int mode = 0);
void fall_down(const int x_pos, const int y_pos, const int row, const int col, const int row_pos, const int col_pos, int matrix[][N], int pos[][N]);
