int matrix_add(int* out_matrix, const int *m1, const int *m2, int row_count, int col_count)
{
  int i,j, index;
  for(i = 0; i < row_count; i++){
    for(j = 0; j < col_count; j++){
      index = i * col_count + j;
      out_matrix[index] = m1[index] + m2[index];
    }
  }
  return 0;
}

int matrix_sub(int* out_matrix, const int *m1, const int *m2, int row_count, int col_count)
{
  int i,j, index;
  for(i = 0; i < row_count; i++){
    for(j = 0; j < col_count; j++){
      index = i * col_count + j;
      out_matrix[index] = m1[index] - m2[index];
    }
  }
  return 0;
}

int matrix_mul(int* out_matrix, int* m1, int* m2, int m1_col_count, int row_count, int m2_col_count)
{
  int i, j, k;
  for(i = 0; i < row_count; i++){
    for(j = 0; j < m2_col_count; j++){
      out_matrix[i * m2_col_count + j] = 0;
      for(k = 0; k < m1_col_count; k++){
        out_matrix[i * m2_col_count + j] += m1[i * m1_col_count + k] * m2[k * m2_col_count + j];
      }
    }
  }
  return 0;
}