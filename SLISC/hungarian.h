// Hungarian algorithm in C++ The Hungarian algorithm,
// also know as Munkres or Kuhn-Munkres algorithm is usefull for solving the assignment problem
// https://github.com/phoemur/hungarian_algorithm
// see also: https://www.geeksforgeeks.org/hungarian-algorithm-assignment-problem-set-1-introduction/

/* This is an implementation of the Hungarian algorithm in C++
 * The Hungarian algorithm, also know as Munkres or Kuhn-Munkres
 * algorithm is usefull for solving the assignment problem.
 *
 * Assignment problem: Let C be an n x n matrix 
 * representing the costs of each of n workers to perform any of n jobs.
 * The assignment problem is to assign jobs to workers so as to 
 * minimize the total cost. Since each worker can perform only one job and 
 * each job can be assigned to only one worker the assignments constitute 
 * an independent set of the matrix C.
 * 
 * It is a port heavily based on http://csclab.murraystate.edu/~bob.pilgrim/445/munkres.html
 * 
 * This version is written by Fernando B. Giannasi */
#pragma once
#include "copy.h"
#include "arithmetic.h"

namespace slisc {

/* Handle negative elements if present. If allowed = true, add abs(minval) to 
 * every element to create one zero. Else throw an exception */
inline void hungarian_handle_negatives(vvecLong& matrix, bool allowed = true)
{
	Long minval = min(matrix);
	if (minval < 0) {
	    if (!allowed) { //throw
	        throw std::runtime_error("Only non-negative values allowed");
	    }
	    else { // add abs(minval) to every element to create one zero
	        minval = abs(minval);
			matrix += minval;
	    }
	}
}

/* For each row of the matrix, find the smallest element and subtract it from every 
 * element in its row.  
 * For each col of the matrix, find the smallest element and subtract it from every 
 * element in its col. Go to Step 2. */
inline void hungarian_step1(vvecLong& matrix, Long& step)
{
	// process rows
	for (auto& row: matrix) {
	    auto smallest = *std::min_element(begin(row), end(row));
	    if (smallest > 0) row -= smallest;
	}
	// process cols
	Long sz = matrix.size(); // square matrix is granted
	for (Long j = 0; j < sz; ++j) {
	    Long minval = std::numeric_limits<Long>::max();
	    for (Long i = 0; i < sz; ++i)
	        minval = std::min(minval, matrix[i][j]);
	    if (minval > 0)
	        for (Long i=0; i<sz; ++i)
	            matrix[i][j] -= minval;
	}
	step = 2;
}

/* Find a zero (Z) in the resulting matrix.  If there is no starred zero in its row or 
 * column, star Z. Repeat for each element in the matrix. Go to Step 3.  In this step, 
 * we introduce the mask matrix M, which in the same dimensions as the cost matrix and 
 * is used to star and prime zeros of the cost matrix.  If M(i,j)=1 then C(i,j) is a 
 * starred zero,  If M(i,j)=2 then C(i,j) is a primed zero.  We also define two vectors 
 * RowCover and ColCover that are used to "cover" the rows and columns of the cost matrix.
 * In the nested loop (over indices i and j) we check to see if C(i,j) is a zero value 
 * and if its column or row is not already covered.  If not then we star this zero 
 * (i.e. set M(i,j)=1) and cover its row and column (i.e. set R_cov(i)=1 and C_cov(j)=1).
 * Before we go on to Step 3, we uncover all rows and columns so that we can use the 
 * cover vectors to help us count the number of starred zeros. */
inline void hungarian_step2(vvecLong_I matrix, vvecChar_IO M, vecBool_IO RowCover,
	       vecBool_IO ColCover, Long& step)
{
	Long sz = matrix.size();
	for (Long r=0; r<sz; ++r) 
	    for (Long c=0; c<sz; ++c) 
	        if (matrix[r][c] == 0)
	            if (RowCover[r] == 0 && ColCover[c] == 0) {
	                M[r][c] = 1; RowCover[r] = 1; ColCover[c] = 1;
	            }
	copy(RowCover, false); copy(ColCover, false);
	step = 3;
}

/* Cover each column containing a starred zero.  If K columns are covered, the starred 
 * zeros describe a complete set of unique assignments.  In this case, Go to DONE, 
 * otherwise, Go to Step 4. Once we have searched the entire cost matrix, we count the 
 * number of independent zeros found.  If we have found (and starred) K independent zeros 
 * then we are done.  If not we procede to Step 4.*/
inline void hungarian_step3(vvecChar_I M, vecBool_IO ColCover, Long_IO step)
{
	Long sz = M.size(), colcount = 0;
	for (Long r=0; r<sz; ++r)
	    for (Long c=0; c<sz; ++c)
	        if (M[r][c] == 1)
	            ColCover[c] = 1;
	for (auto n : ColCover)
	    if (n == 1)
	        colcount++;
	if (colcount >= sz)
	    step = 7; // solution found
	else
	    step = 4;
}

// Following functions to support step 4
inline void hungarian_find_a_zero(Long& row, Long& col,
	             vvecLong_I matrix, vecBool_I RowCover, vecBool_I ColCover)
{
	Long r = 0, c = 0, sz = matrix.size();
	bool done = false;
	row = col = -1;
	while (!done) {
	    c = 0;
	    while (true) {
	        if (matrix[r][c] == 0 && !RowCover[r] && !ColCover[c]) {
	            row = r; col = c; done = true;
	        }
	        c += 1;
	        if (c >= sz || done)
	            break;
	    }
	    r += 1;
	    if (r >= sz)
	        done = true;
	}
}

inline bool hungarian_star_in_row(Long row, vvecChar_I M)
{
	bool tmp = false;
	for (Long c = 0; c < size(M); c++)
	    if (M[row][c] == 1)
	        tmp = true;
	return tmp;
}

/* Find a noncovered zero and prime it.  If there is no starred zero in the row containing
 * this primed zero, Go to Step 5.  Otherwise, cover this row and uncover the column 
 * containing the starred zero. Continue in this manner until there are no uncovered zeros
 * left. Save the smallest uncovered value and Go to Step 6. */
inline void hungarian_step4(vvecLong_I matrix, vvecChar_IO M, vecBool_IO RowCover,
	       vecBool_IO ColCover, Long& path_row_0, Long& path_col_0, Long& step)
{
	Long row = -1, col = -1, sz = M.size();
	bool done = false;
	while (!done) {
	    hungarian_find_a_zero(row, col, matrix, RowCover, ColCover);
	    if (row == -1){
	        done = true;
	        step = 6;
	    }
	    else {
	        M[row][col] = 2;
	        if (hungarian_star_in_row(row, M)) {
	            // hungarian_find_star_in_row(row, col, M);
	            col = -1;
	            for (Long c = 0; c < sz; c++)
	                if (M[row][c] == 1)
	                    col = c;
	            RowCover[row] = 1; ColCover[col] = 0;
	        }
	        else {
	            done = true; step = 5;
	            path_row_0 = row;
	            path_col_0 = col;
	        }
	    }
	}
}

// Following functions to support step 5
inline void hungarian_find_star_in_col(Long c, Long& r, vvecChar_I M)
{
	r = -1;
	for (Long i = 0; i < size(M); i++)
	    if (M[i][c] == 1)
	        r = i;
}

inline void hungarian_find_prime_in_row(Long r, Long& c, vvecChar_I M)
{
	for (unsigned j = 0; j < M.size(); j++)
	    if (M[r][j] == 2)
	        c = j;
}

/* Construct a series of alternating primed and starred zeros as follows.  
 * Let Z0 represent the uncovered primed zero found in Step 4.  Let Z1 denote the 
 * starred zero in the column of Z0 (if any). Let Z2 denote the primed zero in the 
 * row of Z1 (there will always be one).  Continue until the series terminates at a 
 * primed zero that has no starred zero in its column.  Unstar each starred zero of 
 * the series, star each primed zero of the series, erase all primes and uncover every 
 * line in the matrix.  Return to Step 3.  You may notice that Step 5 seems vaguely 
 * familiar.  It is a verbal description of the augmenting path algorithm (for solving
 * the maximal matching problem). */
inline void hungarian_step5(vvecLong& path, Long path_row_0, Long path_col_0, 
	       vvecChar_IO M, vecBool_IO RowCover, vecBool_IO ColCover, Long& step)
{
	Long r = -1, c = -1;
	Long path_count = 1;
	path[path_count - 1][0] = path_row_0;
	path[path_count - 1][1] = path_col_0;
	bool done = false;
	while (!done) {
	    hungarian_find_star_in_col(path[path_count - 1][1], r, M);
	    if (r > -1) {
	        path_count += 1;
	        path[path_count - 1][0] = r;
	        path[path_count - 1][1] = path[path_count - 2][1];
	    }
	    else {done = true;}
	    
	    if (!done) {
	        hungarian_find_prime_in_row(path[path_count - 1][0], c, M);
	        path_count += 1;
	        path[path_count - 1][0] = path[path_count - 2][0];
	        path[path_count - 1][1] = c;
	    }
	}
	// augment_path
	for (Long p = 0; p < path_count; p++)
	    if (M[path[p][0]][path[p][1]] == 1)
	        M[path[p][0]][path[p][1]] = 0;
	    else
	        M[path[p][0]][path[p][1]] = 1;
	copy(RowCover, false); copy(ColCover, false);
	// erase primes
	for (auto& row: M)
	    for (auto& val: row)
	        if (val == 2)
	            val = 0;
	step = 3;
}

/* Add the value found in Step 4 to every element of each covered row, and subtract it 
 * from every element of each uncovered column.  Return to Step 4 without altering any
 * stars, primes, or covered lines. Notice that this step uses the smallest uncovered 
 * value in the cost matrix to modify the matrix.  Even though this step refers to the
 * value being found in Step 4 it is more convenient to wait until you reach Step 6 
 * before searching for this value.  It may seem that since the values in the cost 
 * matrix are being altered, we would lose sight of the original problem.  
 * However, we are only changing certain values that have already been tested and 
 * found not to be elements of the minimal assignment.  Also we are only changing the 
 * values by an amount equal to the smallest value in the cost matrix, so we will not
 * jump over the optimal (i.e. minimal assignment) with this change. */
inline void hungarian_step6(vvecLong& matrix, vecBool_I RowCover, vecBool_I ColCover, Long& step)
{
	Long sz = matrix.size(), minval = std::numeric_limits<Long>::max();
	for (Long r = 0; r < sz; r++)
	    for (Long c = 0; c < sz; c++)
	        if (RowCover[r] == 0 && ColCover[c] == 0)
	            if (minval > matrix[r][c])
	                minval = matrix[r][c];
	for (Long r = 0; r < sz; r++)
	    for (Long c = 0; c < sz; c++) {
	        if (RowCover[r] == 1)
	            matrix[r][c] += minval;
	        if (ColCover[c] == 0)
	            matrix[r][c] -= minval;
	}
	step = 4;
}

/* Main function of the algorithm */
// `original` is the square cost matrix
inline Long hungarian(vvecLong_I cost, bool allow_negatives = true)
{
	const Long sz = cost.size();
#ifdef SLS_CHECK_SHAPES
	if (cost.empty() || size(cost[0]) != sz)
	    SLS_ERR("wrong shape!");
#endif
	vvecLong matrix(sz, vecLong(sz));
	copy(matrix, cost);
	hungarian_handle_negatives(matrix, allow_negatives);

	vvecChar M(sz, vecChar(sz, 0)); // The masked matrix M
	vecBool RowCover(sz, 0), ColCover(sz, 0); // "cover" the cost matrix
	Long path_row_0, path_col_0; // temporary to hold the smallest uncovered value
	vvecLong path(2*sz, vecLong(2, 0)); // Array for the augmenting path algorithm
	
	bool done = false;
	Long step = 1;
	while (!done) {
	    switch (step) {
	        case 1:
	            hungarian_step1(matrix, step); break;
	        case 2:
	            hungarian_step2(matrix, M, RowCover, ColCover, step); break;
	        case 3:
	            hungarian_step3(M, ColCover, step); break;
	        case 4:
	            hungarian_step4(matrix, M, RowCover, ColCover, path_row_0, path_col_0, step); break;
	        case 5:
	            hungarian_step5(path, path_row_0, path_col_0, M, RowCover, ColCover, step); break;
	        case 6:
	            hungarian_step6(matrix, RowCover, ColCover, step); break;
	        case 7:
	            for (auto &vec: M) { vec.resize(sz); }
	            M.resize(sz); done = true; break;
	        default:
	            done = true; break;
	    }
	}
	// total cost
	Long res = 0;
	for (Long j = 0; j < sz; ++j)
	    for (Long i = 0; i < sz; ++i)
	        if (M[i][j]) {
	            auto it1 = cost.begin();
	            std::advance(it1, i);
	            auto it2 = it1->begin();
	            std::advance(it2, j);
	            res += *it2;
	            continue;                
	        }
	return res;
}

} // namespace slisc
